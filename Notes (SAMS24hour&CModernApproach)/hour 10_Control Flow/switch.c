#include <stdio.h>
int main()
{

    int num1;
    printf("Enter 1-3: \n");
    num1 = getchar();
    putchar(num1);

    switch (num1)
    {
    case '1':
        printf("Number is One");
    case '2':
        printf("Number is Two");
    case '3':
        printf("Number is Three");
    }
    return 0;
}