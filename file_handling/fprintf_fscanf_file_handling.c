#include <stdio.h>
int main()
{
        FILE *fp;
        fp = fopen("numbers.txt", "w");
        if(fp == NULL)
        {
                perror("Error ");
                return -1;
        }
        int num1, num2, num3, num4, num5;
        printf("Enter 5 Numbers : ");
        scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
        fprintf(fp, "%d %d %d %d %d", num1, num2, num3, num4, num5);
        fclose(fp);
        fp = fopen("numbers.txt", "r");
        fscanf(fp, "%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
        printf("%d %d %d %d %d\n", num1, num2, num3, num4, num5);
        fclose(fp);
        return 0;
}