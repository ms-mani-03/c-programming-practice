#include <stdio.h>
int arr_sum(int *arr, int size);
int main()
{
    int size, i, ret;
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array elements : ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    ret = arr_sum(arr, size);
    printf("The sum of array is %d\n", ret);
}
int arr_sum(int *arr, int size)
{
    int sum = 0, i;
    for(i = 0;i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}