#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>



int main()
{

    double letters, words, sentences;
    letters =  sentences =  0.0;
    //inicializate with 1 because last sentece is not computated
    words = 1;

    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        //letters  a to z
        if ((text[i] >= 'a' &&  text[i] <=  'z') || (text[i] >= 'A' &&  text[i] <=  'Z'))
        {
            letters++;
        }
        //wprds define by spaces
        if (text[i] == ' ')
        {
            words++;
        }
        //sentences ? . !
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }
    

    //cast to float
    float index = 0.0588 * ((float) letters / (float) words * 100.0) - 0.296 * (((float) sentences / (float) words) * 100.0) - 15.8;


    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        //round
        printf("Grade %d\n", (int)round(index));
    }

    return 0;
}
