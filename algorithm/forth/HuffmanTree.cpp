#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100;
struct node{
    char ch;
    int val;
    struct node *left,*right;
}*HuffmanTree,P[maxn];
queue<node *>first,second;
int cmp(node a,node b){
    return a.val<b.val;
}
node *getMin(){
    node *root=NULL;
    if(first.size()!=0&&second.size()!=0){
        if(first.front()->val<second.front()->val){
            root=first.front();
            first.pop();
        }
        else{
            root=second.front();
            second.pop();
        }
    }
    else if(second.size()==0){
        root=first.front();
        first.pop();
    }
    else {
        root=second.front();
        second.pop();
    }
    return root;
}
node *Huffman(int N){
    sort(P,P+N,cmp);
    for(int i=0;i<N;i++){
        node *t=new node();
        t->ch=P[i].ch; t->val=P[i].val;
        first.push(t);
    }
    while(1){
        node *left=getMin();
        node *right=getMin();
        node *T=new node();
        T->ch='-';
        T->left=left;T->right=right;
        T->val=left->val+right->val;
        second.push(T);
        if(!first.size()&&second.size()==1)break;
    }
    return second.front();
}
void dfs(node *root){
    if(root){
        dfs(root->left);
        cout<<root->ch<<' '<<root->val<<endl;
        dfs(root->right);
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>P[i].ch>>P[i].val;
    }
    HuffmanTree=Huffman(N);
    dfs(HuffmanTree);
    return 0;
}