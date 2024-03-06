1. Access /robots.txt and get the .js file:

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/765f26e9-dd3e-4641-8f7a-ed71a7174f4d)

```var code = `\nHello User👋,\nThis Application has rate limit: 100/hr\nThis Might Help You: /e8e53a51ba308caf79e4628357787f65`;```

2. Access `/e8e53a51ba308caf79e4628357787f65`

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/2451e124-cc1a-4a50-9547-a477dd68cc40)

3. Find loginPage.js in the page source and login with the specified creds (`system0:5yc0re`):

```
console.log("<--system0:5yc0re-->");
document.getElementById('login-form').addEventListener('submit', function (event) {
    event.preventDefault();

    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    fetch('/auth', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ username, password }),
        credentials: 'include', // Include credentials in the request
    })
        .then(response => {
            if (response.ok) {
                // If the response is OK (status code 200-299), redirect to the protected page
                window.location.href = '/retroshop';
            } else {
                // If the response is not OK, log the status code
                if (response.status == 401) {
                    alert("Error: Invalid Username & Password")
                } else {
                    let resError = response.status;
                    alert(`Error: ${resError}`);
                }
            }
        })
        .catch((error) => {
            console.error('Error:', error);
        });
});
```

4. Forge the JWT session cookie by cracking the secret with rockyou.txt (secret: `winniethepooh`) and putting `samarth` as the user.

5. We need to buy 4 more RAM sticks as indicated by the main page:

```
Notice: System is Running out of RAM. Upgrade your memory to 8GB.
            [0.000000] Memory: 4096MB = 4096MB total
```

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/e62d8a0c-bf70-4f23-a453-65101cb2f7bb)

To buy, the site sends a POST to /buy with the following payload:

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/eca1454d-d47d-4401-91c1-e9a99b8bf237)

The hash2 value is rot47 encrypted and the first number is the price of the total purchase. Here is an example when I tried to buy 1 stick worth $8:

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/47a7c25d-b09c-4ff1-87ae-c76b41097b42)

Therefore, we can forge the JSON and send a POST to /buy in order to buy 4 RAM sticks to get the flag without actually having the "money".
