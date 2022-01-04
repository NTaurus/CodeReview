#include<iostream>
using namespace std;
const int maxn=100;
void Print(int m[][maxn],int n){
    cout<<"````````````````````````````````````````\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%-6d ",m[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
int m[maxn][maxn],s[maxn][maxn],p[maxn];
int n;
// 矩阵连乘备忘录写法
// 自顶向下
int LookupChain(int i,int j){
    if(m[i][j]>0)
        return m[i][j];
    if(i==j)
        return 0;
    int u=LookupChain(i,i)+LookupChain(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++){
        int t=LookupChain(i,k)+LookupChain(k+1,j)+p[i-1]*p[k]*p[j];
        if(u>t){
            u=t;
            s[i][j]=k;
        }
    }
    m[i][j]=u;
    return u;
}

int MemoizedMatrixChain(int i,int j){
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    return LookupChain(i,j);
}
int main(){
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    cout<<MemoizedMatrixChain(1,6);


    return 0;
}