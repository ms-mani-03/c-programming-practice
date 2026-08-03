#include <stdio.h>
int isprime(int num);
int main()
{
    int num, ret;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = isprime(num);
    if(ret == 0)
        printf("The number is not a prime number");
    else
        printf("The number is a prime number");
    return 0;
}
int isprime(int num)
{
    int i;
    if(num < 2)
        return 0;
    for(i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}