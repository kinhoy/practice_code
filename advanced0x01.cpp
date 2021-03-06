/*
The Advanced Code
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

struct student
{
    int id;
    char gender;
    char name[20];
    char major[20];
    student *bestFriend;
    // student(int _id, char _gender)
    // {
    //     id = _id;
    //     gender = _gender;
    // }
    //student(int _id, char _gender) : id(), gender(_gender) {}
} Alice, Bob, stu[10], *pstu;

void fun1(int nums[], int a[][5])
{
    nums[0] = -1;
    a[0][1] = -1;
}
void fun2(int *p)
{
    *p = 111;
}
void fun3(int &x)
{
    x = 1;
}
int main()
{
    char str[] = "abcdefg";
    char str1[] = "abcdefgh";
    char str2[] = "abc";
    char str3[20];
    char str4[50];
    printf("%d\n", strlen(str));
    printf("%d\n", strcmp(str, str1));
    strcpy(str2, str1);
    printf("before cpy:%s\n", str2);
    printf("after cpy :%s\n", str2);
    // gets(str3);
    // gets(str4);
    // puts(str4);
    // strcat(str4,str3);
    // puts(str4);
    int n;
    char str5[100] = "1234";
    sscanf(str5, "%d", &n);
    printf("%d\n", n);
    n = 2333;
    sprintf(str5, "%d", n);
    printf("%s\n", str5);

    int a[10][5] = {0};
    int nums[3] = {0};
    fun1(nums, a);

    printf("%d , %d\n", &n, n);

    //int* p1,p2; // p2 is int
    int *p1, *p2, *p3;
    int num1;
    p1 = &num1, p2 = &n;
    printf("*p2 : %d\n", *p2);
    *p2 = 666;
    printf("*p2 : %d\nn = %d\n", *p2, n);

    int k[10] = {1, 2, 3};
    int *pk = k;
    printf("%d %d %d\n", *pk, *(pk + 1), pk[2]);
    int *pk2 = &k[2];
    printf("%d\n", pk - pk2); //-2
    int q = 123;
    int *pq = &q;
    printf("from %d\n", q);
    fun2(pq);
    printf("to %d\n", q);

    int y = 100;
    printf("from %d\n", y);
    fun3(y);
    printf("to %d\n", y);

    Alice.id = 1;
    pstu = &Alice;
    int id = pstu->id;
    printf("id : %d\n", id);
    system("pause");
    return 0;
}