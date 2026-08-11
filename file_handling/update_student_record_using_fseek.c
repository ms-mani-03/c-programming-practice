#include <stdio.h>
struct Student
{
        int id;
        char name[20];
        float marks;
};
int main()
{
        int n, i;
        printf("Enter the no of students : ");
        scanf("%d", &n);
        struct Student stud[n];
        for(i = 0; i < n; i++)
        {
                scanf("%d %s %f", &stud[i].id, stud[i].name, &stud[i].marks);
        }
        FILE *fp;
        fp = fopen("Students.dat", "wb");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        for(i = 0; i < n; i++)
        {
                fwrite(&stud[i],sizeof(struct Student), 1, fp);
        }
        fclose(fp);
        fp = fopen("Students.dat", "rb+");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        int search_id, found_index = -1;
        struct Student temp;
        printf("Enter the ID to search :");
        scanf("%d", &search_id);
        for(i = 0; i < n; i++)
        {
                fseek(fp, i * sizeof(struct Student), SEEK_SET);
                fread(&temp, sizeof(struct Student), 1, fp);
                if(temp.id == search_id)
                {
                        found_index = i;
                        break;
                }
        }
        if(found_index == -1)
        {
                printf("ID not found\n");
                fclose(fp);
                return -1;
        }
        float new_marks;
        printf("Enter the new marks : ");
        scanf("%f", &new_marks);
        temp.marks = new_marks;
        fseek(fp, found_index * sizeof(struct Student), SEEK_SET);
        fwrite(&temp, sizeof(struct Student), 1, fp);
        printf("%f" , new_marks);
        printf("\nUpdated Student : \n");
        printf("ID : %d\n", temp.id);
        printf("Name : %s\n", temp.name);
        printf("Marks : %f\n", temp.marks);
        fclose(fp);
        return 0;
}