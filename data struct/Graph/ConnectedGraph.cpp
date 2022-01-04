#include<iostream>
#include"../base.h"
using namespace std;
int Mr[maxn][maxn];
int N;
void Floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j&&Mr[i][k]&&Mr[k][j]){
                    Mr[i][j]=1;
                }
            }
        }
    }
}
int main(){
    fill(Mr[0],Mr[0]+maxn*maxn,INF);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Mr[i][j];
        }
    }
    Floyd();
    base::Print(Mr,N,N);
    return 0;
}