#include <stdio.h>

int main()
{
    int i;
    int selisih = 'a' - 'A';
    char str[100];

    gets(str);
    printf("Inputted string: %s\n", str);

    // convert to uppercase string
    for (i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - selisih;
    }
    printf("Uppercase string: \n");
    puts(str);
    return 0;
}
/*
The gets function is considered unsafe and has been removed from the C11 standard due to its vulnerability to buffer overflow issues. As an alternative, it is recommended to use fgets, which allows you to specify a maximum number of characters to read, thus providing a measure of safety against overflows.
*/