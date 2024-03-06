`git branch -a` lists all branches (there were 3: main, 2, and 3)

`git show *` in the master branch tells us the format:

```
+string -- VishwaCTF{}
+
+HERE -- 0th Index of string is V.
+1th - i
+2nd - s .... and so on.
```

`git log` in branch `3`:
`string[0] = G string[1] = 1 string[2] = t`

`cat index.html | grep string` in branch `2`:

`string[3: 6] = G1g`

Get the image from branch `2` commits:

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/009a1181-e143-4315-b781-adf4bda18251)


`git checkout 2` and `git show 41dca9f040deaa65060065ef78523ba44b2c60f1`:

```
-string[9] = _
-string[10] = 2
-string[11] = 7
-string[12] = 2
-string[13] = 7
```

Full flag: `VishwaCTF{G1tG1gger_2727}`
