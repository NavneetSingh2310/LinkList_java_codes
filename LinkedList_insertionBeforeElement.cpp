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
}

struct node * insertionAtBegin(struct node * start,int value)
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
        n->next=start;
        start=n;
    }
    
    return start;
}

struct node * insertionAtGivenIndex(struct node * start,int index, int value)
{
      struct node *n,*ptr;
    
    n=new node;
    n->info=value;
    n->next=NULL;
    
    int count=2;
    ptr=start;
    while(count<index)
    {
        ptr=ptr->next;
        count++; 
    }
    n->next=ptr->next;
    ptr->next=n;
    
    return start;
    
}

struct node * insertionAfterInfo(struct node * start,int element,int value)
{
    struct node *n,*ptr;
    
    n=new node;
    n->info=value;
    n->next=NULL;
    
    ptr=start;
    
    while(ptr->info!=element)
    {
        ptr=ptr->next;
    }
    
    n->next=ptr->next;
    ptr->next=n;
    
    return start;
}

struct node * insertionBeforeInfo(struct node * start,int element,int value)
{
     struct node *n,*ptr, *preptr;
    
    n=new node;
    n->info=value;
    n->next=NULL;
    
    ptr=start;
    preptr=ptr;
    
    while(ptr->info!=element)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    
    n->next=preptr->next;
    preptr->next=n;
    
    return start;
    
    
}

int main() {
    
    
    struct node * start;
    start=NULL;
    start=insertionAtEnd(start,1);
    start=insertionAtEnd(start,2);
    start=insertionAtEnd(start,3);
    start=insertionAtEnd(start,4);
    start=insertionAtBegin(start,-1);
    start=insertionAtBegin(start,0);
    start=insertionAtEnd(start,5);
    start=insertionAtEnd(start,6);
    start=insertionAtGivenIndex(start,3,23);
    start=insertionAtGivenIndex(start,6,23);
    start=insertionAfterInfo(start,4,100);
    start=insertionAfterInfo(start,6,100);
    start=insertionBeforeInfo(start,4,200);
    start=insertionBeforeInfo(start,6,200);
    
    
    printList(start);
    return 0;
	
	
}








