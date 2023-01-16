
//Name - Mohit Jaiswal
//Batch - A4
//Roll No. - 57

#include<iostream>
#include<string.h>
#define max 10
using namespace std;

class Food
{   
    public:
		string food_name;
		int quantity;
		int price;	
};

//Linear Queue using Array
class Queue
{   
    public:
		Food array[max];
		int front,rear;
	
	Queue()
	{
		front=-1;
		rear=-1;	
	}
	
	bool is_empty();
	bool is_full();
	void enqueue(string name , int quant , int price);
	void dqueue();
	void display();
	
};

bool Queue::is_empty()
{
	if(front==-1)
	 return true;
	 
	else
	  return false;
}

bool Queue::is_full()
{
	if(rear==max-1)
	 return true;
	 
	else
	  return false;
}

void Queue::enqueue(string name , int quant , int price)
{
	if(is_full())
	{
		cout<<"Queue is Full"<<endl;
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		
	   rear++;
	   array[rear].food_name=name;
	   array[rear].quantity=quant;
	   array[rear].price=price;
	}	
}

void Queue::dqueue()
{
	if(is_empty())
	{
		cout<<"Queue is Empty"<<endl;
	}

	else
	{   
	   string n=array[front].food_name;
	   int q=array[front].quantity;
	   int p=array[front].price;
	   
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}

		else
		{
		  front=front+1;	
		}
	   
	   cout<<"\nDeleted iteam:"<<endl;
	   cout<<"Food name:"<<n<<endl;
	   cout<<"Quantity:"<<q<<endl;
	   cout<<"Price:"<<p<<endl;
	}	
}

void Queue::display()
{   
	cout<<"*****************"<<endl;
   
  	for(int i=front;i<=rear;i++)
	{
	   cout<<"\nFood name:"<<array[i].food_name<<endl;
	   cout<<"Quantity:"<<array[i].quantity<<endl;
	   cout<<"Price:"<<array[i].price<<endl;
	}	

	cout<<"*****************"<<endl;
}

//Circular Queue using Array
class CQueue
{   
    public:
		Food array[max];
		int front,rear;
	
	CQueue()
	{
		front=-1;
		rear=-1;	
	}
	
	bool is_empty();
	bool is_full();
	void enqueue(string name , int quant , int price);
	void dqueue();
	void display();
	
};

bool CQueue::is_empty()
{
	if(front==-1)
	 return true;
	 
	else
	  return false;
	
}

bool CQueue::is_full()
{
	if((front==0 && rear==max-1) || front==rear+1)
		return true;
	 
	else
		return false;
	
}

void CQueue::enqueue(string name , int quant , int price)
{
	if(is_full())
	{
		cout<<"Queue is Full"<<endl;
	}

	else
	{
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		
		else
		{
			rear=(rear+1)%max;
		}

	   array[rear].food_name=name;
	   array[rear].quantity=quant;
	   array[rear].price=price;
	}	
}

void CQueue::dqueue()
{
	if(is_empty())
	{
		cout<<"Queue is Empty"<<endl;
	}

	else
	{   
	   string n=array[front].food_name;
	   int q=array[front].quantity;
	   int p=array[front].price;
	   
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}

		else
		{
		  front=(front+1)%max;	
		}
	   
	   cout<<"\nDeleted iteam:"<<endl;
	   cout<<"Food name:"<<n<<endl;
	   cout<<"Quantity:"<<q<<endl;
	   cout<<"Price:"<<p<<endl;
	}	
}

void CQueue::display()
{   
    cout<<"*****************"<<endl;

    if(front<rear)
    {
    	for(int i=front;i<=rear;i++)
		{	
			cout<<"\nFood name:"<<array[i].food_name<<endl;
			cout<<"Quantity:"<<array[i].quantity<<endl;
			cout<<"Price:"<<array[i].price<<endl;
		}

		cout<<"*****************"<<endl;
	}

	else
	{
		for(int i=front;i<=max-1;i++)
		{
			cout<<"\nFood name:"<<array[i].food_name<<endl;
			cout<<"Quantity:"<<array[i].quantity<<endl;
			cout<<"Price:"<<array[i].price<<endl;
		}
		
		for(int i=0;i<=rear;i++)
		{
			cout<<"\nFood name:"<<array[i].food_name<<endl;
			cout<<"Quantity:"<<array[i].quantity<<endl;
			cout<<"Price:"<<array[i].price<<endl;
		}

		cout<<"*****************"<<endl;
	}
}

