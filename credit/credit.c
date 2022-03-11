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
        if ( ( lengthOfCard == 13 || lengthOfCard == 16)&& strcmp(firstChar,"4"))
        {
            printf("VISA");
        }

        if (lengthOfCard == 15 &&  strcmp(firstChar ,"3") &&  ( firstChar ,"4") || secondChar ,"7")  ))
            {
                printf("American Express");
            }
        if (lengthOfCard == 16)
        {
            if (    strcmp(firstChar,"5")   &&  ( strcmp(secondChar ,"1") || strcmp(secondChar ,"2") || strcmp(secondChar ,"3") || strcmp(secondChar ,"4") || strcmp(secondChar ,"5") ) )
            {
                printf("\nchar is : %c\n", firstChar ); //4003600000000014
                printf("MasterCard");
            }
        }
    }
    else
    {
        printf("INVALID");
    }
}