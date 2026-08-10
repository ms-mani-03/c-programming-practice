#include <stdio.h>

struct Contact
{
    char name[30];
    char contact_number[5][20];
    char email[5][30];
};

void read_contact(struct Contact *contact);
void print_contact(struct Contact *contact);

int main()
{
    struct Contact contact[3];

    read_contact(contact);
    print_contact(contact);

    return 0;
}

void read_contact(struct Contact *contact)
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        printf("Name : ");
        scanf(" %[^\n]", (contact + i)->name);

        for(j = 0; j < 2; j++)
        {
            printf("Number : ");
            scanf(" %[^\n]", (contact + i)->contact_number[j]);

            printf("Email : ");
            scanf(" %[^\n]", (contact + i)->email[j]);
        }
    }
}

void print_contact(struct Contact *contact)
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        printf("\nName: %s\n", (contact + i)->name);

        for(j = 0; j < 2; j++)
        {
            printf("Number: %s\n", (contact + i)->contact_number[j]);
            printf("Email: %s\n", (contact + i)->email[j]);
        }
    }
}