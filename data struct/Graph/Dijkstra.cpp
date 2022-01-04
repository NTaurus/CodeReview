#include<iostream>
using namespace std;
const int maxn=100;
const int inf=0x3fffffff;
struct Graph{
    int E[maxn][maxn];
    int Vnum,Enum;
}G;
bool visit[maxn];
int dis[maxn];
int Dijkstra(int s){
    for(int i=0;i<maxn;i++)
        dis[i]=inf;
    dis[s]=0;
    for(int i=0;i<G.Vnum;i++){
        int u=-1,Min=inf;
        for(int j=0;j<G.Vnum;j++){
            if(visit[j]==false&&dis[j]<Min){
                u=j;
                Min=dis[j];
            }
        }
        if(u==-1)return -1;
        visit[u]=true;
        for(int v=0;v<G.Vnum;v++){
            if(visit[v]==false&&G.E[u][v]!=inf&&dis[u]+G.E[u][v]<dis[v]){
                dis[v]=dis[u]+G.E[u][v];
            }
        }
    }
    return 1;
}

void Dijkstra_2_0(int s){
    fill(dis,dis+maxn,inf);
    dis[s]=0;
    for(int i=0;i<G.Vnum;i++){
        int Min=inf,u=-1;
        for(int j=0;j<G.Vnum;j++)
        {
            if(Min>dis[j]&&visit[j]==0){
                Min=dis[j];
                u=j;
            }
        }
        if(u==-1)return ;
        visit[u]=1;
        for(int v=0;v<G.Vnum;v++){
            if(visit[v]==0&&G.E[u][v]!=inf&&G.E[u][v]+dis[u]<dis[v]){
                dis[v]=dis[u]+G.E[u][v];
            }
        }
    }
}

int main(){
    cin>>G.Vnum>>G.Enum;
    fill(G.E[0],G.E[0]+maxn*maxn,inf);
    for(int i=0;i<G.Enum;i++){
        int u,v,val;
        cin>>u>>v>>val;
        G.E[u][v]=G.E[v][u]=val;
    }
    // int ok=Dijkstra(0);
    Dijkstra_2_0(0);
    for(int i=0;i<G.Vnum;i++){
        cout<<dis[i]<<' ';
    }
    return 0;
}



