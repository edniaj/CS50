#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string creditCard = get_string("Number: ");
    int total =0;
    unsigned long lengthOfCard = strlen(creditCard);
    // if (( lengthOfCard != 13 && lengthOfCard !=15 ) && lengthOfCard != 16 ) printf("gg %lu",lengthOfCard);


    for(int i=lengthOfCard-2; i>0; i++)
    {
        int temp = (int) creditCard[i] * 2;
        if (temp >10) {
            total++; // Max total is 18
            temp -=10;
        }
        total += temp;
    }
    printf("%i", total);
}