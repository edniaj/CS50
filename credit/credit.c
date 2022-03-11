#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string creditCard = get_string("Number: ");
    int total = 0;
    unsigned long lengthOfCard = strlen(creditCard);
    // if (( lengthOfCard != 13 && lengthOfCard !=15 ) && lengthOfCard != 16 ) printf("gg %lu",lengthOfCard);

    for (int i = lengthOfCard - 2; i >= 0; i = i - 2)
    {
        int temp = ((int)creditCard[i] - 48) * 2;
        if (temp > 10)
        {
            total++; // Max total is 18
            temp -= 10;
        }
        total += temp;
    }
    for (int i = lengthOfCard - 1; i >= 0; i = i - 2)
    {
        int temp = ((int)creditCard[i] - 48);
        total += temp;
    }
    if (total % 10 == 0)
    {
        printf("%i\n", total);
    } else {
        printf("INVALID")
    }
}