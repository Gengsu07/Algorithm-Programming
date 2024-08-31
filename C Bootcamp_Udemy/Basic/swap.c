// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int num1=4, num2=7, temp;
    printf("BEFORE SWAP:\n");
    printf("Number 1:%d\n", num1);
    printf("Number 2:%d\n",num2);

    printf("AFTER SWAP:\n");
    temp = num1;
    num1 = num2;
    num2=temp;
    printf("Number 1:%d\n",num1);
    printf("Number 2:%d\n",num2);
    return 0;
} 