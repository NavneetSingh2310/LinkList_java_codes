import java.util.*;
class node
{
int data;
node next;
node prev;
int priority;
node(){}
node(int d)
{
    data=d;
    next=null;
    prev=null;
}
}

class GFG {
    
    public static int sum(node start)
    {
        if(start==null)
        return 0;
        else return start.data+sum(start.next);
    }
    
    public static node insertAtBegin(node start,node n)
    {
        if(start==null)
        start=n;
        else {
           n.next=start;
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
        System.out.println();
    }
    
    	public static void main (String[] args) {
	
	
		node start=null;
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++)
		{
		    node n=new node(sc.nextInt());
		    start=insertAtEnd(start,n); 
		}
		
	//	node m=new node(200);
	//	start=insertAtIndex(start,m,2);
	//	start=deleteAtIndex(start,1);
	    //start=bubbleSort(start);
		//System.out.println(length(start));
		printList(start);  
		System.out.println("Sum is :"+sum(start));
	}
}
    
