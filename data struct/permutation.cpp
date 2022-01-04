#include<bits/stdc++.h>
using namespace std;
int N,visit[100];   //visit用来判断该数是否已被访问 
vector<int>path;    //存放路径的数组 
long long ans;
void dfs(){
    if(path.size()==N){ //当数组path内元素的个数等于N时，说明已生成一个的排列，即可打印出来 
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<' ';
        }
        printf("\n");
        // ans++;
        return;
    }
    for(int i=1;i<=N;i++){  
        if(visit[i]==0){    //如果该数未被访问
            path.push_back(i);  //把它加到路径中
            visit[i]=1;     //标记已访问 
            dfs();    //对加入该数后的路径继续进行DFS 
            path.pop_back();    //该数递归完后，把该数弹出来 
            visit[i]=0;     //把该数的访问重新标记为0，以便其他位数能继续访问 
        }
    }
}
int main(){
    cin>>N;
    dfs();
    cout<<ans;
    return 0;
}