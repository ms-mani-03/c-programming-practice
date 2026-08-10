#include <stdio.h>

struct Contact
{
    char name[30];
    char contact_number[5][20];
    char email[5][30];
};

int main()
{
    int i;
    struct Contact c1;

    printf("Name : ");
    scanf(" %[^\n]", c1.name);

    for(i = 0; i < 2; i++)
    {
        printf("Number : ");
        scanf(" %[^\n]", c1.contact_number[i]);

        printf("Email : ");
        scanf(" %[^\n]", c1.email[i]);
    }

    printf("\nName: %s\n", c1.name);

    for(i = 0; i < 2; i++)
    {
        printf("Number: %s\n", c1.contact_number[i]);
        printf("Email: %s\n", c1.email[i]);
    }

    return 0;
}