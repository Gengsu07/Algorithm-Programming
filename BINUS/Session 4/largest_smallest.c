/*Buat program dengan input tiga integer, kemudian tampilkan nilai total, nilai rata-rata, nilai terkecil dan terbesar.*/

#include <stdio.h>

// function find largest from 3 integers
int largest3(int num1, int num2, int num3)
{
    int largest;
    if (num1 > num2)
    {
        if (num1 > num3)
            largest = num1;
        else
            largest = num3;
    }
    else if (num2 > num3)
        largest = num2;
    else
        largest = num3;

    return largest;
}

// function find smallest from 3 integers
int smallest3(int num1, int num2, int num3)
{
    int smallest;
    if (num1 < num2)
    {
        if (num1 < num3)
            smallest = num1;
        else
            smallest = num3;
    }
    else if (num2 < num3)
        smallest = num2;
    else
        smallest = num3;

    return smallest;
}

int main()
{
    // define variabel
    int num1, num2, num3, sum;
    float rata_rata;

    // get input data
    printf("Enter three different integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // operation
    sum = num1 + num2 + num3;
    rata_rata = (float)sum / 3;

    // pakai ternary operator
    //  largest = num1 > num2 ? num1 : num2 > num3 ? num2 : num3;
    //  smallest = num1 < num2 ? num1 : num2 < num3 ? num2:num3;

    printf("Sum is %d\n", sum);
    printf("Average is %f\n", rata_rata);
    printf("Smallest is %d\n", smallest3(num1, num2, num3));
    printf("Largest is %d", largest3(num1, num2, num3));
    return 0;
}
