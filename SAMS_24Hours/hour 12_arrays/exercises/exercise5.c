// 3
#include <stdio.h>

int main()
{
    double list_data[6] = {
        1.12345,
        2.12345,
        3.12345,
        4.12345,
        5.12345};
    int sizeofarrays = sizeof(double) * 5;
    printf("%d\n", sizeofarrays);
    printf("%zu\n", sizeof(list_data));

    return 0;
}