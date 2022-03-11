#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string creditCard = get_string("Number: ");
    int total = 0;
    unsigned long lengthOfCard = strlen(creditCard);


    printf("%i",CharAt(creditCard[0]));

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
        if ( ( lengthOfCard == 13 || lengthOfCard == 16)&& strcmp(creditCard[0],"4"))
        {
            printf("VISA");
        }

        if (lengthOfCard == 15 &&  strcmp(&creditCard[0] ,"3") &&  ( strcmp(&creditCard[1] ,"4") || strcmp(&creditCard[0] ,"7")  ))
            {
                printf("American Express");
            }
        if (lengthOfCard == 16)
        {
            if (    strcmp(&creditCard[0] ,"5")   &&  ( strcmp(&creditCard[1] ,"1") || strcmp(&creditCard[1] ,"2") || strcmp(&creditCard[1] ,"3") || strcmp(&creditCard[1] ,"4") || strcmp(&creditCard[1] ,"5") ) )
            {
                printf("\nchar is : %c\n", creditCard[0] ); //4003600000000014
                printf("MasterCard");
            }
        }
    }
    else
    {
        printf("INVALID");
    }
}