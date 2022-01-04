#include<iostream>
#include<stdio.h>
#include"../base.h"
using namespace std;
const int maxSize=100;
int maxBit(int A[],int N){
    int maxnum=A[0];
    for(int i=0;i<N;i++)
        maxnum=maxnum<A[i]?A[i]:maxnum;
    int d=0;
    while(maxnum){
        d++;
        maxnum/=10;
    }
    return d;
}

void RadixSort(int A[],int N){
    int d=maxBit(A,N);
    int temp[N];
    int count[10];
    int i,j,k;
    int radix=1;
    for(i=0;i<d;i++){
        for(j=0;j<10;j++)
            count[j]=0;
        for(j=0;j<N;j++){
            k=(A[j]/radix)%10;
            count[k]++;
        }
        for(j=1;j<N;j++)
            count[j]+=count[j-1];
        for(j=N-1;j>=0;j--){
            k=(A[j]/radix)%10;
            temp[count[k]-1]=A[j];
            count[k]--;
        }
        for(j=0;j<N;j++)
            A[j]=temp[j];
        radix*=10;
    }
}
void Rsort(int A[],int N){
    int d=maxBit(A,N);
    int i,j,k;
    int count[10],temp[N];
    int radix=1;
    for(i=0;i<d;i++){
        for(j=0;j<10;j++)
            count[j]=0;
        for(j=0;j<N;j++){
            k=(A[j]/radix)%10;
            count[k]++;
        }           
        for(j=1;j<N;j++)
            count[j]+=count[j-1];
        for(j=N-1;j>=0;j--){
            k=(A[j]/radix)%10;
            temp[count[k]-1]=A[j];
            count[k]--;
        }
        for(j=0;j<N;j++)
            A[j]=temp[j];
        radix*=10;
    }

}
void Print(int A[],int N){
    for(int i=0;i<N;i++){
        printf("%-4d ",A[i]);
    }
    cout<<endl;
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxBit(data, n);//获取最大位数
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        // Print(count,10);
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        // Print(count,10);
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;//获取data[j]属于的桶
            tmp[count[k] - 1] = data[j];
            count[k]--;
            // Print(tmp,n);
        }
        // Print(tmp,n);
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        Print(data,n);
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}
void RadixSort2(int A[],int N){
    int d=maxBit(A,N);
    int temp[N],count[10];
    int i,j,k;
    int radix=1;
    for(int i=0;i<d;i++){
        for(int j=0;j<10;j++)
            count[j]=0;
        for(int j=0;j<N;j++){
            k=(A[j]/radix)%10;
            count[k]++;
        }
        for(int j=1;j<10;j++){
            count[j]=count[j-1]+count[j];
        }
        for(int j=N-1;j>=0;j--){
            k=(A[j]/radix)%10;
            temp[count[k]-1]=A[j];
            count[k]--;
        }
        Print(temp,N);
        for(int j=0;j<N;j++){
            A[j]=temp[j];
        }
        radix*=10;
    }
}


void RadixSort_2_0(int A[],int N){
    int d=maxBit(A,N);
    int temp[N];
    int count[10];
    int radix=1;
    int i,j,k;
    for(j=0;j<d;j++){
        for(i=0;i<10;i++)
            count[i]=0;
        for(i=0;i<N;i++){
            k=(A[i]/radix)%10;
            count[k]++;
        }
        for(i=1;i<10;i++)
            count[i]+=count[i-1];
        for(i=N-1;i>=0;i--){
            k=(A[i]/radix)%10;
            temp[count[k]-1]=A[i];
            count[k]--;
        }
        for(i=0;i<N;i++)
            A[i]=temp[i];
        base::Print(A,N);
        radix*=10;
    }
}


int main(){
    int N,A[maxSize];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    RadixSort_2_0(A,N);
    // Rsort(A,N);
    // cout<<maxBit(A,N)<<' '<<maxbit(A,N);
    for(int i=0;i<N;i++){
        cout<<A[i]<<' ';
    }
    return 0;
}