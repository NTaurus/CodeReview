#include<iostream>
using namespace std;
const int maxn=100;
string a,b;
// int dp[maxn][maxn];
/*
状态转移方程
dp[i][j]={
    0                                     i=0||j=0||a[i]!=a[j]
    1                                     a[i]==b[j]&&a[i-1]!=b[i-1]&&i>0&&j>0
    dp[i-1][j-1]+1                        a[i]==b[j]&&a[i-1]==b[j-1]&&i>0&&j>0
}

dp[i][j]={
    0                                     i=0||j=0||a[i]!=a[j]
    dp[i-1][j-1]+1                        a[i]==b[j]&&a[i-1]==b[j-1]&&i>0&&j>0
}
*/
/*
    本算法时间复杂度为O(m*n),空间复杂度为O(m*n)
    如果仅仅只求最长连续公共子序列的长度，那么可以优化空间复杂度

    分析dp数组可知道，dp[i]数组的值最多依赖与dp[i-1]数组的值
    因此，可以将dp二维数组降成一维数组
    优化后的空间复杂度为O(max(m,n))

*/
int dp[maxn][maxn];
int LCCS(string a,string b){
    int m=a.size(),n=b.size(); 
    int ans=0;
    for(int i=1;i<a.size();i++){
       for(int j=1;j<b.size();j++){
            dp[i][j]=0;
            if(a[i]==b[j]&&i&&j)
                dp[i][j]=dp[i-1][j-1]+1;
        //    if(a[i]==b[j]){
        //        if(i>0&&j>0&&a[i-1]==b[j-1])
        //             dp[i][j]=dp[i-1][j-1]+1;
        //         else
        //             dp[i][j]=1;
        //    }
           ans=max(ans,dp[i][j]);
       }
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            printf("%-2d ",dp[i][j]);
        }
        cout<<endl;
    }
    return ans;
}
int main(){
    cin>>a>>b;
    cout<<LCCS(a,b);
    return 0;
}