#include <stdio.h>

enum
{
    SUCCESS,
    FAILED,
    MAX_LEN = 60
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

    char charbuffer[MAX_LEN + 1];
    int counter = 1;
    size_t numread;
    while (!feof(fin))
    {
        numread = fread(charbuffer, sizeof(charbuffer), MAX_LEN, fin);

        printf("%d| %s\n", counter, charbuffer);
        fwrite(charbuffer, sizeof(charbuffer), MAX_LEN, fout);
        counter++;
    };
    if (feof(fin))
        charbuffer[numread * sizeof(charbuffer)] = '\0'; // append null character at the end of the string
    fflush(fout);                                        // Ensure all data is written to the file before closing it.

    printf("Ready to close the file\n");
}
