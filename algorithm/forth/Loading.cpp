#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
int Loading(int w[],int n,int c){
    sort(w,w+n);
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+w[i]<=c){
            sum+=w[i];
            cout<<w[i]<<' ';
        }
    }
    cout<<endl;
    return sum;
}
int main(){
    int c,w[maxn],n;
    
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<Loading(w,n,c);
    
    return 0;
}