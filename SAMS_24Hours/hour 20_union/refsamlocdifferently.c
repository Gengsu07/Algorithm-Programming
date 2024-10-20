/* 20L04.c: Referencing the same memory in different ways */
#include <stdio.h>

// Define a union that can store either two characters or an integer
union u
{
    char ch[2]; // Array to store two characters
    int num;    // Integer to store a number
};

// Function prototype for UnionInitialize
void UnionInitialize(union u *val);

int main(void)
{
    union u val; // Declare a union variable

    // Call the function to initialize the union
    UnionInitialize(&val);

    // Print the two characters stored in the union
    printf("The two characters held by the union:\n");
    printf("%c\n", val.ch[0]); // Print the first character
    printf("%c\n", val.ch[1]); // Print the second character

    return 0; // Return 0 to indicate successful execution
}

// Function definition for UnionInitialize
void UnionInitialize(union u *val)
{
    // Initialize the character array with 'H' and 'i'
    val->ch[0] = 'H';
    val->ch[1] = 'i';
}
