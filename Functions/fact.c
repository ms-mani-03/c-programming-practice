#include <stdio.h>
int fact(int num);
int main()
{
    int num, ret;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = fact(num);
    printf("The factorial of %d is %d", num, ret);
    return 0;
}
int fact(int num)
{
    if(num == 1)
    {
        return 1;
    }
    return num * fact(num - 1);
}