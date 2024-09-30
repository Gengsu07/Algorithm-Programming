#include <stdio.h>
int main()
{
    int idx_rows, idx_cols, rows = 9, cols = 9;

    for (idx_rows = 0; idx_rows < rows; idx_rows++)
    {
        if ((idx_rows == 0) || (idx_rows == rows - 1))
        {
            for (idx_cols = 0; idx_cols < cols; idx_cols++)
                printf("*");
        }
        else
            for (idx_cols = 0; idx_cols < cols; idx_cols++)
                if ((idx_cols == 0) || (idx_cols == cols - 1))
                    printf("*");
                else
                    printf(" ");
        printf("\n");
    }
    return 0;
}
/*
Dalam program ini saya menggunakan for loop dan if untuk melakukan pengecekan kondisi dengan logika berikut
Jika baris pertama atau terakhir maka tampilkan * sebanyak 9 kali
Jika bukan baris pertama atau terakhir maka
jika kolom pertama dan terakhir tampilkan *
jika bukan maka tampilkan spasi saja " "
*/