#include<iostream>
using namespace std;
const int maxn=100;
int arr[maxn],N;
int dp[maxn];
void print(int a[],int n){
    cout<<"`````````````````\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int Dp(){
    int maxL=0;
    dp[0]=1;
    for(int i=1;i<N;i++){
        dp[i]=1;
        if(arr[i]>arr[i-1]){
            dp[i]+=dp[i-1];
        }
        maxL=maxL<dp[i]?dp[i]:maxL;
    }
    print(dp,N);
    return maxL;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<Dp();  
    return 0;
}