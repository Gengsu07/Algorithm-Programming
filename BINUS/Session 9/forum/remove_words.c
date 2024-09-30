/*
Removing Particular Word
Buat program yang menerima input kalimat serta kata. Gunakan fungsi dari string.h seperti strcmp dan strcpy untuk membuang kata tertentu dalam suatu kalimat. Gunakan fungsi strok untuk menghitung jumlah kata pada awal kalimat dan jumlah kata setelah kata tertentu dibuang dalam kalimat.
*/

#include <stdio.h>
#include <string.h>

void remove_word(char *words, const char *toremove, char *result, int *count, int *count_aftr)
{
    char *token;
    token = strtok(words, " "); // split kalimat sesuai kata yg ingin dihilangkan

    while (token != NULL) // cek jika token tidak null

    {
        (*count)++; // increment jmlh kata sebelum dihilangkan
        // cek token selanjutnya apakah null yg berarti terakhir
        char *next_token = strtok(NULL, " ");
        // bandingkan token dengan kata yg ingin dihilangkan. jika tidak sama dengan 0 alias beda
        if (strcmp(token, toremove) != 0)
        {
            // concat ke array result
            strcat(result, token);
            (*count_aftr)++;
            if (next_token != NULL)
                strcat(result, " ");
        }
        token = next_token;
    }
}

int main()
{
    // deklarasi untuk menampung kalimat, kata, hasil, dan count dari kata sebelum dan sesudah
    char kalimat[300], kata[50], result[300];
    int charsum_bfr = 0, charsum_aftr = 0;
    result[0] = '\0'; // inisialisasi hasil sementara

    // menerima input kalimat dan kata
    printf("Masukkan kalimat anda: \n");
    fgets(kalimat, sizeof(kalimat), stdin);
    printf("Masukkan kata yg ingin dihilangkan: ");
    fgets(kata, sizeof(kata), stdin);

    // menghilangkan newline dari kata
    kata[strcspn(kata, "\n")] = '\0';

    // melakukan proses penghilangan kata
    remove_word(kalimat, kata, result, &charsum_bfr, &charsum_aftr);

    // menampilkan hasil
    printf("Jumlah kata sebelum %s dihilangkan: %d\n", kata, charsum_bfr);
    printf("Jumlah kata setelah %s dihilangkan: %d\n", kata, charsum_aftr);
    printf("Setelah %s dihilangkan: \n%s", kata, result);

    return 0;
}