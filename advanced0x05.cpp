/*
The Advanced Code
 */
#include <iostream>
using namespace std;
template <typename T>
struct Point
{
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
};
template <typename T>
Point<T> operator+(const Point<T> &A, const Point<T> &B)
{
    return Point<T>(A.x + B.x, A.y + B.y);
}
template <typename T>
ostream &operator<<(ostream &out, const Point<T> &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
template <typename T>
T sum(T *begin, T *end)
{
    T ans = 0;
    for (T *p = begin; p != end; p++)
        ans = ans + *p;
    return ans;
}
int main()
{
    double d[] = {1.1, 2.2, 3.3, 4.4};
    cout << sum(d, d + 4) << endl;
    Point<int> a(1, 2), b(3, 4);
    Point<double> c(1.1, 2.2), dp(3.3, 4.4);
    cout << a + b << " " << c + dp << "\n";
    system("pause");
    return 0;
}