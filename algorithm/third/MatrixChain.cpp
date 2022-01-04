#include <iostream>
using namespace std;
/*
m[i][j]可以递归定义为：
 m[i][j]=  {
            0,                                      i=j
            min(m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[k]),  i<j
                }
*/
const int maxSize = 100;
void Print(int m[][maxSize], int n)
{
    cout << "````````````````````````````````````````\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%-6d ", m[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
void MatrixChain(int p[], int n, int m[][maxSize], int s[][maxSize])
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++)
    { //分割长度从2开始
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j]; //(A1*A2*A3)=(A1*A2)*A3=m[1][2]+p
            s[i][j] = i;                                    //[1:3]=1再中间分开
            for (int k = i + 1; k < j; k++)
            {                                                           //看i~j之间是否可分，若可分则枚举分割位置k
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; //注意这里是p[k]
                if (t < m[i][j])
                { //如果在k位置分割乘的次数更少，则更新m[i][j]
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
        Print(m, n);
        Print(s, n);
    }
}
void MC(int p[], int n, int m[][maxSize], int s[][maxSize])
{
    for (int i = 0; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = r + i - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}
void TraceBack(int i, int j, int s[][maxSize])
{
    if (i == j)
        return;
    cout << "(A" << i;
    TraceBack(i, s[i][j], s);
    TraceBack(s[i][j] + 1, j, s);
    cout << ")";
    // cout<<"Multiply A"<<i<<","<<s[i][j];
    // cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
}

int dfs(int i, int j, int m[][maxSize], int s[][maxSize], int p[])
{
    if (m[i][j] > 0)
        return m[i][j];
    if (i == j)
        return 0;
    int u = dfs(i, i, m, s, p) + dfs(i + 1, j, m, s, p) + p[i - 1] * p[i] * p[j];
    s[i][j] = i;
    for (int k = i + 1; k < j; i++)
    {
        int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (t < u)
        {
            u = t;
            s[i][j] = k;
        }
    }
    m[i][j] = u;
    return u;
}

int LookupChain(int i, int j, int m[][maxSize], int s[][maxSize], int p[])
{
    if (m[i][j] > 0)
        return m[i][j];
    if (i == j)
        return 0;
    int u = LookupChain(i, i, m, s, p) + LookupChain(i + 1, j, m, s, p) + p[i - 1] * p[i] * p[j];
    s[i][j] = i;
    for (int k = i + 1; k < j; k++)
    {
        int t = LookupChain(i, k, m, s, p) + LookupChain(k + 1, j, m, s, p) + p[i - 1] * p[k] * p[j];
        if (t < u)
        {
            u = t;
            s[i][j] = k;
        }
    }
    m[i][j] = u;
    return u;
}
int MemoizedMatrixChain(int n, int m[][maxSize], int s[][maxSize], int p[])
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    return dfs(1, n, m, s, p);
}

int MatrixChain_2_0(int p[], int n, int m[][maxSize], int s[][maxSize])
{
    for (int i = 0; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > t)
                {
                    m[i][j] = t;
                }
            }
        }
    }
    Print(m, n);
    return m[1][n];
}
int MatrixChain_3_0(int p[], int n, int m[][maxSize], int s[][maxSize])
{
    for (int i = 0; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > t)
                {
                    m[i][j] = t;
                }
            }
        }
    }
    return m[1][n];
}

void MatrixChain_4_0(int p[], int n, int m[][maxSize])
{
    for (int i = 0; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for (int k = i + 1; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                m[i][j] = min(m[i][j], t);
            }
        }
    }
}

int main()
{
    int m[maxSize][maxSize];
    int s[maxSize][maxSize];
    int p[maxSize + 1]; // pi是Ai的列数，pi-1表示Ai的行数
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    // MC(p,n,m,s);
    MatrixChain(p, n, m, s);
    // MatrixChains_4_0(p,n,m);
    Print(m, n);
    // cout<<m[1][n]<<endl;
    TraceBack(1, 6, s);
    // cout<<MemoizedMatrixChain(n,m,s,p);
    return 0;
}
