#include <stdio.h>

void move(int n, char source, char target, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    // Move n-1 disks from source to auxiliary, using target as temporary
    move(n - 1, source, auxiliary, target);

    // Move nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);

    // Move the n-1 disks from auxiliary to target, using source as temporary
    move(n - 1, auxiliary, target, source);
}

int main(void)
{
    int num_disks = 4;              // Number of disks
    move(num_disks, 'A', 'C', 'B'); // A = source, C = target, B = auxiliary
    return 0;
}
