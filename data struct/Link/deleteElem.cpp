#include<iostream>
#include"../base.h"
using namespace std;
void Del_x(int *A,int &N,int S,int T){
    
    int k=0;
    for(int i=0;i<N;i++){
        if(A[i]<S||A[i]>T){
            A[i-k]=A[i];
        }
        else k++;
    }
    N-=k;
}
void Del_x_2(int *A,int &N,int x){
    int k=0;
    for(int i=0;i<N;i++){
        if(A[i]!=x)
            A[i-k]=A[i];
        else 
            k++;
    }
    N-=k;
}
int main(){
    int N,*A,S,T;
    cin>>N>>S>>T;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    Del_x(A,N,S,T);
    // Del_x_2(A,N,1);
    base::Print(A,N);
    return 0;
}