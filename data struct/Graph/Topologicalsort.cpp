#include<iostream>
#include<algorithm>
#include"../base.h"
using namespace std;
// const int maxn=100;
struct Graph{
    int edge[maxn][maxn]; 
    int Vn,En;
    int indegree[maxn];
};
Graph G;
int Queue[maxn];
int rear=0,front=0;
int visit[maxn];
bool Toposort(){
    for(int i=1;i<=G.Vn;i++){
        if(G.indegree[i]==0){
            Queue[rear++]=i;
            visit[i]=1;
        }
    }
    int cnt=0;
    while(front!=rear){
        int v=Queue[front++];
        cnt++;
        for(int i=1;i<=G.Vn;i++){
            if(G.edge[v][i]){
                G.indegree[i]--;
                if(G.indegree[i]==0&&visit[i]==0){
                    Queue[rear++]=i;
                    visit[i]=1;
                }
            }
        }
    }
    if(cnt==G.Vn)
        return true;
    return false;
}

int path[maxn],L=0;
void TopoDfs(){
    if(L==G.Vn){
        for(int i=0;i<L;i++){
            cout<<path[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=G.Vn;i++){
        if(G.indegree[i]==0&&visit[i]==0){
            path[L++]=i;
            visit[i]=1;
            for(int j=1;j<=G.Vn;j++){
                if(G.edge[i][j]){
                    G.indegree[j]--;
                }
            }
            TopoDfs();
            for(int j=1;j<=G.Vn;j++){
                if(G.edge[i][j]){
                    G.indegree[j]++;
                }
            }
            visit[i]=0;
            L--;
        }
    }
}
int main(){
    cin>>G.Vn>>G.En;
    for(int i=0;i<G.En;i++){
        int u,v;
        cin>>u>>v;
        G.edge[u][v]=1;
        G.indegree[v]++;
    }
    // base::Print(G.edge,G.Vn,G.Vn);
    // cout<<Toposort()<<"..............\n";
    // TopoDfs();
    if(Toposort()){
        // cout<<"success\n";
        // cout<<rear<<' '<<endl;
        for(int i=0;i<rear;i++){
            cout<<Queue[i]<<' ';
        }
    }
    else
        cout<<"failure\n";
    // TopoDfs();
    return 0;
}