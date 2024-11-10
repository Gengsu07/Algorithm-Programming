#include <stdio.h>

int main(void)
{
    int num1 = 12;
    // float f = 3.141593;
    float f = 3.14;

    printf("%6d %-6d \n", num1, num1);
    printf("%06d %-6.3d \n", num1, num1); //.precision tidak berguna buat integer

    printf("%6.2f %-6f \n", f, f);
    printf("%06.2f %-6.2f \n", f, f);
    return 0;
}
