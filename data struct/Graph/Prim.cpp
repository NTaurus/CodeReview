#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
const int inf=0x3ffffff;
int N,M;
int G[maxn][maxn];
int dis[maxn];
int visit[maxn];
int prim(int s){
    fill(dis,dis+maxn,inf);
    dis[s]=0;
    int cost=0;
    for(int i=0;i<N;i++){
        int u=-1,Min=inf;
        for(int j=0;j<N;j++){
            if(visit[j]==0&&dis[j]<Min){
                u=j;
                Min=dis[j];
            }
        }
        if(u==-1)return -1;
        cost+=dis[u];
        visit[u]=1;
        for(int v=0;v<N;v++){
            if(visit[v]==0&&G[u][v]!=inf&&G[u][v]<dis[v]){
                dis[v]=G[u][v];
            }
        }
    }
    for(int i=0;i<N;i++)
        cout<<dis[i]<<' ';
    cout<<endl;
    return cost;
}

int main(){
    fill(G[0],G[0]+maxn*maxn,inf);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a][b]=G[b][a]=c;
    }
    cout<<prim(0);
    return 0;
}