#include <iostream>
using namespace std;

struct node{
    int info;
    struct node *next;
};

struct node * insertionAtEnd(struct node * start,int value)
{
    struct node *n,*ptr;
    
    n=new node;
    n->info=value;
    n->next=NULL;
    
    if(start==NULL)
    {
        start=n;
    }
    else {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        
        ptr->next=n;
    }
    
    return start;
    
    
}

void printList(struct node * start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct node * insertionAtBegin(struct node * start,struct node *n)
{
    struct node *ptr;
    
    
    if(start==NULL)
    {
        start=n;
    }
    else {
        n->next=start;
        start=n;
    }
    
    return start;
}

struct node * reverse(struct node* start)
{
    struct node *current,*next,*prev;
    current=start;
    next=NULL;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    
    
    return prev; 
}

struct node * addList(struct node *start1,struct node *start2)
{
    start1=reverse(start1);
    start2=reverse(start2);
    
    struct node *output=NULL;
    
    struct node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    
    int carry=0;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        struct node *n;
        n=new node;
       int num1=ptr1->info;
        int num2=ptr2->info;
        n->info=( num1+ num2 +carry)%10;
        n->next=NULL;
        carry=(num1 + num2 +carry)/10;
        output=insertionAtBegin(output,n);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        
    }
    if(ptr1)
    {
        while(ptr1!=NULL){
        struct node *n;
        n=new node;
        int num1=ptr1->info;
       // int num2=ptr2->info;
        n->info=( num1+carry)%10;
        n->next=NULL;
        carry=(num1 +carry)/10;
        output=insertionAtBegin(output,n);
        ptr1=ptr1->next;
        }
    }
    
    if(ptr2)
    {
        while(ptr1!=NULL){
        struct node *n;
        n=new node;
        //int num1=ptr1->info;
       int num2=ptr2->info;
        n->info=( num2+carry)%10;
        n->next=NULL;
        carry=(num2 +carry)/10;
        output=insertionAtBegin(output,n);
        ptr2=ptr2->next;
        }
    }
    
    if(carry!=0)
    {
        struct node *n;
        n->info=carry;
        n->next=NULL;
        output=insertionAtBegin(output,n);
    }
    
    return output;
}


int main()
{  
    struct node *start1=NULL;
    struct node *start2=NULL;
    struct node *output=NULL;
    start1=insertionAtEnd(start1,9);
    
    start1=insertionAtEnd(start1,0);
    
    start1=insertionAtEnd(start1,0);
    
    start2=insertionAtEnd(start2,1);
    
    start2=insertionAtEnd(start2,0);
    
    start2=insertionAtEnd(start2,0);
    
    output=addList(start1,start2);
    
    
    
    
    printList(output);
   // printList(start2);
    
    
    
}