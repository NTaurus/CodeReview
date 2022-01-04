#include<iostream>
using namespace std;
// 阶乘
long long permutation(long long n,long long m){
    if(n==m)return n;
    long long mid=(n+m)/2;
    return permutation(n,mid)*permutation(mid+1,m);
}
int main(){
    cout<<permutation(1,6)*permutation(7,8)<<' '<<permutation(1,6)<<' '<<permutation(7,8)<<' '<<permutation(1,8);
    return 0;
}