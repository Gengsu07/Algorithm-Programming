/*
Write a program to receive a string entered by the user, and then save the string into a file with the name also given by the user.
*/

#include <stdio.h>


int main(void){
    char kalimat[256];
    char filename[]=NULL;
    FILE *fi;


    printf("Masukkan kata-kata hari ini:");
    scanf("%s", &kalimat);
    printf("Masukkan nama file yang akan disimpan:");
    scanf("%s", &kalimat);


    return 0;
}