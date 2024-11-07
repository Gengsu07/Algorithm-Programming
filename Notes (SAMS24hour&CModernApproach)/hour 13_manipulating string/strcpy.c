#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "Gengsuishere";
    char dest[sizeof(src) + 1];
    strcpy(dest, src);

    printf("Copied using strcpy: %s\n", dest);

    for (int i = 0; src[i]; i++)
        dest[i] = src[i];

    printf("Copied using for loop: %s\n", dest);
    return 0;
}

/*
dest[i] = '\0';
so after the loop ended, the i value is still carried the last value?


Fitten Code

Yes, exactly! After the loop ends, the variable i will hold the last value that was incremented during the copying process, which corresponds to the length of the string from src.
*/