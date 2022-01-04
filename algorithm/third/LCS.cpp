#include<iostream>
#include<string.h>
#include<string>
#include"../base.h"
using namespace std;

/*
构造c表
c[i][j] ={  
            0                           i=0||j=0
            c[i-1][j-1]+1               x[i]==y[j],i>0,j>0
            max(c[i-1][j],c[i][j-1])    x[i]!=y[j],i>0,j>0
*/
int c[maxn][maxn];
char X[maxn]="#ABCBDAB";//书上的写法第一位元素不属于序列元素
char Y[maxn]="#BDCABA";
void Print(int m[][maxn],int x,int y){
    cout<<"`````````````````````\n";
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            printf("%-2d ",m[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
int b[maxn][maxn];
void LCSLength(char X[],int m,char Y[],int n,int c[][maxn]){
    for(int i=0;i<=n;i++)
        c[i][0]=0;
    for(int i=0;i<=m;i++)
        c[0][i]=0;
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i]==Y[j]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            // else if(c[i-1][j]>=c[i][j-1]){
            //     c[i][j]=c[i-1][j];
            //     b[i][j]=2;
            // }
            // else{
            //     c[i][j]=c[i][j-1];
            //     b[i][j]=3;
            // }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
                b[i][j]=(c[i-1][j]>c[i][j-1])?2:3;
            }
            ans=max(ans,c[i][j]);
        }
    }
    // cout<<ans;
}
char S[maxn];
void LCS(int i,int j,char x[]){
    if(i==0||j==0)return;
    if(b[i][j]==1){
        LCS(i-1,j-1,x);
        cout<<x[i]<<' '<<i<<' ';
        // cout<<x[i];
    }
    else if(b[i][j]==2){
        LCS(i-1,j,x);
    }
    else LCS(i,j-1,x);
}

int LCS_2_0(char X[],int n,char Y[],int m,int c[][maxn]){
    for(int i=0;i<n;i++)
        c[i][0]=0;
    for(int i=0;i<m;i++)
        c[0][i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i]==Y[j]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
            ans=max(c[i][j],ans);
        }
    }
    return ans;
}
void traceback(int i,int j){
    if(i==0||j==0)return ;
    if(b[i][j]==1){
        traceback(i-1,j-1);
        cout<<X[i]<<' ';
    }
    else if(b[i][j]==2)
        traceback(i-1,j);
    else 
        traceback(i,j-1);
}
int main(){
    LCSLength(X,6,Y,7,c);
    LCS(6,7,X);
    // cout<<LCS_2_0(X,7,Y,8,c);
    return 0;
}