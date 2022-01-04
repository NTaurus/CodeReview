#include<iostream>
using namespace std;
const int maxn=5;
typedef struct Queue{
    int data[maxn];
    int rear,front;
}Queue;
void initQueue(Queue &Q){
    Q.front=Q.rear=0;
}
void EnQueue(Queue &Q,int x){
    if((Q.rear+1)%maxn==Q.front){
        cout<<"队列已经满，无法插入\n";
        return;
    }
    Q.data[Q.rear++]=x;
}
void DeQueue(Queue &Q,int &x){
    if(Q.front==Q.rear){
        cout<<"队列为空\n";
        return ;
    }
    x=Q.data[Q.front++];
}
int QueueSize(Queue Q){
    return Q.rear-Q.front;
}
int main(){
    Queue Q;
    initQueue(Q);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        EnQueue(Q,x);
    }

    for(int i=0;i<N;i++){
        int x=-1;
        DeQueue(Q,x);
        cout<<x<<'\n';
    }
    return 0;
}