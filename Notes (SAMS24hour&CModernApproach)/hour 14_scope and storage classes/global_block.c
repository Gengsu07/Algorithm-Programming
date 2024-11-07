#include <stdio.h>

// Program Scope / Global Variables
int a = 1234;
double b = 1.234567;

void function1()
{
    printf("From function_1 :\n a = % d, b = % f\n", a, b);
}
int main()
{
    // block scope
    int a = 4321;
    function1();

    printf("From main function a=%d, b=%f\n", a, b);

    // nested block scope
    {
        double b = 7.654321; // block scope
        function1();
        printf("From Nested block scope:a=%d, b=%f\n", a, b);
    }

    return 0;
}