#include<iostream>
using namespace std;
const int maxn=100;
const int INF=0x3f3f3f3f;
struct Graph{
    int E[maxn][maxn];
    int numV,numE;
}G;
int dis[maxn],visit[maxn];
void Dijkstra(int s){
    fill(dis,dis+G.numV,INF);
    dis[s]=0;
    for(int i=0;i<G.numV;i++){
        int u=-1,Min=INF;
        for(int j=0;j<G.numV;j++){
            if(visit[j]==0&&Min>dis[j]){
                u=j;
                Min=dis[j];
            }
        }
        if(u==-1)return;
        visit[u]=1;
        for(int v=0;v<G.numV;v++){
            if(G.E[u][v]!=INF&visit[v]==0&&dis[v]>dis[u]+G.E[u][v]){
                dis[v]=dis[u]+G.E[u][v];
            }
        }
    }
    for(int i=0;i<G.numV;i++){
        cout<<dis[i]<<' ';
    }
}
int main(){
    fill(G.E[0],G.E[0]+maxn*maxn,INF);
    cin>>G.numV>>G.numE;
    for(int i=0;i<G.numE;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        G.E[u][v]=G.E[v][u]=cost;
    }
    Dijkstra(0);
}