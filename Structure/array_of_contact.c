#include <stdio.h>

struct Contact
{
    char name[30];
    char contact_number[5][20];
    char email[5][30];
};

int main()
{
    int i, j;
    struct Contact contact[3];

    for(i = 0; i < 3; i++)
    {
        printf("Name : ");
        scanf(" %[^\n]", contact[i].name);

        for(j = 0; j < 2; j++)
        {
            printf("Number : ");
            scanf(" %[^\n]", contact[i].contact_number[j]);

            printf("Email : ");
            scanf(" %[^\n]", contact[i].email[j]);
        }
    }

    printf("\n--- Contact List ---\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nName: %s\n", contact[i].name);

        for(j = 0; j < 2; j++)
        {
            printf("Number: %s\n", contact[i].contact_number[j]);
            printf("Email: %s\n", contact[i].email[j]);
        }
    }

    return 0;
}