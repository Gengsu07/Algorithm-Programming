/* 20L01.c Referencing a union */
#include <stdio.h>
#include <string.h>

union menu
{
    char name[23];
    double price;
} dish;
void refwithpointer(union menu *menu)
{
    printf("The content referenced by the union pointer:\n");
    printf("Dish Name: %s\n", menu->name);
    printf("Dish Price: %5.2f\n", menu->price);
}

int main(void)
{
    printf("The content assigned to the union separately:\n");
    /* reference name */
    strcpy(dish.name, "Sweet and Sour Chicken");
    printf("Dish Name: %s\n", dish.name);
    /* reference price */
    dish.price = 9.95;
    printf("Dish Price: %5.2f\n", dish.price);
}
