#include<bits/stdc++.h>
using namespace std;
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
bool IsCompleteTree(node *root){
    if(root==NULL)return true;
    queue<node *>q;
    q.push(root);
    int tag=0;  //记录第一次出现空结点
    while(!q.empty()){
        root=q.front();
        q.pop();
        if(tag&&root)  //如果前面有空结点并且当前结点不为空
            return false;
        if(root==NULL&&tag==0)//如果当前结点为空则且第一次出现，则记录
            tag=1;
        if(root==NULL)continue;//如果当前结点为空，则不做入队操作
        q.push(root->lchild);
        q.push(root->rchild);
    }
    return true;
}
int judgeComplete(node *root){
    int tag=0;
    queue<node *>q;
    if(root==NULL)return 1;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        if(root->lchild&&!tag){
            q.push(root->lchild);
        }
        else if(root->lchild) return 0;
        else tag=1;
        if(root->rchild&&!tag)
            q.push(root->rchild);
        else if(root->rchild)
            return 0;
        else tag=1;
    }
    return 1;
}
bool Judge(node *root){
    node *Queue[100];
    int rear=0,front=0;
    Queue[rear++]=root;
    int tag=0;
    while(rear!=front){
        root=Queue[front++];
        if(root!=NULL&&tag)
            return false;
        if(root==NULL)
            tag=1;
        if(root==NULL)continue;
        Queue[rear++]=root->lchild;
        Queue[rear++]=root->rchild;
    }
    return true;
}
int main(){
    int n;
    int In[100],Le[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>Le[i];
    for(int i=0;i<n;i++)cin>>In[i];
    node *root=build(In,Le,0,n-1);
    // dfs(root);
    cout<<IsCompleteTree(root)<<' ';
    cout<<judgeComplete(root)<<' ';
    cout<<Judge(root);
    return 0;
}