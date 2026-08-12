#include <stdio.h>
void str_cpy(const char *str1, char *str2);
int main()
{
    char str1[10];
    char str2[10];
    printf("Enter the String : ");
    scanf(" %[^\n]", str1);
    str_cpy(str1, str2);
    printf("The copied string is %s\n", str2);
    return 0;
}
void str_cpy(const char *str1, char *str2)
{
    while(*str2++ = *str1++);
}