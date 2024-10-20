#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    SUCCESS,
    FAILED
};

typedef struct
{
    char nomor_registrasi[11];
    char nama[70];
    int umur;
} Students;

void clrscr(void);
void addStudent(void);
void displayStudent(void);
void searchStudent(void);
void deleteStudent(void);
void setMsgNotif(const char *msg);
size_t countRecords(FILE *db_session);
int status = SUCCESS;

Students binus;
FILE *db_session;
char filename[] = "db.csv";
char *msg_notif = NULL;
int main(void)
{
    int navmenu = 0;

    while (navmenu != 5)
    {

        clrscr();
        printf("\n\n\t\t\t========== STUDENT MANAGEMENT PROGRAM =========");
        if (msg_notif != NULL && strcmp(msg_notif, "") != 0)
        {
            printf("\n\n\t\t\t status : %s", msg_notif);
            free(msg_notif);
        }
        printf("\n\n\t\t\t--------- Pilih Menu Dibawah Ini --------");
        printf("\n\t\t\t1. Tambah Data Mahasiswa");
        printf("\n\t\t\t2. Tampilkan Data Mahasiswa");
        printf("\n\t\t\t3. Cari Data Mahasiswa");
        printf("\n\t\t\t4. Delete Data Mahasiswa");
        printf("\n\t\t\t5. Keluar\n");
        printf("\n\t\t\t-------------------------------------------------------");

        printf("\n\t\t\t Masukkan Pilihan Menu : ");
        scanf("%d", &navmenu);
        getchar();

        switch (navmenu)
        {
        case 1:
            clrscr();
            addStudent();
            setMsgNotif("Data Berhasil Ditambahkan...");
            break;
        case 2:
            clrscr();
            displayStudent();
            break;
        case 3:
            clrscr();
            searchStudent();
            break;
        case 4:
            clrscr();
            deleteStudent();
            setMsgNotif("Data Berhasil Dihapus...");
            break;
        default:
            setMsgNotif(" Pilihan Menu Tidak Ada...\n");
        }
    }
    return status;
}
void addStudent(void)
{
    Students *newStudent = NULL;
    char inputlagi;
    size_t counter = 0;
    db_session = fopen(filename, "a");

    if (db_session != NULL)
    {
        do
        {
            newStudent = realloc(newStudent, sizeof(Students) * (counter + 1));
            if (newStudent == NULL)
            {
                printf("\n\t\t\t Gagal mengalokasikan memori...\n");
                status = FAILED;
            }
            clrscr();
            printf("\n\t\t\t========== Tambah Data Mahasiswa =========\n");
            printf("\n\t\t\t Nomor Registrasi (10digit) : ");
            scanf("%10s", newStudent[counter].nomor_registrasi);
            getchar();
            // fgets(newStudent[counter].nomor_registrasi, sizeof(newStudent[counter].nomor_registrasi), buffernomorregistrasi);
            // newStudent[counter].nomor_registrasi[10] = 0;

            printf("\n\t\t\t Nama Siswa : ");
            fgets(newStudent[counter].nama, sizeof(newStudent[counter].nama), stdin);
            newStudent[counter].nama[strcspn(newStudent[counter].nama, "\n")] = 0;

            printf("\n\t\t\t Umur Siswa (Tahun) : ");
            scanf("%2d", &newStudent[counter].umur);

            printf("\n\t\t\t Ingin Menambahkan Data Lagi? (y/n) : ");
            scanf(" %c", &inputlagi);
            getchar();
            counter++;
        } while (inputlagi == 'y' || inputlagi == 'Y');
        for (size_t i = 0; i < counter; i++)
        {
            fprintf(db_session, "%s|%s|%d\n", newStudent[i].nomor_registrasi, newStudent[i].nama, newStudent[i].umur);
        }
        free(newStudent);
        fclose(db_session);
    }
    else
    {
        printf("\n\t\t\t Koneksi ke Database Error...\n");
        status = FAILED;
    }
}

