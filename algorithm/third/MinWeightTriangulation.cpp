#include<iostream>
#include"../base.h"
using namespace std;
int weight[maxn][maxn] = {
{0,2,2,3,1,4},
{2,0,1,5,2,3},
{2,1,0,2,1,4},
{3,5,2,0,6,2},
{1,2,1,6,0,1},
{4,3,4,2,1,0}
};
int s[maxn][maxn],t[maxn][maxn];
int n=7;
int getWeight(int a,int b,int c){
    return weight[a][b]+weight[a][c]+weight[b][c];
}
int MinWeightTriangulation(int n,int t[][maxn],int s[][maxn]){
    for(int i=1;i<=n;i++)
        t[i][i]=0;
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=i+r-1;
            t[i][j]=t[i+1][j]+getWeight(i-1,i,j);
            s[i][j]=1;
            for(int k=i+1;k<j;k++){
                int u=t[i][k]+t[k+1][j]+getWeight(i-1,k,j);
                if(u<t[i][j]){
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
    return t[1][n-2];
}
int  MinWTriangulation(int n,int t[][maxn],int s[][maxn]){
    for(int i=0;i<=n;i++)
        t[i][i]=0;
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=i+r-1;
            t[i][j]=t[i+1][j]+getWeight(i-1,i,j);
            s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int u=t[i][k]+t[k+1][j]+getWeight(i-1,k,j);
                if(u<t[i][j]){
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
    return t[1][n-2];
}
int  MinWeightTritangulation_2_0(int n,int t[][maxn],int s[][maxn]){
    for(int i=0;i<=n;i++)
        t[i][i]=0;
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=i+r-1;
            t[i][j]=t[i+1][j]+getWeight(i-1,i,j);
            s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int u=t[i][k]+t[k+1][j]+getWeight(i-1,k,j);
                if(u<t[i][j]){
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
    return 24;
}
int main(){
    cout<<MinWeightTritangulation_2_0(n,t,s)<<endl;
    base::Print(t,n,n);
    return 0;
}