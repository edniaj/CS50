#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string creditCard = get_string("Number: ");
    int total = 0;
    unsigned long lengthOfCard = strlen(creditCard);

    int firstChar = (int) creditCard[0] - 48;
    int secondChar = (int) creditCard[1] - 48;

    for (int i = lengthOfCard - 2; i >= 0; i = i - 2)
    {
        int temp = ((int)creditCard[i] - 48) * 2; //
        if (temp >= 10)
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
        if (  firstChar == 4  && ( lengthOfCard == 13 || lengthOfCard == 16) )
        {
            printf("VISA\n");
        }

        else if (lengthOfCard == 15 && ( firstChar ==3  &&  ( secondChar == 4 || secondChar == 7 )  ) )
            {
                printf("AMEX\n");
            }
        else if (lengthOfCard == 16)
        {
            if (    (firstChar == 5)   && (   secondChar == 1  || secondChar == 2  || secondChar == 3 || secondChar == 4 || secondChar == 5  ) )
            {   //4003600000000014
                printf("MasterCard\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else
    {
    printf("INVALID\n");
    }
}