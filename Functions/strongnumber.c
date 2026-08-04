#include <stdio.h>
int strongnum(int num);
int main()
{
    int num, ret;
    int original;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = strongnum(num);
    original = num;
    if(original == ret)
    {
        printf("It is strong number");
    }
    else
    {
        printf("It is not a strong number");
    }
}
int strongnum(int num)
{
    int rem, fact, sum = 0;
    while(num != 0)
    {
        fact = 1;
        rem = num % 10;
        for(int i = 1; i <= rem; i++)
        {
            fact *= i;
        }
        sum += fact;
        num /= 10;
    }
    return sum;
}