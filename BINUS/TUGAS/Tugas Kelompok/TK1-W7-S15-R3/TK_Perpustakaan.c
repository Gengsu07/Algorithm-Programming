#include <stdio.h>
#include <string.h>

// Definisi union untuk menyimpan informasi media
union Media {
    struct {
        char author[100]; // Nama penulis untuk buku
    } book;
    struct {
        char editor[100]; // Nama editor untuk majalah
    } magazine;
};

// Definisi struct untuk item perpustakaan
struct LibraryItem {
    char title[100];          // Judul buku atau majalah
    int publicationYear;      // Tahun terbit
    char mediaType;           // 'B' untuk Buku, 'M' untuk Majalah
    union Media media;        // Union untuk menyimpan informasi buku atau majalah
};

int main() {
    struct LibraryItem item;

    // Input data
    printf("Masukkan Judul: ");
    fgets(item.title, sizeof(item.title), stdin);
    item.title[strcspn(item.title, "\n")] = 0; // Menghapus newline

    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &item.publicationYear);
    getchar(); // Mengonsumsi newline

    printf("Masukkan Jenis Media (B/M): ");
    scanf("%c", &item.mediaType);
    getchar(); // Mengonsumsi newline

    // Input informasi berdasarkan jenis media
    if (item.mediaType == 'B') {
        printf("Masukkan Nama Penulis: ");
        fgets(item.media.book.author, sizeof(item.media.book.author), stdin);
        item.media.book.author[strcspn(item.media.book.author, "\n")] = 0; // Menghapus newline
    } else if (item.mediaType == 'M') {
        printf("Masukkan Nama Editor: ");
        fgets(item.media.magazine.editor, sizeof(item.media.magazine.editor), stdin);
        item.media.magazine.editor[strcspn(item.media.magazine.editor, "\n")] = 0; // Menghapus newline
    }

    // Tampilkan informasi
    printf("\nInformasi Item:\n");
    printf("Judul: %s\n", item.title);
    printf("Tahun Terbit: %d\n", item.publicationYear);
    if (item.mediaType == 'B') {
        printf("Jenis Media: Buku\n");
        printf("Penulis: %s\n", item.media.book.author);
    } else if (item.mediaType == 'M') {
        printf("Jenis Media: Majalah\n");
        printf("Editor: %s\n", item.media.magazine.editor);
    }

    return 0;
}
