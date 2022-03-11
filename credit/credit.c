#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string creditCard = get_string("Number: ");
    printf("%s", creditCard);
    int length = strlen(creditCard);
    for (int i = 0; i < length; i++)
    {
        printf("%s", typeid(cardCard[i]));
    }
}