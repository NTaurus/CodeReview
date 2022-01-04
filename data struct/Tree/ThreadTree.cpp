#include<iostream>
using namespace std;
typedef struct ThreadNode{
    int val;
    ThreadNode *lchild,*rchild;
    ThreadNode *parent;//只有后序线索二叉树需要定义
    int ltag,rtag;
}*ThreadTree;

int Find(int In[],int Le[],int inL,int inR,int N){//找到
    for(int i=0;i<=N;i++){
        for(int j=inL;j<=inR;j++){
            if(Le[i]==In[j])return j;
        }
    }
    return -1;
}
ThreadNode *build(int In[],int Le[],int inL,int inR){
    if(inL>inR)return NULL;
    ThreadNode *root=new ThreadNode();
    root->lchild=root->rchild=NULL;
    int mid=Find(In,Le,inL,inR,7);
    root->val=In[mid];
    root->lchild=build(In,Le,inL,mid-1);
    root->rchild=build(In,Le,mid+1,inR);
    return root;
}

// pre=NULL
// void InThread(ThreadNode *root,ThreadNode *&pre){
//     if(root){

//         InThread(root->lchild,pre);
//         if(root->lchild==NULL){
//             root->lchild=pre;
//             root->ltag=1;
//         }
//         if(pre!=NULL&&pre->rchild==NULL){
//             pre->rchild=root;
//             pre->rtag=1;
//         }
//         pre=root;
//         InThread(root->rchild,pre);
//     }
// }

// pre=NULL
void InThread(ThreadNode *root,ThreadNode **pre){
    if(root){

        InThread(root->lchild,pre);
        if(root->lchild==NULL){
            root->lchild=*pre;
            root->ltag=1;
        }
        if(*pre!=NULL&&(*pre)->rchild==NULL){
            (*pre)->rchild=root;
            (*pre)->rtag=1;
        }
        (*pre)=root;
        InThread(root->rchild,pre);
    }
}

void InThread_2_0(ThreadNode *root,ThreadNode *&pre){
    if(root==NULL)return ;
    InThread_2_0(root->lchild,pre);
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rtag=1;
        pre->rchild=root;
    }
    if(root->lchild==NULL){
        root->lchild=pre;
        root->ltag=1;
    }
    pre=root;
    InThread_2_0(root->rchild,pre);
}

void InOrder_2_0(ThreadNode *root){
    while(root){
        while(root->ltag!=1)
            root=root->lchild;
        cout<<root->val<<' ';
        while(root->rtag){
            root=root->rchild;
            cout<<root->val<<' ';
        }
        root=root->rchild;
    }
}

void InThread_3_0(ThreadNode *root,ThreadNode *&pre){
    if(root==NULL)return ;
    InThread_3_0(root->lchild,pre);
    if(root->lchild==NULL){
        root->lchild=pre;
        root->ltag=1;
    }
    if(pre&&pre->rchild==NULL){
        pre->rchild=root;
        pre->rtag=1;
    }
    pre=root;
    InThread_3_0(root->rchild,pre);
}

void InOrder_3_0(ThreadNode *root){
    while(root){
        while(root->ltag==0)
            root=root->lchild;
        cout<<root->val<<' ';
        while(root->rtag){
            root=root->rchild;
            cout<<root->val<<' ';
        }
        root=root->rchild;
    }
}




void InOrder(ThreadNode *root){
    while(root){
        while(root->ltag!=1)
            root=root->lchild;
        cout<<root->val<<' ';
        while(root->rtag){
            root=root->rchild;
            cout<<root->val<<' ';
        }
        root=root->rchild;
    }
}

void PreThread(ThreadNode *root,ThreadNode *&pre){
    if(root){
        if(root->lchild==NULL){
            root->lchild=pre;
            root->ltag=1;
            
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild=root;
            pre->rtag=1;
        }
        pre=root;
        if(root->ltag==0)
            PreThread(root->lchild,pre);
        if(root->rtag==0)
            PreThread(root->rchild,pre);
    }
}

void PreThread_2_0(ThreadNode *root,ThreadNode *&pre){
    if(root==NULL)return ;
    if(root->lchild==NULL){
        root->ltag=1;
        root->lchild=pre;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rtag=1;
        pre->rchild=root;
    }
    pre=root;
    if(root->ltag==0)
    PreThread_2_0(root->lchild,pre);
    if(root->rtag==0)
    PreThread_2_0(root->rchild,pre);
}

void PreOrder_2_0(ThreadNode *root){
    while(root){
        while(root->ltag==0){
            cout<<root->val<<' ';
            root=root->lchild;
        }
        cout<<root->val<<' ';
        root=root->rchild;
    }
}

void PreOrder(ThreadNode *root){
    while(root){
        while(root->ltag==0){
            cout<<root->val<<' ';
            root=root->lchild;
        }
        cout<<root->val<<' ';
        root=root->rchild;
    }
}


void PreThread_3_0(ThreadNode *root,ThreadNode *&pre){
    if(root==NULL)return;
    if(root->lchild==NULL){
        root->lchild=pre;
        root->ltag=1;
    }
    if(pre&&pre->rchild==NULL){
        pre->rchild=root;
        pre->rtag=1;
    }
    pre=root;
    if(root->ltag==0)
    PreThread_3_0(root->lchild,pre);
    if(root->rtag==0)
    PreThread_3_0(root->rchild,pre);
}

