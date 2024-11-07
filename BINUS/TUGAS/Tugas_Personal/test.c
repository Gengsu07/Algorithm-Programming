#include <stdio.h>

void move_zeros(int *arr, int array_size)
{
    int temp = 0;
    for (int i = 0; i < array_size; i++)
    {
        printf("arr i: %d \n", arr[i]);
        while (arr[i] == 0 && i < array_size - 1)
        {
            printf("arr i+j: %d \n", arr[i + 1]);
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i++;
        }
    }
}

int main(void)
{
    int arr[] = {0, 1, 0, 3, 2, 4};
    int arrsize = sizeof(arr) / sizeof(arr[0]);

    move_zeros(arr, arrsize);
    for (int i = 0; i < arrsize; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
