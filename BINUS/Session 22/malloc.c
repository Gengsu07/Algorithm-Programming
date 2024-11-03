#include <stdio.h>
#include <stdlib.h>

void fun(int **a)
{
    *a = (int *)malloc(sizeof(int));
}

int main(void)
{
    int *p, num = 10;
    p = &num;
    fun(&p);
    *p = 6;
    printf("%d", *p);
    return (0);
}

/*
- pointer integer p tidak pernah dilakukan inisialisasisehingga pointer p akan mereferen ke memory address random dan bisa menyebabkan program tidak sesuai yang diinginkan.
- pointer p tidak dilakukan malloc karena pointer p tidak memiliki right value atau content yang merefer ke alamat variable lain maka saat di fungsi fun(p) maka argumen yang dipassing adalah leftvalue dari pointer p ke pointer int*a. Operasi malloc pada a maka hanya akan berlaku di variabel pointer a, bukan pointer p.
- dereference melakukan referen ke memori address yang tidak jelas karena pointer p tidak pernah diinisiasi

karena yg akan di alokasikan memori adalah pointer p maka yg dipassing fungsi fun adalah memori address &p dan di fungsi fun menggunakan double dereference karena ingin mengalokasikan memori untuk pointer p sehingga int **a adalah pointer to pointer
*/