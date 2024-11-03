/*
Write a program to receive a string entered by the user, and then save the string into a file with the name also given by the user.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char namafile[256];
    char input[MAX_LENGTH];

    printf("Masukan Karakter yang akan di input: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Menghapus newline karena fgets menyimpan newline di akhir string
    printf("Masukan Nama file (menggunakan extension .txt): ");
    scanf("%s", namafile);
    getchar();

    char fullname[256];
    snprintf(fullname, sizeof(fullname), "%s.txt", namafile);

    FILE *file = fopen(fullname, "w");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1; // Exit with error code
    }
    else
    {
        fprintf(file, "%s", input);
    }

    fclose(file);

    printf("String saved to '%s' successfully.\n", namafile);

    return 0;
}
