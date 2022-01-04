#include <algorithm>
#include <iostream>

using namespace std;
struct node
{
    int val;
    struct node *next;
};
node *head = new node();

void quickSortRestOnLink(node *start, node *end)
{
    if (start == end)
        return;
    node *p = start;
    node *q = start->next;
    int index = start->val;
    while (q != end)
    {
        if (q->val < index)
        {
            p = p->next;
            swap(q->val, p->val);
        }
        q = q->next;
    }
    cout << "《" << index << "》" << endl;
    swap(p->val, start->val);
    for (node *y = head->next; y != NULL; y = y->next)
    {
        cout << y->val << ' ';
    }
    cout << endl;
    quickSortRestOnLink(start, p);
    quickSortRestOnLink(p->next, end);
}
void qsort(node *start, node *end)
{
    if (start == end)
        return;
    node *p = start;
    node *q = start->next;
    int index = start->val;
    cout << index << ' ' << endl;
    while (q != end)
    {
        if (q->val < index)
        {
            p = p->next;
            swap(q->val, p->val);
        }
        q = q->next;
    }
    // cout<<p->val<<endl;
    swap(start->val, p->val);
    for (node *y = head->next; y != NULL; y = y->next)
    {
        cout << y->val << ' ';
    }
    cout << endl;
    qsort(start, p);
    qsort(p->next, end);
}
void Print(node *head)
{
    for (node *p = head->next; p != NULL; p = p->next)
    {
        cout << p->val << ' ';
    }
    cout << endl;
}
//把偶数挑到尾部，但要控制循环结束的时机
void Sort_2_0(node *head)
{
    node *p, *q, *pre = head;
    p = head->next;
    q = head;
    int n=0;
    while (q->next)
    {
        if(q->next->val % 2 != 0)
            n++;
        q = q->next;
    }
    int m=0;
    while (m < n)
    {
        if (p->val % 2 == 0)
        {
            pre->next = p->next;
            q->next = p;
            p->next = NULL;
            q = p;
            p = pre->next;
        }
        else
        {
            m++;
            p = p->next;
            pre = pre->next;
        }
        Print(head);
    }
}
int main()
{
    int n;
    cin >> n;
    head->next = NULL;
    node *p = head, *end = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        node *t = new node();
        t->val = x;
        t->next = p->next;
        p->next = t;
        p = t;
    }
    // for(p=head->next;p!=NULL;p=p->next){
    //     cout<<p->val<<' ';
    // }
    // cout<<endl;
    // quickSortRestOnLink(head->next,end);
    // Sort(head);
    Sort_2_0(head);
    // Sort_2_0(head);
    // Print(head);
    // qsort(head->next,end);

    return 0;
}