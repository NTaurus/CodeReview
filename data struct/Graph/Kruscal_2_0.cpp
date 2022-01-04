#include<iostream>
#include<algorithm>
#include"../base.h"
using namespace std;
typedef struct Graph{
    // int Edge[maxn][maxn];
    int u,v;
    int cost;
}Graph;
Graph G[maxn];
int N,M;
int Father[maxn];
int Find(int root){
    while(root!=Father[root]){
        root=Father[root];
    }
    return root;
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    Father[b]=a;
}
bool cmp(Graph a,Graph b){
    return a.cost<b.cost;
}
int Kruscal(){
    for(int i=0;i<N;i++)
        Father[i]=i;
    sort(G,G+M,cmp);
    int p=G[0].u,n=0,cost=0;
    for(int i=0;i<M;i++){
        if(Find(G[i].u)!=Find(G[i].v)){
            n++;
            cost+=G[i].cost;
            Union(G[i].u,G[i].v);
        }
    }
    if(n!=N-1)return -1;
    return cost;
}
int Kruscal_2_0(){
    for(int i=0;i<N;i++)
        Father[i]=i;
    sort(G,G+N,cmp);
    int cost=0,n=0;
    for(int i=0;i<M;i++){
        if(Father[G[i].u]!=Father[G[i].v]){
            Union(G[i].u,G[i].v);
            cost+=G[i].cost;
            n++;
        }
    }    
    if(n!=N-1)return -1;
    return cost;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,val;
        cin>>a>>b>>val;
        G[i].u=a,G[i].v=b;
        G[i].cost=val;
    }
    cout<<Kruscal()<<endl;
    return 0;
}