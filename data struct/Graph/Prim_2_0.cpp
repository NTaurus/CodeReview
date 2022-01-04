#include<iostream>
#include"../base.h"
using namespace std;
typedef struct Graph{
    int Edge[maxn][maxn];
    int Vn,En;
}Graph;
Graph G;
int N,M;
int dis[maxn],visit[maxn];
int Prim(int s){
    fill(dis,dis+N,INF);
    dis[s]=0;
    int n=0,cost=0;
    for(int i=0;i<N;i++){
        int u=-1,Min=INF;
        for(int j=0;j<N;j++){
            if(visit[j]==0&&dis[j]<Min){
                u=j;
                Min=dis[j];
            }
        }
        if(u==-1)return -1;
        n++;
        cost+=dis[u];
        visit[u]=1;
        // base::Print(dis,N);
        for(int v=0;v<N;v++){
            // 记住是顶点到集合的距离，判断是dis[v]>G.Edge[u][v]
            if(!visit[v]&&G.Edge[u][v]!=INF&&dis[v]>G.Edge[u][v]){
                dis[v]=G.Edge[u][v];
            }
        }
    }
    if(n!=N)return -1;
    // base::Print(dis,N);
    // cout<<endl;
    return cost;
}
int main(){
    fill(G.Edge[0],G.Edge[0]+maxn*maxn,INF);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        G.Edge[u][v]=G.Edge[v][u]=cost;
    }
    cout<<Prim(0);
    return 0;
}