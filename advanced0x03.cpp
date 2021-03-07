/*
The Advanced Code
 */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
#define Equ(a, b) ((fabs((a) - (b))) < (eps))
#define More(a, b) (((a) - (b)) > (eps))
#define Less(a, b) (((a) - (b)) < (-eps))
#define MoreEqu(a, b) (((a) - (b)) > (-eps))
#define LessEqu(a, b) (((a) - (b)) < (eps))
int main()
{
    int n, m;
    double db;
    cin >> n >> db;
    cout << n << " " << db << endl;
    char str[100] = "world";
    cin.getline(str, 100);
    //string str2;
    //getline(cin, str2);

    cout << "hello"
         << "\n"
         << str << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << 123.4567 << endl;

    if (Equ(db, 1.23))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    double db1 = 4 * asin(sqrt(2.0) / 2); //pi
    double db2 = 3 * asin(sqrt(3.0) / 2); //pi
    if (db1 == db2)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    if (Equ(db1, db2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    // while (scanf("%d%d", &n, &m) != EOF) //while (gets(str) != NULL)
    // {
    //     printf("%d\n", m + n);
    // }
    int T;
    scanf("%d",&T);
    while(T--){
        printf("%d,",T);
    }
    system("pause");
    return 0;
}