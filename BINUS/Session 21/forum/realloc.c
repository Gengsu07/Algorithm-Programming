/*
Buat program dengan menggunakan malloc untuk alokasi sejumlah elemen pada memory kemudian realloc untuk mengubah elemen alokasi memory sebelumnya.
Output:
Enter number of elements: 3
Elements: 1, 2, 3

Enter the new size of elemets: 5
New elements: 1, 2, 3, 4, 5
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // deklarasi pointers untuk menampung elemen dan integer
    int *container = NULL, num_elements;

    // dapatkan input dari user
    printf("Enter number of elements: ");
    scanf("%d", &num_elements);

    // alokasi memori dengan malloc sesuai jumlah elemen
    container = malloc((size_t)num_elements * sizeof(int));
    if (container == NULL)
    {
        printf("Alokasi memori gaga");
        free(container);
        return 1;
    }
    // input dan tampilkan elemen ke dalam array
    for (int i = 0; i < num_elements; i++)
    {
        container[i] = i + 1;
        printf("%d ", container[i]);
    };

    // input new elemen size
    printf("\nEnter the new size of elemets: ");
    scanf("%d", &num_elements);

    // realokasi memori berdasarkan ukuran elemen baru
    container = realloc(container, (size_t)num_elements * sizeof(int));
    if (container == NULL)
    {
        printf("Alokasi memori gaga");
        free(container);
        return 1;
    }
    // input dan tampilkan elemen ke dalam array
    for (int i = 0; i < num_elements; i++)
    {
        container[i] = i + 1;
        printf("%d ", container[i]);
    };
    printf("\n");
    // free memori yang tidak digunakan lagi
    free(container);
    return 0;
}
