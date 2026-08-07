#include <stdio.h>
int second_largest(int *arr, int size);
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
    ret = second_largest(arr, size);
    printf("The second largest element is %d", ret);
    return 0;
}
int second_largest(int *arr, int size)
{
    int max = arr[0], second = arr[0], i;
    if(size < 2)
    {
        printf("Array must have atleast two elements");
        return -1;
    }
    for(i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            second = max;
            max = arr[i];
        }
        else if(arr[i] > second && arr[i] != max)
        {
            second = arr[i];
        }
    }
    return second;
}