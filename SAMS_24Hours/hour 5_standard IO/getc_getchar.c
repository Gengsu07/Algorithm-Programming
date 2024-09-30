#include <stdio.h>

int main()
{
    char ch, chara;
    printf("Masukkan 2 karakter: ");
    ch = getc(stdin);
    chara = getchar();
    printf("karakter: %c\n", ch);
    printf("karakter in int: %d\n", ch);
    printf("karakter: %c\n", chara);
    printf("karakter in int: %d\n", chara);

    return 0;
}