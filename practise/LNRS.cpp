#include<iostream>
#include<string>
#include"../base.h"
using namespace std;
int dp[maxn];
int Hash[maxn];
string str;
int main(){
    cin>>str;
    Hash[0]=0;
    dp[0]=1;
    for(int i=1;i<str.size();i++){
        int j=str[i]-'a';
        int L=dp[i-1];
        // cout<<"`````````"<<endl;
        // base::Print(dp,str.size());
        // base::Print(Hash,26);
    }
    base::Print(dp,str.size());
    return 0;
}