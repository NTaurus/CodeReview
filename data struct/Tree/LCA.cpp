#include<iostream>
#include"../base.h"
using namespace std;
node *lca(node *root,int a,int b){
    if(root==NULL)return NULL;
    if(root->val==a||root->val==b)
        return root;
    node *l=lca(root->lchild,a,b);
    node *r=lca(root->rchild,a,b);
    if(l&&r)
        return root;
    return (l==NULL)?r:l;
}
node  *LCA(node *root,int u,int v){
	if(root==NULL)return NULL;
	if(root->val==u||root->val==v)return root;
	node *l=LCA(root->lchild,u,v);
    node *r=LCA(root->rchild,u,v);
        if(l!=NULL&&r!=NULL)return root;
        return l==NULL?r:l;
    }
node *LCA_2_0(node *root,int u,int v){
    if(root==NULL)return NULL;
    if(root->val==u||root->val==v)return root;
    node *l=LCA_2_0(root->lchild,u,v);
    node *r=LCA_2_0(root->rchild,u,v);
    if(l&&r)return root;
    return (l==NULL)?r:l;
}
node *LCa(node *root,int u,int v){
    if(root==NULL)return NULL;
    if(root->val==u||root->val==v)
        return root;
    node *L=LCa(root->lchild,u,v);
    node *R=LCa(root->rchild,u,v);
    if(L&&R)
        return root;
    return (L!=NULL)?L:R;
}
int LevelOrder(node *root){
    if(root==NULL)return 0;
    node *Q[maxn];
    int rear=0,front=0;
    int a=0,b=0,ans;
    Q[rear++]=root;
    ans=a=1;
    cout<<a<<endl;
    while(front!=rear){
        root=Q[front++];
        a--;
        if(root->lchild){
            Q[rear++]=root->lchild;
            b++;
        }
        if(root->rchild){
            Q[rear++]=root->rchild;
            b++;
        }
        if(a==0){
            swap(a,b);
            ans=max(ans,a);
            cout<<a<<endl;
        }
    }
    return ans;
}

int main(){
    int *A,N;
    cin>>N;
    A=base::Cin(N);
    node *root=base::BST(A,N);
    cout<<"````\n"<<LevelOrder(root);
    // base::PreOrder(root);
    // int u=1,v=4;
    // node *ans=lca(root,u,v);
    // cout<<ans->val<<endl;
    // ans=LCa(root,u,v);
    // cout<<ans->val<<endl;
    return 0;
}