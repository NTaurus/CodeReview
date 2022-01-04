#include<iostream>
using namespace std;
const int maxn=500;
int N,W,w[maxn],c[maxn];
int dp[maxn][maxn],visit[maxn];
void Print(int A[][maxn],int N){
    cout<<"`````````````````\n";
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            printf("%-3d",A[i][j]);
        }
        cout<<endl;
    }
}
int snapsack(){
    for(int j=w[0];j<=W;j++){
        dp[0][j]=c[0];
    }   
    Print(dp,N);
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
        Print(dp,N+1);
    }
    // cout<<dp[N-1][W]<<' ';
    return dp[N-1][W];
}
int snapsack_2_0(){
    for(int i=0;i<N;i++)
        dp[0][i]=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return dp[N-1][W];
}
int snapsack_3_0(){
    for(int i=0;i<N;i++)
        dp[0][i]=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return 1;
}
int snapsack33(){
    cout<<w[0]<<endl;
    for(int i=w[0];i<N;i++)
        dp[0][i]=c[0];
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return dp[N-1][W];
}

int snapsack2(){
    for(int j=w[0];j<=W;j++)
        dp[0][j]=c[0];
    Print(dp,N+1);
    for(int i=1;i<N;i++){
        for(int j=i;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
            // Print(dp,N+1);
        }
    }
    return dp[N-1][W];
}

int snapsack3(){
    for(int j=w[0];j<=W;j++)
        dp[0][j]=c[0];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    Print(dp,N);

    return dp[N-1][W];
}
int snapsack4(){
    for(int i=0;i<N;i++)
        dp[0][i]=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<W;j++){
            if(j<w[j])
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return dp[N-1][N];
}
int snapsack5(){
    for(int i=0;i<N;i++)
        dp[0][i]=c[0];
    for(int i=0;i<N;i++){
        for(int j=0;j<W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else    
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return dp[N-1][W];
}
int snapsack6(){
    for(int i=0;i<N;i++)
        dp[0][i]=c[0];
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return dp[N-1][W];
}
int snapsack7(){
    for(int i=0;i<N;i++)    
        dp[0][i]=c[0];
    for(int i=0;i<N;i++){
        for(int j=0;j<W;j++){
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
        }
    }
    return dp[N-1][W];
}
int main(){
    cin>>N>>W;
    for(int i=w[0];i<N;i++)
        cin>>w[i];
    for(int j=0;j<N;j++)
        cin>>c[j];
    cout<<snapsack()<<endl;
    // cout<<snapsack6()<<endl;
    return 0;
}
