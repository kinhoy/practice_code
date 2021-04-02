#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
void insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (root->data > data)
        insert(root->left, data);
    else
        insert(root->right, data);
}
void preOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}
void mpreOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    vi.push_back(root->data);
    mpreOrder(root->right, vi);
    mpreOrder(root->left, vi);
}
void postOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}
void mpostOrder(node *root, vector<int> &vi)
{
    if (root == NULL)
        return;
    mpostOrder(root->right, vi);
    mpostOrder(root->left, vi);
    vi.push_back(root->data);
}
vector<int> nums,preO, mpreO, postO, mpostO;
int main()
{
    int n;
    cin >> n;
    int data;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        nums.push_back(data);
        insert(root, data);
    }
    preOrder(root, preO);
    mpreOrder(root, mpreO);
    if (nums == preO)
    {
        postOrder(root, postO);
        cout << "YES" << endl
             << postO[0];
        for (int i = 1; i < postO.size(); i++)
        {
            cout << " " << postO[i];
        }
    }
    else if (nums == mpreO)
    {
        mpostOrder(root, mpostO);
        cout << "YES" << endl
             << mpostO[0];
        for (int i = 1; i < mpostO.size(); i++)
        {
            cout << " " << mpostO[i];
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}