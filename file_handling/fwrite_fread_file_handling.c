#include <stdio.h>
int main()
{
        FILE *fp;
        int arr[5] = {10, 20, 30, 40, 50};
        fp = fopen("data.dat", "wb");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        fwrite(arr, sizeof(int), 5, fp);
        fclose(fp);
        fp = fopen("data.dat", "rb");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        int arr2[5];
        fread(arr2, sizeof(int), 5, fp);
        printf("The element of arr2 : ");
        int i;
        for(i = 0; i < 5; i++)
        {
                printf("%d ", arr2[i]);
        }
        printf("\n");
        fclose(fp);
        return 0;
}