/* 19L06.c Using nested structures */
#include <stdio.h>

struct department
{
    int code;
    char name[32];
    char position[15];
};

typedef struct department DPT;

struct employees
{
    DPT dept;
    char name[32];
};

typedef struct employees EMPLY;

void InfoDisplay(EMPLY *ptr);
void InfoEnter(EMPLY *ptr);

int main()
{
    EMPLY info = {
        {1,
        “Marketing”,
        “Manager”},
        1,
        “B.Smith”};
    printf("Here is a sample:\n");
    InfoDisplay(&info);

    InfoEnter(&info);

    printf("\nHere are what you entered:\n");
    InfoDisplay(&info);

    return 0;
}

void InfoDisplay(EMPLY *ptr)
{
    printf("Name: %s\n", ptr->name);
    printf("Dept. Code: %d\n", ptr->dept.code);
    printf("Your position: %s\n", ptr->dept.position);
}

void InfoEnter(EMPLY *ptr)
{
    printf("\nPlease enter your information:\n");
    printf("Your name:\n");
    fgets(ptr->name, sizeof(ptr->name), stdin);

    printf("Your position:\n");
    fgets(ptr->dept.position, sizeof(ptr->dept.position), stdin);

    printf("Dept name:\n");
    fgets(ptr->dept.name, sizeof(ptr->dept.name), stdin);

    printf("Dept code:\n");
    scanf("%d", &(ptr->dept.code));

    printf("Your employee ID #:\n");
    scanf("%d", &(ptr->code));
}
