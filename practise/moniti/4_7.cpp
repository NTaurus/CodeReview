#include<iostream>
#include"../base.h"
using  namespace std;
int dp[maxn];
int solve(int *nums,int N,int s){
    if(s>=N)return -1;
    if(s==N-1)return 1;
    if(dp[s])return dp[s];
    int is=-1;
    for(int i=1;i<=nums[s];i++){
        int res=solve(nums,N,s+i);
        is=(res==1)?1:-1;
        if(is==1)break;
    }
    dp[s]=is;
    return dp[s];
}
int main(){ 
    int N;
    cin>>N;
    int *nums=base::Cin(N);
    cout<<solve(nums,N,0);
    return 0;
}