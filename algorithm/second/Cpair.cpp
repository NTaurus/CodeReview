#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double INF=10000000.0;
double Midnum(double *A,int begin,int end,int k){
    if(begin>=end)return -1;
    int L=begin,R=end-1;
    double index=A[L];
    cout<<index<<endl;
    while(L<R){
        while(L<R&&A[R]>index)R--;
        swap(A[R],A[L]);
        while(L<R&&A[L]<index)L++;
        swap(A[L],A[R]);
    }
    A[L]=index;
    for(int i=0;i<11;i++){
        cout<<A[i]<<' ';
    }
    cout<<"````````````````\n";
    if(L==k-1)return A[L];
    else if(L>k-1)
        return Midnum(A,begin,L,k);
    else 
        return Midnum(A,L+1,end,k);
}
// double Cpair(double *A,int L,int R){
//     if(L+1==R)return fabs(A[L]-A[R]);
//     double mid=Midnum(A,L,R,);
// }
double Cpair2(double *A,int N){
    if(N<2)return 0;
    double d=INF;
    for(int i=1;i<N;i++){
        d=min(d,abs(A[i]-A[i-1]));
    }
    return d;
}
int main(){
    int N;
    cin>>N;
    double A[100000];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    // cout<<Cpair(A,0,N-1)<<endl;
    // sort(A,A+N);
    // cout<<Cpair2(A,N)<<endl;
    cout<<Midnum(A,0,N,N/2)<<endl;
    // for(int i=0;i<N;i++){
    //     cout<<A[i]<<' ';
    // }
    return 0;
}