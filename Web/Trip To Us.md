1. Find /Error.php in the source.

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/f02b4c92-76a0-4f42-8baf-bb587a9f403b)

3. Change User Agent to `IITIAN`

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/10d2f48b-8e89-449a-8a8f-4ab1728aed14)

4. SQLi in the password parameter on the login page to get the flag:
Username: `admin`
Password: `' OR 1=1 -- -`

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/51814346-beb0-496a-be8f-523b30be1920)
