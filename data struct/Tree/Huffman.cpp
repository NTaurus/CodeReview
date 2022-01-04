#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
#define maxn 100
struct node{
    int val;
    char ch;
    string code;
    node *lchild,*rchild;
};
vector<node *>P;
queue<node *>first,second;
vector<char>path;
bool cmp(node *a,node *b){
    return a->val<b->val;
}
node *getMin(){//获取两个队列中权值最小的元素
    node *root=NULL;
    if(!second.empty()&&!first.empty()){//两个队列都非空，则从中取权值最小的结点
        if(second.front()->val>first.front()->val){
            root=first.front();
            first.pop();
        }
        else {
            root=second.front();
            second.pop();
        }
    }
    else if(!first.empty()){
        root=first.front();
        first.pop();
    }
    else{
        root=second.front();
        second.pop();
    }
    return root;
}
node *Haffman(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        node *root=new node();
        cin>>root->ch>>root->val;
        // cout<<root->ch<<' '<<root->val<<endl;
        root->lchild=root->rchild=NULL;
        P.push_back(root);
    }
    sort(P.begin(),P.end(),cmp);//排序
    for(int i=0;i<P.size();i++)//将结点存放到队列中
        first.push(P[i]);
    while(first.size()||second.size()!=1){
        node *lchild=getMin();//获取两个权值最小的子树
        node *rchild=getMin();
        node *root=new node();//创建根节点
        root->ch='-';//非叶子结点
        root->val=lchild->val+rchild->val;
        //合并子树
        root->lchild=lchild;
        root->rchild=rchild;
        second.push(root);//合并后的子树放入second队列中
        // if(first.empty()&&second.size()==1)break;
        //只剩一棵子树时说明已经构建完毕
    }
    return second.front();//最后second队列中剩下的结点为树的根节点
}
void preorder(node *&root){
    if(root){
        // cout<<root->ch<<' '<<root->val<<endl;
        if(root->ch!='-'){
            cout<<"编号: "<<root->ch<<" 编码：";
            for(int i=0;i<path.size();i++)
                cout<<path[i];
            cout<<endl;
        }
        path.push_back('0');
        preorder(root->lchild);
        path.pop_back();
        path.push_back('1');
        preorder(root->rchild);
        path.pop_back();
    }
}
void inorder(node *root){
    if(root){
        if(root->ch!='-'){
            cout<<"编号: "<<root->ch<<" 编码："<<root->code;
            cout<<endl;
        }
        inorder(root->lchild);
        // cout<<root->ch<<' '<<root->val<<endl;  
        inorder(root->rchild);
    }
}
typedef struct Queue{
    int rear,front;
    node *data[maxn];
}Queue;
void Encode(node *root){
    Queue Q;
    Q.rear=Q.front=0;
    Q.data[Q.rear++]=root;
    while(Q.rear!=Q.front){
        root=Q.data[Q.front++];
        if(root->lchild!=NULL){
            root->lchild->code=root->code+"0";
            Q.data[Q.rear++]=root->lchild;
        }
        if(root->rchild!=NULL){
            root->rchild->code=root->code+"1";
            Q.data[Q.rear++]=root->rchild;
        }
    }
}
int main(){
    node *T=Haffman();
    cout<<"先序：\n";
    preorder(T);
    Encode(T);
    cout<<"先序：\n";
    inorder(T);
    return 0;
}