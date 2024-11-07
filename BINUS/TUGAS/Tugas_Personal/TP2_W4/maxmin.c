#include <stdio.h>

void maxmin(int arr[], int n, int *max, int *min);
int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    maxmin(arr, n, &max, &min);
    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
    return 0;
}

void maxmin(int arr[], int n, int *max, int *min)
{
    int max_temp = arr[0];
    int min_temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_temp)
        {
            max_temp = arr[i];
        }
        else if (arr[i] < min_temp)
        {
            min_temp = arr[i];
        }
    }
    *max = max_temp;
    *min = min_temp;
}