//Linear Queue usng Linked List
class Node
{
  public:
	string food_name;
	int quantity;
	int price;
	
	Node *next;	
};

class LQueue
{
  public:
  	Node *front , *rear;
  
	LQueue()
	{
		front=rear=NULL;
	}
  
	bool is_empty();
	void enqueue(string name , int quant , int price);
	void dqueue();
	void display();  

};


bool LQueue::is_empty()
{
	if(front==NULL)
	 return true;
	 
	else
	  return false;	
}

void LQueue::enqueue(string name , int quant , int price)
{
   Node *temp;
   temp=new Node;
   temp->food_name=name;
   temp->quantity=quant;
   temp->price=price;
   temp->next=NULL;
   
   if(is_empty())
   {
   		front=rear=temp;
   }
   
   else
   {
   		rear->next=temp;
   		rear=temp;
   }
}


void LQueue::dqueue()
{
	if(is_empty())
	{
		cout<<"Queue is Empty"<<endl;
	}

	else
	{  
       Node *temp=front; 
	   string n=front->food_name;
	   int q=front->quantity;
	   int p=front->price;
	   
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
			delete temp;
		}

		else
		{
		  	front=front->next;
		  	delete temp;	
		}
	   
	   cout<<"\nDeleted iteam:"<<endl;
	   cout<<"Food name:"<<n<<endl;
	   cout<<"Quantity:"<<q<<endl;
	   cout<<"Price:"<<p<<endl;
	}	
}

void LQueue::display()
{   
     Node *temp=front;
     cout<<"*****************"<<endl;
  
   	while(temp!=NULL)
	{
	   cout<<"\nFood name:"<<temp->food_name<<endl;
	   cout<<"Quantity:"<<temp->quantity<<endl;
	   cout<<"Price:"<<temp->price<<endl;
	   
	   temp=temp->next;
	}
	cout<<"*****************"<<endl;	
}

//Circular Queue using Linked List
class CLQueue
{
  public:
  	Node *front , *rear;
  
	CLQueue()
	{
		front=rear=NULL;
	}
  
	bool is_empty();
	void enqueue(string name , int quant , int price);
	void dqueue();
	void display();  
};


bool CLQueue::is_empty()
{
	if(front==NULL)
	 return true;
	 
	else
	  return false;
}

void CLQueue::enqueue(string name , int quant , int price)
{
   Node *temp;
   temp=new Node;
   
   temp->food_name=name;
   temp->quantity=quant;
   temp->price=price;
   temp->next=temp;
   
   if(is_empty())
   {
   		front=rear=temp;
   }

   else
   {
   		rear->next=temp;
   		rear=temp;
   		rear->next=front;
   }
}

void CLQueue::dqueue()
{
	if(is_empty())
	{
		cout<<"Queue is Empty"<<endl;
	}

	else
	{  
       Node *temp=front;
	    
	   string n=front->food_name;
	   int q=front->quantity;
	   int p=front->price;
	   
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
			
			delete temp;
		}

		else
		{
			front=front->next;
			rear->next=front;
			delete temp;	
		}
	   
	   cout<<"\nDeleted iteam:"<<endl;
	   cout<<"Food name:"<<n<<endl;
	   cout<<"Quantity:"<<q<<endl;
	   cout<<"Price:"<<p<<endl;
	}	
}

void CLQueue::display()
{   
     Node *temp=front;
     cout<<"*****************"<<endl;
  
    do
	{
	   cout<<"\nFood name:"<<temp->food_name<<endl;
	   cout<<"Quantity:"<<temp->quantity<<endl;
	   cout<<"Price:"<<temp->price<<endl;
	   
	   temp=temp->next;
	}while(temp!=front);
	
	cout<<"*****************"<<endl;
}

