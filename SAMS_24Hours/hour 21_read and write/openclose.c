#include <stdio.h>

enum
{
    SUCCESS,
    FAILED
};
int main(void)
{
    FILE *fptr;
    char filename[] = "test.txt";
    int status = SUCCESS;

    if ((fptr = fopen(filename, "r")) != NULL)
    {
        printf("File opened successfully\n");
        printf("Content dalam fptr: 0x%p\n", (void *)fptr);
        printf("Ready to close the file\n");
        fclose(fptr);
    }
    else
    {
        printf("Error! Could not open file %s\n", filename);
        status = FAILED; // Program exits if file opening fails.
    }

    return status;
}
