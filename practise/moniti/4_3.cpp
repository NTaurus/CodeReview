#include<iostream>
#include"../base.h"
using namespace std;
bool judge(int n){
    if(n==1)return true;
    if(n!=2&&n%2)return false;
    return judge(n/2);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
        if(judge(i))
            cout<<i<<endl;
    return 0;
}