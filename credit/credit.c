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
        if (lengthOfCard == 13 && strcmp(creditCard[0],"4"))
        {
            printf("VISA");
        }

        if (lengthOfCard == 15 && (creditCard [0:2] == "34" || creditCard [0:2] == "37")))
            {
                printf("American Express")
            }
        if (lengthOfCard == 16)
        {
            if (creditCard [0:2] == "51" || creditCard [0:2] == "52" || creditCard [0:2] == "53" || creditCard [0:2] == "54")
            {
                printf("MasterCard")
            }
        }
    }
    else
    {
        printf("INVALID")
    }
}