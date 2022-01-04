#include<iostream>
#include"../base.h"
using namespace std;
typedef long long ll;
ll dfs(ll n,ll x){
    if(n==0)return 1;
    if(n==1)return 2*x;
    return 2*x*dfs(n-1,x)-2*(n-1)*dfs(n-2,x);
}
// Iterative;迭代
// recursion;递归
ll Iterative(int n,int x){
    ll a0=1;
    ll a1=2*x;
    if(n==0)return a0;
    if(n==1)return a1;
    for(int i=2;i<=n;i++){
        ll an=2*x*a1-2*(i-1)*a0;
        a0=a1;
        a1=an;
    }
    return a1;
}
int main(){
    ll x,n;
    cin>>n>>x;
    cout<<dfs(n,x)<<endl<<Iterative(n,x)<<endl;
    return 0;   
}