int main()
{  
    int choice1,choice2; 
	string name ;
	int price,quant;
	
	cout<<"\n_______________QUEUE_______________\n";
	cout<<"1]. Simple Queue using Array\n2].Simple Queue using Linked List\n3].Circular Queue using Array\n4]. Circular Queue using Linked List\n";
	cout<<"Enter your choice - ";
	cin>>choice1;
	
	switch(choice1)
	{   
	    
		case 1:
			{
			
			Queue obj1;
		    do
			{
			
			cout<<"\n 1.Add Food item \n 2.Delete Food iteam \n 3.Display all Food iteMS \n 4.Press 0 to exit"<<endl;
			cout<<"Enter your Choice:";
			cin>>choice2;
			
			switch(choice2)
			{
			
			 case 1:
			 	cout<<"\n>>Enter item name:";
			 	cin>>name;
			 	cout<<">>Enter item quantity:";
			 	cin>>quant;
			 	cout<<">>Enter item price:";
			 	cin>>price;
			 	
			 	obj1.enqueue(name,quant,price);
			 	
			 	break;
			 
			 case 2:
			 	
			 	obj1.dqueue();
			 	
			 	break;
			 	
			 case 3:
				
				obj1.display();
				break;
				
			 case 0:
			      cout<<"\nOrder Placed"<<endl;
			      break;
			      
			default:
		    	cout<<"You entered invalid choice..................";
		        break;
			      
		    }
		    
		   }while(choice2 != 0);
		   
		   }break;
			
		
		   
       		case 2:
       		{
			LQueue obj2;
		    do
			{
			
			cout<<"\n 1.Add food item \n 2.Delete food iteam \n 3.Display all food iteam \n 4.Press 0 to exit"<<endl;
			cout<<"Enter your Choice:";
			cin>>choice2;
			
			switch(choice2)
			{
			
			 case 1:
			 	cout<<"\n>>Enter item name:";
			 	cin>>name;
			 	cout<<">>Enter item quantity:";
			 	cin>>quant;
			 	cout<<">>Enter item price:";
			 	cin>>price;
			 	
			 	obj2.enqueue(name,quant,price);
			 	
			 	break;
			 
			 case 2:
			 	
			 	obj2.dqueue();
			 	
			 	break;
			 	
			 case 3:
				
				obj2.display();
				break;
				
			 case 0:
			      cout<<"\nDONE"<<endl;
			      break;
			      
			default:
		    	cout<<"You entered invalid choice";
		        break;
			      
		    }
			
		   }while(choice2 != 0);
		   
		   }break;
		    
		   
		case 3:
			{
			CQueue obj3;
			
		    do
			{
			
			cout<<"\n 1.Add food item \n 2.Delete food iteam \n 3.Display all food iteam \n 4.Press 0 to exit"<<endl;
			cout<<"Enter your Choice:";
			cin>>choice2;
			
			switch(choice2)
			{
			 case 1:
			 	cout<<"\n>>Enter item name:";
			 	cin>>name;
			 	cout<<">>Enter item quantity:";
			 	cin>>quant;
			 	cout<<">>Enter item price:";
			 	cin>>price;
			 	
			 	obj3.enqueue(name,quant,price);
			 	
			 	break;
			 
			 case 2:
			 	
			 	obj3.dqueue();
			 	
			 	break;
			 	
			case 3:
				
				obj3.display();
				break;
				
			case 0:
			      cout<<"\nDone"<<endl;
			      break;
			      
			default:
		    	cout<<"You entered invalid choice";
		        break;
			      
		    }
		    
		   }while(choice2 != 0);
		    
		    }break;
		    
		case 4:
		  {
			CLQueue obj4;
			
		    do
			{
			
			cout<<"\n 1.Add food item \n 2.Delete food iteam \n 3.Display all food iteam \n 4.Press 0 to exit"<<endl;
			cout<<"Enter your Choice:";
			cin>>choice2;
			
			switch(choice2)
			{
			
			 case 1:
			 	cout<<"\n>>Enter item name:";
			 	cin>>name;
			 	cout<<">>Enter item quantity:";
			 	cin>>quant;
			 	cout<<">>Enter item price:";
			 	cin>>price;
			 	
			 	obj4.enqueue(name,quant,price);
			 	
			 	break;
			 
			 case 2:
			 	
			 	obj4.dqueue();
			 	
			 	break;
			 	
			case 3:
				
				obj4.display();
				break;
				
			case 0:
			      cout<<"\nDone"<<endl;
			      break;
			      
			default:
		    	cout<<"You entered invalid choice";
		        break;
			      
		    }
		   } while(choice2 != 0); 
		    
		    }break;
		    
		    default:
		    	cout<<"You entered invalid choice";
		        break;
		    
		   }  
			
	}