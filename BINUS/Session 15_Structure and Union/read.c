#include <stdio.h>
#include <string.h>

typedef struct mahasiswa
{
    char nim[9];
    char nama[30];
    float gpa;
} siswa;

int main(void)
{
    siswa kelas_a[5];
    FILE *mahasiswa = fopen("mahasiswa.txt", "r");

    if (mahasiswa == NULL)
    {
        printf("File tidak ditemukan\n");
        return 1;
    }

    char line[1024];
    int structIndex = 0;

    while (fgets(line, sizeof(line), mahasiswa) != NULL && structIndex < 5) // Read up to 5 students.
    {
        int field = 0;
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            switch (field)
            {
            case 0:
                strncpy(kelas_a[structIndex].nim, token, sizeof(kelas_a[structIndex].nim));
                kelas_a[structIndex].nim[sizeof(kelas_a[structIndex].nim) - 1] = '\0'; // memastikan ada null-termination
                break;
            case 1:
                strncpy(kelas_a[structIndex].nama, token, sizeof(kelas_a[structIndex].nama));
                kelas_a[structIndex].nama[sizeof(kelas_a[structIndex].nama) - 1] = '\0'; // memastikan ada null-termination
                break;
            case 2:
                sscanf(token, "%f", &kelas_a[structIndex].gpa);
                break;
            }
            token = strtok(NULL, " ");
            field++;
        }
        structIndex++; // Move to the next structure
    }

    fclose(mahasiswa);

    for (int i = 0; i < structIndex; i++)
    {
        printf("Mahasiswa %d:\n", i + 1);
        printf("NIM: %s\n", kelas_a[i].nim);
        printf("Nama: %s\n", kelas_a[i].nama);
        printf("GPA: %.2f\n\n", kelas_a[i].gpa);
    }

    return 0;
}
