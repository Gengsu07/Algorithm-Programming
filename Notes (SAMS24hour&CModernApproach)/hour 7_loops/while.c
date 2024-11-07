#include <stdio.h>

int main()
{
    int counter = 10;
    printf("while dibawah 10\n");
    while (counter < 10)
    {
        printf("%d\n", counter);
        counter++;
    }

    printf("Do While dibawah:\n");
    do
    {
        printf("%d\n", counter);
        counter++;
    } while (counter < 10);
    printf("this is the end\n");
    return 0;
}