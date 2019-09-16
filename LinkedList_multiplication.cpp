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
        while(ptr2!=NULL){
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
  // printList(output);
    return output;
}

struct node *multiplyList(struct node* start1,struct node* start2)
{
    start1=reverse(start1);
    start2=reverse(start2);
   // printList(start1);
    //printList(start2);
    struct node *output=NULL;
    struct node *temp=NULL;
    struct node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    int count=0;
    while(ptr1!=NULL)
{
   // cout<<ptr1->info<<endl;
    int num1=ptr1->info;
    int carry=0;
    int x=count;
        while(x--)
        {
            struct node *n;
            n=new node;
            n->info=0;
            n->next=NULL;
            temp=insertionAtBegin(temp,n);
        }
    while(ptr2!=NULL)
    {
     //   cout<<ptr2->info<<endl;
        
        int num2=ptr2->info;
        struct node *n;
        n=new node;
        //cout<<num1<<" "<<num2<<" "<<(num1*num2+carry)%10<<" "<<(num1*num2+carry)/10<<endl;
        
        n->info=(num1*num2 + carry)%10;
        carry=(num1*num2 + carry)/10;
        n->next=NULL;
        
        temp=insertionAtBegin(temp,n);
        ptr2=ptr2->next;
       //printList(temp);
    }
   // cout<<carry<<endl;
    if(carry!=0)
    {
        
        struct node *n;
            n=new node;
            n->info=carry;
            n->next=NULL;
            temp=insertionAtBegin(temp,n);
    }
  
    ptr1=ptr1->next;
    // printList(temp);
   output=addList(output,temp);
  //printList(output);
  
   temp=NULL;
    count++;
    ptr2=start2;
}

return output;
    
}

int main()
{  
    struct node *start1=NULL;
    struct node *start2=NULL;
    struct node *output=NULL;
    start2=insertionAtEnd(start2,2);
    
    start2=insertionAtEnd(start2,3);
    
    start2=insertionAtEnd(start2,5);
    
   start1=insertionAtEnd(start1,1);
    
    start1=insertionAtEnd(start1,1);
    
    start1=insertionAtEnd(start1,5);
    
    output=multiplyList(start1,start2);
    
    
    
    
   printList(output);
   // printList(start2);
    
    
    
}