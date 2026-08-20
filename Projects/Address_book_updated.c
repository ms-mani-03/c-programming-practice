#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct Contact
{
        char name[30];
        char phone[11];
        char email[50];
};
struct Address_book
{
        struct Contact book[100];
        int contact_count;
};
void contact_create(struct Address_book *book);
void contact_search(struct Address_book *book);
void contact_edit(struct Address_book *book);
void contact_delete(struct Address_book *book);
void contact_list(struct Address_book *book);
void contact_save(struct Address_book *book);
void contact_load(struct Address_book *book);
int main()
{
        struct Address_book book;
        book.contact_count = 0;
        int choice;
	contact_load(&book);
	contact_list(&book);
        do
        {
		printf("1. Create\n2. Search\n3. Edit\n4. Delete\n5. List\n6. Save\n7. Exit\n");
                printf("Enter the option you need : ");
                if(scanf("%d", &choice) != 1)
                {
                        printf("Invalid Option\n");
                        while(getchar() != '\n');
                        continue;
                }
                switch(choice)
                {
                        case 1:
                                contact_create(&book);
                                break;
                        case 2:
                                contact_search(&book);
                                break;
                        case 3:
                                contact_edit(&book);
                                break;
                        case 4:
                                contact_delete(&book);
                                break;
                        case 5:
                                contact_list(&book);
                                break;
			case 6:
                                contact_save(&book);
                                break;
                        case 7:
                                printf("Exited\n");
                                return 0;
                        default:
                                printf("Invalid Option\n");
                                break;
                }
        } while(choice != 7);
        return 0;
}
void to_lower(char *str)
{
        int i;

        for(i = 0; str[i] != '\0'; i++)
        {
                str[i] = tolower((unsigned char)str[i]);
        }
}
/* ========================= VALIDATION ========================= */
int valid_name(struct Address_book *book)
{
        int i;
        for(i = 0; book->book[book->contact_count].name[i] != '\0'; i++)
        {
                if(!(isalnum(book->book[book->contact_count].name[i]) || book->book[book->contact_count].name[i] == '.' || book->book[book->contact_count].name[i] == ' '))
                {
                        return 0;
                }
        }
        return 1;
}
int valid_number(struct Address_book *book)
{
        int i;
        if(strlen(book->book[book->contact_count].phone) != 10)
        {
                return 0;
        }
        for(i = 0;
            book->book[book->contact_count].phone[i] != '\0'; i++)
        {
                if(!isdigit(book->book[book->contact_count].phone[i]))
                {
                        return 0;
                }
        }
        return 1;
}
int valid_email(struct Address_book *book)
{
        char *email = book->book[book->contact_count].email;
        char *at = strstr(email, "@");
        char *dot = strstr(email, ".com");
        if(at == NULL || dot == NULL)
        {
                return 0;
        }
        if(at == email)
        {
                return 0;
        }
        if(dot < at)
        {
                return 0;
        }
        if(dot == at + 1)
        {
                return 0;
        }
        if(dot == email + strlen(email) - 1)
        {
                return 0;
        }
        if(strstr(at + 1, "@") != NULL)
        {
                return 0;
        }
        if(strstr(dot + 1, ".") != NULL)
        {
                return 0;
        }
        return 1;
}
/* ========================= CREATE ========================= */
void contact_create(struct Address_book *book)
{
        int i;
        char phone_input[30];
        if(book->contact_count < 100)
        {
                printf("Enter Name : ");
                scanf(" %29[^\n]", book->book[book->contact_count].name);
                if(!valid_name(book))
                {
                        printf("Invalid Name\n");
                        return;
                }
		for(i = 0; i < book->contact_count; i++)
                {
        		if(strcmp(book->book[i].name, book->book[book->contact_count].name) == 0)
        		{
                		printf("Name Already Exists\n");
                		return;
        		}
		}
                printf("Enter Phone Number : ");
                scanf(" %29[^\n]", phone_input);
                if(strlen(phone_input) != 10)
                {
                        printf("Invalid Phone Number\n");
                        return;
                }
                for(i = 0; phone_input[i] != '\0'; i++)
                {
                        if(!isdigit(phone_input[i]))
                        {
                                printf("Invalid Phone Number\n");
                                return;
                        }
                }
                strcpy(book->book[book->contact_count].phone, phone_input);
                for(i = 0; i < book->contact_count; i++)
                {
                        if(strcmp(book->book[i].phone,
                                  book->book[book->contact_count].phone) == 0)
                        {
                                printf("Contact Already Exists\n");
                                return;
                        }
                }
                printf("Enter Email : ");
                scanf(" %49[^\n]", book->book[book->contact_count].email);
                if(!valid_email(book))
                {
                        printf("Invalid Email!\n");
                        return;
                }
                for(i = 0; i < book->contact_count; i++)
                {
                        if(strcmp(book->book[i].email,
                                  book->book[book->contact_count].email) == 0)
                        {
                                printf("Email Already Exists\n");
                                return;
                        }
                }
                book->contact_count++;
                contact_save(book);
                printf("Contact Created\n");
        }
        else
        {
                printf("Contact full\n");
        }
}
/* ========================= SEARCH ========================= */
void search_name(struct Address_book *book)
{
        char sch_name[30];
	char temp_name[30];
        printf("Enter the Name : ");
        scanf(" %29[^\n]", sch_name);
	to_lower(sch_name);
        int i, found = 0;
        for(i = 0; i < book->contact_count; i++)
        {
		strcpy(temp_name, book->book[i].name);
		to_lower(temp_name);
                if(strstr(temp_name, sch_name) != NULL)
                {
                        printf("%-5d ", i);
                        printf("Name : %-15s ", book->book[i].name);
                        printf("Number : %-15s ", book->book[i].phone);
                        printf("Email : %-30s\n", book->book[i].email);
                        found = 1;
                }
        }
        if(found == 0)
        {
                printf("Contact Not Found\n");
                return;
        }
}
void search_number(struct Address_book *book)
{
        char sch_num[11];
        printf("Enter the Number : ");
        scanf(" %10[^\n]", sch_num);
        int i, found = 0;
        for(i = 0; i < book->contact_count; i++)
        {
                if(strstr(book->book[i].phone, sch_num) != NULL)
                {
                        printf("%-5d ", i);
                        printf("Name : %-15s ", book->book[i].name);
                        printf("Number : %-15s ", book->book[i].phone);
                        printf("Email : %-30s\n", book->book[i].email);
                        found = 1;
                }
        }
        if(found == 0)
        {
                printf("Contact Not Found\n");
                return;
        }
}
void search_email(struct Address_book *book)
{
        char sch_email[50];
        printf("Enter the Mail : ");
        scanf(" %49[^\n]", sch_email);
        int i, found = 0;
        for(i = 0; i < book->contact_count; i++)
        {
                if(strstr(book->book[i].email, sch_email) != NULL)
                {
                        printf("%-5d ", i);
                        printf("Name : %-15s", book->book[i].name);
                        printf("Number : %-15s", book->book[i].phone);
                        printf("Email : %-30s\n", book->book[i].email);
                        found = 1;
                }
        }
        if(found == 0)
        {
                printf("Contact Not Found\n");
                return;
        }
}
void contact_search(struct Address_book *book)
{
        int opt;
        do
        {
                printf("Search the contact by,\n1. Name\n2. Number\n3. Email\n4. Exit Search\n");
                printf("Enter the Option : ");
		if(scanf("%d", &opt) != 1)
{
        printf("Invalid option!\n");
        while(getchar() != '\n');
        continue;
}
                switch(opt)
                {
                        case 1:
                                search_name(book);
                                break;
                        case 2:
                                search_number(book);
                                break;
                        case 3:
                                search_email(book);
                                break;
                        case 4:
                                printf("Exit\n");
                                return;
                        default:
                                printf("Invalid option!\n");
                }
        } while(opt != 4);
}
/* ========================= EDIT NAME ========================= */
int edt_valid_name(char *new_name)
{
        int i;
        for(i = 0; new_name[i] != '\0'; i++)
        {
                if(!(isalnum(new_name[i]) || new_name[i] == '.' || new_name[i] == ' '))
                {
                        return 0;
                }
        }
        return 1;
}
int edt_search_name(struct Address_book *book, char *sch_edt_name, int *found_index)
{
        int i, found = 0;
	char temp_name[30];
	to_lower(sch_edt_name);
        for(i = 0; i < book->contact_count; i++)
        {
		strcpy(temp_name, book->book[i].name);
		to_lower(temp_name);
                if(strstr(temp_name, sch_edt_name) != NULL)
                {
                        printf("Index : %d Name : %-10s Number : %-15s Email : %20s\n", i, book->book[i].name, book->book[i].phone, book->book[i].email);
                        found_index[found] = i;
                        found++;
                }
        }
        if(found == 0)
        {
                printf("Contact Not Found!\n");
                return 0;
        }
        return found;
}
void edt_name(struct Address_book *book)
{
        char sch_edt_name[30];
        int found_index[100];
        int found_count;
        do
        {
                printf("Enter the name to edit : ");
                scanf(" %29[^\n]", sch_edt_name);
                found_count = edt_search_name(book, sch_edt_name, found_index);
        } while(found_count == 0);
        int idx;
        int valid_index;
        int i;
        do
        {
                valid_index = 0;
                printf("Enter the index you want to edit : ");
                scanf("%d", &idx);
                for(i = 0; i < found_count; i++)
                {
                        if(idx == found_index[i])
                        {
                                valid_index = 1;
                                break;
                        }
                }
                if(!valid_index)
                {
                        printf("Invalid index\n");
                }
        } while(!valid_index);
        char new_name[30];
        int duplicate;
        do
        {
                duplicate = 0;
                printf("Enter the new name : ");
                scanf(" %29[^\n]", new_name);
                if(!edt_valid_name(new_name))
                {
                        printf("Invalid Name\n");
                        continue;
                }
                for(i = 0; i < book->contact_count; i++)
                {
                        if(i != idx && strcmp(book->book[i].name, new_name) == 0)
                        {
                                duplicate = 1;
                                break;
                        }
                }
                if(duplicate)
                {
                        printf("Name Already Exists\n");
                }
        } while(!edt_valid_name(new_name) || duplicate);
        strcpy(book->book[idx].name, new_name);
	contact_save(book);
        printf("Name edited successfully!\n");
}
/* ========================= EDIT NUMBER ========================= */
int sch_edt_number(struct Address_book *book, char *sch_edt_num, int *found_index)
{
        int i, found = 0;
        for(i = 0; i < book->contact_count; i++)
        {
                if(strstr(book->book[i].phone, sch_edt_num) != NULL)
                {
                        printf("Index %d Name : %-10s Number : %-15s Email : %-25s\n", i, book->book[i].name, book->book[i].phone, book->book[i].email);
                        found_index[found] = i;
                        found++;
                }
        }
        if(found == 0)
        {
                printf("Contact Not Found\n");
                return 0;
        }
        return found;
}
int edt_valid_number(char *new_num)
{
        int i;
        if(strlen(new_num) != 10)
        {
                return 0;
        }
        for(i = 0; new_num[i] != '\0'; i++)
        {
                if(!isdigit(new_num[i]))
                {
                        return 0;
                }
        }
        return 1;
}
void edt_num(struct Address_book *book)
{
        char sch_edt_num[30];
        int found_index[100];
        int found_count;
        do
        {
                printf("Enter the number to edit : ");
                scanf(" %29[^\n]", sch_edt_num);
                found_count = sch_edt_number(book, sch_edt_num, found_index);
        } while(found_count == 0);
        int num_idx;
        int valid_index;
        int i;
        do
        {
                valid_index = 0;
                printf("Enter the index you want to edit : ");
                scanf("%d", &num_idx);
                for(i = 0; i < found_count; i++)
                {
                        if(num_idx == found_index[i])
                        {
                                valid_index = 1;
                                break;
                        }
                }
                if(!valid_index)
                {
                        printf("Invalid Index!\n");
                }
        } while(!valid_index);
        char new_num[11];
        int duplicate;
        do
        {
                duplicate = 0;
                printf("Enter the new Number : ");
                scanf(" %10[^\n]", new_num);
                if(!edt_valid_number(new_num))
                {
                        printf("Invalid Number!\n");
                        continue;
                }
                for(i = 0; i < book->contact_count; i++)
                {
                        if(i != num_idx &&
                           strcmp(book->book[i].phone, new_num) == 0)
                        {
                                duplicate = 1;
                                printf("Number Already exists!\n");
                                break;
                        }
                }
        } while(!edt_valid_number(new_num) || duplicate);
        strcpy(book->book[num_idx].phone, new_num);
	contact_save(book);
        printf("Number Updated Successfully!\n");
}
/* ========================= EDIT EMAIL ========================= */
int sch_edt_email(struct Address_book *book, char *sch_edt_mail, int *found_index)
{
        int i, found = 0;
        for(i = 0; i < book->contact_count; i++)
        {
                if(strstr(book->book[i].email, sch_edt_mail) != NULL)
                {
                        printf("Index %d Name : %-10s Number : %-15s Email : %-25s\n", i, book->book[i].name, book->book[i].phone, book->book[i].email);
                        found_index[found] = i;
                        found++;
                }
        }
        if(found == 0)
        {
                printf("Contact Not Found!\n");
                return 0;
        }
        return found;
}
int edt_valid_email(char *new_mail)
{
        char *email = new_mail;
        char *at = strstr(email, "@");
        char *dot = strstr(email, ".com");
        if(at == NULL || dot == NULL)
        {
                return 0;
        }
        if(at == email)
        {
                return 0;
        }
        if(dot < at)
        {
                return 0;
        }
        if(dot == at + 1)
        {
                return 0;
        }
        if(dot == email + strlen(email) - 1)
        {
                return 0;
        }
        if(strstr(at + 1, "@") != NULL)
        {
                return 0;
        }
        if(strstr(dot + 1, ".") != NULL)
        {
                return 0;
        }
        return 1;
}
void edt_email(struct Address_book *book)
{
        char sch_edt_mail[50];
        int found_index[100];
        int found_count;
        do
        {
                printf("Enter the email to edit : ");
                scanf(" %49[^\n]", sch_edt_mail);
                found_count = sch_edt_email(book, sch_edt_mail, found_index);
        } while(found_count == 0);
        int mail_idx;
        int valid_index;
        int i;
        do
        {
                valid_index = 0;
                printf("Enter the index you want to edit : ");
                scanf("%d", &mail_idx);
                for(i = 0; i < found_count; i++)
                {
                        if(mail_idx == found_index[i])
                        {
                                valid_index = 1;
                                break;
                        }
                }
                if(!valid_index)
                {
                        printf("Invalid Index!\n");
                }
        } while(!valid_index);
        char new_mail[50];
        int duplicate;
        int valid;
        do
        {
                valid = 1;
                duplicate = 0;
                printf("Enter the New Email : ");
                scanf(" %49[^\n]", new_mail);
                if(!edt_valid_email(new_mail))
                {
                        printf("Invalid Email\n");
                        valid = 0;
                        continue;
                }
                for(i = 0; i < book->contact_count; i++)
                {
                        if(i != mail_idx && strcmp(book->book[i].email, new_mail) == 0)
                        {
                                duplicate = 1;
                                printf("Email Already Exists\n");
                                break;
                        }
                }
        } while(!valid || duplicate);
        strcpy(book->book[mail_idx].email, new_mail);
	contact_save(book);
        printf("Email Updated Successfully!\n");
}
/* ========================= EDIT MENU ========================= */
void contact_edit(struct Address_book *book)
{
        int edt_opt;
	do
	{
        printf("Edit by,\n1. Name\n2. Number\n3. Email\n4. Exit\nEnter the option : ");
        if(scanf("%d", &edt_opt) != 1)
{
        printf("Invalid Edit Option\n");
        while(getchar() != '\n');
        continue;
}
        switch(edt_opt)
        {
                case 1:
                        edt_name(book);
                        break;
                case 2:
                        edt_num(book);
                        break;
                case 3:
                        edt_email(book);
                        break;
                case 4:
                        printf("Exit Edit\n");
                        return;
                default:
                        printf("Invalid Edit Option\n");
        }
	}while(edt_opt != 4);
}
/* ========================= DELETE ========================= */
void dlt_name(struct Address_book *book)
{
	char dlt_sch_name[30];
	int found_index[100];
	int found_count;
	do
	{
		printf("Enter the name to delete : ");
		scanf(" %29[^\n]", dlt_sch_name);
		found_count = edt_search_name(book, dlt_sch_name, found_index);
	}while(found_count == 0);
	int idx;
	int valid_index;
	int i;
	do
	{
		valid_index = 0;
		printf("Enter the index you want to delete : ");
		scanf("%d", &idx);
		for(i = 0; i < found_count; i++)
		{
			if(idx == found_index[i])
			{
				valid_index = 1;
				break;
			}
		}
		if(!valid_index)
		{
			printf("Invalid Index\n");
		}
	}while(!valid_index);
	for(i = idx; i < book->contact_count - 1; i++)
	{
			book->book[i] = book->book[i + 1];
	}
	book->contact_count--;
	contact_save(book);
	printf("contact Deleted Successfully!\n");
}
void dlt_num(struct Address_book *book)
{
        char dlt_sch_num[30];
        int found_index[100];
        int found_count;
        do
        {
                printf("Enter the number to delete : ");
                scanf(" %29[^\n]", dlt_sch_num);
                found_count = sch_edt_number(book, dlt_sch_num, found_index);
        }while(found_count == 0);
        int idx;
        int valid_index;
        int i;
        do
        {
                valid_index = 0;
                printf("Enter the index you want to delete : ");
                scanf("%d", &idx);
                for(i = 0; i < found_count; i++)
                {
                        if(idx == found_index[i])
                        {
                                valid_index = 1;
                                break;
                        }
                }
                if(!valid_index)
                {
                        printf("Invalid Index\n");
                }
        }while(!valid_index);
        for(i = idx; i < book->contact_count - 1; i++)
        {
                book->book[i] = book->book[i + 1];
        }
        book->contact_count--;
	contact_save(book);
        printf("Contact Deleted Successfully!\n");
}
void dlt_email(struct Address_book *book)
{
        char dlt_sch_email[50];
        int found_index[100];
        int found_count;
        do
        {
		printf("Enter the email to delete : ");
                scanf(" %49[^\n]", dlt_sch_email);
                found_count = sch_edt_email(book, dlt_sch_email, found_index);
        }while(found_count == 0);
        int idx;
        int valid_index;
        int i;
        do
        {
                valid_index = 0;
                printf("Enter the index you want to delete : ");
                scanf("%d", &idx);
                for(i = 0; i < found_count; i++)
                {
                        if(idx == found_index[i])
                        {
                                valid_index = 1;
                                break;
                        }
                }
                if(!valid_index)
                {
                        printf("Invalid Index\n");
                }
        }while(!valid_index);
        for(i = idx; i < book->contact_count - 1; i++)
        {
                book->book[i] = book->book[i + 1];
        }
        book->contact_count--;
	contact_save(book);
        printf("Contact Deleted Successfully!\n");
}
/* ========================= DELETE MENU ========================= */
void contact_delete(struct Address_book *book)
{
        int dlt_opt;
	do
	{
		printf("Delete the contact by,\n1. Name\n2. Number\n3. Email\n4. Exit\n");
		printf("Enter the Option : ");
		if(scanf("%d", &dlt_opt) != 1)
{
        printf("Invalid Option\n");
        while(getchar() != '\n');
        continue;
}
		switch(dlt_opt)
		{
			case 1:
				dlt_name(book);
				break;
			case 2:
				dlt_num(book);
				break;
			case 3:
				dlt_email(book);
				break;
			case 4:
				printf("Exited Delete\n");
			        return;
			default:
				printf("Invalid Option\n");
		}
	}while(dlt_opt != 4);	
}
/* ========================= LIST ========================= */
void contact_list(struct Address_book *book)
{
        int i;
        if(book->contact_count == 0)
        {
                printf("No Contact Saved!\n");
                return;
        }
        printf("----------------------------------------------------------\n");
        printf("%-25s %-15s %10s\n", "Name", "Phone Number", "Email");
        printf("----------------------------------------------------------\n");
        for(i = 0; i < book->contact_count; i++)
        {
                printf("%-25s %-15s %-30s\n", book->book[i].name, book->book[i].phone, book->book[i].email);
        }
        printf("----------------------------------------------------------\n");
}
/* ========================= SAVE ========================= */
void contact_save(struct Address_book *book)
{
        FILE *fp;
	fp = fopen("Address_Book.txt", "w");
	if(fp == NULL)
	{
		perror("Error ");
		return;
	}
	int i;
	fprintf(fp, "----------------------------------------------------------------\n");
	fprintf(fp, "%7s | %-10s | %-15s | %-25s\n", "Index", "Name", "Number", "Email");
	fprintf(fp, "----------------------------------------------------------------\n");
	for(i = 0; i < book->contact_count; i++)
	{
		fprintf(fp, "%d|%s |%s|%s\n", i, book->book[i].name, book->book[i].phone, book->book[i].email);
		fprintf(fp, "----------------------------------------------------------------\n");
	}
	fclose(fp);
}
/* ======================== LOAD ========================== */
void contact_load(struct Address_book *book)
{
        FILE *fp;
        int index;
        fp = fopen("Address_Book.txt", "r");
        if(fp == NULL)
        {
                perror("Error ");
                return;
        }
        fscanf(fp, "%*[^\n]\n");
        fscanf(fp, "%*[^\n]\n");
        fscanf(fp, "%*[^\n]\n");
        book->contact_count = 0;
        while(book->contact_count < 100)
        {
                if(fscanf(fp, "%d|%29[^|]|%10[^|]|%49[^\n]\n", &index, book->book[book->contact_count].name, book->book[book->contact_count].phone, book->book[book->contact_count].email) != 4)
                {
                        break;
                }
                book->contact_count++;
                fscanf(fp, "%*[^\n]\n");
        }
        fclose(fp);
}
