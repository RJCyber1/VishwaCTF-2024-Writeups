1. Go to /robots.txt:

```
# https://www.robotstxt.org/robotstxt.html
User-agent: *
Disallow: /admin
L3NlY3JldC1sb2NhdGlvbg==
Decryption key: th1s_1s_n0t_t5e_f1a9
```

2. Go to /secret-location (base64 above decodes to this).

3. Find the ciphertext in Local Storage:

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/f315b62a-893d-48f5-807f-d3918c931a71)

4. The challenge says 128 robots, so it must be AES-128. Decrypt the ciphertext (`Gkul0oJKhNZ1E8nxwnMY8Ljn1KNEW9G9l+w243EQt0M4si+fhPQdxoaKkHVTGjmA`) with the key (`th1s_1s_n0t_t5e_f1a9`):

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/2fb066ac-9c2c-4499-bee0-afdf0192ac8e)
