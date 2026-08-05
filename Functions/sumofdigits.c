#include <stdio.h>
int sumofdigits(int num);
int main()
{
    int num, ret;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = sumofdigits(num);
    printf("The sum of number is %d\n", ret);
}
int sumofdigits(int num)
{
    int sum = 0;
    if(num == 0)
    {
        return 0;
    }
    else
    {
        sum = (num % 10) + sumofdigits(num / 10);
    }
    return sum;
}