#include<iostream>
using namespace std;

class node
{
	public:
		int coef;
		int expo;
		node *next;	
};

class poly
{
	public:
		node *head;
		poly()
		{
			head = NULL;
		}
		void sortedCreate(node *temp);
		void add(poly p1, poly p2);
		void multiply( poly p1, poly p2);
		void display();
};

void poly::sortedCreate(node *temp)                       //Sorting the polynomial
{
	node *p;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		if(temp->expo > head->expo)
		{
			temp->next=head;
			p=head;
		
			while(p->next!=head)
			{
				p=p->next;
			}
			p->next=temp;
			head=temp;
		}
		
		else 
		{
			if(temp->expo==head->expo)
			{
				head->coef +=temp->coef;
			}
			
			else
			{
				p=head;
				int f=1;
				while(1)
				{
					if(p->expo==temp->expo)
					{
						p->coef=p->coef+temp->coef;
						f=2;
						break;
					}
					else if((p->expo>temp->expo && temp->expo>p->next->expo)|| p->next==head)
					{
						f=1;
						break;
					}
					p=p->next;
				}
				if(f==1)
				{
					temp->next=p->next;
					p->next=temp;
				}
			}
		}
	}
}

void poly::add(poly p1, poly p2)                            //Adding the polynomial
{
	node *t1, *t2, *t3;
	t1=p1.head;
	t2=p2.head;
	do
	{
		t3=new node;
		t3->coef=t1->coef;
		t3->expo=t1->expo;
		t3->next=t3;
		sortedCreate(t3);
		t1=t1->next;	
	}while(t1!=p1.head);

	do
	{
		t3=new node;
		t3->coef=t2->coef;
		t3->expo=t2->expo;
		t3->next=t3;
		sortedCreate(t3);
		t2=t2->next;	
	}while(t2!=p2.head);
	
}

void poly::multiply(poly p1, poly p2)               //Multiplication
{
	node *t1, *t2, *t4;
	t1=p1.head;

	do
	{	
		t2=p2.head;
		do
		{
			t4=new node;
			t4->coef=t1->coef * t2->coef;
			t4->expo=t1->expo + t2->expo;
			t4->next=t4;
			sortedCreate(t4);
			t2=t2->next;
		}while(t2!=p2.head);
		t1=t1->next;
	}while(t1!=p1.head);
}


void poly::display()                                   //Display
{
	node *p=head;
	do
	{
		cout<< p->coef <<"x^"<< p->expo <<" + ";
		p=p->next;
		
	}while(p->next!=head);
	cout<< p->coef <<"x^"<< p->expo;
	cout<<" = 0";
}

int main()
{
	poly p1, p2, p3,p4;
	char ch;
	int choice;
	node *temp;

	cout<<"\nEnter polynomial 1 : \n";                           //For poly 1
	do{
		temp=new node;
		cout<<"\nEnter the coefficient -\n";
		cin>>temp->coef;
		temp->next=temp;
		cout<<"Enter the exponent -\n";
		cin>>temp->expo;
		temp->next=temp;
		p1.sortedCreate(temp);
		cout<<"\nDo you want to add more nodes - ";
		cin>>ch;
		
	}while(ch=='y');
	cout<<"\nPolynomial 1 is :  ";
	p1.display();
	cout<<"\n------------------------------------------------------------------------------------";

	cout<<"\nEnter polynomial 2 : \n";                               //For poly 2
	do{
		temp=new node;
		cout<<"\nEnter the coefficient -\n";
		cin>>temp->coef;
		cout<<"Enter the exponent -\n";
		cin>>temp->expo;
		temp->next=temp;
		p2.sortedCreate(temp);
		cout<<"\nDo you want to add more nodes - ";
		cin>>ch;
		
	}while(ch=='y');
	cout<<"\nPolynomial 2 is :  ";
	p2.display();
    cout<<"\n------------------------------------------------------------------------------------";
	
	do{
	    cout<<"\n\n1].Addition \n2].Multiplication ";
		cout<<"\n\nEnter your choice of operation - ";
		cin>>choice;
	
		switch (choice)
		{
			case 1:
				p3.add(p1,p2);
				cout<<"\nAddition is : ";
				p3.display();
				break;

			case 2:
				p4.multiply(p1,p2);
				cout<<"\nMultiplication is : ";
				p4.display();
				break;
			
			default:
				cout<<"\nInvalid choice of operation !!";
				break;

		}
        cout<<"\n\nDo you wants to continue - "<<endl;
		cin>>ch;
	}while(ch!='n');

    return 0;

}