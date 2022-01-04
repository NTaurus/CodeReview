#include <algorithm>
#include <iostream>
using namespace std;
class JOB
{
public:
    int key, index;
    bool job;
};
bool cmp(JOB a, JOB b)
{
    return a.key < b.key;
}
int func(int n, int a[], int b[], int c[])
{
    int i, j, k;
    JOB *d = new JOB[n];
    for (i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            d[i].job = true;
            d[i].key = a[i];
        }
        else
        {
            d[i].job = false;
            d[i].key = b[i];
        }
        d[i].index = i;
    }
    sort(d, n + d, cmp);
    j = 0, k = n - 1;
    for (i = 0; i < n; i++)
    {
        if (d[i].job == true)
            c[j++] = d[i].index;
        else
            c[k--] = d[i].index;
    }
    j = a[c[0]];
    k = j + b[c[0]];
    for (i = 1; i < n; i++)
    {
        j = j + a[c[i]];
        k = j < k ? k + b[c[i]] : j + b[c[i]];
    }
    delete d;
    return k;
}
int main()
{
    int i, n, m, a[100], b[100], c[100];
    cin >> n;
    while (n--)
    {
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> a[i];
            cin >> b[i];
        }
        cout << func(m, a, b, c) << endl;
    }
    return 0;
}
/*
1
7
5 2
3 4
6 7
4 2
8 9
9 7
6 3
*/