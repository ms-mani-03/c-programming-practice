#include <stdio.h>
void binary(int num);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    if(num == 0)
    {
        printf("0");
    }
    binary(num);
    return 0;
}
void binary(int num)
{
    if(num == 0)
    {
        return ;
    }
    binary(num / 2);
    printf("%d", num % 2);
}