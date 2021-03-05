#include <iostream>
#include <stdio.h>
#include <math.h>

//using namespace std;

#define PI 3.14
//const double PI = 3.14;

#define ADD(a, b) ((a) + (b))
#define CALL(x) (x * 2 + 1)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef long long LL;
int main()
{
    int a = 1, b = 1;

    char c1 = 'z', c2 = 'j', c3 = 117;
    printf("%c %c %c\n", c1, c2, c3);
    printf("%d\n", 'z' - 'Z'); //32
    printf("###########################\n");

    char str1[25] = "hello world";
    printf("%s\n", str1);
    printf("###########################\n");

    bool flag1 = 0, flag2 = true;
    printf("%d %d %d\n", flag1, flag2, a == b);
    printf("###########################\n");

    double r = 12.56;
    a = 3, b = 5;
    printf("%d\n", (int)r);
    printf("%d\n", a / b);
    printf("%.1f\n", (double)a / (double)b);
    printf("###########################\n");

    r = 3;
    printf("%f\n", r * r * PI);
    printf("###########################\n");

    int num1 = 3, num2 = 4;
    printf("%d\n", ADD(num1, num2));
    printf("%d\n", CALL(num2 + 1));
    printf("###########################\n");

    int x = 5, y = 4, z = 5, k = 6;
    printf("%f\n", x / y);
    printf("###########################\n");

    a = 1, b = 1;
    int n = a++;
    int o = ++b;
    printf("%d %d\n", n, a);
    printf("%d %d\n", o, b);
    printf("###########################\n");

    int kk = a > b ? 7 : 11;
    printf("%d\n", kk);
    printf("###########################\n");

    printf("%d\n", MAX(4, 54));
    printf("###########################\n");

    const int INF = (1 << 30) - 1;
    printf("%d\n", INF);
    printf("###########################\n");

    // int num;
    // char cc, str2[10];
    // scanf("%d%c%s", &num, &cc, str2);
    // printf("%d|%c|%s\n", num, cc, str2);
    // system("pause");
    // printf("###########################\n");

    float f1 = 8765.4, f2 = 8765.4;
    double d1 = 8765.4, d2 = 8765.4; //opt
    printf("%f\n%f\n", f1 * f2, d1 * d2);
    printf("###########################\n");

    a = 123, b = 1234567;
    d1 = 12.3456;
    printf("%5d\n", a);
    printf("%5d\n", b);
    printf("%05d\n", a);
    printf("%05d\n", b);
    printf("%.2f\n", d1);
    printf("###########################\n");

    /*
    char cc1, cc2, cc3;
    cc1 = getchar();
    getchar();
    cc2 = getchar();
    cc3 = getchar();
    putchar(cc1);
    putchar(cc2);
    putchar(cc3);
    system("pause");
    printf("###########################\n");
    */

    LL llnum = 1234567890123456789;
    printf("%lld\n", llnum);
    printf("###########################\n");

    d1 = -12.35;
    printf("%.2f\n", fabs(d1));
    printf("%f\n", sqrt(2.0));
    printf("%f\n", pow(2.0, 3.0));

    printf("###########################\n");

    int oneNum;

    // do{
    //     scanf("%d", &oneNum);
    //     printf("INPUT\n");
    // }while (oneNum % 2 != 0);

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 1)
            continue;
        printf("%3d", i);
        if (i % 5 == 0)
            printf("\n");
    }
    printf("###########################\n");

    int numbers[10] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", numbers[i]);
    }

    printf("###########################\n");
    system("pause");
    return 0;
}
