// #include <iostream>
// int main()
// {
//     int n, t, e = 0;
//     while (scanf("%d", &n) != EOF)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d", &t);
//             if (t % 2 == 0)
//                 e++;
//         }
//         if (e > n / 2)
//             printf("NO\n");
//         else
//             printf("YES\n");
//     }
//     return 0;
// }
// #include <iostream>
// #define MAX 0x7FFFFFFF
// int main()
// {
//     int n,x=MAX,y=MAX,tx,ty;
//     while(scanf("%d",&n)!=EOF)
//     {
//         for (int i=0;i<n;i++)
//         {
//             scanf("%d %d",&tx,&ty);
// 			if(tx<x)
// 			{
// 				x=tx;
// 				y=ty;
// 			}else if(tx==x&&ty<y){
// 				y=ty;
// 			}
//         }
//         printf("%d %d\n",x,y);
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int t,res = 0;
        priority_queue<int,vector<int>,greater<int>> queue;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            queue.push(t);
        }
        while(queue.size()>1)
        {
            int a = queue.top();
            queue.pop();
            int b = queue.top();
            queue.pop();
            queue.push(a+b);
            res+=a+b;
        }
        cout<<res<<endl;   
    }
    return 0;
}