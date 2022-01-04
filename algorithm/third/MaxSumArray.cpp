#include<iostream>
#include<algorithm>
using namespace std;
//烂代码
const int maxn=100;
int A[maxn][maxn],dp[maxn][maxn];
int m,n;
void Print(int A[][maxn],int m,int n){
    cout<<"`````````````````````"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

int maxSum(){
    for(int i=1;i<=m;i++){
        for(int j=i;j<=n-m+i;j++){
            if(j>i){
                dp[i][j]=dp[i][j-1]+A[j];
                for(int k=i-1;k<j;k++){
                    if(dp[i][j]<dp[i-1][k]+A[j]){
                        dp[i][j]=dp[i-1][k]+A[j];
                    }
                    else 
                        dp[i][j]=dp[i-1][j-1]+A[i][j];
                }
            }
        }
    }
    int sum=0;
    for(int j=m;j<=n;j++){
        sum=max(sum,dp[m][j]);
    }
    return sum;
}

int visit[maxn][maxn];
// int maxSum(){
//     int ans=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(i==0&&j==0)
//                 dp[i][j]=A[i][j];
//             else if(i==0&&j){
//                 if(dp[i][j-1]+A[i][j]>A[i][j])
//                     visit[i][j]=1;
//                 dp[i][j]=max(dp[i][j-1]+A[i][j],A[i][j]);

//                 // dp[i][j]=A[i][j]+dp[i][j-1];
//             }
//             else if(i&&j==0){
//                 if(dp[i-1][j]+A[i][j]>A[i][j])
//                     visit[i][j]=1;
//                 dp[i][j]=max(dp[i-1][j]+A[i][j],A[i][j]);
//                 // dp[i][j]=A[i][j]+dp[i-1][j];
//             }
//             else{
//                 int t=A[i][j];
//                 if(visit[i-1][j]==0&&visit[i][j-1]==0){
//                     dp[i][j]=max(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+A[i][j],A[i][j]);
//                 }
//                 else if(visit[i-1][j]==0){
//                     dp[i][j]=max(dp[])
//                 }
//                 else if(visit[i][j-1]==0){

//                 }
//                 else 
//                 // dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+A[i][j];
//             }
//             ans=max(ans,dp[i][j]);
//         }
//     }
//     Print(dp,m,n);
//     return ans;
// }
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    cout<<maxSum();
    return 0;
}