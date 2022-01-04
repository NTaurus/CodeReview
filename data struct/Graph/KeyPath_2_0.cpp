#include<iostream>
#include"../base.h"
using namespace std;
typedef struct Graph{
    int Edge[maxn][maxn];
    int Vn,En;
}Graph;
Graph G;
int Stack[maxn],top=0;
int visit[maxn];
int Maxc=0,keypath[maxn],L=0;
void KeyPath(int s,int d,int cost){
    if(visit[s]==1)return ;
    Stack[top++]=s;
    if(s==d){
        if(Maxc<=cost){
            L=0;
            for(int i=0;i<top;i++)
                keypath[L++]=Stack[i];
            Maxc=cost;
            // base::Print(keypath,L);
        }
    }
    visit[s]=1;
    for(int i=1;i<=G.Vn;i++){
        if(G.Edge[s][i]!=INF&&!visit[i]){
            KeyPath(i,d,cost+G.Edge[s][i]);
        }
    }
    top--;
    visit[s]=0;
}
int main(){
    cin>>G.Vn>>G.En;
    fill(G.Edge[0],G.Edge[0]+maxn*maxn,INF);
    for(int i=0;i<G.En;i++){
        int a,b,cost;
        cin>>a>>b>>cost;
        G.Edge[a][b]=cost;
    }
    int x;
    cin>>x;
    while(x--){
        int s,d;
        cin>>s>>d;
        Maxc=0;
        fill(visit,visit+maxn,0);
        KeyPath(s,d,0);
        base::Print(keypath,L);
    }
    return 0;
}