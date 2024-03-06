1. Solve the number puzzle in the challenge:
5, 12, 23, 50, 141, 488, 1859, 7326, ?
The number is 29177 if we use the algorithm provided by https://www.quora.com/5-12-23-50-141-What-number-will-replace-the-question-mark

2. Use the password `29177` to extract a PNG from DeepSound.

3. Use stegosuite (https://github.com/osde8info/stegosuite) to get the next riddle.

4. Instead of solving the riddle, I just brute forced the pass using the format with mcrypt on the enc file provided in the challenge :)

`for i in {000..999}; do mcrypt -d encryptedcode.txt.nc -k "VISHWA-$i";done`

5. Get the decrypted txt file for the flag.
