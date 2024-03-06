#include <stdio.h>
#include <stdbool.h>

static int enc[] = {-1934298443, -1728250251, -2103640211, -1153630219, 1775435890, -1670578291, 2009268234, -2009268235, 1950549658, -1992754035, 1673724026, -1398997107, 1405288466, 1824718858, 2131951730, -1765998643, 1934298490, -1330315635, 2063794322, 1889730674, 1124270194, -2059599891, 1086521394, -1858273331, 1909484170, 1229390194, 1757609994, -1275265139, 1201864818, -1892876403, 1673723922, 2009268234, 1950549402, 1229390194, 1947140466, -1942159371, 1849884786, 1703084146, 1824718858, -1665335347, 1909484170, -1229390195, 1757609994, 1170407434, 1124270194, -1918042227, 2038628466, -1982005363, 1950549834, 1124270322, 1782775922, -1738735731, 1768095858, 1842544754, 2127757426};
static char key[] = "VishwaCTF";

int createTopping(int curr, int idx, int *not_remainder)
{
    int temp = 0;
    int num = 1;
    num = num << 1;
    while (curr)
    {
        int remainder = curr % idx;
        if (remainder)
        {
            temp = temp * 10 + remainder;
            curr = curr - remainder;
        }
        else
        {
            num = num | 1;
            curr = curr / idx;
        }
        num = num << 1;
    }
    temp = temp << 1;
    temp = temp | 1;
    *not_remainder = temp;
    return num | 1;
}

int createBase(int not_remainder)
{
    int num = 0;
    for (int i = 0; i < 30; ++i)
    {
        if (not_remainder)
        {
            num = num | (not_remainder & 1);
            not_remainder = not_remainder >> 1;
        }
        num = num << 1;
    }
    return num;
}

bool checkValidity(int num)
{
    for (int i = 2; i * i < num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    for (int i = 0; i < 55; ++i) {
        int idx = (i % 8) + 2;
        bool found = false;
        for (int curr = 0x20; curr < 0x7F; ++curr) {
            int not_remainder = 0;
            int topping = createTopping(curr, idx, &not_remainder);
            int base = createBase(not_remainder);
            int num = base | topping;

            for (int k = 0; k < 9; ++k) {
                int curr_key = key[k];
                int cnt = 0;
                int cpy = curr_key;
                while (cpy)
                {
                    if (cpy & 1)
                        ++cnt;
                    cpy = cpy >> 1;
                }
                curr_key = curr_key << (k + 10);
                while (cnt--)
                {
                    curr_key = curr_key << 1;
                    curr_key = curr_key ^ 1;
                }

                num ^= curr_key;
            }

            if (checkValidity(i + 2))
                num = ~num;

            if (num == enc[i]) {
                printf("%c", curr);
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Failed to find chr for index %d\n", i);
            return 1;
        }
    }

    return 0;
}
