#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Gender
{
    Laki,
    Perempuan,
};

// buat Struct Dob
struct Dob
{
    int day;
    int month;
    int year;
};

// buat Struct Student dan typedef ke Student biar singkat
typedef struct Student
{
    char nim[25];
    char name[50];
    int age;
    enum Gender gender;
    struct Dob dob;
} Student;

int main(void)
{
    int const countrecords = 100;
    Student alpro[countrecords];
    FILE *fin = fopen("input.txt", "r");

    if (fin == NULL)
    {
        printf("File tidak ditemukan\n");
        return 1;
    }

    char line[countrecords];
    int StructIndex = 0;
    // cek jika line tidak kosong dan tidak overflow countrecords
    while (fgets(line, sizeof(line), fin) != NULL && StructIndex < countrecords)
    {
        int field = 0;
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            switch (field)
            {
            case 0:
                strncpy(alpro[StructIndex].nim, token, sizeof(alpro[StructIndex].nim));
                alpro[StructIndex].nim[sizeof(alpro[StructIndex].nim) - 1] = '\0'; // memastikan ada null-termination
                break;
            case 1:
                strncpy(alpro[StructIndex].name, token, sizeof(alpro[StructIndex].name));
                alpro[StructIndex].name[sizeof(alpro[StructIndex].name) - 1] = '\0';
                // memastikan ada null-termination
                break;
            case 2:
                alpro[StructIndex].age = atoi(token);
                break;
            case 3:
                if (strcmp(token, "Laki") == 0)
                    alpro[StructIndex].gender = Laki;
                else
                    alpro[StructIndex].gender = Perempuan;
                break;
            case 4:
                sscanf(token, "%2d%2d%4d", &alpro[StructIndex].dob.day, &alpro[StructIndex].dob.month, &alpro[StructIndex].dob.year);
                break;
            }
            token = strtok(NULL, " ");
            field++;
        }
        StructIndex++; // Move to the next structure
    }

    fclose(fin);

    printf("\nRow   NIM        Nama    Age  Gender         DoB\n");
    printf("___|__________|__________|__|_______________|___________\n");
    for (int i = 0; i < StructIndex; i++)
    {

        printf("%3d|", i + 1);
        printf("%10s|", alpro[i].nim);
        printf("%-10s|", alpro[i].name);
        printf("%2d|", alpro[i].age);
        printf("%-15s|", alpro[i].gender == 0 ? "Laki" : "Perempuan");
        printf("%2d/ %2d/ %4d \n", alpro[i].dob.day, alpro[i].dob.month, alpro[i].dob.year);
    }

    return 0;
}
// mcoba pakai sscanf lebih gampang