void PreInorder_3_0(ThreadNode *root){
    while(root){
        while(root->ltag==0){
            cout<<root->val<<' ';
            root=root->lchild;
        }
        cout<<root->val<<' ';
        root=root->rchild;
    }
}


void PostThread(ThreadNode *root,ThreadNode *&pre){
    if(root){
        // 儿子找爸爸
        if(root->lchild!=NULL){
            root->lchild->parent=root;
        }
        // 女儿找爸爸 
        if(root->rchild!=NULL)
            root->rchild->parent=root;
        // if(root->parent)cout<<root->val<<' '<<root->parent->val<<endl;
        if(root->ltag==0)
            PostThread(root->lchild,pre);
        if(root->rtag==0)
            PostThread(root->rchild,pre);
        if(root->lchild==NULL){
            root->lchild=pre;
            root->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild=root;
            pre->rtag=1;
        }
        pre=root;
    }
}

void PostOrder(ThreadNode *T){
    ThreadNode *pre=NULL;
    ThreadNode *root=T;
    while(root){
        //往左走
        while(root->lchild!=pre&&root->ltag==0){
            root=root->lchild;
        }//结束后root要么为空要么是根结点
        
        //找后继结点
        while(root&&root->rtag==1){
            cout<<root->val<<' ';
            pre=root;
            root=root->rchild;
        }
        // 如果回到树的根结点则return
        if(root==T){
            cout<<root->val<<' ';
            return ;
        }
        // 找父结点，如果满足root->rchild==pre则表示该结点的左右子树已访问完
        while(root&&root->rchild==pre){
            cout<<root->val<<' ';
            pre=root;
            root=root->parent;
        }
        // 返回上一层后，访问右子树
        if(root&&root->rtag==0)
            root=root->rchild;
    }
}

void PostThread_2_0(ThreadNode *root,ThreadNode *&pre){
    if(root==NULL)return;
    if(root->lchild)
        root->lchild->parent=root;
    if(root->rchild)
        root->rchild->parent=root;
    PostThread_2_0(root->lchild,pre);
    PostThread_2_0(root->rchild,pre);
    if(pre&&pre->rchild==NULL){
        pre->rchild=root;
        pre->rtag=1;
    }
    if(root->lchild==NULL){
        root->lchild=pre;
        root->ltag=1;
    }
    pre=root;
}

void dfs(ThreadNode *root){
    // ThreadNode *root=T;
    if(root){
        // root->val=9;
        dfs(root->lchild);
        cout<<root->val<<' '<<root->ltag<<' '<<root->rtag<<endl;
        dfs(root->rchild);
    }
}
void bfs(ThreadNode *T){
    ThreadNode *root=T;
    if(root==NULL)return ;
    ThreadNode *Q[100];
    int front=0,rear=0;
    Q[rear++]=root;
    while(rear!=front){
        root=Q[front++];
        ThreadNode *t=root->lchild;
        root->lchild=root->rchild;
        root->rchild=t;
        if(root->lchild)
            Q[rear++]=root->lchild;
        if(root->rchild)
            Q[rear++]=root->rchild;
    }
}

int is=0;
int m=8,n=7;
void DFS(ThreadNode *root,int m,int n){
    if(root){
        DFS(root->lchild,m,n);
        if(is==0)
            DFS(root->rchild,m,n);
        if(root->val==n)
            is=1;
        if(is)cout<<root->val<<' ';
        if(root->val==m)is=0;
    }
}

int main(){
    int In[8]={1,2,3,4,5,6,7,8};
    int Le[8]={4,2,6,1,3,5,8,7};
    ThreadNode *root=build(In,Le,0,7);
    ThreadNode *pre = NULL;//不能漏
    //中序线索化
    // InThread(root,pre);
    // InThread(root,&pre);
    // InThread_2_0(root,pre);
    // InOrder_2_0(root);
    // InThread_3_0(root,pre);
    // InOrder_3_0(root);


    // InOrder(root);
    // 先序线索化
    // PreThread(root,pre);
    // PreOrder(root);
    // PreOrder(root);
    // PreThread_2_0(root,pre);
    // PreOrder_2_0(root);
    // PreThread_3_0(root,pre);
    // PreInorder_3_0(root);

    //后序线索化
    // PostThread(root,pre);
    PostThread_2_0(root,pre);
    PostOrder(root);
    // cout<<&root<<cout<<&root;
    // dfs(root);
    // cout<<endl;
    // bfs(root);
    // dfs(root);
    // DFS(root,m,n);
    //指针
    // int a=1;
    // int *b=&a;
    // int **c=&b;
    // int *d=b;
    // cout<<*d<<' ';
    // cout<<a<<' '<<b<< ' '<<c<<endl;
    // **c=4;
    // cout<<a<<' '<<*b<<' '<<**c<<' '<<*c<<' '<<&**c<<' ';
    // cout<<endl;
    // cout<<' '<<&a<<' '<<&b<<' '<<&c;

    return 0;
}
