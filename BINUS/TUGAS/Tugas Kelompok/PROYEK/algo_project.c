#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAILED
};

typedef struct
{
    char kode_buku[11];
    char nama_buku[255];
    char jns_buku[70];
    double harga;
} Book;

void clrscr(void);
void addBook(void);
void displayBook(void);
void searchBook(void);
void deleteBook(void);
void setMsgNotif(const char *msg);
size_t countRecords(FILE *db_session);
int status = SUCCESS;

Book Catalog;
FILE *db_session;
char databuku[] = "databuku.txt";
char datatransaksi[] = "datatransaksi.txt";
char *msg_notif = NULL;
int main(void)
{
    int navmenu = 0;

    while (navmenu != 6)
    {

        clrscr();
        printf("\n\n\t\t\t========== BOOK MONITORING SYSTEM =========");
        if (msg_notif != NULL && strcmp(msg_notif, "") != 0)
        {
            printf("\n\n\t\t\t status : %s", msg_notif);
            free(msg_notif);
        }
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
            clrscr();
            addBook();
            setMsgNotif("Data Berhasil Ditambahkan...");
            break;
        case 2:
            clrscr();
            displayBook();
            break;
        case 3:
            clrscr();
            searchBook();
            break;
        case 4:
            clrscr();
            deleteBook();
            setMsgNotif("Data Berhasil Dihapus...");
            break;
        default:
            setMsgNotif(" Pilihan Menu Tidak Ada...\n");
        }
    }
    return status;
}
void addBook(void)
{
    db_session = fopen(databuku, "a+");
    if (db_session == NULL)
    {
        printf("Gagal Membuka File %s\n", databuku);
        status = FAILED;
    }
    printf("\n\t\t\t========== Tambah Data Buku ==========\n");
    printf("\nMasukkan Kode Buku : ");
    fgets(Catalog.kode_buku, 11, stdin);
    Catalog.kode_buku[strcspn(Catalog.kode_buku, "\n")] = '\0';
    printf("\nMasukkan Nama Buku : ");
    fgets()
}

void displayBook(void)
{
}
void searchBook(void)
{
}
void deleteBook(void)
{
}
size_t countRecords(FILE *dbcount)
{
}
void setMsgNotif(const char *msg)
{
    msg_notif = calloc(strlen(msg) + 1, 1);
    strcpy(msg_notif, msg);
}
void clrscr(void)
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux
#endif
}
