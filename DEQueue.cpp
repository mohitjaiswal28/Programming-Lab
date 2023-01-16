
//Name - Mohit Jaiswal
//Batch - A4
//Roll No. - 57

#include<iostream>
#include<string.h>
#define max 15

using namespace std;

class Mall
{   public:
	string product_name;
	int price;
	
	void input()
	{
	 cout<<"\nEnter the product name: ";
	 cin>>product_name;
	 cout<<"\nEnter price: ";
	 cin>>price;	
	}
		
};

class Dequeue
{
	public:
	Mall data[max];
	int front,rear;
	
	Dequeue()
	{
		front=rear=-1;
		
	}
	
	void enqueue_F(Mall m);
	void enqueue_R(Mall m);
	void dequeue_F();
	void dequeue_R();
	bool is_empty();
	bool is_full();
	void display();
};

bool Dequeue ::is_empty()
{
	if (front==-1)
	 return true;
	 
	else
	return false;
}

bool Dequeue ::is_full()
{
	if(front==(rear+1)%max)
	return true; 
	else
	return false;
}

void Dequeue::enqueue_F(Mall m)
{
	if(is_empty())
	{
		rear=0;
		front=0;
	}
	
	else
	{
		front=(front-1+max)%max;
	}
	
	data[front].product_name=m.product_name;
	data[front].price=m.price;
	
}

void Dequeue::enqueue_R(Mall m)
{
	if(is_empty())
	{
		rear=0;
		front=0;
	}
	
	else
	{
		rear=(rear+1)%max;
	}
	
	data[rear].product_name=m.product_name;
	data[rear].price=m.price;
}

void Dequeue::dequeue_F()
{ 
  if(is_empty())
  {
  	cout<<"Queueu is empty"<<endl;
  	
  }
  else
  {
  cout<<"\n*************";
  cout<<"\nDeleted product is :"<<endl;
  cout<<"\nPrice : "<<data[front].price<<endl;
  cout<<"********\n";
     if(rear==front)
     {
  	  rear=front=-1;
     }
  
      else
     {
  	   front=(front+1)%max;
  	
     }
  }	
}

void Dequeue::dequeue_R()
{ 
  if(is_empty())
  {
  	cout<<"Queueu is Empty"<<endl;
  	
  }
  else
  {
  cout<<"\n************";
  cout<<"\nDeleted product is : "<<endl;
  cout<<"\nPrice : "<<data[rear].price<<endl;
  cout<<"******\n";
     if(rear==front)
     {
  	  rear=front=-1;
     }
  
      else
     {
     	if(rear==0)
     	{
     	  rear=max-1;	
		}
		else
		{
		  rear--;	
		}
  	
     }
  }	
}

void Dequeue::display()
{
	cout<<"\n*********"<<endl;
	cout<<"Display"<<endl;
	if(front<=rear)
	{
		for(int i=front; i<=rear; i++)
		{
		cout<<"\nProduct name is : "<<data[i].product_name<<endl;
        cout<<"\nPrice : "<<data[i].price<<endl;	
	   }
		
	}
	
	else
	{
		for(int i=front; i<=max-1; i++)
		{
		cout<<"\nProduct name is : "<<data[i].product_name<<endl;
        cout<<"\nPrice : "<<data[i].price<<endl;	
	   }
	   
	   for(int i=0; i<=rear; i++)
		{
		cout<<"\nProduct name : "<<data[i].product_name<<endl;
        cout<<"\nPrice : "<<data[i].price<<endl;	
	   }
		
	}
	cout<<"\n********"<<endl;
}

int main()
{
	Mall m;
	Dequeue obj;
	int choice;
	do
	{
	cout<<"\nSelect the task:"<<endl;
	cout<<"\n 1.Insert at Front\n 2.Insert at Rear\n 3.Delete from Front";
	cout<<"\n 4)Delete from Rear\n 5)Dislay all products\n 6)Press 0 to exit "<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	cout<<"\n";
	
	switch(choice)
	{
		case 1:
			m.input();
			obj.enqueue_F(m);
			
		break;
		
		case 2:
			m.input();
			obj.enqueue_R(m);
			
		break;
		
		case 3:
			obj.dequeue_F();
			
		break;
		
		case 4:
			obj.dequeue_R();
			
		break;
		
		case 5:
			obj.display();
			
		break;
		
		case 0:
			cout<<"\nTask Completed"<<endl;
			
		break;	
		
		default:
			cout<<"Invalid choice";
			break;
	}
	
   }while(choice!=0);

	
}

//OUTPUT

/*Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 1


Enter the product name: sugar

Enter price: 80

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 1


Enter the product name: oil

Enter price: 50

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 2


Enter the product name: masala

Enter price: 90

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 5


*******
Display

Product name is : oil

Price : 50

Product name : sugar

Price : 80

Product name : masala

Price : 90

******

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 3


*************
Deleted product is :

Price : 50
********

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 5


*******
Display

Product name is : sugar

Price : 80

Product name is : masala

Price : 90

******

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 2


Enter the product name: tea

Enter price: 30

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 3


*************
Deleted product is :

Price : 80
********

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 5


*******
Display

Product name is : masala

Price : 90

Product name is : tea

Price : 30

******

Select the task:

 1.Insert at Front
 2.Insert at Rear
 3.Delete from Front
 4)Delete from Rear
 5)Dislay all products
 6)Press 0 to exit
Enter your choice : 0


Task Completed

--------------------------------
Process exited after 154.7 seconds with return value 0
Press any key to continue . . .*/