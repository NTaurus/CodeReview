#include<iostream>
using namespace std;
bool isvalid(int num){
    if(num==1)return true;
    if(num%2&&num%3&&num%5)
        return false;
    int r=1;
    if(num%2==0)
        r*=2;
    if(num%3==0)
        r*=3;
    if(num%5==0)
        r*=5;
    return isvalid(num/r);
}
int main(){
    int n,m=1,i;
    cin>>n;
    if(n==1)cout<<1;
    for(i=2;m<n;i++){
        if(isvalid(i)){
            m++;
            cout<<i<<endl;
        }
    }
    cout<<i-1<<' '<<m;
    return 0;
}