#include<iostream>
#include"../base.h"
using namespace std;
void Print(int *A,int N){
    for(int i=0;i<N;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
void SelectSort(int *A,int N){
    for(int i=0;i<N;i++){
        int index=i;
        for(int j=i+1;j<N;j++){
            if(A[j]<A[index]){
                index=j;
            }
        }
        int temp=A[index];
        A[index]=A[i];
        A[i]=temp;
        printf("swap(%d,%d)\n",A[i],A[index]);
        // Print(A,N);
        base::Print(A,N);
    }
}

int main(){
    int *A,N,M,B[100][100];
    cin>>N;
    A=base::Cin(N);
    SelectSort(A,N);
    // base::Cin(B,N,M);
    // base::Print(B,N,M);
    // A=base::Cin(N);
    // SelectSort(A,N);
    // base::Print(A,N);
    
    return 0;
}