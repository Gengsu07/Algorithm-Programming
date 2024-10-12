#include <stdio.h>
#include <string.h>
#include <ctype.h> // Fungsi rekursif untuk memeriksa apakah string adalah palindrome

int is_palindrome(const char *str, int awal, int akhir)
{

    // Abaikan spasi dan karakter non-alphanumeric
    while (awal < akhir && !isalnum(str[awal]))
        awal++;
    while (awal < akhir && !isalnum(str[akhir]))
        akhir--;
    {
        // Kasus dasar: jika indeks awal lebih besar atau sama dengan indeks akhir, maka string adalah palindrome
        if (awal >= akhir)
        {
            return 1; // 1 berarti palindrome
        }

        // Jika karakter di indeks awal dan akhir tidak cocok, maka string bukan palindrome
        if (str[awal] != str[akhir])
        {
            return 0; // 0 berarti bukan palindrome
        }

        // Bandingkan karakter setelah diubah menjadi huruf kecil
        if (tolower(str[awal]) != tolower(str[akhir]))
        {
            return 0; // 0 berarti bukan palindrome
        }

        // Panggilan rekursif untuk memeriksa karakter yang tersisa
        return is_palindrome(str, awal + 1, akhir - 1);
    }

    int main()
    {
        char input[100];
        int continue_checking = 1;

        while (continue_checking)
        {
            // Input dari user printf("Masukkan karakter: ");
            fgets(input, sizeof(input), stdin);

            // Hapus karakter newline
            input[strcspn(input, "")] = '\0';

            // Cek apakah string adalah palindrome  int panjang = strlen(input);
            if (is_palindrome(input, 0, panjang - 1))
            {
                printf("\"%s\" adalah palindrome.", input);
            }
            else
            {
                printf("\"%s\" bukan palindrome.", input);
            }

            // Tanya pengguna apakah ingin mengecek lagi  printf("Ingin Masukkan karakter lain? (1 = Ya, 0 = Tidak): ");
            scanf("%d", &continue_checking);
            getchar(); // Membuang newline yang tersisa dari input
        }

        printf("Program selesai.");
        return 0;
    }