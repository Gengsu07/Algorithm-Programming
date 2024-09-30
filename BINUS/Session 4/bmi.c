#include <stdio.h>

int main()
{
    double weight, height, bmi;

    // get data
    printf("Weight (kg):");
    scanf("%lf", &weight);
    printf("height (m):");
    scanf("%lf", &height);

    // calculate bmi
    bmi = weight / (height * height);

    // show the bmi 2digit precision
    printf("BMI: %.2lf", bmi);
    return 0;
}