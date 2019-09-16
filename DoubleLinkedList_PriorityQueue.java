/*package whatever //do not write package name here */

import java.util.*;
class node
{
int data;
node next;
node prev;
int priority;
node(){}
node(int d,int p)
{
    data=d;
    priority=p;
    next=null;
    prev=null;
}
}

class GFG {
    
    public static node insertAtBegin(node start,node n)
    {
        if(start==null)
        start=n;
        else {
           n.next=start;
           start.prev=n;
           start=n;
        }
        return start;
    }
    
     public static node insertAtEnd(node start,node n)
    {
        if(start==null)
        start=n;
        else {
         node ptr=start;
         while(ptr.next!=null)
         {
             ptr=ptr.next;
         }
         ptr.next=n;
         n.prev=ptr;
        }
        return start;
    }
    
     public static node insertAtIndex(node start,node n,int index)
    {
        if(start==null)
        start=n;
        else {
         node ptr=start;
         int count=1;
         while(ptr.next!=null && count<index-1)
         {
             ptr=ptr.next;
             count++;
         }
         n.next=ptr.next;
         ptr.next.prev=n;
         ptr.next=n;
         n.prev=ptr;
         
        }
        return start;
    }
    
    public static node deleteAtBegin(node start)
    {
        if(start==null)
        System.out.println("UnderFlow");
        else{
       node ptr=start;
       start=start.next;
       start.next.prev=null;
        }   
       return start;
    }
    
    public static node deleteAtEnd(node start)
    {
        if(start==null)
        System.out.println("UnderFlow");
        else {
            node ptr=start;
            while(ptr.next.next!=null) ptr=ptr.next;
            
            ptr.next=null;
        }
        
        return start;
    }
    
    public static node deleteAtIndex(node start,int index)
    {
        if(start==null)
        System.out.println("UnderFlow");
        else if(index==1)
        {
            start=start.next;
            start.prev=null;
        }
        else {
            int count=0;
            node ptr=start;
            node x=ptr;
            node y=null;
            while(ptr.next!=null && count<index-1)
            {
                x=ptr;
                ptr=ptr.next;
                count++;
                
            }
            
            
            y=ptr.next;
            x.next=y;
            y.prev=x;
          System.out.println(x.data);
          System.out.println(y.data);
            
        }
        
        return start;
    }
    
    public static void printList(node start)
    {
        node ptr=start;
        while(ptr!=null)
        {
            System.out.print(ptr.data +" ");
            ptr=ptr.next;
        }
    }
    
    public static int length(node start)
    {
        node ptr=start;
        int len=0;
        while(ptr!=null)
        {
            ptr=ptr.next;
            len++;
        }
        return len;
    }
    
    /*public static node bubbleSort(node start)
    {
     
     node i=start;
     node j=start;
    while(i.next!=null)
    { j=i;
        while(j!=i)
        {
            if(j.data>j.next.data)
            {
                node temp1=j;
                node temp2=j.next;
                temp1.next=temp2.next;
                temp2.next=temp1;
                temp2.prev=temp1.prev;
                temp1.prev=temp2;
                
            }
            j=j.next;
        }
        i=i.next;
    }
     return start;
        
    }*/
    
    public static node priorityQueueInsertion(node start,node n)
    {
        if(start==null)
        start=n;
        else{
            int p=n.priority;
            node ptr=start;
            node x=ptr;
            node y=null;
            while(ptr!=null && ptr.priority>p)
            {   
                x=ptr;
                ptr=ptr.next;
            }
            
            if(ptr.next==null)
            {
                ptr.next=n;
                n.prev=ptr;
            }
            else {
                  n.next=ptr.next;
                  ptr.next.prev=n;
                  ptr.next=n;
                  n.prev=ptr;
            }
            
            
            
        }
        
        return start;
        
    }
    
    
	public static void main (String[] args) {
	
	
		node start=null;
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++)
		{
		    node n=new node(sc.nextInt(),sc.nextInt());
		    start=priorityQueueInsertion(start,n); 
		}
		
	//	node m=new node(200);
	//	start=insertAtIndex(start,m,2);
	//	start=deleteAtIndex(start,1);
	    //start=bubbleSort(start);
		//System.out.println(length(start));
		printList(start);  
	}
}