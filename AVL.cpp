#include <bits/stdc++.h>
using namespace std;
struct node
{
    int v;                 //结点权值
    int height;            //当前子树的高度
    node *lchild, *rchild; //左右孩子结点地址
};
node *newNode(int v)
{
    node *Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
}
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int getBalanceFactor(node *root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(node *root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void search(node *root, int x)
{
    if (root == NULL)
    {
        printf("search failed\n");
        return;
    }
    if (x == root->v)
        printf("%d\n", x);
    else if (x < root->v)
        search(root->lchild, x);
    else
        search(root->rchild, x);
}
//左旋
void L(node *&root)
{
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
//右旋
void R(node *&root)
{
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void insert(node *&root, int v)
{
    if (root == NULL)
    {
        root = newNode(v);
        return;
    }
    if (v < root->v)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2)
        {
            if (getBalanceFactor(root->lchild) == 1) //LL
            {
                R(root);
            }
            else if (getBalanceFactor(root->lchild) == -1) //LR
            {
                L(root->lchild);
                R(root);
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        if (getBalanceFactor(root) == -2)
        {
            if (getBalanceFactor(root->rchild) == -1) //RR
            {
                L(root);
            }
            else if (getBalanceFactor(root->rchild) == -1) //LR
            {
                R(root->rchild);
                L(root);
            }
        }
    }
}
node *Create(int data[], int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}
int main()
{
    int a[] = {1, 2, 3, 4, 51, 3, 5};
    node *AVL_tree = Create(a, 7);
    int n;
    while (cin >> n && n != 0)
    {
        search(AVL_tree, n);
    }
    system("pause");
    return 0;
}