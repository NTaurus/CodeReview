#include<iostream>
using namespace std;
const int maxn=100;
typedef struct Stack{
    int data[maxn];
    int top;
}Stack;
typedef struct ShareStack{
    int data[maxn];
    int top0,top1;
}SStack;
void InitSStack(SStack &SS){
    SS.top0=-1;
    SS.top1=maxn;
}
void EnSStack(SStack &SS,int id,int x){
    if(id==0&&SS.top0!=SS.top1){
        SS.data[++SS.top0]=x;
    }
    else if(id==1&&SS.top0!=SS.top1){
        SS.data[--SS.top1]=x;
    }
    else cout<<"栈满，非法操作！\n";
}
bool DeSStack(SStack &SS,int id,int &x){
    if(id==0&&SS.top0!=-1){
        x=SS.data[SS.top0--];
        return true;
    }
    else if(id==1&&SS.top1!=maxn){
        x=SS.data[SS.top1++];
        return true;
    }
    return false;
}
void initStack(Stack &S){
    S.top=0;
}
void EnStack(Stack &S,int x){
    if(S.top==maxn){
        cout<<"栈已满，无法入栈\n";
        return ;
    }
    S.data[S.top++]=x;
}
void DeStack(Stack &S,int &x){
    if(S.top==0){
        cout<<"栈为空，无法出栈\n";
        return ;
    }
    x=S.data[--S.top];
}
int main(){
    // Stack S;
    // int N,x;
    // initStack(S);
    // cin>>N;
    // for(int i=0;i<N;i++){
    //     cin>>x;
    //     EnStack(S,x);
    // }
    // for(int i=0;i<N;i++){
    //     int x;
    //     DeStack(S,x);
    //     cout<<x<<' ';
    // }

    // 共享栈
    SStack SS;
    InitSStack(SS);
    while(1){
        int x,id,opt;
        cin>>opt>>id;
        if(opt==0){
            cin>>x;
            EnSStack(SS,id,x);
        }
        else{
            if(DeSStack(SS,id,x))
            cout<<"出栈元素："<<x<<endl;
            else cout<<"非法操作\n";
        }
    }
    return 0;
}