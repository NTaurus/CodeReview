#include<iostream>
using namespace std;
const int maxn=100;
typedef int ElemType; 
typedef struct SStack{
    ElemType data[maxn];
    int top;
}SStack;
typedef struct SNode{
    ElemType data;
    SNode *next;
}Node;
typedef struct LStack{
    Node *top;
    int size;
}LStack;
bool isvalid(int *A,int *B,int N){
    SStack S;
    S.top=0;
    int j=0;
    for(int i=0;i<N;i++){
        S.data[S.top++]=A[i];
        while(S.top&&S.data[S.top-1]==B[j]){
            S.top--;
            j++;
        }
    }
    if(j!=N||S.top)
        return false;
    else return true;
}
int main(){
    int N;
    cin>>N;
    int A[maxn],B[maxn];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    cout<<isvalid(A,B,N);
    return 0;
}