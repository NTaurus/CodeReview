#include<bits/stdc++.h>
#include"../base.h"
using namespace std;
const int maxv=100;	//最大顶点数
// const int INF=111;	//设INF为很大的数
int N,M;	//N、M分别为顶点数跟边数 
int G[maxv][maxv];
int dis[maxv][maxv];
void Print(){
    for(int i=0;i<N;i++){	//打印 
        for(int j=0;j<N;j++)
            if(G[i][j]!=INF)
                cout<<G[i][j]<<' ';
            else cout<<"∞ ";
        cout<<endl;
    }
    cout<<"`````````````\n";
}
void Floyd(){

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(G[i][k]!=INF&&G[k][j]!=INF&&G[i][k]+G[k][j]<G[i][j]){
                    G[j][i]=G[i][j]=G[i][k]+G[k][j];
                }
            }
            // Print();
            // cout<<"···················\n";
        }

    }
}

void Floyd_2_0(){
    for(int k=0;k<N;k++){//中间顶点k
        for(int i=0;i<N;i++){//枚举顶点i
            for(int j=0;j<N;j++){//枚举顶点j
                // 如果中间顶点k连通顶点i和j，则如果通过中间顶点k能
                //使i到j的距离更短，则G[i][j]=G[i][k]+G[k][j];
                if(G[i][k]!=INF&&G[k][j]!=INF&&G[i][k]+G[k][j]<G[i][j]){
                    G[i][j]=G[i][k]+G[k][j];
                    cout<<i<<' '<<j<<' '<<k<<endl;
                    Print();

                }
                // base::Print(G,N,N);
            }
        }
    }
}

int main(){
    cin>>N>>M;
    fill(G[0],G[0]+maxv*maxv,INF);	//初始化图中的所有边都为INF，即所有边都不存在 
    fill(dis[0],dis[0]+maxv*maxv,INF);	//初始化图中的所有边都为INF，即所有边都不存在 
    for(int i=0;i<N;i++){
        G[i][i]=0;//顶点i到i的距离为0 
    }
    for(int i=0;i<M;i++){
        int u,v,w;	//u、v为顶点，w为边权 
        cin>>u>>v>>w;
        G[u][v]=G[v][u]=w;	//无向图
        // G[u][v]=w;	//有向图 
    }
    Print();
    // Floyd();	//算法入口 
    Floyd_2_0();
    base::Print(G,N,N);
    return 0;
}
/**输入**
6 8
0 1 3
0 2 1
1 2 1
1 3 1
1 4 3
3 4 1
4 5 1
2 5 2
*/

/**输出**
0 2 1 3 4 3 
2 0 1 1 2 3 
1 1 0 2 3 2 
3 1 2 0 1 2 
4 2 3 1 0 1 
3 3 2 2 1 0
*/ 