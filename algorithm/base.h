#include<iostream>
using namespace std;
const int maxn=100;
struct node{
    int val;
    node *lchild,*rchild;
};
class base
{
private:
    /* data */
    node static *build(node *root,int val);
public:
    base(/* args */);

    void static Print(int *A,int N);
    void static Print(int A[][maxn],int N,int M);
    int static *Cin(int N);
    void static Cin(int A[][maxn],int N,int M);
    void static PreOrder(node *root);
    node static *BST(int *A,int N);

    ~base();
};

base::base(/* args */)
{
}
int *base::Cin(int N){
    int *A=new int[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    return A;
}
void base::Cin(int A[][maxn],int N,int M){
    // int (*A)[100]=new int [N][100];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    // return A;
}
void base::Print(int *A,int N){
    for(int i=0;i<N;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
void base::Print(int A[][maxn],int N,int M){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
}
void base::PreOrder(node *root){
    if(root==NULL)return;
    cout<<root->val<<' ';
    base::PreOrder(root->lchild);
    base::PreOrder(root->rchild);
}
node *base::build(node *root,int val){
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
node *base::BST(int *A,int N){
    node *root=NULL;
    for(int i=0;i<N;i++){
        root=base::build(root,A[i]);
    }
    return root;
}

base::~base()
{
}
