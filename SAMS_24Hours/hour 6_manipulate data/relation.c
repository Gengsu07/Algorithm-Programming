
/* 06L03.0: Using relational operators */ 
#include <stdio.h>
int main()
{
    int x, y; 
    double z;

    x =7;
    y = 25;
    z = 24.46;
    printf ("Given x =%d, y =%d, and z = %.2f, \n", x, y, z); 
    printf("x >= y produces: %d\n", x >= y);
    printf("x ==y produces: %d\n", x==y);
    printf("x < z produces: %d\n", x < z);
    printf("y > z produces: %d\n", y > z);
    printf("x != y - 18 produces: %d\n", x != y - 18); 
    printf("x+y !=z produces: %d\n", x +y != z);
    
return 0;  
}

/*
Lines 9–11 initialize the three variables. Line 12 prints out the values assigned to the variables.
Because the value of x is 7 and the value of y is 25, y is greater than x. Therefore, line 13 prints out 0, which is the result yielded by the relational expression x >= y.
Likewise, in line 14, the relational expression x == y yields 0.
Lines 15 and 16 print out the result of 1,which is yielded by the evaluations of both
x < zandy > z.
The statement in line 17 displays 0, which is the result of the relational expression
x != y - 18.Sincey - 18yields7,andthevalueofxis7,the!=relationshipdoes not hold. In line 18, the expression x + y != z produces 1, which is displayed on the screen.
*/