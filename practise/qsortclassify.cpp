#include<iostream>
#include"../base.h"
using namespace std;
void solve(int *A,int N){
    int i=0,j=N-1;
    while(i<j){
        while(i<j&&A[j]>=0)j--;
        while(i<j&&A[i]<0)i++;
        int t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    base::Print(A,N);
}
int main(){
    int N;
    cin>>N;
    int *A=base::Cin(N);
    solve(A,N);
    return 0;
}