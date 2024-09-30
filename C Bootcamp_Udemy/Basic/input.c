#include <stdio.h>

//getc -> read 1 char kemudian menampilkan ke screen atau stdout sesuai format specifier
int main() {
    int ch;
    printf("Enter a character: ");
    ch =  getc(stdin);
    // printf("Character entered: %c\n", ch);
    // printf("Character to Integer entered: %d\n", ch);
    return 0;
}