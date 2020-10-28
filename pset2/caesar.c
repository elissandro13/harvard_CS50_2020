#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>



int main(int argc, string argv[])
{

    //check if is only one argument and if is a number
    if (argc != 2 || !(isdigit(*argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //chack if is number + string
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {

            printf("Key must interger\n");
            return 1;
        }
    }
    //check if is positive
    if (atoi(argv[1]) < 0)
    {
        printf("Key must be positive\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string code = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0; i < strlen(code); i++)
        {
            //lowercase
            if (code[i] >= 'a' && code[i] <= 'z')
            {
                printf("%c", (((code[i] - 'a') + key) % 26) + 'a');
            }
            //uppercaser
            else if (code[i] >= 'A' && code[i] <= 'Z')
            {
                printf("%c", (((code[i] - 'A') + key) % 26) + 'A');
            }
            //blank spaces and other chars
            else
            {
                printf("%c", code[i]);
            }
        }




        printf("\n");

    }




    return 0;
}