#include <stdio.h>
int my_strstr(char *str, char *pos);
int main()
{
    char str[50];
    char sub[50];
    printf("Enter the main string : ");
    scanf("%[^\n]", str);
    printf("Enter the sub : ");
    scanf(" %[^\n]", sub);
    int ret = my_strstr(str, sub);
    if(ret != 0)
    {
        printf("%s\n", &str[ret]);
    }
    else
    {
        printf("The substring not found\n");
    }
    return 0;
}
int my_strstr(char *str, char *sub)
{
    int i, j;
    for(i = 0; str[i] != '\0'; i++)
    {
        j = 0;
        while(str[i + j] == sub[j] && sub[j] != '\0')
        {
            j++;
        }
        if(sub[j] == '\0')
        {
            return i;
        }
    }
    return 0;
}