#include <stdio.h>

int main(void)
{
    struct computer
    {
        float cost;
        int year;
        int cpu_speed;
        char cpu_type[16];
    } model;

    printf("The type of the CPU inside your computer?\n");
    fgets(model.cpu_type, sizeof(model.cpu_type), stdin);

    printf("The speed (MHz) of the CPU?\n");
    scanf("%d", &model.cpu_speed);

    printf("The year your computer was made?\n");
    scanf("%d", &model.year);

    printf("How much you paid for the computer?\n");
    scanf("%f", &model.cost);

    printf("Here are what you entered:\n");
    printf("Year: %d\n", model.year);
    printf("Cost: $%6.2f\n", model.cost);
    printf("CPU type: %s", model.cpu_type); // fgets includes the newline character
    printf("CPU speed: %d MHz\n", model.cpu_speed);

    return 0;
}
