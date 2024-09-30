// 1
#include <stdio.h>

int main()
{
    char array_ch[5];
    for (int i = 0; i < 5; i++)
    {
        array_ch[i] = 'a' + i;
        printf("%c ", array_ch[i]);
    }
    return 0;
}