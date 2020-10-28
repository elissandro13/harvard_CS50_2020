#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int check[26] = {0};

    // check numbers of inputs
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // check 26 chars

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check if its alphabetical
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]) || isdigit(argv[1][i]))
        {
            printf("Characters must be alphabetical");
            return 1;
        }
    }

    // check if the caracters are unique

    for (int i = 0; i < 26; i++)
    {
        argv[1][i] = tolower(argv[1][i]);
        int pos = argv[1][i] - 'a';
        if (check[pos] == 1)
        {
            printf("Key must contain 26 different characters.\n");
            return 1;
        }
        check[pos] = 1;

    }


    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext)];
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!(!isalpha(plaintext[i]) || isdigit(plaintext[i])))
        {

            // check if is capitalized
            if (isupper(plaintext[i]))
            {
                // uppercase
                plaintext[i] = tolower(plaintext[i]);
                char result = argv[1][plaintext[i] - 'a'];
                ciphertext[i] = toupper(result);
            }
            else
            {
                // lower case
                plaintext[i] = tolower(plaintext[i]);
                char result = argv[1][plaintext[i] - 'a'];
                ciphertext[i] = result;
            }
        }
        // non-alphabetical caracters
        else
        {
            ciphertext[i] = plaintext[i];
        }

        printf("%c", ciphertext[i]);
    }

    printf("\n");
    // printf("ciphertext: %s", ciphertext);
    // printf("\n");
    return 0;


}