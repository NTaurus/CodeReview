#include<iostream>
#include"../base.h"
using namespace std;
const int maxSize=10000;
int main(){
    int N,*A=new int[maxSize],k;
    cin>>N>>k;
    // A=base::Cin(N);
    for(int i=0;i<k;i++){
        // A[i]=(i*2);
        A[k+i]=i;
        // cout<<A[i]<<' ';
    }
    for(int i=k;i<N;i++){
        // A[i]=((i-k)*2+1);
        A[i-k]=i;
        // cout<<A[i]<<' ';
    }
    // base::Print(A,N);
    int i=0,j=k,p=0;
    while(i<N){
        // cout<<A[i]<<' '<<A[j]<<endl;
        if(A[i]>A[j]){
            base::Print(A,N);
            swap(A[i],A[j]);
            int t=j;
            while(j>i&&A[j]<A[j-1]){//移动A[j]使后半段数组仍有序
                swap(A[j],A[j-1]);
                j--;
                p++;
            }
            // j=t+1;
            base::Print(A,N);
        }
        p++;
        i++;
        // base::Print(A,N);
    }
    cout<<p<<endl;
    // base::Print(A,N);


    return 0;
}