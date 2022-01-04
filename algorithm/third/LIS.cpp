#include<iostream>
using namespace std;
const int maxn=100005;
int dp[maxn];
int arr[maxn],N;
void print(int a[],int n){
    cout<<"`````````````````\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int Dp(){
    int ans=0;
    dp[0]=1;
    for(int i=1;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<endl;
    return ans;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<Dp();
    return 0;
}