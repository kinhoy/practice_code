/*
The Advanced Code
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 10
void bubble();
void print_array(int (*a)[N], int m, int n);
int main()
{
    int d2nums[5][N] = {{2, 1, 3}, {4, 5}, {}, {1, 2, 3, 6, 9}};
    int x = sizeof(d2nums) / sizeof(d2nums[0]);
    int y = sizeof(d2nums[0]) / sizeof(int);
    print_array(d2nums, x, y);
    int a[5] = {1, 2, 3, 4, 5};
    memset(a, -1, sizeof(a));
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n ");
    char str[] = "abcdefg";
    char str1[] = "abcdefgh";
    printf("%d\n ", strlen(str));
    printf("%d\n ", strcmp(str, str1));
    system("pause");
    return 0;
}
void print_array(int (*a)[N], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d,", a[i][j]);
        printf("\n");
    }
}
void bubble()
{
    int nums[N] = {4, 3, 5, 2, 6, 7, 1, 8, 9};
    int len = (sizeof(nums) / sizeof(int));
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                // int temp = nums[j];
                // nums[j] = nums[j + 1];
                // nums[j + 1] = temp;
                nums[j] = nums[j] ^ nums[j + 1];
                nums[j + 1] = nums[j] ^ nums[j + 1];
                nums[j] = nums[j] ^ nums[j + 1];
            }
        }
        for (int i = 0; i < len; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}