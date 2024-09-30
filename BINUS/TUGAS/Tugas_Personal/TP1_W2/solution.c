#include <stdio.h>
int main() {
    int  a, b;
    float result;

    printf("Enter two integers: \n");

    // menambahkan format specifier sehingga menerima input 2 integer
    scanf("%d%d", &a, &b); 

    //melakukan explicit casting sehingga hasil menjadi float
    result = (float)a/b; 

    printf("The division of %d and %d is %f\n", a, b, result);

    return 0;
}
