#include <stdio.h>
int smallest_arr(int *arr, int size);
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
    ret = smallest_arr(arr, size);
    printf("The smallest is %d\n", ret);
}
int smallest_arr(int *arr, int size)
{
    int min = arr[0], i;
    for(i = 0;i < size; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}