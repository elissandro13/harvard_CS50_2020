#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting user input data(name)
    string name = get_string("What is your name?\n");
    //Priting user name
    printf("hello, %s\n", name);

}
