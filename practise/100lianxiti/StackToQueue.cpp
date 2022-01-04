#include<iostream>
#include"../../base.h"
using namespace std;
typedef node *ElemType;
ElemType *null=NULL;
typedef struct Stack{
    ElemType data[maxn];
    int top;
}Stack;
typedef struct Queue{
    Stack S1,S2;
    int size;
    Queue(){
        S1.top=S2.top=0;
        size=0;
    }
}Queue;
void EnQueue(Queue &Q,ElemType x){
    Q.S1.data[Q.S1.top++]=x;
    Q.size++;
}
void DeQueue(Queue &Q,ElemType &x){
    if(Q.S2.top==0){
        while(Q.S1.top){
            Q.S2.data[Q.S2.top++]=Q.S1.data[--Q.S1.top];
        }
    }
    if(Q.S2.top){
        x=Q.S2.data[--Q.S2.top];
        Q.size--;
    }
    else x=null;
}
//利用两个栈来模拟队列，并用这个队列实现二叉树的层序遍历
void LevelOrder(node *root){
    Queue Q;
    EnQueue(Q,root);
    while(Q.size){
        DeQueue(Q,root);
        cout<<root->val<<' ';
        if(root->lchild)
            EnQueue(Q,root->lchild);
        if(root->rchild)
            EnQueue(Q,root->rchild);
    }
}
//递归求二叉树中最小值
int Min(node *root){
    if(root==NULL)return INF;
    int m=min(Min(root->lchild),Min(root->rchild));
    return min(m,root->val);
}
int main(){
    int N;
    cin>>N;
    int *A=base::Cin(N);
    node *T=base::BST(A,N);
    LevelOrder(T);
    cout<<endl<<Min(T);
    return 0;
}