#include <stdio.h>
int main()
{
        int arr[5] = {10, 20, 30, 40, 50};
        FILE *fp = fopen("Data.dat", "w");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        fwrite(arr, sizeof(int), 5, fp);
        fclose(fp);
        fp = fopen("Data.dat", "r");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        int num;
        fseek(fp, 2 * sizeof(int), SEEK_SET);
        fread(&num, sizeof(int), 1, fp);
        printf("%d\n", num);
        fclose(fp);
        return 0;
}