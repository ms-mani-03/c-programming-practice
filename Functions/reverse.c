#include <stdio.h>
int reverse(int num);
int main()
{
    int num, ret;
    printf("Enter the number : ");  
    scanf("%d", &num);
    ret = reverse(num);
    printf("The reverse of %d is %d", num, ret);
    return 0; 
}
int reverse(int num)
{
    int rev = 0;
    while(num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}