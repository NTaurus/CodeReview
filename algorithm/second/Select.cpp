#include<iostream>
#include<time.h>
#include<stdio.h>
using namespace std;

// template<class int>
void Swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

//选择排序
// template<class int>
void SelectSort(int a[], int p, int r) {
    for (int i = p; i < r; ++i) {
        int index = i;
        for (int j = i + 1; j <= r; ++j) {
            if (a[j] < a[index])
                index = j;
        }
        Swap(a[i], a[index]);
    }
}

//按x划分，返回划分基准下标
// template<class int>
int Partition(int a[], int p, int r, int x) {
    int i = p - 1, j = r + 1;
    while (true) {
        while (a[++i] < x && i < r);
        while (a[--j] > x && j > p);
        if (i >= j)break;
        Swap(a[i], a[j]);
    }
    return j;
}

//找到中位数（用于找每组的5个数的中位数）
// template<class int>
int SearchMid(int a[], int p, int r) {
    int *b = new int[r - p + 1];
    for (int i = p; i <= r; ++i) {
        b[i - p] = a[i];
    }
    SelectSort(b, 0, r - p);
    for (int i = p; i <= r; ++i) {
        if (a[i] == b[(r - p + 1) / 2])
            return i;
    }
    return 0;
}

//p第一个数下标，r最后一个数下标，k要找的第k个数
// template<class int>
int Select(int a[], int p, int r, int k) {
    //规模小于75时直接排序查找
    if (r - p < 75) {
        SelectSort(a, p, r);
        return a[p + k - 1];
    }
    // for(int i=0;i<100;i++){
    //     printf("%-5d",a[i]);
    // }
    // cout<<endl;
    //分成n/5组，每组5个；找到每组中位数，放置队首
    for (int i = 0; i <= (r - p - 4) / 5; ++i) {
        int mid = SearchMid(a, p + 5 * i, p + 5 * i + 4);
        Swap(a[mid], a[p + i]);
    }
    //找到所有中位数的中位数
    int x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10 + 1);
    //按中位数划分
    int i = Partition(a, p, r, x), j = i - p + 1;
    if (k <= j)return Select(a, p, i, k);
    else return Select(a, i + 1, r, k - j);
}

int main(){
    int A[1000];
    srand(unsigned(time(NULL)));
    int N=100;
    for(int i=0;i<N;i++){
        A[i]=rand()%1000;
    }
    cout<<"```"<<Select(A,0,N,78);
    return 0;
}

// int slect(int A[],int p,int r,int k){
//     if(r-p<75){
//         // 使用简单排序算法堆数组A[p:r]排序
//         return A[p+k-1];
//     }
//     for(int i=0;i<(r-p-4)/5;i++){
//         //将A[p+5*i]到A[p+5*i+4]的第3小元素与A[p+i]交换位置
//         // 找中位数的中位数，r-p-4即使上面所说的n-5
//         int x=select(a,p,p+(r-p-4)/5,(r-p-4)/10);
//         int i=Partition(a,p,r,x);
//         int j=i-p+i;
//         if(k<=j)
//             return select(A,p,i,k);
//         else return select(A,i+1,r,k-j);
//     }
// }