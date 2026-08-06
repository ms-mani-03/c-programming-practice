#include <stdio.h>
int gcd(int a, int b);
int main()
{
    int a, b, ret;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    ret = gcd(a, b);
    printf("The gcd is %d", ret);
    return 0;
}
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}