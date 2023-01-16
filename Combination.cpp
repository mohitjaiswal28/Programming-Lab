
//Name - Mohit Jaiswal
//Permutation for String

#include <iostream>
#include <string.h>
using namespace std;
char temp[10];          //Temporary array to store combination

void combinations(char str[],int r,int index) 
{
	for(int i=0;i<strlen(str);i++)
	{
		temp[index]=str[i];
		if(index==r-1)
		{
			cout<<temp<<"\t";
		}

		else
		{
			combinations(str,r,index+1);
		}
	}
}

int main()
{
	int n;
	char str[10];
	cout<<"\nEnter string - ";
	cin>>str;
	cout<<"\nPossible combination of string are =>\n"<<endl;
	for(int r=1;r<=strlen(str);r++)
	{
		combinations(str,r,0);
	}
	return 0;
}
