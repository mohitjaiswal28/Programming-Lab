
#include <iostream>
using namespace std;

class Node
{
    public:
    int prn;
    string name;

    Node*next;              //node pointer

    Node()
    {
        next=NULL;              //whenever the node will be created it's next will be NULL
    }
};

class SLL
{
    public:
    Node* head;

    SLL()
    {
        head=NULL;
    }

    public:
    void create();
    void display();
    void insert_begin();
    void insert_end();
    void insert_after(int x);//by value
    int search(int x);
    int deletePRN(int info);
    void update();
    void sort();
};

//creating a list
void SLL::create()
{
    Node * temp, *p;
    char choice;

    do
    {
        temp = new Node();

        cout<<"\nEnter the name of the Student -\n";
        cin>>temp->name;

        cout<<"Enter the PRN number -\n";
        cin>>temp->prn;

        if(head==NULL)
        {
            head=temp;
        }

        else
        {
            p=head;

            while(p->next!=NULL)
                p=p->next;

            p->next=temp;
        }

        cout<<"\nDo you want to add some more nodes -\n";
        cin>>choice;
    }while(choice!='n');
}

//display the list
void SLL::display()
{
    Node *p;

    if(head==NULL)
    cout<<"Linked List is Empty!!!";

    else
    {
        p=head;
        
        cout<<"\nName\t\tPRN number\n";
        while(p!=NULL)
        {
            cout<<"\n";
            cout<<p->name;
            cout<<"\t\t";
            cout<<p->prn;
            p=p->next;
        }
        cout<<"\n";
    }
}

//insert at begining
void SLL::insert_begin()
{
    Node *temp;
    temp = new Node();

    cout<<"\nEnter the name of the Student -\n";
    cin>>temp->name;

    cout<<"\nEnter the PRN number -\n";
    cin>>temp->prn;

    if(head==NULL)              //linked list is empty
    head=temp;

    else
    {
        temp->next=head;
        head=temp;
    }
}

//insert at end
void SLL::insert_end()
{
    Node *temp;
    temp = new Node();

    cout<<"\nEnter the name of the Student -\n";
    cin>>temp->name;

    cout<<"\nEnter the PRN number -\n";
    cin>>temp->prn;

    Node *p;

    if(head==NULL)              //linked list is empty
        head=temp;

    else
    {
        p=head;

        while(p->next!=NULL)
            p=p->next;

        p->next=temp;
    }
}

//insert after element
void SLL::insert_after(int x)
{
    if(head==NULL)
        cout<<"\nEMPTY!!";

    else
    {
        Node *p, *temp;
        int flag=0;
        
        cout<<"\nEnter the name of the Student -\n";
        cin>>temp->name;

        cout<<"\nEnter the PRN number -\n";
        cin>>temp->prn;

        while(p!=NULL)
        {
            if(p->prn==x)
            {
                flag=1;
                break;
            }

            p=p->next;
        }

        if(flag==0)
            cout<<"\nElement not found!!!\n";

        else
        {
            temp->next=p->next;
            p->next=temp;
        }

    }
}

//searching an element in linked list
int SLL::search(int x)
{
    if(head==NULL)
    {
        cout<<"List is Empty";
    }

    else
    {
    	Node *p;
        p=head;

        while(p!=NULL)
        {
            if(p->prn==x)
            return 1;
            break;
            
            p=p->next;
        }

        return 0;
    }
}

//delete
int SLL::deletePRN(int info)
{
	if(head==NULL)
	cout<<"List is Empty!!";
	
	else
	{
		int flag=0;
		Node *p, *prev, *temp;
		p=head;
		
		while(p!=NULL)
		{
			if(p->prn==info)
			{
				flag=1;
				break;					//PRN is found
			}
			prev=p;
			p=p->next;
		}
		
		if(flag==1)
		{
			if(p==head)					//if element is at first
			{									
				temp=p;
				head=head->next;
				delete temp;	
			}
			
			else if(p->next==NULL)						//if element is at last
			{								
				prev->next=p->next;
				delete p;
			}
			
			else									//if element is at other positions
			{
				prev->next=p->next;
				p->next=NULL;
				delete p;	
			}
			
			cout<<"Deleted Successfully!!";
		}
		
		else
		cout<<"\nPRN is not found!!";
	}
	
}

//updating the list
void SLL::update()
{
    int x;

    cout<<"\nEnter the PRN number to be updated -\n";
    cin>>x;

    if(head==NULL)
    cout<<"\nList is Empty!!!";

    else
    {
        int flag=0;
        Node *p;
        p=head;

        while(p!=NULL)
        {
            if(p->prn==x)
            {
                cout<<"\nEnter the new Name of the Student-\n";
                cin>>p->name;

                cout<<"\nEnter the new PRN number -\n";
                cin>>p->prn;
                flag=1;
                break;
            }
            p=p->next;
        }

        if(flag==1)
        cout<<"\nUpadted Successfully!!";

        else
        cout<<"\nElement not found!!";
    }
}

//sorting the linked list
void SLL::sort()
{
    Node *p, *q, *temp;
    temp=new Node;

    p=head;

    if(head==NULL)
    cout<<"List is Empty";

    else
    {
        while(p->next!=NULL)
        {
            q=head;
            while(q->next!=NULL)
            {
                if((q->prn)>((q->next)->prn))
                {
                    temp->name=q->name;
                    temp->prn=q->prn;

                    q->name=(q->next)->name;
                    q->prn=(q->next)->prn;

                    (q->next)->name=temp->name;
                    (q->next)->prn=temp->prn;
                }

                q=q->next;
            }
            p=p->next;
        }
    }
}


int main()
{   
    SLL s;
    int ch;
    
    do
    {
        cout<<"\n------------------------------------------[STUDENT LINKED LIST]---------------------------------------------------"<<endl;
        cout<<"1]. Create\n2]. Display\n3]. Insert\n4]. Delete\n5]. Search\n6]. Update\n7]. Sort\n0].Exit the Program";
        cout<<"\n\nEnter the choice -\n";
        cin>>ch;

        switch(ch)
        {
            case 1:
                s.create();
                break;

            case 2:
                s.display();
                break;

            case 3:
                int insert_type;

                cout<<"\n_____________________________INSERT OPTIONS_____________________________\n";
                cout<<"\n1]. Insert at begining\n2]. Insert at end\n3]. Insert after element\n"<<endl;
                cout<<"Enter the insert type -\n";
                cin>>insert_type;

                switch(insert_type)
                {
                    case 1:
                        s.insert_begin();
                        break;

                    case 2:
                        s.insert_end();
                        break;

                    case 3:
                        int x;

                        cout<<"\nEnter the element after which you want to add -\n";
                        cin>>x;

                        s.insert_after(x);
                        break;
                        
                    	default:
                        break;
                }
                break;
                
            case 4:
                int info;
                	
                cout<<"\nEnter the PRN number to delete -\n";
                cin>>info;
                	
                s.deletePRN(info);
                break;
                	
            case 5:
                int key;

                cout<<"\nEnter the PRN number to search -\n";
                cin>>key;

                if(s.search(key)==0)
                    cout<<"\nPRN number "<<key<<" not found!!";

                else
                cout<<"PRN number "<<key<<" is found!!";
                break;

            case 6:
                s.update();
                break;

            case 7:
                s.sort();
                cout<<"\nSorted Successfully!!";
                break;
                    
            case 0 :
                cout<<"Thank You!!";
                break;

            default :
                cout<<"Wrong Selection!!\nPlease Selecet from the above menu!!";
        }

    }while(ch!=0);

    return 0;
}
