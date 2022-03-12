#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkKey(string ciperKey);
int main(int argc, string argv[])
{

    // ensure argc is 26
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    const int stringLength = strlen(argv[1]);
    if (stringLength != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    if (checkKey(argv[1]) == 1)
    {
        printf("Invalid key");
        return 1;
    }

    string plainText = get_string("plaintext: "); // VCHPRZGJNTLSKFBDQWAXEUYMOI

    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isupper(plainText[i]))
        {
            int indexChar = (int)plainText[i] - 'A';
            plainText[i] = toupper(argv[1][indexChar]);
        }
        if (islower(plainText[i]))
        {
            int indexChar = (int)plainText[i] - 'a';
            plainText[i] = tolower(argv[1][indexChar]);
        }
    }
    printf("ciphertext: %s\n", plainText);

    // Use an if statement to convert back to upper / lowercase

    // convert plaintext to cipher text
}

int checkKey(string cipherKey)
{
    for (int i = 0; i < strlen(cipherKey); i++)
    {
        for (int j = i + 1; j < strlen(cipherKey); j++)
        {
            char a = tolower(cipherKey[i]);
            char b = tolower(cipherKey[j]);
            if (!isalpha(cipherKey[j]))
            {
                return 1;
            }
            int value = strcmp(&a, &b);
            if (value == 0)
            {
                return 1;
            }
        }
    }
    return 0;
    // Do a N^2 check to see for repetition // Check isalpha
}