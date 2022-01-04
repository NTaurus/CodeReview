#include<iostream>
using namespace std;
const int maxn=100;
int dp[100];
int MaxSum(int A[],int N){
    dp[0]=A[0];
    int maxnum=A[0];
    for(int i=1;i<N;i++){
        dp[i]=max(A[i],dp[i-1]+A[i]);
        maxnum=max(dp[i],maxnum);
    }
    return maxnum;
}

int MaxSum2(int m,int n,int a[][maxn]){
    int sum=0;
    int *b=new int [n];
    for(int i=0;i<m;i++){
        fill(b,b+n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++)
                b[k]+=a[j][k];
            for(int k=0;k<n;k++)
                cout<<b[k]<<' ';
            cout<<endl;
            int Max=MaxSum(b,n);
            cout<<"最大值："<<Max<<endl;
            sum=max(sum,Max);
        }
    }
    // Print();
    return sum;
}

int MaxSum_3_0(int m,int n,int a[][maxn]){
    int Max=0;
    int *b=new int[n];
    for(int i=0;i<m;i++){
        fill(b,b+n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++)
                b[k]+=a[j][k];
            int t=MaxSum(b,n);
            Max=max(Max,t);
        }
    }
    return Max;
}

int maxSum(int A[],int n){
    int dp[n],sum;
    sum=dp[0]=A[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+A[i],A[i]);
        sum=max(dp[i],sum);
    }
    return sum;
}

//最大连乘积
int MaxMul(int A[],int n){
    int Max,Min;
    Max=Min=A[0];
    int res=A[0];
    for(int i=1;i<n;i++){
        int a=A[i]*Max;
        int b=A[i]*Min;
        Max=max(max(a,b),A[i]);
        Min=min(min(a,b),A[i]);
        // cout<<Max<<' '<<Min<<endl;
        res=max(Max,res);
    }
    return res;
}

int maxSum5(int m,int n,int A[][maxn]){
    int *b=new int[n];
    int sum=0;
    for(int i=0;i<m;i++){
        fill(b,b+n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++)
                b[k]+=A[j][k];
            int Max=maxSum(b,n);
            sum=max(Max,sum);
        }
    }
    return sum;
}
int MaxSubSum(int *A,int left,int right){
    if(left==right)return (A[left]>0)?A[left]:0;
    int sum=0;
    int center = (left+right)/2;
    int leftSum=MaxSubSum(A,left,center);
    int rightSum=MaxSubSum(A,center+1,right);
    int s1=0,s2=0;
    int lefts=0,rights=0;
    for(int i=center;i>=left;i--){
        lefts+=A[i];
        s1=max(s1,lefts);
    }
    for(int i=center+1;i<=right;i++){
        rights+=A[i];
        s2=max(s2,rights);
    }
    int s=s1+s2;
    s=max(leftSum,s);
    s=max(rightSum,s);
    return s;
}
// int main(){
//     int m,n;
//     int A[maxn][maxn];
//     cin>>m>>n;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>A[i][j];
//         }
//     }
//     cout<<maxSum5(m,n,A);
//     return 0;
// }
int main(){
    int A[100];
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<MaxSum(A,N)<<' '<<MaxSubSum(A,0,N-1)<<' '<<MaxMul(A,N);
    return 0;
}