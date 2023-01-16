
// Name - Mohit Jaiswal
// Batch - A4
// Roll No. - 57

#include <iostream>
using namespace std;

class node
{
    public:
    int roll_no;
    int marks;
    node *prev, *next;

    node()
    {
        prev=NULL;
        next=NULL;
    }
};

class marksheet
{
    int count=0;
    node *head;

    public:
    marksheet()
    {
        head=NULL;
    }

    int create();
    void display();
    void sort(int);
    void merge(marksheet, marksheet);
};

int marksheet::create()
{
    node*sample;
    char ch;

    do
    {
        sample=new node;
        cout<<"\nEnter roll number & marks -\n";
        cin>>sample->roll_no>>sample->marks;
    
        if(head==NULL)
        head=sample;

        else
        {
            node*p=head;

            while(p->next!=NULL)
            p=p->next;

            p->next=sample;
            sample->prev=p;
        }
        count++;

        cout<<"\nDo you want continue - ";
        cin>>ch;

    }while(ch=='y');
    return count;
}

void marksheet::display()
{
    node *p;

    p=head;

    while(p!=NULL)
    {
        cout<<"Roll = "<<p->roll_no<<"\t";
        cout<<"Mark = "<<p->marks;
        cout<<"\n";
        p=p->next;
    }
}

void marksheet::sort(int n)
{
    node* p, *q, *ptr1, *ptr2, *temp;
    int i;

    for(i=1; i<=n; i++)
    {
        q=head;
        while(q->next!=NULL)
        {
            if(q->marks>q->next->marks)
			{
				ptr1=q;
				ptr2=q->next;
				temp=ptr2->next;
				if(ptr1->prev!=NULL)
				{
					ptr1->prev->next=ptr2;
				}
                else
			    {
				    head=ptr2;
                }
				ptr2->next=ptr1;
				ptr2->prev=ptr1->prev;
				ptr1->next=temp;
				ptr1->prev=ptr2;
				if(temp!=NULL)
				{
					temp->prev=ptr1;
				}
				q=ptr2;
			}
			q=q->next;
        }
    }
}

void marksheet::merge(marksheet m1, marksheet m2)
{
    if(m1.head==NULL && m2.head==NULL)
    {
        head=NULL;
        return;
    }

    if(m1.head==NULL)
    {
        head=m2.head;
        return;
    }

    if(m2.head==NULL)
    {
        head=m1.head;
        return;
    }

    node*p, *q, *r;

    p=m1.head;
    q=m2.head;

    if(p->marks<=p->marks)
    {
        head=p; 
        r=p;
        p=p->next;
    }

    else
    {
        head=q;
        r=q;
        q=q->next;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->marks<=q->marks)
        {
            r->next=p;
            p->prev=r;
            p=p->next;
            r=r->next;
        }

        else
        {
            r->next=q;
            q->prev=r;
            q=q->next;
            r=r->next;
        }

        if(p!=NULL)
        {
            r->next=p;
            p->prev=r;
        }

        if(q!=NULL)
        {
            r->next=q;
            q->prev=r;
        }
    }
}


int main()
{
    marksheet m1, m2, m3;
    int cnt1, cnt2, choice, ch;

    do
    {
        cout<<"_____________________________________________\n\n";
        cout<<"1]. Create Marklist 1\n2]. Display Marklist 1\n3]. Create Marklist 2\n4]. Display Marklist 2\n5]. Sort Marklist 1\n6]. Sort Marklist 2\n7]. Merge List\n"<<endl;
        cout<<"Enter the Choice - ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cnt1=m1.create();
                break;

            case 2:
                cout<<"\nMarklist 1 =>\n";
                m1.display();
                break;

            case 3:
                cnt2=m2.create();
                break;

            case 4:
                cout<<"\nMarklist 2 =>\n";
                m2.display();
                break;
            
            case 5:
                cout<<"\nSorted 1 =>\n"
                m1.sort(cnt1);
                m1.display();
                break;

            case 6:
                cout<<"\nSorted 2 =>\n"
                m2.sort(cnt2);
                m2.display();
                break;

            case 7:
                cout<<"\nMerged Marklist =>\n";
                m3.merge(m1, m2);
                m3.display();
                break;

            default:
                cout<<"Wrong Selection!!";
                break;
        }

        cout<<"\nPress 1 to Continue..";
        cin>>ch;

    }while(ch==1);

    return 0;
}