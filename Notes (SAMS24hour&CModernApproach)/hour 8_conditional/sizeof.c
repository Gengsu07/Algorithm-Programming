#include <stdio.h>

int main()
{
    int num1, size;
    float num2 = 3.5;
    double num3 = 3.14;

    num1 = 100;
    size = sizeof(int);
    printf("size of integer = %d bytes \n", size);
    printf("interger %d also = %d bytes \n", num1, (int)sizeof(num1));
    printf("size of float = %zu bytes \n", sizeof(num2));
    printf("size of double = %zu bytes \n", sizeof(num3));
}