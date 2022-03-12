#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int convertKey(string);

int main(int argc, string argv[])
{

    // Convert key into index. Check for non-integer arvv[2]
    if (argc <= 3) {
        printf("Usage: ./caesar key");
        return 1;
    }
    const int keyInString = get_int("");
    const int key = convertKey(argv[2]);

    string plainText = argv[1];
    int lengthText = strlen(plainText);

    for (int i = 0; i < lengthText; i++)
    {
        int index;
        if (isupper(plainText[i]))
        {
            index = (int)plainText[i] - 'A' + 1;
            index += key;
            index %= 26;
            index += 'A';
            plainText[i] = (char)index;
        }
        if (islower(plainText[i]))
        {
            index = (int)plainText[i] - 'a' + 1;
            index += key;
            index %= 26;
            index += 'a';
            plainText[i] = (char)index;
        }
    }
    printf("%s", plainText);
}

int convertKey(string keyInString)
{
    int lengthKey = strlen(keyInString);
    for (int i = 0; i < lengthKey; i++)
    {
        // Check for each character
        if (isdigit(keyInString[i]) != 0)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    int key = atoi(keyInString);
    key %= 26;
    return key ;// Handle testcase where key is invalid later
}