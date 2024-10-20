#include <stdio.h>
#include <string.h>

// buat enum Gender
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
int const records = 3;
void DisplayStudent(Student *student, int const records);
int main(void)
{
    Student students[records];

    // Inisialisasi data
    for (int i = 0; i < records; i++)
    {
        sprintf(students[i].nim, "%d", i + 1);
        sprintf(students[i].name, "Siswa %d", i + 1);
        students[i].age = i + 25;
        students[i].gender = (i % 2 == 0) ? Laki : Perempuan;
        students[i].dob.day = i + 1;
        students[i].dob.month = i + 1;
        students[i].dob.year = 1999 + i;
    }

    // Tampilkan data
    DisplayStudent(students, records);
    return 0;
}
void DisplayStudent(Student *student, int rowrecord)
{
    for (int i = 0; i < rowrecord; i++)
    {
        printf("\n===== Informasi Mahasiswa =====\n");
        printf("NIM: %s\n", (student + i)->nim);
        printf("Name: %s\n", (student + i)->name);
        printf("Age: %d\n", (student + i)->age);
        printf("Gender: %s\n", (student + i)->gender == Laki ? "Laki-laki" : "Perempuan");
        printf("Tanggal Lahir: %02d/%02d/%d\n", (student + i)->dob.day, (student + i)->dob.month, (student + i)->dob.year);
    }
}

/*
printf("\n===== Informasi Mahasiswa =====\n");
        printf("NIM: %s\n", (*(students + i)).nim); // Dereference and use dot operator
        printf("Name: %s\n", (*(students + i)).name);
        printf("Age: %d\n", (*(students + i)).age);
        printf("Gender: %s\n", (*(students + i)).gender == Laki ? "Laki-laki" : "Perempuan");
        printf("Tanggal Lahir: %02d/%02d/%d\n", (*(students + i)).dob.day, (*(students + i)).dob.month, (*(students + i)).dob.year);
    }
}
*/