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
    
    printList(start);
    return 0;
	
	
}








