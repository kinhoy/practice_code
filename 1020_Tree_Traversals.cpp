/* 1020 Tree Traversals  */
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> post, in;
map<int, int> level;
void pre(int root, int start, int end, int index)
{
        if (start > end)
                return;
        int i = start;
        while (i < end && in[i] != post[root])
                i++;
        level[index] = post[root];
        pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
        pre(root - 1, i + 1, end, 2 * index + 2);
}
int main()
{
        int n;
        scanf("%d", &n);
        post.resize(n);
        in.resize(n);
        for (int i = 0; i < n; i++)
                scanf("%d", &post[i]);
        for (int i = 0; i < n; i++)
                scanf("%d", &in[i]);
        pre(n - 1, 0, n - 1, 0);
        auto it = level.begin();
        printf("%d", it->second);
        while (++it != level.end())
                printf(" %d", it->second);
        return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// using gg = long long;
// struct BTNode {
//     gg val;
//     BTNode *left, *right;
//     BTNode(gg v, BTNode* l = nullptr, BTNode* r = nullptr) : val(v) {}
// };
// BTNode* buildTree(vector<gg>& post, vector<gg>& in, gg r, gg left, gg right) {
//     if (left > right)
//         return nullptr;
//     gg i = find(in.begin(), in.end(), post[r]) - in.begin();
//     auto root = new BTNode(post[r]);
//     root->left = buildTree(post, in, r - 1 - (right - i), left, i - 1);
//     root->right = buildTree(post, in, r - 1, i + 1, right);
//     return root;
// }
// void levelOrder(BTNode* root) {
//     queue<BTNode*> q;
//     q.push(root);
//     bool space = false;
//     while (not q.empty()) {
//         auto t = q.front();
//         q.pop();
//         cout << (space ? " " : "") << t->val;
//         if (t->left)
//             q.push(t->left);
//         if (t->right)
//             q.push(t->right);
//         space = true;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     gg ni;
//     cin >> ni;
//     vector<gg> post(ni), in(ni);
//     for (gg i = 0; i < ni; ++i) {
//         cin >> post[i];
//     }
//     for (gg i = 0; i < ni; ++i) {
//         cin >> in[i];
//     }
//     levelOrder(buildTree(post, in, ni - 1, 0, ni - 1));
//     return 0;
// }