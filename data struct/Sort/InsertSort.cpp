#include <iostream>
using namespace std;
void Print(int *A, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;
}
int a, b, c, d;
void InsertSort(int *A, int N)
{
    for (int i = 1; i < N; i++)
    {
        int x = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] > x; j--)
        {
            A[j + 1] = A[j];
            a++;
        }
        A[j + 1] = x;
        // Print(A,N);
    }
}
void ShellSort(int *A, int N)
{
    int k = 0, p = 2, gap;
    for (gap = N / p; gap > 0; gap /= p)
    {
        if (gap < p)
            gap = 1;
        cout << "当前躺数为:" << ++k << "增量为：" << gap << endl;
        for (int i = gap; i < N; i += gap)
        {
            int x = A[i];
            int j = i - gap;
            for (; j >= 0 && A[j] > x; j -= gap)
            {
                A[j + gap] = A[j];
                b++;
            }
            A[j + gap] = x;
        }
        if (gap == 1)
            return;
    }
}
void shellsort(int *A, int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += gap)
        {
            int x = A[i];
            int j = i - gap;
            for (; j >= 0 && A[j] > x; j -= gap)
            {
                A[j + gap] = A[j];
            }
            A[j + gap] = x;
        }
    }
}

//利用二分查找，找到将要插入元素所在的位置，复杂度O(log2N)
int BSearch(int A[], int L, int R, int x)
{
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (A[mid] > x)
            R = mid - 1;
        else
            L = mid + 1;
    }
    return L;
}

void BSInsert(int A[], int N)
{
    for (int i = 1; i < N; i++)
    {
        int index = BSearch(A, 0, i - 1, A[i]);
        // cout<<A[i]<<' '<<index<<endl;
        int t = A[i];
        for (int j = i; j > index; j--)
        {
            c++,
            A[j] = A[j - 1];
        }
        A[index] = t;
    }
}
// 折半插入排序，一般是将新元素以"插入排序"的方式插入到有序的序列中
//由于原序列已经有序，因此，为了找到新元素，插入到序列中的位置i，可采用二分查找
//的方式O(logN),再将[i,N-1]的元素向后移动一个位置，最后将新元素插入位置i即可
//有个屁的效率改进，二分找位置，该移动的步数，一个也别想省
//又不是链表，是链表也二分不了
void BSInsert_2_0(int A[], int &N, int x)
{
    int index = BSearch(A, 0, N - 1, x);
    int t = A[N - 1], i;
    // for(i=N;i>=1&&x<A[i-1];i--){
    for (i = N; i > index; i--)
    {
        A[i] = A[i - 1];
        d++;
    }
    // A[i]=x;
    A[index] = x;
    N++;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int N, L = 0;
    cin >> N;
    int *B = new int[1000];
    int *A = new int[1000];
    int *C = new int[1000];
    int *D = new int[1000];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        BSInsert_2_0(D, L, D[i]);
    }
    InsertSort(A, N);
    ShellSort(B, N);
    // Print(B,N);
    // shellsort(B,N);
    // cout<<a<<' '<<b;
    //折半插入排序
    BSInsert(C, N);
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    // Print(A,N);
    // Print(B,N);
    // Print(C,N);
    Print(D, N);
    // Print(A,N);
    // BSInsert_2_0(A,N,100);
    // Print(A,N);
    // Print(C,L);
    return 0;
}