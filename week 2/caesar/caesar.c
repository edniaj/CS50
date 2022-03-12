#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int convertKey(string);

int main(int argc, string argv[])
{

    // Convert key into index. Check for non-integer arvv[2]
    if (argc !=2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    const int key = convertKey(argv[1]);
    if (key == 0)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    string plainText = get_string("plaintext: ");
    int lengthText = strlen(plainText);

    for (int i = 0; i < lengthText; i++)
    {
        int index;
        if (isupper(plainText[i]))
        {
            index = (int)plainText[i] - 'A';
            index += key;
            index %= 26;
            index += 'A';
            plainText[i] = (char)index;
        }
        if (islower(plainText[i]))
        {
            index = (int)plainText[i] - 'a';
            index += key;
            index %= 26;
            index += 'a';
            plainText[i] = (char)index;
        }
    }
    printf("ciphertext: %s\n", plainText);
}

int convertKey(string keyInString)
{
    int lengthKey = strlen(keyInString);
    for (int i = 0; i < lengthKey; i++)
    {
        // Check for each character
        if (isdigit(keyInString[i]) == 0)
        {
            return 0;
        }
    }
    int key = atoi(keyInString);
    key %= 26;
    return key; // Handle testcase where key is invalid later
}