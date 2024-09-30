#include <stdio.h>

int main()
{
    int x, y;
    char str[100];

    printf("Enter two integers: ");
    scanf("%d"
          "%d",
          &x, &y);

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Your data are:\n");
    printf("Integers: %d %d \n", x, y);
    printf("String: %s \n", str);

    return 0;
}