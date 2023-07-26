//
//  main.cpp
//  deleting_from_doubly_linked_list
//
//  Created by Uby H on 26/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int val;
    struct Node *prev,*next;
}*first=NULL;
void create(int A[], int n)
{
    struct Node *last,*t;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->prev=NULL;
    first->val=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->val=A[i];
        t->prev=last;
        last->next=t;
        t->next=NULL;
        last=t;
    }
}
void display()
{
    struct Node *p=first;
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Delete(int pos,int n)
{
    int x=0;
    struct Node *p=first;
    if(pos<1||pos>n)return -1;
    else
    {
        if(pos==1)
        {
            x=first->val;
            p->next->prev=NULL;
            first=p->next;
            delete p;
            p=NULL;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            x=p->val;
            if(p->next!=NULL)
            {
                p->prev->next=p->next;
                p->next->prev=p->prev;
            }
            else
            {
                p->prev->next=NULL;
            }
            delete p;
        }
    }
    return x;
}
int main()
{
    int n,x,pos;
    cout<<"Enter the number of elements in the linked list : "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the elements in the linked list : "<<endl;
    for(int i=0;i<n;i++)cin>>A[i];
    create(A,n);
    cout<<"The original linked list is given by : "<<endl;
    display();
    cout<<"Enter the position of the element which has to be deleted : "<<endl;
    cin>>pos;
    x=Delete(pos,n);
    if(x<0)
        cout<<"The given position is invalid "<<endl;
    else
    {
        cout<<"The element "<<x<<" is deleted from the linked list "<<endl;
        cout<<"The updated linked list is given by : "<<endl;
        display();
    }
    return 0;
}
