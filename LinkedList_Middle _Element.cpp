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

void findMiddle(struct node *start)
{
  struct node *slow,*fast;
  slow=start;
  fast=start;
 while( fast->next->next!=NULL)
  {
    fast=fast->next->next;
    slow=slow->next;
  
    
  }
   cout<<slow->info<<endl;

  
  
}

int main()
{
  struct node *start;
  start=NULL;
  int a;
  for(int i=0;i<10;i++)
  {
    cin>>a;
    start=insertionAtEnd(start,a);
  }
  printList(start);
  
  findMiddle(start);
  
  
}