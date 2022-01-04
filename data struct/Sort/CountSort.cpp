#include<iostream>
using namespace std;
const int maxSize=100;
void countSort(int A[],int N,int maxnum){
    int hash[maxnum+1];
    for(int i=0;i<=maxnum;i++)
        hash[i]=0;
    for(int i=0;i<N;i++){
        hash[A[i]]++;
    }
    int p=0;
    for(int i=0;i<=maxnum;i++){
        while(hash[i]){
            A[p++]=i;
            hash[i]--;
        }
    }
}
int main(){
    int N,A[maxSize],maxnum=-1;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        maxnum=maxnum<A[i]?A[i]:maxnum;
    }
    countSort(A,N,maxnum);
    for(int i=0;i<N;i++){
        cout<<A[i]<<' ';
    }
    return 0;
}