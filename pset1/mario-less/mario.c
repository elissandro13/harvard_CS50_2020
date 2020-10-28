#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Getting input
    int height;
    do
    {
        height = get_int("Height: ");

    }
    while (height < 1 || height > 8);
    //Loop through
    for (int i = 1; i <= height; i++)
    {
        //Priting blank spaces
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        //Printing hashes
        for (int k = 0; k < i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
