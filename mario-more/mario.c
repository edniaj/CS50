#include <cs50.h>
#include <stdio.h>

void leftTower(int height);
void rightTower(int height);
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
    leftTower(height);
}

void leftTower(int height)
{
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = height - i; k > 0; k--)
        {
            printf("#");
        }
        printf("  ");
        for (int k = height - i; k > 0; k--)
        {
            printf("#");
        }
        printf("\n");
    }
}
