#include <stdio.h>

enum
{
    SUCCESS,
    FAILED
};
void OneLineAtTime(FILE *fin, FILE *fout);
int main(void)
{
    FILE *fin, *fout;
    char filein[] = "test.txt";
    char fileout[] = "out.txt";
    int status = SUCCESS;

    if ((fin = fopen(filein, "r")) == NULL)
    {
        printf("Error! Could not open file %s\n", filein);
        status = FAILED; // Program exits if file opening fails.
    }
    else if ((fout = fopen(fileout, "w")) == NULL)
    {
        printf("Error! Could not open file %s\n", fileout);
        status = FAILED; // Program exits if file
    }
    else
    {
        printf("File %s opened successfully\n", filein);
        OneLineAtTime(fin, fout);

        fclose(fin);
        fclose(fout);
    }

    return status;
}

void OneLineAtTime(FILE *fin, FILE *fout)
{
    char charbuffer[30];
    int counter = 1;
    while (fgets(charbuffer, sizeof(charbuffer), fin) != NULL)
    {
        fputs(charbuffer, fout);
        printf("%d| %s\n", counter, charbuffer);
        counter++;
    };

    printf("Ready to close the file\n");
}
