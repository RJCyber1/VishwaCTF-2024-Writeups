```
from PIL import Image
from itertools import cycle

def xor(a, b):
    return [i^j for i, j in zip(a, cycle(b))]

f = open("original.png", "rb").read()
key = [f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]]

enc = bytearray(xor(f,key))

open('enc.txt', 'wb').write(enc)
```
As indicated by the script used to encrypt, the key for XOR is `key = [f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]]`. This means that we need to XOR the encrypted text with the PNG magic bytes (`89 50 4E 47 0D 0A 1A 0A`):
![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/f4acff5b-b0ff-4c87-b214-81f7c54c358d)
