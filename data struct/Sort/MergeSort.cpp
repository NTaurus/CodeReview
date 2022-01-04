#include <algorithm>
#include <iostream>
using namespace std;
const int maxSize = 100;
// int temp[100];
void MergeSort(int A[], int L, int R)
{
    if (L >= R)
        return;
    int mid = (L + R) / 2;
    MergeSort(A, L, mid);
    MergeSort(A, mid + 1, R);
    int temp[R - L + 1];
    int p = 0, i = L, j = mid + 1;
    while (i <= mid && j <= R)
        temp[p++] = (A[i] < A[j]) ? A[i++] : A[j++];
    while (i <= mid)
        temp[p++] = A[i++];
    while (j <= R)
        temp[p++] = A[j++];
    while (j > L)
        A[--j] = temp[--p];
}

void mergesort(int A[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    mergesort(A, begin, mid);
    mergesort(A, mid + 1, end);
    int *temp = new int[end - begin + 1];
    int i = begin, j = mid + 1, L = 0;
    while (i <= mid && j <= end)
        temp[L++] = (A[i] < A[j]) ? A[i++] : A[j++];
    while (i <= mid)
        temp[L++] = A[i++];
    while (j <= end)
        temp[L++] = A[j++];
    while (j > begin) //开始j=end+1,从后往前复制
        A[--j] = temp[--L];
    // delete []temp;
}
void MergeSort_2_0(int A[], int L, int R)
{
    if (L >= R)
        return;
    int mid = (L + R) / 2;
    MergeSort_2_0(A, L, mid);
    MergeSort_2_0(A, mid + 1, R);
    int temp[R - L + 1], i = L, j = mid + 1, p = 0;
    while (i <= mid && j <= R)
        temp[p++] = (A[i] < A[j]) ? A[i++] : A[j++];
    while (i <= mid)
        temp[p++] = A[i++];
    while (j <= R)
        temp[p++] = A[j++];
    while (j > L)
        A[--j] = temp[--p];
}
int main()
{
    int A[maxSize];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    MergeSort(A, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << ' ';
    }
    return 0;
}