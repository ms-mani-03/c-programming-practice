#include <stdio.h>
int power(int x, int y);
int main()
{
    int x, y, ret;
    printf("Enter the value of x and y :");
    scanf("%d %d", &x, &y);
    ret = power(x, y);
    printf("The power value is : %d", ret);
    return 0;
}
int power(int x, int y)
{
    if(y == 0)
        return 1;
    return x * power(x , y - 1);
}