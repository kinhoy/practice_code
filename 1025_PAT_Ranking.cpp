#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
struct Stu
{
    string id;
    int score;
    int local_n;
    int local_rank;
} Student[30001];
bool cmp(Stu a, Stu b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id.compare(b.id) < 0;
}
int main()
{
    int n, total = 0, score, r;
    string id;
    cin >> n;
    for (int p = 1; p <= n; p++)
    {
        r = 1;
        int local, sum;
        cin >> local;
        sum = total + local;
        for (int i = total; i < sum; i++)
        {
            cin >> id >> score;
            Student[i].id = id;
            Student[i].score = score;
            Student[i].local_n = p;
        }
        sort(Student + total, Student + sum, cmp);
        Student[total].local_rank = r++;
        for (int k = total + 1; k < sum; k++)
        {
            if (Student[k].score == Student[k - 1].score)
                Student[k].local_rank = Student[k - 1].local_rank;
            else
                Student[k].local_rank = r;
            r++;
        }
        total = sum;
    }
    r = 1;
    sort(Student, Student + total, cmp);
    cout << total << endl;
    cout << Student[0].id << " " << r << " " << Student[0].local_n << " " << Student[0].local_rank << endl;
    for (int i = 1; i < total; i++)
    {
        if (Student[i].score != Student[i - 1].score)
            r = i + 1;
        cout << Student[i].id << " " << r << " " << Student[i].local_n << " " << Student[i].local_rank << endl;
    }
    return 0;
}