#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
}

int leftTower(void)
{
    int height = get_int("enter : ");
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            printf(" ");
        }
        printf("#");
    }
    return 0;
}

leftTower()

