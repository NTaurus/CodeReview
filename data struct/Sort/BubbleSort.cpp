#include<iostream>
#include<algorithm>
#include"../base.h"
using namespace std;
void TwoBubbleSort(int *A,int N){
    for(int i=0;i<N;i++){
        bool flag=false;
        for(int j=1,k=N-1;j<N-i;j++,k--){
            if(A[j]<A[j-1]){
                int t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
                flag=true;
            }
            if(A[k]<A[k-1]){
                int t=A[k];
                A[k]=A[k-1];
                A[k-1]=t;
                flag=true;
            }
        }
        if(flag==false)
            break;
        cout<<"第"<<i+1<<"躺：\n";
        base::Print(A,N);
    }
}
void BubbleSort(int *A,int N){
    for(int i=0;i<N;i++){
        for(int j=1;j<N-i;j++){
            if(A[j-1]<A[j]){
                int t=A[j-1];
                A[j-1]=A[j];
                A[j]=t;
            }
        }
        base::Print(A,N);
    }
}
int main(){
    int N,M;
    cin>>N;
    int *A=base::Cin(N);
    base::Print(A,N);
    // TwoBubbleSort(A,N);
    BubbleSort(A,N);
    return 0;
}