#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int convertKey(string)

int main(int argc, string argv[])
{
    // Convert key into index. Check for non-integer arvv[2]
    const int keyInString = get_int("");
    const int key = convertKey(argv[2]);

    string plainText = argv[1];

    // argv[1] is word to censor.

    // Tranlate every word into the next word. Check for overflows. use islower() for different casing
}

int convertKey(string keyInString)
{
    int lengthKey = strlen(keyInString);
    for (int i = 0; i < lengthKey; i++)
    {
        // Check for each character
        if (isdigit(keyInString[i]) != 0)
        {
            continue
        }
        else
        {
            return 0;
        }
    }
    return atoi(keyInString) // Handle testcase where key is invalid later
}