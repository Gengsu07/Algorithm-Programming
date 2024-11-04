#include <stdio.h>

int main(void)
{
    int navmenu = 0;

    while (navmenu != 6)
    {
        printf("\n\n\t\t\t========== BOOK MONITORING SYSTEM =========");

        printf("\n\n\t\t\t--------- Pilih Menu Dibawah Ini --------");
        printf("\n\t\t\t1. Tambah Data Buku");
        printf("\n\t\t\t2. Tampilkan History Penjualan");
        printf("\n\t\t\t3. Tampilkan Data Buku");
        printf("\n\t\t\t4. Delete History Penjualan");
        printf("\n\t\t\t5. Delete Buku");
        printf("\n\t\t\t6. Keluar\n");
        printf("\n\t\t\t-------------------------------------------------------");

        printf("\n\t\t\t Masukkan Pilihan Menu : ");
        scanf("%d", &navmenu);
        getchar();

        switch (navmenu)
        {
        case 1:

            printf("1");

            break;
        case 2:
            // clrscr();
            printf("asdfas");
            break;
        case 3:

            // searchBook();
            break;
        case 4:

            // deleteBook();
            break;

        default:
            printf("de");
            break;
        }
    }
    return 0;
}
