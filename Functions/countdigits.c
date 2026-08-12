#include <stdio.h>
int countdigits(int num);
int main()
{
    int num, ret;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = countdigits(num);
    printf("The count of digits is %d", ret);
    return 0;
}
int countdigits(int num)
{
    if(num == 0 )
    {
        return 0;
    }
    return 1 + countdigits(num / 10);
}