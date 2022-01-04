#include<iostream>
using namespace std;
struct QueueNode{
    int val;
    QueueNode *next;
};
typedef struct Queue{
    int length;
    QueueNode *front,*rear;
}*LinkQueue;
LinkQueue InitQueue(){
    LinkQueue Q=new Queue();
    Q->length=0;
    Q->front=Q->rear=NULL;
    return Q;
}
void EnQueue(LinkQueue &Q,int val){
    QueueNode *node=new QueueNode();
    node->next=NULL;
    node->val=val;
    if(Q->rear!=NULL)
        Q->rear->next=node;
    Q->rear=node;
    Q->length++;
    if(Q->length==1)
        Q->front=node;
}
bool DeQueue(LinkQueue &Q,int &val){
    if(Q->front==NULL){
        cout<<"队列为空，非法操作\n";
        return false;
    }
    Q->length--;
    val=Q->front->val;
    QueueNode *t=Q->front;
    Q->front=Q->front->next;
    free(t);
    return true;
}
int main(){
    LinkQueue Q=InitQueue();
    while(1){
        int opt,x;
        cout<<"请输入操作（0:入队列  1:出队列  2:队列中元素个数）\n";
        cin>>opt;
        if(opt==0){
            cout<<"请输入入队列元素:\n";
            cin>>x;
            EnQueue(Q,x);
        }
        else if(opt==1){
            if(DeQueue(Q,x))
                cout<<"出队列的元素为："<<x<<endl;
        }
        else{
            cout<<"队列中元素的个数为:"<<Q->length<<endl;
        }
    }
    return 0;
}