#include <stdio.h>

int main()
{
    char str1[] = {'A', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'};

    char str2[] = "Hello, World!";
    char *ptr_str;

    for (int i = 0; str1[i]; i++)
        printf("%c", str1[i]);
    printf("\n");

    for (int i = 0; str2[i]; i++)
        printf("%c", str2[i]);
    printf("\n");

    ptr_str = str2;
    for (int i = 0; *ptr_str; i++)
        printf("%c", *ptr_str++);

    return 0;
}

/*
# Question

expalain me this:
ptr_str = “Assign a string to a pointer.”;
for (i=0; *ptr_str; i++)
  printf(“%c”, *ptr_str++);

i know the first row , the second row why using the deferenced value instead of the mempry addres like ptr_str. same in printf statement

# Answer

Let's break down the selected code snippet:

```c
ptr_str = "Assign a string to a pointer.";
for (i=0; *ptr_str; i++)
  printf("%c", *ptr_str++);
```

1. **Initialization of `ptr_str`:**
   - The line `ptr_str = "Assign a string to a pointer.";` initializes the pointer `ptr_str` to point to the first character of the string literal `"Assign a string to a pointer."`. This means `ptr_str` now holds the memory address where this string is stored.

2. **The `for` loop:**
   - The loop `for (i=0; *ptr_str; i++)` iterates over the characters in the string.
   - `*ptr_str` dereferences the pointer, meaning it accesses the character located at the current memory address pointed to by `ptr_str`. This will evaluate to `true` (or non-zero) as long as the character is not the null terminator `\0`, which indicates the end of the string.

3. **Printing characters:**
   - Inside the loop, the statement `printf("%c", *ptr_str++);` prints the current character pointed to by `ptr_str` using `printf`.
   - After printing the character, `ptr_str++` increments the pointer to point to the next character in the string. This is a post-increment operation, so the value of `ptr_str` is dereferenced first (to get the character) and then incremented to the next memory address.

### Why Use Dereferencing:
- Using `*ptr_str` allows you to access the actual character value at that address. If you were to use `ptr_str` directly in `printf`, you would not print the string character but rather the memory address. That would not be useful in this context because you want to display the characters one by one.

In summary, the code iterates through the string character by character until it reaches the end, printing each character individually. The use of dereferencing is essential to obtain the character value stored at the memory location pointed to by `ptr_str`.

# Question

i see, when using *ptr_str in for loop it can break the loop if meet \0. but when using ptr_str which is the address, it cannot get \0 so the loop never stop?

# Answer

Exactly! You've got it.

When you use `*ptr_str` in the loop condition, like this:

```c
for (i=0; *ptr_str; i++)
```

the loop checks the value at the memory location pointed to by `ptr_str`. If that value is the null terminator (`\0`), which signifies the end of a string in C, the expression `*ptr_str` will evaluate to `false` (or zero), causing the loop to terminate.

On the other hand, if you used `ptr_str` (the pointer itself) in the loop condition:

```c
for (i=0; ptr_str; i++)
```

This condition always evaluates to `true` as long as `ptr_str` itself is not `NULL`. This would mean the loop continues indefinitely, never checking the actual content of the string.

So, using `*ptr_str` allows you to check the value of the character at the current pointer location, enabling you to break the loop when you reach the end of the string.
*/