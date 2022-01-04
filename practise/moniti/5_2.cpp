#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int m=0;
ll power(int x,int n){
    if(n==0)return 1;
    if(n==1)return x;
    if(n==2)return x*x;
    if(n==3)return x*x*x;
    int mid=n/4;
    m++;
    ll t=power(x,mid);
    return t*t*t*t*power(x,n%4);
}
int main(){ 
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<' '<<m<<' '<<pow(x,n);
    return 0;
}