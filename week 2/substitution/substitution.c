#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    // ensure argc is 26
    if (argc != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    string plainText = get_string("plaintext: ");
    const int stringLength = strlen(argv[1]);

    for (int i = 0; i < stringLength; i++)
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
    printf("%s", plainText);

    // Use an if statement to convert back to upper / lowercase

    // convert plaintext to cipher text
}