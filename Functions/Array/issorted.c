#include <stdio.h>
int sorted(int *arr, int size);
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
    ret = sorted(arr, size);
    if(ret)
    {
        printf("The array is sorted\n");
    }
    else
    {
        printf("The array is not sorted\n");
    }
    return 0;
}
int sorted(int *arr, int size)
{
    int i;
    for(i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}