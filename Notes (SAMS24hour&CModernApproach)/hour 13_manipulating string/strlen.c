#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = {'A', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'};

    char str2[] = "Hello, World!";
    char *ptr_str;

    printf("%zu", strlen(str1));
    printf("\n");

    printf("%zu", strlen(str2));
    printf("\n");

    ptr_str = str2;
    printf("%zu", strlen(ptr_str));

    return 0;
}
/*
ptr_str = str2;
    printf("%zu", strlen(ptr_str));
in this we initiate the first memory addres of str2 to ptr_str . then how come strlen can get 13? it shoudl count the first memory address right? please explain

The strlen() function doesn't just check the first memory address of a string but continues reading bytes until it encounters a null terminator ('\0'), which signifies the end of the string in C.
If str2 contains a string like "Hello, world!", which has 13 characters (including spaces and punctuation but excluding the '\0'), strlen(ptr_str) will return 13, not 1. The function isn't concerned with the address of the first character itself but continues until the null terminator.

If str2 is properly null-terminated, then strlen() will correctly return the number of characters before that null terminator​​.

ptr_str is mempry address of the first character string array. why no use * to dereference first so can be count by strlen
ChatGPT said:

In C, when you pass ptr_str (which is a pointer to the first character of the string) to strlen(), you don’t need to dereference it with * because strlen() expects a pointer to the entire string, not just the first character.

Here's why:

Dereferencing (*ptr_str): When you dereference ptr_str, you are accessing just the first character at that memory location. For example, if ptr_str points to "Hello", dereferencing it with *ptr_str will give 'H', the first character, not the whole string.

Passing ptr_str directly: When you pass ptr_str (the pointer to the first character), strlen() starts reading from that memory address and keeps reading each subsequent character until it hits the null terminator ('\0').
Why no dereference with strlen?
strlen() expects a pointer to the start of a string (not the value it points to), and it will automatically iterate through the string using pointer arithmetic to count characters until it finds the null terminator. Passing the pointer (i.e., the memory address) is sufficient; no need to dereference it.

Key Points:
Do not dereference: You should pass the pointer (ptr_str), not *ptr_str (the character itself).
Dereferencing gives you the value at the pointer, not the string.
Thus, strlen(ptr_str) works perfectly because ptr_str already holds the memory address of the first character of the string.
*/