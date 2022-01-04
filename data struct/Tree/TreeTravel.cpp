#include<iostream>
#include"../base.h"
using namespace std;
typedef node *ElemType;
typedef struct Stack{
    ElemType data[maxn];
    int top;
}Stack;
typedef struct Queue{
    ElemType data[maxn];
    int front,rear;
}Queue;
typedef struct QueueNode{
    int val;
    QueueNode *next;
}*QNode;
typedef struct LinkQueue{
    QueueNode front,rear;
}LQueue;
void LevelOrder(node *root){
    if(root==NULL)return ;
    Queue Q;
    Q.front=Q.rear=0;
    Q.data[Q.rear++]=root;
    while(Q.front!=Q.rear){
        root=Q.data[Q.front++];
        cout<<root->val<<' ';
        if(root->lchild)
            Q.data[Q.rear++]=root->lchild;
        if(root->rchild)
            Q.data[Q.rear++]=root->rchild;
    }
}
void PreOrder(node *root){
    if(root==NULL)return ;
    Stack S;
    S.top=0;
    while(S.top||root){
        if(root){
            cout<<root->val<<' ';
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[--S.top];
            // if(root)
                root=root->rchild;
        }
    }
}
void InOrder(node *root){
    Stack S;
    S.top=0;
    while(root||S.top){
        if(root){
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[--S.top];
            cout<<root->val<<' ';
            root=root->rchild;
        }
    }
}
void PostOrder(node *root){
    Stack S;
    S.top=0;
    node *pre=NULL;
    while(root||S.top){
        if(root){
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[S.top-1];//此处只是读栈顶，不是出栈
            if(root->rchild&&root->rchild!=pre)
                root=root->rchild;
            else{//访问根结点的标志
                S.top--;//在这里出栈
                cout<<root->val<<' ';
                pre=root;
                root=NULL;
            }
        }
    }
}
void preordered(node *root){
    Stack S;
    S.top=0;
    while(S.top||root){
        if(root){
            cout<<root->val<<' ';
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[--S.top];
            root=root->rchild;
        }
    }
}
void Inordered(node *root){
    Stack S;
    S.top=0;
    while(S.top||root){
        if(root){
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[--S.top];
            cout<<root->val<<' ';
            root=root->rchild;
        }
    }
}
// 栈只是做存储的作用，指针root来遍历，root为空则回溯，并从栈顶获取结点，以此来模拟递归ss
void Postordered(node *root){
    Stack S;
    S.top=0;
    node *r=NULL;
    while(S.top||root){
        if(root){
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[S.top-1];
            if(root->rchild&&root->rchild!=r)
                root=root->rchild;
            else{
                S.top--;
                cout<<root->val<<' ';
                r=root;
                root=NULL;
            }
        }
    }
}
void POST(node *root){
    Stack S;
    S.top=0;
    node *r=NULL;
    while(root||S.top){
        if(root){
            S.data[S.top++]=root;
            root=root->lchild;
        }
        else{
            root=S.data[S.top-1];
            if(root->rchild&&root->rchild!=r)
                root=root->rchild;
            else{
                S.top--;
                cout<<root->val<<' ';
                r=root;
                root=NULL;
            }
        }
    }
}
int main(){
    int *A,N;
    cin>>N;
    A=base::Cin(N);
    node *root=base::BST(A,N);
    LevelOrder(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    preordered(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    Inordered(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    POST(root);
    return 0;
}