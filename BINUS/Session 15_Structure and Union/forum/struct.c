/*
Buat data structure student yang terdiri atas nim, name, age, gender.
Record student dapat diinput dari program.
Tambahkan dob (date of birth) pada struct student tersebut.
*/

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

// fungsi menghilangkan karakter newline pada input string
void removeNewline(char *input)
{
    input[strcspn(input, "\n")] = '\0';
}

// function untuk menampilkan data
void DisplayStudent(Student *student)
{
    printf("\n===== Informasi Mahasiswa =====\n");
    printf("NIM: %s\n", student->nim);
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Gender: %s\n", student->gender == Laki ? "Laki-laki" : "Perempuan");
    printf("Tanggal Lahir: %02d/%02d/%d\n", student->dob.day, student->dob.month, student->dob.year);
}
int main(void)
{
    Student newstudent;   // buat struct student
    char temp_gender[30]; // untuk menampung input string gender

    // Inisialisasi data
    printf("===== Masukkan data Mahasiswa ===== :\n");
    printf("NIM (10 digit): ");
    fgets(newstudent.nim, sizeof(newstudent.nim), stdin);
    removeNewline(newstudent.nim);

    printf("Nama: ");
    fgets(newstudent.name, sizeof(newstudent.name), stdin);
    removeNewline(newstudent.name);

    printf("Age: ");
    scanf("%d", &newstudent.age);
    getchar(); // consume newline character

    printf("Gender (Laki/Perempuan): ");
    fgets(temp_gender, sizeof(temp_gender), stdin);
    removeNewline(temp_gender);
    // lakukan perbandingan input string, jika "Laki" maka 0 , karena enum berisi integer
    newstudent.gender = strcmp(temp_gender, "Laki") == 0 ? Laki : Perempuan;

    printf("Tanggal Lahir (ddmmyyyy): ");
    // lakukan format input agar sesuai saat dimasukkan ke struct
    scanf("%2d%2d%4d", &newstudent.dob.day, &newstudent.dob.month, &newstudent.dob.year);

    DisplayStudent(&newstudent); // call fungsi tampilkan data
    return 0;
}
