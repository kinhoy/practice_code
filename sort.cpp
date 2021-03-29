#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
void merge(int a[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    int tmp[maxn], index = 0;
    while (i <= r1 && j <= r2)
    {
        if (a[i] <= a[j])
            tmp[index++] = a[i++];
        else
            tmp[index++] = a[j++];
    }
    while (i <= r1)
        tmp[index++] = a[i++];
    while (j <= r2)
        tmp[index++] = a[j++];
    for (int i = 0; i < index; i++)
        a[l1 + i] = tmp[i];
}
void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, mid + 1, right);
    }
}
void mergeSortPlus(int a[], int n)
{
    for (int step = 2; step / 2 <= n; step *= 2)
    {
        for (int i = 1; i <= n; i += step)
        {
            int mid = i + step / 2 - 1;
            //sort(a + i, a + min(i + step - 1, n + 1));
            if (mid + 1 <= n)
                merge(a, i, mid, mid + 1, min(i + step - 1, n));
        }
    }
}

int partition(int a[], int left, int right)
{
    int tmp = a[left];
    while (left < right)
    {
        while (left < right && a[right] > tmp)
            right--;
        a[left] = a[right];
        while (left < right && a[right] <= tmp)
            left++;
        a[right] = a[left];
    }
    a[left] = tmp;
    return left;
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int randPartition(int a[], int left, int right)
{
    int p = (round(1.0 * rand() / RAND_MAX * 50000 + 10000));
    swap(a[p], a[left]);
    int tmp = a[left];
    while (left < right)
    {
        while (left < right && a[right] > tmp)
            right--;
        a[left] = a[right];
        while (left < right && a[right] <= tmp)
            left++;
        a[right] = a[left];
    }
    a[left] = tmp;
    return left;
}
void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int pos = partition(a, left, right);
        quickSort(a, left, pos - 1);
        quickSort(a, pos + 1, right);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        //[a,b] ---- %(b-a+1)+a
        printf("%d ", rand() % 6 + 5);
        //[10000,60000]
        printf("%d ", (int)(round(1.0 * rand() / RAND_MAX * 50000 + 10000)));
    }
    return 0;
}