#include <bits/stdc++.h>
using namespace std;
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
int getImportance(vector<Employee *> employees, int id)
{
    queue<Employee *> q;
    int sum = 0;
    int i = 0;
    for (; i < employees.size(); i++)
    {
        if (employees[i]->id == id)
            break;
    }
    q.push(employees[i]);
    while (!q.empty())
    {
        Employee *e = q.front();
        q.pop();
        sum += e->importance;
        for (int i = 0; i < e->subordinates.size(); i++)
        {
            int j = 0;
            for (; j < employees.size(); j++)
            {
                if (employees[j]->id == e->subordinates[i])
                    break;
            }
            q.push(employees[j]);
        }
    }
    return sum;
}