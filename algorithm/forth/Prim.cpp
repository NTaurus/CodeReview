#include<iostream>
using namespace std;
const int maxn=100,INF=0x3f3f3f3f;
struct Graph{
    int Eage[maxn][maxn];
    int numE,numV;
}G;
int dis[maxn],visit[maxn];
int Prim(int s){
    fill(dis,dis+G.numV,INF);
    dis[s]=0;
    int cost=0;
    for(int i=0;i<G.numV;i++){
        int u=-1,Min=INF;
        for(int j=0;j<G.numV;j++){
            if(visit[j]==0&&Min>dis[j]){
                u=j;
                Min=dis[j];
            }
        }
        if(u==-1)return -1;
        visit[u]=1;
        cost+=dis[u];
        for(int v=0;v<G.numV;v++){
            if(visit[v]==0&&G.Eage[u][v]<dis[v]){
                dis[v]=G.Eage[u][v];
            }
        }
    }
    for(int i=0;i<G.numV;i++)
        cout<<dis[i]<<' ';
    cout<<endl;
    return cost;
}
int main(){
    fill(G.Eage[0],G.Eage[0]+maxn*maxn,INF);
    cin>>G.numV>>G.numE;
    for(int i=0;i<G.numE;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        G.Eage[u][v]=G.Eage[v][u]=cost;
    }
    cout<<Prim(0)<<endl;
    return 0;
}