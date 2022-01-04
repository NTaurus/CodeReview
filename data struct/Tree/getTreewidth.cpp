#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
struct node{
    int val;
    node *lchild,*rchild;
};
int Find(int In[],int Le[],int inL,int inR,int N){
    for(int i=0;i<=N;i++){
        for(int j=inL;j<=inR;j++){
            if(Le[i]==In[j])return j;
        }
    }
    return -1;
}
node *build(int In[],int Le[],int inL,int inR){
    if(inL>inR)return NULL;
    node *root=new node();
    root->lchild=root->rchild=NULL;
    int mid=Find(In,Le,inL,inR,7);
    root->val=In[mid];
    root->lchild=build(In,Le,inL,mid-1);
    root->rchild=build(In,Le,mid+1,inR);
    return root;
}
void dfs(node *root){
    if(root){
        cout<<root->val<<' ';
        dfs(root->lchild);
        dfs(root->rchild);
    }
}
int Level[1000],maxH;
void preOrder(node *root,int H){
    if(root){
        Level[H]++;
        maxH=max(H,maxH);   
        preOrder(root->lchild,H+1);
        preOrder(root->rchild,H+1);
    }
}
int getW(node *root){
    if(root==NULL)return 0;
    node *Q[maxn];
    int front=0,rear=0;
    Q[rear++]=root;
    int a=1,b=0,W=1;
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
            a=b;
            W=(W<b)?b:W;
            b=0;
        }
    }
    return W;
}
int main(){
    int In[8]={1,2,3,4,5,6,7,8};
    int Le[8]={4,2,6,1,3,5,8,7};
    node *root=build(In,Le,0,7);
    // dfs(root);
    preOrder(root,1);
    int width=0;
    for(int i=1;i<=maxH;i++){
        width=max(Level[i],width);
    }
    cout<<width<<' '<<getW(root);
    return 0;
}