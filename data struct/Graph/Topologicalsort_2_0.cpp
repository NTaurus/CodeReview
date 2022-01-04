#include<iostream>
#include"../base.h"
using namespace std;
#define INF 0x3fffffff
typedef struct Graph{
    int Edge[maxn][maxn];
    int Enum,Vnum;
    int InDegree[maxn];
}Graph;
typedef struct Queue{
    int data[maxn];
    int front,rear;
}Queue;
int visit[maxn];
void TopologicalSort(Graph &G){
    Queue Q;
    Q.front=Q.rear=0;
    for(int i=1;i<=G.Vnum;i++){
        if(G.InDegree[i]==0){
            visit[i]=1;
            Q.data[Q.rear++]=i;
        }
    }
    Queue res;
    res.front=res.rear=0;
    while(Q.front!=Q.rear){
        int v=Q.data[Q.front++];
        // cout<<v<<' ';
        res.data[res.rear++]=v;
        for(int i=1;i<=G.Vnum;i++){
            if(G.Edge[v][i]==1){
                G.InDegree[i]--;
                if(G.InDegree[i]==0&&visit[i]==0){
                    visit[i]=1;
                    Q.data[Q.rear++]=i;
                }
            }
        }
    }
    while(res.front!=res.rear){
        cout<<res.data[res.front++]<<' ';
    }
    cout<<endl;
    for(int i=0;i<Q.rear;i++)
        cout<<Q.data[i]<<' ';
}

int main(){
    Graph G;
    cin>>G.Vnum>>G.Enum;
    fill(G.Edge[0],G.Edge[0]+maxn*maxn,INF);
    fill(G.InDegree,G.InDegree+maxn,0);
    // base::Print(G.Edge,G.Vnum,G.Vnum);
    // cout<<"~``"<<G.Enum<<endl;
    for(int i=0;i<G.Enum;i++){
        int u,v;
        cin>>u>>v;
        G.Edge[u][v]=1;
        G.InDegree[v]++;
    }
    // base::Print(G.Edge,G.Vnum,G.Vnum);
    TopologicalSort(G);
    return 0;
}