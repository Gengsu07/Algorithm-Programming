#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    // Jika hanya ada 1 cakram, pindahkan langsung
    if (n == 1)
    {
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", from_rod, to_rod);
        return;
    }

    // Pindahkan n-1 cakram dari tiang asal ke tiang bantu (tiang tujuan sebagai perantara)
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Pindahkan cakram terbesar (cakram ke-n) dari tiang asal ke tiang tujuan
    printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, from_rod, to_rod);

    // Pindahkan n-1 cakram dari tiang bantu ke tiang tujuan (tiang asal sebagai perantara)
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(void)
{
    int n = 4;
    printf("Langkah-langkah untuk memindahkan %d cakram:\n", n);

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
