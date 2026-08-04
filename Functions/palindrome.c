#include <stdio.h>
int ispalindrome(int num);
int main()
{
    int num, ret;
    printf("Enter the number : ");
    scanf("%d", &num);
    ret = ispalindrome(num);
    if(ret == 1)
        printf("palindrome");
    else
        printf("Not a palindrome");
    return 0;
}
int ispalindrome(int num)
{
    int rev = 0, original = num;
    while(num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    if(original == rev)
        return 1;
    else
        return 0;
}