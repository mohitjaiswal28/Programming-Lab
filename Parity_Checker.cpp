
//Name - Mohit Jaiswal
//Parity Checker

#include <iostream>
#include <string.h>
using namespace std;

class parity_checker
{
	public:
		int j=0, count=0;
		string s;
		int b[20];
	
    void input();
	void parity_check();
};

void parity_checker::input()
{
	cout<<"Enter the String - "<<endl;
	cin>>s;
}

void parity_checker::parity_check()
{
	int n=s.length();
	cout<<"\nString length is = "<<n<<endl;

	for(int i=0;i<n;i++)
	{
		int val=int(s[i]);
		cout<<s[i]<<" = "<<val<<endl;  //Takes the ASCII value
		
        j=0;
		while(val>0)
		{
			int p=val%2;              //Binary conversion
			b[j]=p;
			val=val/2;
			j++;
		}	
	}

	cout<<"\n";
	for(int i=j-1; i>=0; i--)
	{
		cout<<b[i];
		if(b[i]==1)
		{
			count++;             //Calculate no. of 1
		}
	}

	if(count%2==0)               //Check parity
	{
		cout<<"\nEven Parity"<<endl;
	}

	else
	{
		cout<<"\nOdd parity"<<endl;
	}
}

int main()
{
	parity_checker p;
	p.input();
	p.parity_check();
    return 0;
}