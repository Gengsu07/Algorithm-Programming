/* 17L01. Using the malloc function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* function declaration */
void StrCopy(char *str1, char *str2);
/* main() function */
int main(void)
{
    char str[] = "Use malloc() to allocate memory.";
    char *ptr_str;
    char strarr[] = "cek";
    int result;
    /* call malloc() */
    ptr_str = malloc(strlen(str) + 1);
    if (ptr_str != NULL)
    {
        StrCopy(str, ptr_str);
        printf("The string pointed to by ptr_str is:\n%s\n",
               ptr_str);
        printf("%s", strarr);
        result = 0;
    }
    else
    {
        printf("malloc() function failed.\n");
        result = 1;
    }
    return result;
}
/* function definition */
void StrCopy(char *str1, char *str2)
{
    int i;

    for (i = 0; str1[i]; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
}
