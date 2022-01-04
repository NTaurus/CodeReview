#include<iostream>
using namespace std;
const int maxn=105;
struct Graph{
    int edge[maxn][maxn];
    int indree[maxn];
    int en,vn;
}G;
int keypath[maxn],L2,L,Max=-1;
int path[maxn];
int visit[maxn];
void keyPath(int s,int e,int cost){
    path[L++]=s;
    visit[s]=1;
    // cout<<s<<' ';
    if(s==e){
        if(Max<cost){
            for(int i=0;i<L;i++){
                keypath[i]=path[i];
                // cout<<keypath[i]<<' ';
            }
            L2=L;
            // cout<<"..."<<cost;
            Max=cost;
            // cout<<endl;
        }
        // return ;//这种写法，不要在这瞎返回，因为状态还没恢复
    }
    for(int i=1;i<=G.vn;i++){
        if(visit[i]==0&&G.edge[s][i]){
            keyPath(i,e,cost+G.edge[s][i]);
        }
    }
    visit[s]=0;
    L--;
}
int main(){

    cin>>G.vn>>G.en;
    for(int i=0;i<G.en;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        G.edge[u][v]=cost;
        G.indree[v]++;
    }
    // keyPath(1,6,0);
    int n=4;
    cin>>n;
    while(n--){
        int s,d;
        L=0,Max=-1;
        fill(visit,visit+maxn,0);
        cin>>s>>d;
        keyPath(s,d,0);
        for(int i=0;i<L2;i++){
            cout<<keypath[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}