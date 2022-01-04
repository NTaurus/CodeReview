#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *lchild,*rchild;
};
int Find(int In[],int Le[],int inL,int inR,int N){
    for(int i=0;i<=N;i++){
        for(int j=inL;j<=inR;j++){
            if(Le[i]==In[j])return j;//在中序的区间上第一次相同的结点即为根结点
        }
    }
    return -1;
}
node *build(int In[],int Le[],int inL,int inR,int N){
    if(inL>inR)return NULL;
    node *root=new node();
    root->lchild=root->rchild=NULL;
    int mid=Find(In,Le,inL,inR,N);
    root->val=In[mid];
    root->lchild=build(In,Le,inL,mid-1,N);
    root->rchild=build(In,Le,mid+1,inR,N);
    return root;
}

int Findx(int In[],int Le[],int inL,int inR,int N){
    for(int i=0;i<N;i++){
        for(int j=inL;j<=inR;j++){
            if(In[j]==Le[i])
                return j;
        }
    }
    return -1;//未找到
}

node *Create(int In[],int Le[],int inL,int inR,int N){
    if(inL>inR)return NULL;
    node *root=new node();
    root->lchild=root->rchild=NULL;
    int index=Findx(In,Le,inL,inR,N);
    root->val=In[index];
    root->lchild=Create(In,Le,inL,index-1,N);
    root->rchild=Create(In,Le,index+1,inR,N);
    return root;
}

void dfs(node *root){
    if(root){
        cout<<root->val<<' ';
        dfs(root->lchild);
        dfs(root->rchild);
    }
}
int main(){
    int In[8]={1,2,3,4,5,6,7,8};
    int Le[8]={4,2,6,1,3,5,8,7};
    node *root=build(In,Le,0,7,8);
    node *T=Create(In,Le,0,7,8);
    dfs(root);
    cout<<endl;
    dfs(T);
    return 0;
}