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

struct node * deleteAtEnd(struct node *start)
{
    struct node *ptr,*preptr;
    if(start==NULL)
    {
        cout<<"UnderFlow"<<endl;
    }
    else {
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    
    preptr->next=NULL;
    delete ptr;
    }
    return start;
}

struct node * deleteAtBegin(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    cout<<"UnderFlow"<<endl;
    else{
    start=ptr->next;
    delete ptr;
    }
    return start;
}

struct node * deleteGivenValue(struct node *start,int element)
{
    struct node *ptr,*preptr;
    if(start==NULL)
    {
        cout<<"UnderFlow"<<endl;
    }
    
    else {
    ptr=start;
    preptr=ptr;
    int flag=0;
    
    while(ptr!=NULL)
    {
        if(ptr->info==element)
        flag=1;
        
        ptr=ptr->next;
    }
    
    if(flag==1)
    {
    while(ptr->info!=element)
    {    
        preptr=ptr;
        ptr=ptr->next;
    }
    
    preptr->next=ptr->next;
     delete ptr;}
     else cout<<"No such element present"<<endl;
    }
    return start;
}

struct node * deleteAfterGivenValue(struct node *start,int element)
{
    struct node *ptr,*preptr;
    if(start==NULL)
    {
        cout<<"UnderFlow"<<endl;
    }
    else {
    ptr=start;
    preptr=ptr;
    while(ptr->info!=element)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr->next!=NULL){
    ptr->next=ptr->next->next;
    //delete ptr->next;
    }
    else cout<<"There is no element after "<<element<<endl;
    }
    
    return start;
}

struct node * deleteBeforeGivenValue(struct node *start,int element)
{
    struct node *ptr,*preptr,*prepreptr;
    if(start==NULL) cout<<"UnderFlow"<<endl;
    else{
    ptr=start;
    preptr=ptr;
    prepreptr=preptr;
    int count=0;
    while(ptr->info!=element)
    { count++;
        prepreptr=preptr;
        preptr=ptr;
        ptr=ptr->next;
    }
    if(count==1)
    start=ptr;
    else
    prepreptr->next=preptr->next;
   
   // delete preptr;
    }
    return start;
    
    
}



int main() {
    
    
    struct node * start;
    start=NULL;
    start=insertionAtEnd(start,1);
    start=insertionAtEnd(start,2);
    
    //start=deleteAtEnd(start);
    
    start=insertionAtEnd(start,3);
    start=insertionAtEnd(start,4);
    start=deleteBeforeGivenValue(start,2);
   //start=deleteAfterGivenValue(start,4);
    //start=deleteAfterGivenValue(start,3);
    //start=deleteGivenValue(start,5);
    //start=deleteGivenValue(start,5);
    //start=deleteAtBegin(start);
    /*start=insertionAtBegin(start,-1);
    start=insertionAtBegin(start,0);
    start=insertionAtEnd(start,5);
    start=insertionAtEnd(start,6);
    start=insertionAtGivenIndex(start,3,23);
    start=insertionAtGivenIndex(start,6,23);
    start=insertionAfterInfo(start,4,100);
    start=insertionAfterInfo(start,6,100);
    start=insertionBeforeInfo(start,4,200);
    start=insertionBeforeInfo(start,6,200);*/
    
    
    printList(start);
    return 0;
	
	
}








