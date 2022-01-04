#include "../base.h"
#include <iostream>
using namespace std;

const int N = 10;

void MNS(int C[], int n, int **size);
void Traceback(int C[], int **size, int n, int Net[], int &m);
void MNS_4_0(int C[], int n, int **size);
void MNS_5_0(int C[], int n, int **size){
    for(int i = 0; i < C[1]; i++)
        size[1][i] = 0;
    for(int i = C[1]; i <= n; i++)
        size[1][i] = 1;
    for(int i = 2; i < n; i++){
        for(int j = 0; j < C[i]; j++)
            size[i][j] = size[i-1][j];
        for(int j = C[i]; j <= n; j++)
            size[i][j] = max(size[i-1][j], size[i-1][C[i] - 1] + 1);
    }
    size[n][n] = max(size[n - 1][n], size[n-1][C[n - 1] - 1] + 1);
}
int main()  
{
    int c[] = {0, 8, 7, 4, 2, 5, 1, 9, 3, 10, 6}; //下标从1开始
    int **size = new int *[N + 1];

    for (int i = 0; i <= N; i++)
    {
        size[i] = new int[N + 1];
    }

    MNS_5_0(c, N, size);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
            cout << size[i][j] << ' ';
        cout << endl;
    }
    cout << "电路布线最大不相交连线数目为：" << size[N][N] << endl;

    int Net[N], m;
    Traceback(c, size, N, Net, m);

    cout << "最大不相交连线分别为：" << endl;
    for (int i = m - 1; i >= 0; i--)
    {
        cout << "(" << Net[i] << "," << c[Net[i]] << ") ";
    }
    cout << endl;
    return 0;
}

void MNS(int C[], int n, int **size)
{
    //初始化，C[1]之前的线都是为无效边
    for (int j = 0; j < C[1]; j++)
    {
        size[1][j] = 0;
    }
    // C[1]之后,的线都是有效边
    for (int j = C[1]; j <= n; j++)
    {
        size[1][j] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < C[i]; j++)
        {
            size[i][j] = size[i - 1][j]; //当i<c[i]的情形
        }
        for (int j = C[i]; j <= n; j++)
        {
            //当j>=c[i]时，考虑(i，c[i])是否属于MNS(i,j)的两种情况
            size[i][j] = max(size[i - 1][j], size[i - 1][C[i] - 1] + 1);
        }
    }
    size[n][n] = max(size[n - 1][n], size[n - 1][C[n] - 1] + 1);
}

void MNS_2_0(int **size, int n, int C[])
{
    for (int i = 0; i < C[1]; i++)
        size[1][i] = 0;
    for (int j = C[1]; j <= n; j++)
        size[1][j] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < C[i]; j++)
        {
            size[i][j] = size[i - 1][j];
        }
        for (int j = C[i]; j <= n; j++)
            size[i][j] = max(size[i - 1][j], size[i - 1][C[i] - 1] + 1);
    }
    size[n][n] = max(size[n - 1][n], size[n - 1][C[n] - 1] + 1);
}
void MNS_2_0(int C[], int n, int **size)
{
    for (int i = 0; i < C[1]; i++)
        size[1][i] = 0;
    for (int i = C[1]; i <= n; i++)
        size[1][i] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < C[i]; j++)
            size[i][j] = size[i - 1][j];
        for (int j = C[i]; j <= n; j++)
            size[i][j] = max(size[i - 1][j], size[i - 1][C[i] - 1] + 1);
    }
    size[n][n] = max(size[n - 1][n], size[n - 1][C[n] - 1] + 1);
}
void MNS_3_0(int C[], int n, int **size)
{
    for (int i = 0; i < C[1]; i++)
        size[1][i] = 0;
    for (int i = 0; i <= n; i++)
        size[1][i] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < C[i]; j++)
            size[i][j] = size[i - 1][j];
        for (int j = C[i]; j <= n; j++)
            size[i][j] = max(size[i - 1][j], size[i - 1][C[i] - 1] + 1);
    }
    size[n][n] = max(size[n - 1][n], size[n - 1][C[n] - 1] + 1);
}
void MNS_4_0(int C[], int n, int **size)
{
    for (int i = 0; i < C[1]; i++)
        size[1][i] = 0;
    for (int i = C[1]; i <= n; i++)
        size[1][i] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < C[i]; j++)
            size[i][j] = size[i - 1][j];
        for(int j = C[i]; j <= n; j++)
            size[i][j] = max(size[i - 1][j], size[i - 1][C[i] - 1] + 1);
    }
    size[n][n] = max(size[n - 1][n], size[n - 1][C[n] - 1] + 1);
}

void Traceback(int C[], int **size, int n, int Net[], int &m)
{
    int j = n;
    m = 0;
    for (int i = n; i > 1; i--)
    {
        if (size[i][j] != size[i - 1][j]) //此时，（i,c[i])是最大不相交子集的一条边
        {
            Net[m++] = i;
            j = C[i] - 1; //更新扩展连线柱区间
        }
    }
    if (j >= C[1]) //处理i=1的情形
    {
        Net[m++] = 1;
    }
}