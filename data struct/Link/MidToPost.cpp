#include<iostream>
#include<string>
#include<stdio.h>
#include<stack>
#include<queue>
#define maxn 100
using namespace std;
/*
中缀转后缀表达式的操作：
    按顺序扫描中缀表达式:
        如果是操作数:
            直接输出
        如果是操作符:
            栈中元素的优先级小于栈外元素的优先级:
                入栈
            栈中元素的优先级大于栈外元素的优先级:
                如果栈外元素是')':
                    则一直出栈输出，直到遇到'('
                否则:
                    栈中元素的优先级大于栈外元素的优先级:
                        一直出栈输出
                    再把当前元素入栈
            若优先级相同('('=='('):
                出栈，但不输出
    当栈不为空时:
        一直输出,直到栈为空
*/
typedef struct Stack{
    int top;
    char data[maxn];
}Stack;
int isP[128],icP[128];
//isP为栈内优先数(in stack priority)   icP是栈外优先数(in coming priority)
void InitPriority(){
    /*
        规律:
            '+''-' ;'/''*'栈内栈外优先级分别一样
            但在栈内与栈外的比较中，优先级相同的运算符，在栈外的优先级要小一级
            (满足优先级相同则按从左往右顺序运算)

            '('在栈内低(1) 栈外高(6)
            ')'在栈内高(6) 栈外低(1)
    */
    //isP初始化
    isP[int('+')]=isP[int('-')]=3;
    isP[int('*')]=isP[int('/')]=5;
    //icP初始化
    icP[int('+')]=icP[int('-')]=2;
    icP[int('*')]=icP[int('/')]=4;

    isP[int('#')]=0; icP[int('#')]=0;//优先级最低
    isP[int('(')]=1; icP[int('(')]=6;//栈内低、栈外高
    isP[int(')')]=6; icP[int(')')]=1;//栈内高、栈外低
}
void Change(string str,string &post){
    Stack S;
    S.top=0;
    S.data[S.top++]='#';//做初始化('#'优先级最低)，方便在空栈时做优先级比较，把所有栈外运算符压入栈
    for(int i=0;i<str.size();i++){
        if(isalpha(str[i])||isalnum(str[i])){
        // if(str[i]>='a'&&str[i]<='z'){
            cout<<str[i];
            post.push_back(str[i]);
        }
        else{
            int ascii_in=int(S.data[S.top-1]);
            int ascii_out=int(str[i]);
            if(isP[ascii_in]<icP[ascii_out]){
                S.data[S.top++]=str[i];
            }
            else if(isP[ascii_in]>icP[ascii_out]){
                if(str[i]==')'){
                    while(S.top&&S.data[--S.top]!='('){
                        cout<<S.data[S.top];
                        post.push_back(S.data[S.top]);
                    }
                }
                else{
                    while(isP[int(S.data[S.top-1])]>icP[ascii_out]){
                        cout<<S.data[--S.top];
                        post.push_back(S.data[S.top]);
                    }
                    S.data[S.top++]=str[i];
                }
            }
            else S.top--;
        }
    }
    while(S.data[--S.top]!='#'){
        cout<<S.data[S.top];
        post.push_back(S.data[S.top]);
    }
    cout<<endl;
}
void PostExpression(string str){
    int Stack[maxn];
    int top=0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            Stack[top++]=(str[i]-'0');
        }
        else{
            cout<<top<<endl;
            int b=(Stack[--top]);
            int a=(Stack[--top]);
            if(str[i]=='+')
                Stack[top++]=a+b;
            else if(str[i]=='-')
                Stack[top++]=a-b;
            else if(str[i]=='*')
                Stack[top++]=a*b;
            else if(str[i]=='/')
                Stack[top++]=a/b;
        }

    }
    cout<<Stack[--top];
}
struct node{
    char ch;
    node *lchild,*right;
};
node *ExpressionBTree(string str){
    queue<node *>q;
    for(int i=0;i<str.size();i++){
        node *root=new node();
        root->ch=str[i];
        root->lchild=root->right=NULL;
        q.push(root);
    }
    
    stack<node *>s;
    while(!q.empty()){
        node *root=q.front();
        q.pop();
        if(root->ch=='+'||root->ch=='-'||root->ch=='*'||root->ch=='/'){
            node *right=s.top();
            s.pop();
            node *left=s.top();
            s.pop();
            root->lchild=left;
            root->right=right;
        }
        s.push(root);
    }
    return s.top();
}
void preorder(node *root,int depth){
    if(root==NULL)return ;
    if(root->lchild==NULL&&root->right==NULL)
        cout<<root->ch;
    else{
        if(depth>1)
            cout<<"(";
        preorder(root->lchild,depth);
        cout<<root->ch;
        preorder(root->right,depth+1);
        if(depth>1)
            cout<<")";
    }

}
int main(){
    string str,post;
    cin>>str;
    InitPriority();
    Change(str,post);
    cout<<post<<endl;
    node *root=ExpressionBTree(post);
    preorder(root,1);
    // PostExpression(post);

    return 0;
}
/*
从左到右扫描输入的中缀表达式，若是数字，则直接输出到结果，若是运算符则判断：

　　1. '(' ：直接入栈；

　　2. ')'：依次把栈中的运算符输出到结果，知道出现'('，将左括号从栈中删除；

　　3. 若是其他运算符，判断当前运算符与栈顶元素的优先级(*／ 为2，+-为1，
( 为0，其他为-1)，若是当前运算符优先级较高，则直接入栈，
否则，依次输入比当前运算符优先级高或相等的运算符，
直到遇到不符合条件的元素或者遇到左括号为止，再将当前运算符入栈。

　　扫描结束后，将栈内存放的运算符依次输出到结果。
*/