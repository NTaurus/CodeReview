#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *lchild,*rchild;
};
node *build(node *root,int val){
    if(root==NULL){
        root=new node();
        root->val=val;
        root->lchild=root->rchild=NULL;
    }
    else if(root->val>=val){
        root->lchild=build(root->lchild,val);
    }
    else root->rchild=build(root->rchild,val);
    return root;
}
node *Create(node *root,int val){
    if(root==NULL){
        root=new node ();
        root->val=val;
        root->lchild=root->rchild=NULL;
    }
    else if(root->val>val)
        root->lchild=Create(root->lchild,val);
    else 
        root->rchild=Create(root->rchild,val);
    return root;
}
void dfs(node *root){
    if(root==NULL)return ;
    dfs(root->lchild);
    cout<<root->val<<' ';
    dfs(root->rchild);
}
int main(){
    int N;
    cin>>N;
    node *root=NULL,*T=NULL;//别忘了初始化root为NULL
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        root=build(root,x);
        T=Create(T,x);
    }
    dfs(root);
    cout<<endl;
    dfs(T);
    return 0;
}