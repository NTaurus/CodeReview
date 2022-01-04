#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
struct activities{
    int s,e;
}P[maxn];
int cmp(activities a,activities b){
    return a.e<b.e;
}
int visit[maxn];
void GreedySelector(int n){
    visit[0]=1;
    int j=1;
    sort(P,P+n,cmp); 
    for(int i=1;i<n;i++){
        if(P[i].s>=P[j].e){
            visit[i]=1;
            j=i;
        }
    }
    for(int i=0;i<n;i++){
        if(visit[i]==1)
            cout<<P[i].s<<' '<<P[i].e<<endl;
    }
}
int main(){
    // int S[maxn],E[maxn];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>P[i].s;
    for(int i=0;i<n;i++)
        cin>>P[i].e;
    GreedySelector(n);
    return 0;
}
