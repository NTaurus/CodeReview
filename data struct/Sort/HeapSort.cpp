#include<iostream>
#include"../base.h"
using namespace std;
const int maxSize=100;
void heapBuild(int A[],int x,int &L){
    A[L]=x;
    for(int i=L;i>1;i/=2){
        if(A[i/2]>x){
            swap(A[i/2],A[i]);
        }
        else break;
    }
    L++;    
}
//大顶堆排序出来时升序
void max_heapify(int A[],int start,int end){
    int dad=start;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&A[son]<A[son+1])
            son++;
        if(A[dad]>A[son])
            return;
        else{
            swap(A[dad],A[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}
void heapify(int A[],int start,int end){
    int dad=start;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&A[son]<A[son+1])
            son++;
        if(A[son]<A[dad])
            return;
        else{
            swap(A[dad],A[son]);
            dad=son;
            son=son*2+1;
        }
    }
}
//小顶堆排序出来时降序
void min_heapify(int A[],int start,int end){
    int dad=start;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&A[son]>A[son+1]){
            son++;
        }
        if(A[son]>A[dad])return;
        else{
            swap(A[dad],A[son]);
            dad=son;
            son=son*2+1;
        }
    }
}
void Printf(int A[],int N){
    cout<<"```````````````\n";
    for(int i=0;i<N;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
// 升序用最大堆，降序用最小堆
void Min_heapify(int A[],int start,int end){
    int dad=start;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&A[son]<A[son+1]){
            son++;
        }
        if(A[son]<A[dad])return ;
        else {
            swap(A[dad],A[son]);
            dad=son;
            son=son*2+1;
        }
    }
    Printf(A,10);
}
void Max_heapify(int A[],int start,int end){
    int dad=start;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&A[son]<A[son+1])
            son++;
        if(A[son]<A[dad])return;
        else{
            swap(A[dad],A[son]);
            dad=son;
            son=son*2+1;
        }
    }
}
void HeapSort(int A[],int L){
    for(int i=L/2-1;i>=0;i--){
        Max_heapify(A,i,L-1);
    }
    Printf(A,L);
    for(int i=L-1;i>=0;i--){
        swap(A[i],A[0]);
        Max_heapify(A,0,i-1);
    }
    Printf(A,L);
}
void heapSort(int A[],int L){
    for(int i=L/2-1;i>=0;i--){
        Min_heapify(A,i,L-1);
    }
    // for(int i=0;i<L;i++){
    //     cout<<A[i]<<' ';
    // }
    // cout<<endl;
    for(int i=L-1;i>0;i--){
        swap(A[0],A[i]);
        Min_heapify(A,0,i-1);
    }
}

void Heapfy_2_0(int *A,int L,int R){
    int dad=L;
    int son=dad*2+1;
    while(son<=dad){
        if(son+1<R&&A[son]<A[son+1])
            son++;
        if(A[son]<A[dad])
            return;
        else{
            swap(A[son],A[dad]);
            dad=son;
            son=son*2+1;
        }
    }
}

void HeapSort_2_0(int *A,int N){
    for(int i=N/2-1;i>=0;i--){
        Heapfy_2_0(A,i,N-1);
    }
    base::Print(A,N);
    for(int i=N-1;i>=0;i--){
        swap(A[0],A[i]);
        Heapfy_2_0(A,0,i);
    }
}


void Heapfy_3_0(int A[],int L,int R){
    int dad=L;
    int son=dad*2+1;
    while(son<=R){
        if(son+1<=R&&A[son]<A[son+1])
            son++;
        if(A[son]<A[dad])return ;
        else{
            swap(A[son],A[dad]);
            dad=son;
            son=son*2+1;
        }
    }
}

void HeapSort_3_0(int *A,int N){
    for(int i=N/2-1;i>=0;i--){
        Heapfy_3_0(A,i,N-1);
    }
    for(int i=N-1;i>=0;i--){
        swap(A[0],A[i]);
        Heapfy_3_0(A,0,i-1);
    }
}

void Heapfy_4_0(int A[],int begin,int end){
    int dad=begin;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&A[son]>A[son+1])
            son++;
        if(A[son]>A[dad])return ;
        else{
            swap(A[son],A[dad]);
            dad=son;
            son=son*2+1;
        }
    }
}
void HeapSort_4_0(int A[],int N){
    for(int i=N/2-1;i>=0;i--){
        Heapfy_4_0(A,i,N-1);
    }
    base::Print(A,N);
    for(int i=N-1;i>=0;i--){
        swap(A[0],A[i]);
        Heapfy_4_0(A,0,i-1);
        base::Print(A,N);
    }
}
int main(){
    int A[maxSize];
    int L=1,N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        A[i]=x;
        // heapBuild(A,x,L);
    }
    // HeapSort(A,N);
    HeapSort_4_0(A,N);
    base::Print(A,N);
    return 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// void max_heapify(int arr[], int start, int end) {
//     // 建立父節點指標和子節點指標
//     int dad = start;
//     int son = dad * 2 + 1;
//     while (son <= end) { // 若子節點指標在範圍內才做比較
//         if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
//             son++;
//         if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
//             return;
//         else { // 否則交換父子內容再繼續子節點和孫節點比較
//             swap(arr[dad], arr[son]);
//             dad = son;
//             son = dad * 2 + 1;
//         }
//     }
// }

// void heap_sort(int arr[], int len) {
//     // 初始化，i從最後一個父節點開始調整
//     for (int i = len / 2 - 1; i >= 0; i--)
//         max_heapify(arr, i, len - 1);
//     // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
//     for (int i = len - 1; i > 0; i--) {
//         swap(arr[0], arr[i]);
//         max_heapify(arr, 0, i - 1);
//     }
// }

// int main() {
//     int arr[] = {8,5,2,6,3,1,9,4,7,10};
//     int len = (int) sizeof(arr) / sizeof(*arr);
//     heap_sort(arr, len);
//     for (int i = 0; i < len; i++)
//         cout << arr[i] << ' ';
//     cout << endl;
//     return 0;
// }