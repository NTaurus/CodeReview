#include<iostream>
using namespace std;
typedef struct StackNode{
    int val;
    StackNode *next;
    StackNode(int x){
        val=x;
    }
}*LinkStack;
LinkStack InitStack(){
    LinkStack S=new StackNode(0);//栈顶的数据存储栈中元素的个数
    S->next=NULL;//初始化，后继指向空
    return S;
}
void EnStack(LinkStack S,int val){
    StackNode *node=new StackNode(val);
    node->next=S->next;
    S->next=node;
    S->val++;
}
bool DeStack(LinkStack S,int &val){
    if(S->next==NULL){
        cout<<"栈为空，非法操作\n";
        return false;
    }
    val=S->next->val;
    StackNode *t=S->next;
    S->next=t->next;
    S->val--;
    free(t);
    return true;
}
int main(){
    LinkStack S=InitStack();//定义一个栈
    while(1){
        int opt,x;
        cout<<"请输入操作（0:入栈  1:出栈  2:栈中元素个数）\n";
        cin>>opt;
        if(opt==0){
            cout<<"请输入入栈元素:\n";
            cin>>x;
            EnStack(S,x);
        }
        else if(opt==1){
            if(DeStack(S,x))
                cout<<"出栈的元素为："<<x<<endl;
        }
        else{
            cout<<"栈中元素的个数为:"<<S->val<<endl;
        }
    }
    return 0;
}