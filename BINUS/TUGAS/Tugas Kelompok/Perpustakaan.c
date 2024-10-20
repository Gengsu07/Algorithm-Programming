#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

// Definisi union untuk menyimpan informasi media
union Media
{
    char author[100]; // Nama penulis untuk buku
    char editor[100]; // Nama editor untuk majalah
};

// Definisi struct untuk item perpustakaan
struct LibraryItem
{
    char title[100];     // Judul buku atau majalah
    int publicationYear; // Tahun terbit
    union Media media;   // Union untuk menyimpan informasi buku atau majalah
};
void handle_sigint(void);
{
    printf("\nTerima kasih, program END.\n");
    exit(0);
}
int main(void)
{
    struct LibraryItem item;
    char mediaType;                // 'B' untuk Buku, 'M' untuk Majalah
    signal(SIGINT, handle_sigint); // Menghandle SIGINT

    while (1)
    {
        // Input data
        printf("----- Sistem Input Perpustakaan (ctrl+c untuk exit) -----\n");
        printf("Masukkan Judul: ");
        fgets(item.title, sizeof(item.title), stdin);
        item.title[strcspn(item.title, "\n")] = 0; // Menghapus newline

        printf("Masukkan Tahun Terbit: ");
        scanf("%d", &item.publicationYear);
        getchar(); // Mengonsumsi newline

        printf("Masukkan Jenis Media (B/M): ");
        scanf("%c", &mediaType);
        getchar(); // Mengonsumsi newline

        // Input informasi berdasarkan jenis media
        if (mediaType == 'B')
        {
            printf("Masukkan Nama Penulis: ");
            fgets(item.media.author, sizeof(item.media.author), stdin);
            item.media.author[strcspn(item.media.author, "\n")] = 0; // Menghapus newline
        }
        else if (mediaType == 'M')
        {
            printf("Masukkan Nama Editor: ");
            fgets(item.media.editor, sizeof(item.media.editor), stdin);
            item.media.editor[strcspn(item.media.editor, "\n")] = 0; // Menghapus newline
        }

        // Tampilkan informasi
        printf("\nInformasi Item:\n");
        printf("Judul: %s\n", item.title);
        printf("Tahun Terbit: %d\n", item.publicationYear);
        if (mediaType == 'B')
        {
            printf("Jenis Media: Buku\n");
            printf("Penulis: %s\n", item.media.author);
        }
        else if (mediaType == 'M')
        {
            printf("Jenis Media: Majalah\n");
            printf("Editor: %s\n", item.media.editor);
        }
    }
    return 0;
}
