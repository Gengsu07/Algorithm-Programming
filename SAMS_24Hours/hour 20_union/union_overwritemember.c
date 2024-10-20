#include <stdio.h>

union u
{
    char ch;
    int x;
    int y;
} a_union;
int main(void)
{
    a_union.ch = 'H';
    printf("Character a_union.ch: %c\n", a_union.ch); // H
    a_union.x = 10;
    printf("Character a_union.ch: %d\n", a_union.x);  // 10
    printf("Character a_union.ch: %c\n", a_union.ch); //
    printf("Character a_union.ch: %d\n", a_union.y);  //
}

/*
printf("Character a_union.ch: %c\n", a_union.ch); attempts to print a_union.ch again. However, since the memory location has been overwritten by the integer 10, the output is not meaningful as a character. The integer 10 in memory does not correspond to a printable character, which is why you see a blank or unexpected character.
*/
