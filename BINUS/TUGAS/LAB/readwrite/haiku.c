/*
Write a program to read the text file haiku.txt and count the number of characters in the file. Also, print out the contents of the file and the total character number on the screen.
*/

#include <stdio.h>

int main(void)
{
    FILE *file;
    size_t counter = 0;
    int c;

    file = fopen("haiku.txt", "r");
    if (file == NULL)
    {
        printf("Error Membuka file ...");
        return 1;
    }
    else
    {
        while ((c = fgetc(file)) != EOF)
        {
            putchar(c);
            counter++;
        }
    }
    printf("\n Total karakter dalam file adalah %zu\n", counter);
}