void displayStudent(void)
{
    Students *savedStudent = NULL;

    size_t counter = 0;
    char bufferStudents[256];

    db_session = fopen(filename, "r");

    if (db_session != NULL)
    {
        size_t records = countRecords(db_session);
        savedStudent = calloc(records, sizeof(Students));
        if (savedStudent == NULL)
        {
            printf("Memory allocation failed.\n");
            status = FAILED;
        }
        rewind(db_session);
        printf("\n\t\t\t --------- Data Mahasiswa --------- \n");
        while (fgets(bufferStudents, sizeof(bufferStudents), db_session) != NULL)
        {
            sscanf(bufferStudents, "%10[^|]|%69[^|]|%d", savedStudent[counter].nomor_registrasi, savedStudent[counter].nama, &savedStudent[counter].umur);
            counter++;
        }
        printf("\n\t\t\t Total Records : %zu\n", counter);
        for (size_t i = 0; i < counter; i++)
        {
            printf("\n\t\t\t Nomor Registrasi : %s", savedStudent[i].nomor_registrasi);
            printf("\n\t\t\t Nama Siswa       : %s", savedStudent[i].nama);
            printf("\n\t\t\t Umur Siswa       : %d", savedStudent[i].umur);
            printf("\n\t\t\t-----------------------------------\n");
        }
        free(savedStudent);
        printf("\n\t\t\t Tekan Enter untuk kembali ke menu utama... \n");
        getchar();
        fclose(db_session);
    }
    else
    {
        printf("\n\t\t\t Koneksi ke Database Error...\n");
        status = FAILED;
    }
}
void searchStudent(void)
{
    char input_nomor_registrasi[12];
    char buffer[256];
    size_t counter = 0;
    Students *savedStudent = NULL;

    db_session = fopen(filename, "r");
    if (db_session != NULL)
    {

        printf("\n\t\t\t ---------- Cari Data Mahasiswa ----------\n");
        printf("\n\t\t\t Nomor Registrasi Siswa (10digit): ");
        fgets(input_nomor_registrasi, sizeof(input_nomor_registrasi), stdin);
        input_nomor_registrasi[strcspn(input_nomor_registrasi, "\n")] = 0;

        size_t records = countRecords(db_session);
        savedStudent = calloc(records, sizeof(Students));
        if (savedStudent == NULL)
        {
            printf("Alokasi memori gagal.\n");
            status = FAILED;
        }
        rewind(db_session);
        while (fgets(buffer, sizeof(buffer), db_session) != NULL)
        {
            sscanf(buffer, "%10[^|]|%69[^|]|%d", savedStudent[counter].nomor_registrasi, savedStudent[counter].nama, &savedStudent[counter].umur);
            counter++;
        }
        for (size_t i = 0; i < records; i++)
        {

            if (strncmp(input_nomor_registrasi, savedStudent[i].nomor_registrasi, strlen(savedStudent[i].nomor_registrasi) + 1) == 0)
            {
                printf("\n\t\t\t Nomor Registrasi : %s", savedStudent[i].nomor_registrasi);
                printf("\n\t\t\t Nama Siswa       : %s", savedStudent[i].nama);
                printf("\n\t\t\t Umur Siswa       : %d", savedStudent[i].umur);
                printf("\n\t\t\t-----------------------------------\n");
            }
        }
        free(savedStudent);
        fclose(db_session);
        printf("\n\t\t\t Tekan Enter untuk kembali ke menu utama... \n");
        getchar();
    }
    else
    {
        printf("\n\t\t\t Koneksi ke Database Error...\n");
        status = FAILED;
    }
}
void deleteStudent(void)
{
    char input_nomor_registrasi[11];
    char buffer[256];
    size_t counter = 0, found = 0;
    Students *savedStudent = NULL;
    Students *notDeletedStudent = NULL;

    db_session = fopen(filename, "r+");
    if (db_session != NULL)
    {

        printf("\n\t\t\t ---------- Hapus Data Mahasiswa ----------\n");
        printf("\n\t\t\t Nomor Registrasi Siswa (10digit): ");
        // fgets(input_nomor_registrasi, sizeof(input_nomor_registrasi), stdin);
        scanf("%10s", input_nomor_registrasi);
        getchar();
        // input_nomor_registrasi[strcspn(input_nomor_registrasi, "\n")] = 0;

        size_t records = countRecords(db_session);
        savedStudent = calloc(records, sizeof(Students));
        notDeletedStudent = calloc(records, sizeof(Students));
        if (savedStudent == NULL)
        {
            printf("Alokasi memori gagal.\n");
            status = FAILED;
        }
        rewind(db_session);
        while (fgets(buffer, sizeof(buffer), db_session) != NULL)
        {
            sscanf(buffer, "%10[^|]|%69[^|]|%d", savedStudent[counter].nomor_registrasi, savedStudent[counter].nama, &savedStudent[counter].umur);
            counter++;
        }
        fclose(db_session); // Close after reading
        size_t counternotdeleted = 0;
        for (size_t i = 0; i < records; i++)
        {

            if (strncmp(input_nomor_registrasi, savedStudent[i].nomor_registrasi, strlen(savedStudent[i].nomor_registrasi) + 1) != 0)
            {
                strncpy(notDeletedStudent[counternotdeleted].nomor_registrasi, savedStudent[i].nomor_registrasi, strlen(savedStudent[i].nomor_registrasi) + 1);
                strncpy(notDeletedStudent[counternotdeleted].nama, savedStudent[i].nama, strlen(savedStudent[i].nama) + 1);
                notDeletedStudent[counternotdeleted].umur = savedStudent[i].umur;
                counternotdeleted++;
            }
            else
            {
                printf("\n\t\t\t Nomor Registrasi : %s", savedStudent[i].nomor_registrasi);
                printf("\n\t\t\t Nama Siswa       : %s", savedStudent[i].nama);
                printf("\n\t\t\t Umur Siswa       : %d", savedStudent[i].umur);
                printf("\n\t\t\t-----------------------------------\n");
                ++found;
            }
        }

        if (found == 0)
            printf("\n\t\t\t Data tidak ditemukan...\n");
        else
        {
            fclose(db_session);
            db_session = fopen(filename, "w+");
            if (db_session != NULL)
            {

                // Write remaining (non-deleted) students back to file
                for (size_t i = 0; i < counternotdeleted; i++)
                {
                    fprintf(db_session, "%s|%s|%d\n",
                            notDeletedStudent[i].nomor_registrasi,
                            notDeletedStudent[i].nama,
                            notDeletedStudent[i].umur);
                }
            }
            else
            {
                printf("\n\t\t\t Koneksi ke database gagal...\n");
                status = FAILED;
            }
        }
        free(savedStudent);
        free(notDeletedStudent);
        fclose(db_session);
        printf("\n\t\t\t Tekan Enter untuk kembali ke menu utama... \n");
        getchar();
    }

    else
    {
        printf("\n\t\t\t Koneksi ke Database Error...\n");
        status = FAILED;
    }
}
size_t countRecords(FILE *dbcount)
{
    size_t counter = 0;
    char buffer[256];
    while (fgets(buffer, 256, dbcount) != NULL)
    {
        counter++;
    }
    return counter;
}
void setMsgNotif(const char *msg)
{
    msg_notif = calloc(strlen(msg) + 1, 1);
    strcpy(msg_notif, msg);
}
void clrscr(void)
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux
#endif
}
