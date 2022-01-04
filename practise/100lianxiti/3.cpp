#include<iostream>
using namespace std;
typedef struct LinkNode{
    int data;
    LinkNode *next;
}*LinkList;
void Print(LinkList A){
    for(LinkNode *p=A->next;p!=NULL;p=p->next)
        cout<<p->data<<' ';
    cout<<endl;
}
LinkList create(){
    int n;
    cin>>n;
    LinkList head=new LinkNode();
    head->next=NULL;
    LinkNode *p=head;
    while(n--){
        int x;
        cin>>x;
        LinkNode *node=new LinkNode();
        node->data=x;
        p->next=node;
        p=node;
    }
    p->next=head->next;
    return head;
}
void Intersaction(LinkList A,LinkList B){
    LinkNode *p=A->next,*pre=A;
    LinkNode *q=B->next;
    while(p&&q){
        if(p->data>q->data)
            q=q->next;
        else if(p->data<q->data){
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
        else{
            p=p->next;
            pre=pre->next;
            q=q->next;
        }
    }
    while(p){
        pre->next=p->next;
        free(p);
        p=pre->next;
    }

}
void Subtraction(LinkList A,LinkList B){
    LinkNode *p=A->next,*pre=A;
    LinkNode *q=B->next;
    while(p&&q){
        if(p->data>q->data)
            q=q->next;
        else if(p->data<q->data){
            pre=pre->next;
            p=p->next;
        }
        else{
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
    }
}
bool IsRing(LinkList L){
    LinkNode *p=L->next;
    LinkNode *q=L->next;
    while(p&&q){
        p=p->next;
        if(p&&p->next)p=p->next;
        q=q->next;
        if(p==q)return true;
    }       
    return false;
}
int main(){
    LinkList A=create();
    // LinkList B=create();
    // Intersaction(A,B);
    // Subtraction(A,B);
    // Print(A);
    cout<<IsRing(A);
    return 0;
}