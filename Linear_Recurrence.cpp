
/*
    Name - Mohit Jaiswal
    Roll No. - 57
    Practical No. 14
*/

#include <iostream>
using namespace std;

float amount_return(float balance,float intrest_rate,int duration)  //Linear recurrence relation
{
	if(duration==0)
	{
		return balance;
	}
	else
	{
		float intrest=balance*(intrest_rate/100);
		return amount_return(balance+intrest,intrest_rate,duration-1);
	}
}

int main()
{
	int time,choice,intrest_rate,amount;
	char ch;

	do
	{
		cout<<endl;
		cout<<"*Loan list*"<<endl;
		cout<<"\n1.Education loan \n2.Home loan \n3.Car loan"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"\nEnter your choice"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:                                           //Education loan
				cout<<"Amount \t\t\t\t intrest rate"<<endl;
				cout<<"0-10000 Rs \t\t\t 5%"<<endl;
				cout<<"10000-50000 Rs \t\t\t 7%"<<endl;
				cout<<"More than 50000 Rs \t\t 9%"<<endl;
				cout<<"Enter the amount"<<endl;
				cin>>amount;
				cout<<"Enter the time"<<endl;
				cin>>time;
		
				if(amount<=10000)
				{
					intrest_rate=5;
				}
				else if(amount>10000 && amount<50000)
				{
					intrest_rate=7;
				}
				else
				{
					intrest_rate=9;
				}
        cout<<"You have to repay amount is : "<<amount_return(amount,intrest_rate,time)<<" after "<<time<<" year"<<endl;
		break;
		
		case 2:                                          //Home Loan
			cout<<"Amount \t\t\t\t intrest rate"<<endl;
			cout<<"0-10000 Rs \t\t\t 9%"<<endl;
			cout<<"10000-50000 Rs \t\t\t 10%"<<endl;
			cout<<"More than 50000 Rs \t\t 15%"<<endl;
			cout<<"Enter the amount"<<endl;
			cin>>amount;
			cout<<"Enter the time"<<endl;
			cin>>time;
	
			if(amount<=10000)
			{
				intrest_rate=9;
			}
			else if(amount>10000 && amount<50000)
			{
				intrest_rate=10;
			}
			else
			{
				intrest_rate=15;
			}
        cout<<"You have to repay amount is : "<<amount_return(amount,intrest_rate,time)<<" after "<<time<<" year"<<endl;
		break;
		
		case 3:                                         //Car Loan
			cout<<"Amount \t\t\t\t intrest rate"<<endl;
			cout<<"0-10000 Rs \t\t\t 12%"<<endl;
			cout<<"10000-50000 Rs \t\t\t 15%"<<endl;
			cout<<"More than 50000 Rs \t\t 19%"<<endl;
			cout<<"Enter the amount"<<endl;
			cin>>amount;
			cout<<"Enter the time"<<endl;
			cin>>time;
	
			if(amount<=10000)
			{
				intrest_rate=12;
			}
			else if(amount>10000 && amount<50000)
			{
				intrest_rate=15;
			}
			else
			{
				intrest_rate=19;
			}
        cout<<"You have to repay amount is : "<<amount_return(amount,intrest_rate,time)<<" after "<<time<<" year"<<endl;
		break;
		
		case 4:
			exit(0);
			break;
		default:
		cout<<"Invalid choice"<<endl;
	}
}while(choice<5);
return 0;
}