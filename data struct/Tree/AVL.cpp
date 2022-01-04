#include<bits/stdc++.h>
#include"../base.h"
using namespace std;
// struct node{
//     int val;
//     node *lchild,*rchild;
// };
node *RotaR(node *root){
    node *t=root->lchild;
    root->lchild=t->rchild;
    t->rchild=root;
    return t;
}
node *RotaL(node *root){
    node *t=root->rchild;
    root->rchild=t->lchild;
    t->lchild=root;
    return t;
}
node *RotaRL(node *root){
    root->rchild=RotaR(root->rchild);
    return RotaL(root);
}
node *RotaLR(node *root){
    root->lchild=RotaL(root->lchild);
    return RotaR(root);
}
int getHeight(node *root){
    if(root==NULL)return 0;
    return max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
typedef struct Stack{
    node *data[maxn];
    int top;
}Stack;
int getH(node *root){
    if(root==NULL)return 0;
    Stack S;
    S.top=0;
    int H=0;
    node *pre=NULL;
    while(S.top||root){
       if(root){
            S.data[S.top++]=root;
            root=root->lchild;
       }
       else{
           root=S.data[S.top-1];
           if(root->rchild&&root->rchild!=pre){
               root=root->rchild;
           }
            else{
                S.top--;
                pre=root;
                root=NULL;
            }
       }
       H=max(H,S.top);
    }
    return H;
}
node *Insert(node *root,int val){
    if(root==NULL){
        root=new node();
        root->val=val;
        root->lchild=root->rchild=NULL;
    }
    else if(root->val>=val){
        root->lchild=Insert(root->lchild,val);

        if(getHeight(root->lchild)-getHeight(root->rchild)==2){
            root=(val<root->lchild->val)?RotaR(root):RotaLR(root);
        }
    }
    else {
        root->rchild=Insert(root->rchild,val);
        if(getHeight(root->rchild)-getHeight(root->lchild)==2){
            root=(val>root->rchild->val)?RotaL(root):RotaRL(root);
        }
    }
    return root;
}

node *RR(node *root){
    node *temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    return temp;
}
node *LL(node *root){
    node *temp=root->rchild;
    root->rchild=temp->lchild;
    temp->rchild=root;
    return temp;
}

void dfs(node *root){
    if(root==NULL)return ;
    dfs(root->lchild);
    cout<<root->val<<' ';
    dfs(root->rchild);
}
void dfs2(node *root){
    if(root==NULL)return ;
    cout<<root->val<<' ';
    dfs2(root->lchild);
    dfs2(root->rchild);
}
void judge_AVL(node *root,int &h,int &balance){
    int lh=0,rh=0,bl=0,br=0;
    if(root==NULL){
        h=0;
        balance=1;
    }
    // else if(root->lchild==NULL&&root->rchild==NULL){
    //     balance=1;
    //     h=1;
    // }
    else{
        judge_AVL(root->lchild,lh,bl);
        judge_AVL(root->rchild,rh,br);
        h=((lh>rh)?lh:rh)+1;
        if(abs(lh-rh)<2){
            balance=(bl&&br);
        }
        else balance=0;
    }
}
void Judge_AVL(node *root,int &h,int &balance){
    if(root==NULL){
        h=0;
        balance=1;
    }
    else{
        int Lh=0,Rh=0,bL=1,bR=1;
        Judge_AVL(root->lchild,Lh,bL);
        Judge_AVL(root->rchild,Rh,bR);
        h=max(Lh,Rh)+1;
        if(bL==0||bR==0)
            balance=0;
        if(abs(Lh-Rh)>=2)
            balance=0;
    }
}
node *detele_leaves(node *root){
    if(root){
        if(root->lchild==NULL&&root->rchild==NULL){
            free(root);
            return NULL;
        }
        else{
            root->lchild=detele_leaves(root->lchild);
            root->rchild=detele_leaves(root->rchild);
        }
    }
    return root;
}

void Levelorder(node *root){
    if(root==NULL)return ;
    node *Queue[100];
    int rear=0,front=0;
    Queue[rear++]=root;
    while(rear!=front){
        root=Queue[front++];
        cout<<root->val<<' ';
        if(root->lchild)
            Queue[rear++]=root->lchild;
        if(root->rchild)
            Queue[rear++]=root->rchild;
    }
}
void bfs(node *root){
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        cout<<root->val<<' ';
        if(root->lchild)
            q.push(root->lchild);
        if(root->rchild)
            q.push(root->rchild);
    }
}
int main(){
    int N;
    cin>>N;
    node *root=NULL;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        root=Insert(root,x);
        // dfs(root);
        // cout<<endl;
        // dfs2(root);
        // cout<<"\n---------"<<endl;
    }
    // cout<<getHeight(root)<<' '<<getH(root)<<endl;
    int h=0;
    int balance=1;
    Judge_AVL(root,h,balance);
    cout<<balance<<endl;

    // root=detele_leaves(root);
    // dfs(root);
    // bfs(root);
    // cout<<endl;
    // Levelorder(root);
    base::PreOrder(root);
    return 0;
}