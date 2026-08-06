#include <stdio.h>
void fibannocci(int num, int a, int b, int count);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    fibannocci(num, 0, 1, 0);
    return 0;
}
void fibannocci(int num, int a, int b, int count)
{
    if(num == count)
    {
        return 0;
    }
    printf("%d ", a);
    return fibannocci(num, b, a + b, count + 1);
}