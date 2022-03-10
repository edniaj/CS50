#include <cs50.h>
#include <stdio.h>

int string_length(char s[])
{
    int c = 0;
    while (s[c] != '\0')
        c++;

    return c;
}

int charToInt(char c)
{
    int num = 0;

    // Substract '0' from entered char to get
    // corresponding digit
    num = c - '0';

    return num;
}

int main(void)
{
    string cardNumber = get_string("Number: ");
    // int count;
    // for (int i = 0; i++;)
    // {
    //     count = 0;

    //     if (cardNumber[i] != "\0")
    //     {
    //         count++;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    int lengthString = string_length(cardNumber);

    int total = 0;
    for (int i = lengthString - 2; i >= 0; i -= 2)
    {
        total += charToInt(cardNumber[i]) * 2;
        
        }

    printf("%i", total);
}
