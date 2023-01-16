
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

//Stack class
class Stack
{
	public:
		string arr[MAX];
		int top;

	Stack()
	{
		top=-1;
	}

public:
	int isEmpty();
	void push(string temp);
	string pop();
};

int Stack::isEmpty()
{
	if(top==-1)
		return 1;

	return 0;
}

void Stack::push(string temp)
{
	top++;
	arr[top]=temp;
}

string Stack::pop()
{
	string x;

	x=arr[top];
	top--;

	return x;
}

//Expression class
class expression
{
public:
	string infix, postfix, prefix;
	Stack s;
    
    int prec(string ch)
    {
        if(ch=="^")
            return 3;

        else if(ch=="*" || ch=="/")
            return 2;

        else if(ch=="+" || ch=="-")
            return 1;

        else	
            return 0;
     }

	bool isOperator(char ch)
	{
    	if(ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-')
        	return true;

    	else
        	return false;
	}

    void infix_postfix();
	void postfix_prefix();
    void postfix_eval();
};

void expression::infix_postfix()
{
	cout<<"\nInfix = ";
	cin>>infix;
	
	for(int i=0; infix[i]!='\0'; i++)
	{
		//for operands
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			postfix=postfix+infix[i];
		}

		//for brackets
		else if(infix[i]=='(')
			s.push("(");

		else if(infix[i]==')')
		{
			while(s.arr[s.top]!="(" && !s.isEmpty())
			{
				string t=s.pop();
				postfix=postfix+t;
			}

			if(s.arr[s.top]=="(")
				s.pop();
		}

		//for operators
		else
		{
			while((prec(string(1, infix[i])))<=prec(s.arr[s.top]) && !s.isEmpty())
			{
			  	string t=s.pop();
			 	postfix=postfix+t;
			}

			s.push(string(1, infix[i]));
		}
	}
		while(!s.isEmpty())
		{
		  	string t=s.pop();
		  	postfix=postfix+t;
		}
	

	cout<<"\nPostfix = "<<postfix<<endl;
}

void expression::postfix_prefix()
{
	cout<<"\nPostfix = ";
    cin>>postfix;

    for(int i=0; i<postfix.length(); i++)
    {
        if(isOperator(postfix[i]) && !s.isEmpty())
        {
            string op2=s.pop();
            string op1=s.pop();

            string t=postfix[i]+op1+op2;

            s.push(t);
        }

        else
        {
            s.push(string(1, postfix[i]));
        }
    }

    cout<<"\nPrefix = "<<s.pop();
}

void expression::postfix_eval()
{
    cout<<"\nPostfix = ";
    cin>>postfix;

    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isOperator(postfix[i]))
		{
		    int op_1, op_2;
		    int ans;
		    
		    string op2=s.pop();
		    string op1=s.pop();
		    
			stringstream stm1(op1);
			stringstream stm2(op2);
			
			stm1>>op_1;
			stm2>>op_2;

			switch(postfix[i])
            {
                case '+':
                    ans=op_1+op_2;
                    break;
            }

			stringstream stm3;
			stm3<< ans ;
			string ans1=stm3.str();
			s.push(ans1);
		}

        else
        {
            s.push(string(1,postfix[i]));
        }
    }

    cout<<"\nAnswer = "<<s.pop();
}

int main()
{
	expression e;
    int choice;

    do
    {
        cout<<"\n----------------------------------------------------------------\n";
        cout<<"1]. Infix to Postfix\n2]. Postfix to Prefix\n3]. Postfix Evaluation\n0]. Exit the Program\n";
        cout<<"\nEnter the Choice - ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            e.infix_postfix();
            break;
        
        case 2:
            e.postfix_prefix();
            break;

        case 3:
            e.postfix_eval();
            break;

        case 0:
            cout<<"Thank You!!";
            break;

        default:
            cout<<"\nWrong Selection!!";
            break;
        }
    }while(choice!=0);
    
	return 0;
}
