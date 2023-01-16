
//Name - Mohit Jaiswal
//Batch - A4
//Roll No. - 57

#include <iostream>
#define max 30
using namespace std;
class student
{
	public:
	int mark[max],n;                        //array of marks
	void getdata();
	void display();
	void sort();
	void linear();
	void binary();
	void sentinal();
	void fibo();
	 
};

void student::getdata()                       //marks of student
{
	cout<<"Enter number of student"<<endl;
	cin>>n;
	cout<<"Enter marks of students"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>mark[i];
	}
}

void student::display()
{
	cout<<"Marks of student"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<mark[i]<<endl;
	}
}

void student::sort()                 //sorting of marks
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mark[j]<mark[i])
		{
			int temp=mark[j];
			mark[j]=mark[i];
			mark[i]=temp;
		
		}
		}
		
	}
	
}

void student::linear()                   //linear search
{
	int key,flag=0;
	cout<<"Enter mark to be search"<<endl;
	cin>>key;
	for(int i=0;i<n;i++)
	{
		if(mark[i]==key)
		{
			cout<<"Your mark found at position :"<<i+1<<endl;
			flag=1;
			break;
			
		}
		
	}
	if(flag!=1)
	{
		cout<<"Your mark not found"<<endl;
	}
		
	
}

void student::binary()                                    //binary search
{
	int key,flag=0;
	int low=0,high=n-1;
	int mid;
	cout<<"Enter mark to be search"<<endl;
	cin>>key;
	
	while(low<=high)
	{    mid=low+(high-low)/2;
		
		if(mark[mid]==key)
	{
		cout<<"Your mark found at position :"<<mid+1<<endl;
		flag=1;
		break;
		
	}
	else 
	{
		if(key<mark[mid])	
	   {
	   	 high=mid-1;
	   }
	   
	   else	
	   {
	   	low=mid+1;
	   }
		
	}
	
}
	if(flag!=1)
	{
		cout<<"Your mark not found"<<endl;
	}
	
}

void student::sentinal()                              //sentinal search
{
	int last,key,i=0;
	cout<<"Enter mark to be searched"<<endl;
	cin>>key;
	last=mark[n-1];
	mark[n-1]=key;
	
	while(mark[i]!=key)
	i++;
	mark[n-1]=last;
	
	if(i<(n-1) || mark[i]==key)
	{
		cout<<"Your mark is found at position :"<<i+1<<endl;
	}
	else
	{
		cout<<"Your mark not found"<<endl;
	}
	
}

void student::fibo()                               //fibonacy search
{
	 int key;
	cout<<">>\nEnter marks to be search : ";
    cin>>key;
    
    int offset = 0;
    int fb_prev2 = 0;
    int fb_prev1 = 1;
    int fb_curr = fb_prev2 + fb_prev1;

    while (fb_curr < n)
    {
        fb_prev2 = fb_prev1;
        fb_prev1 = fb_curr;
        fb_curr  = fb_prev2 + fb_prev1;
    }
    
    int i=0;
    
    while (fb_curr > 1)
    {
      i = min(offset+fb_prev2, n-1);
      if (mark[i] < key)
      {
        fb_curr  = fb_prev1;
        fb_prev1 = fb_prev2;
        fb_prev2 = fb_curr - fb_prev1;
        offset = i;
      }
      else if (mark[i] > key)
      {
        fb_curr  = fb_prev2;
        fb_prev1 = fb_prev1 - fb_prev2;
        fb_prev2 = fb_curr - fb_prev1;
      }
      else
      {
      	cout<<" \nGiven Marks found at position : "<<i+1<<endl;
 	    
	   break;
      	
	  }

    }
    
    if(fb_prev1 && mark[offset+1] == key)
    {
     cout<<" \nGiven Marks found at position : "<<offset+2<<endl;
 	 
	}
    
	else
	{
		cout<<"\nMarks was not found"<<endl;
		
	} 
}

int main()
{
	student s;
	int choice;
	char ch;
	s.getdata();
	
	
	do
	{
		cout<<"***Menu***"<<endl;
		cout<<"\n1.display\n2.linear Search\n3.binary Search\n4.sentinal search"<<endl;
		cout<<"5.fibonacii search"<<endl;
		cout<<"Enter your choice"<<endl;
	    cin>>choice;
	
	switch(choice)
	{
		case 1:                                //display
			s.display();
			break;
		case 2:                               //linear search
			s.linear();
			break;
		case 3:                               //binary search
			cout<<"Sorted Array"<<endl;        //first sorting 
			s.sort();
			s.display();
			s.binary();
			break;
		case 4:                                 //sentinal search
			s.sentinal();
			break;
		case 5:                                //fibonacy search
			s.sort();                           //first sorting
			cout<<"Your sorted array"<<endl;
			s.display();
			s.fibo();
			
	}
	cout<<"Do you want to continue"<<endl;
	cin>>ch;
}while(ch=='y');
	
}


//OUTPUT
/*Enter number of student
5
Enter marks of students
21
78
90
54
3
***Menu***

1.display
2.linear Search
3.binary Search
4.sentinal search
5.fibonacii search
Enter your choice
1
Marks of student
21
78
90
54
3
Do you want to continue
y
***Menu***

1.display
2.linear Search
3.binary Search
4.sentinal search
5.fibonacii search
Enter your choice
2
Enter mark to be search
78
Your mark found at position :2
Do you want to continue
y
***Menu***

1.display
2.linear Search
3.binary Search
4.sentinal search
5.fibonacii search
Enter your choice
3
Sorted Array
Marks of student
3
21
54
78
90
Enter mark to be search
54
Your mark found at position :3
Do you want to continue
y
***Menu***

1.display
2.linear Search
3.binary Search
4.sentinal search
5.fibonacii search
Enter your choice
4
Enter mark to be searched
1
Your mark not found
Do you want to continue
y
***Menu***

1.display
2.linear Search
3.binary Search
4.sentinal search
5.fibonacii search
Enter your choice
5
Your sorted array
Marks of student
3
21
54
78
90
>>
Enter marks to be search : 90

Given Marks found at position : 5

Given Marks found at position : 5
Do you want to continue
n

--------------------------------
Process exited after 76.59 seconds with return value 0
Press any key to continue . . .*/