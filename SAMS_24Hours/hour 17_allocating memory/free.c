/* 17L62.c: Using the free() function */
#include <stdio.h>
#include <stdlib.h>

/* function declarations */
void DataMultiply(int max, int *ptr);
void TablePrint(int max, int *ptr);

/* main() function */
int main()
{
    int *ptr_int, max;
    int termination;
    char key = 'c';

    max = 0;
    termination = 0;
    while (key != 'x')
    {
        printf("Enter a single digit number: \n");
        scanf("%d", &max);

        ptr_int = (int *)malloc(max * max * sizeof(int)); /* call malloc() */
        if (ptr_int != NULL)
        {
            DataMultiply(max, ptr_int);
            TablePrint(max, ptr_int);
            free(ptr_int);
        }
        else
        {
            printf("malloc() function failed. \n");
            termination = 1;
            key = 'x'; /* Stop while loop */
        }

        printf("\n\nPress x key to quit; other key to continue.\n");
        scanf("%s", &key);
    }
    printf("\ngye!\n");
    return termination;
}

/* function definition */
void DataMultiply(int max, int *ptr)
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            *(ptr + i * max + j) = (i + 1) * (j + 1);
        }
    }
}

/* function definition */
void TablePrint(int max, int *ptr)
{
    int i, j;

    printf("The multiplication table of %d is:\n", max);

    for (i = 0; i < max; i++)
    {
        printf("%3d", i + 1);
    }
    printf("\n");

    for (int k = 0; k < max; k++)
    {
        printf("----");
    }
    printf("\n");

    for (i = 0; i < max; i++)
    {
        printf("%3d|", i + 1);
        for (j = 0; j < max; j++)
        {
            printf("%3d", *(ptr + i * max + j));
        }
        printf("\n");
    }
}
