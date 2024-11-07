// 3
#include <stdio.h>

int main()
{
    char list_ch[][2] = {
        '1', 'a',
        '2', 'b',
        '3', 'c',
        '4', 'd',
        '5', 'e',
        '6', 'f'};
    printf("%zu", sizeof(list_ch));

    return 0;
}