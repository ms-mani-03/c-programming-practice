#include <stdio.h>
int largest_arr(int *arr, int size);
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
    ret = largest_arr(arr, size);
    printf("The largest element of array is %d\n", ret);
}
int largest_arr(int *arr, int size)
{
    int max = arr[0], i;
    for(i = 0;i < size; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}