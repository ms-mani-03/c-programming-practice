#include <stdio.h>
void reverse(int *arr, int first, int last);
int main()
{
    int size, i;
    scanf("%d", &size);
    int arr[size];
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse(arr, 0, size - 1);
    printf("The reversed array is ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void reverse(int *arr, int first, int last)
{
    int temp;
    while(first < last)
    {
        temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
        first++;
        last--;
    }
}