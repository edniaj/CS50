#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string creditCard = get_string("Number: ");
    unsigned long lengthOfCard = strlen(creditCard);
    if (( lengthOfCard != 13 && lengthOfCard !=15 ) && lengthOfCard != 16 ) printf("gg %lu",lengthOfCard);

    for(int i=0; i<strlen;)
}