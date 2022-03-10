#include <cs50.h>
#include <stdio.h>

void leftTower(int height);
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
}

void leftTower(int height)
{
    for (int i = height-1; i >= 0; i--)
    {
        for(int j=i; j>0; j-- )
        {
            printf('.');
        }
        printf('#');
    }

}

leftTower(3)