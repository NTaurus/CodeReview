#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
    int cost;
};
vector<edge>T;
int N,M;
const int maxn=100;
int father[maxn];
int Find(int r){
    while(r!=father[r]){
        // 路径压缩，加快查找
        father[r]=father[father[r]];
        r=father[r];
    }
    return r;
}
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    father[x]=y;
}

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
int Kruscal(){
    for(int i=0;i<maxn;i++){
        father[i]=i;
    }
    // O(e*loge),当e=Ω(n^2)时性能比Prim差，当e=O(n^2)时比Prim好
    // Ω(n)表示时间复杂度的下界，最优
    // O(n)表示时间复杂度的上界，最坏
    sort(T.begin(),T.end(),cmp);
    int edgen=0,cost=0;
    for(int i=0;i<T.size();i++){
        if(Find(T[i].u)!=Find(T[i].v)){
            Union(T[i].u,T[i].v);
            cost+=T[i].cost;
            edgen++;
        }
    }
    if(edgen!=N-1)return -1;
    return cost;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        edge e;
        cin>>e.u>>e.v>>e.cost;
        T.push_back(e);
    }
    cout<<Kruscal();
    return 0;
}
