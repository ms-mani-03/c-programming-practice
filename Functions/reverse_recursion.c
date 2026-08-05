#include <stdio.h>
int reverse(int num, int rev);
int main()
{
    int num, ret;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = reverse(num, 0);
    printf("The reversed number is %d\n", ret);
}
int reverse(int num, int rev)
{
    if(num == 0)
    {
        return rev;
    }
    return reverse(num / 10, rev * 10 + num % 10);
}