#include <stdio.h>

int main()
{
    enum units
    {
        penny = 1,
        nickel = 5,
        dime = 10,
        quarter = 25,
        dollar = 100
    };

    int money_units[5] = {dollar, quarter, dime, nickel, penny};

    char unit_name[5][20] = {
        "dollar (s)",
        "quarter (s)",
        "dime(s)",
        "nickel(s)",
        "penny (s)"};

    int cent, tmp, i;
    printf("Enter a monetary value in cents:\n");
    scanf("%d", &cent); /* get input from the user */
    printf("Which is equivalent to:\n");
    tmp = 0;
    for (i = 0; i < 5; i++)
    {
        tmp = cent / money_units[i];
        cent -= tmp * money_units[i];
        if (tmp)
            printf("%d %s", tmp, unit_name[i]);
    }
    printf("\n");
    return 0;
}
/*
When you create an enumeration using the enum keyword, you are essentially defining a new type and a set of named constants.
While enum constants behave like variables, they are actually simple symbolic names for constant integer values. They cannot be modified because they are constants. This means you cannot assign a new value to dollar (for example), as it must always represent the value 100.
*/