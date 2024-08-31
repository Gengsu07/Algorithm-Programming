#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("MAsukkan 2 angka\n");
    int num1 ,num2;
    scanf("%d", & num1);
    scanf("%d", & num2);

    printf("num1 = %d, num2 = %d, sum = %d \n", num1, num2, num1+num2);
    return 0;
}