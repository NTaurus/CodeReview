#include<iostream>
using namespace std;
typedef struct LinkNode{
    int val;
    struct LinkNode *next;
}*LinkList;
void Print(LinkList head){
    LinkNode *p=head->next;
    while(p){
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
}
LinkList rearInsert(){
    int x,n;
    cin>>n;
    LinkList head=new LinkNode();
    head->next=NULL;
    LinkNode *p=head;
    for(int i=0;i<n;i++){
        cin>>x;
        LinkNode *t=new LinkNode();
        t->val=x;
        t->next=p->next;
        p->next=t;
        p=t;
    }
    return head;
}
LinkList headInsert(){
    int n,x;
    cin>>n;
    LinkList head=new LinkNode();
    head->next=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        LinkNode *p=new LinkNode();
        p->val=x;
        p->next=head->next;
        head->next=p;
    }
    return head;
}
// 1 2 3 4 5 null
LinkNode *Reverse(LinkNode *p){
    if(p==NULL)return NULL;
    if(p->next==NULL)return p;
    LinkNode *head=Reverse(p->next);
    // LinkNode *q=p->next;
    // p->next=q->next;
    // q->next=p;
    p->next->next=p;
    // cout<<p->val<<endl;
    p->next=NULL;
    return head;
}
LinkNode *Rever(LinkNode *p){
    if(p==NULL)return NULL;
    if(p->next==NULL)return p;
    LinkNode *head=Rever(p->next);
    LinkNode *t=p->next;
    p->next=t->next;
    t->next=p;
    return head;
}
LinkList Reverse_2_0(LinkNode *head){
    LinkList new_head=head;
    LinkNode *p=head->next,*t;
    new_head->next=NULL;
    while(p){
        t=p->next;
        p->next=new_head->next;
        new_head->next=p;
        p=t;
    }
    return new_head;
}
int Search(LinkList head,int k){
    LinkNode *p=head->next,*q=head->next;
    int count=0;
    while(p){
        if(count<k)count++;
        else q=q->next;
        cout<<q->val<<' ';
        p=p->next;
    }
    if(count<k)return 0;
    else{
        cout<<q->val<<endl;
        return 1;
    }
}
int main(){
    LinkList head = rearInsert();
    // cout<<Search(head,4);
    // Print(head);
    // LinkList head2 = headInsert();
    // Print(head2);
    head->next=Reverse(head->next);
    Print(head);
    head->next=Rever(head->next);
    Print(head);
    // head=Reverse_2_0(head);
    // Print(head);
    // head2->next=Reverse(head2->next);
    // Print(head2);
    return 0;
}
