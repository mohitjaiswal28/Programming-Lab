
/*
    Name - Mohit Jaiswal
    Date - 19/09/2022
*/

#include <iostream>
#define MAX 10
using namespace std;

class sparse
{
    public:

    int a[10][10];
    int sp[MAX][3];
    int r, c, l;

    public:

    void accept();
    void display_normal();
    void convert();
    void display();
    sparse addition(sparse sp2);
    sparse transpose();
    sparse multiply(sparse sp2);
};

void sparse::accept()			//accepting the elements of matrix
{
    int i, j;

    cout<<"\nEnter the number of rows and columns -\n";
    cin>>r>>c;

    cout<<"\nEnter the "<<r*c<<" elements -\n";

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }
}

void sparse::display_normal()			//displaying the normal matrix
{
    int i, j;

    cout<<"\nNormal matrix is -->\n\n";

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout<<a[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }
}

void sparse::convert()						//converting into sparse matrix
{
    int i, j;

    sp[0][0]=r;
    sp[0][1]=c;

    l=0;

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(a[i][j]!=0)
            {
                sp[l+1][0]=i;
                sp[l+1][1]=j;
                sp[l+1][2]=a[i][j];

                l++;
            }
        }
    }

    sp[0][2]=l;
}

void sparse::display()								//displaying the sparse matrix
{
    int i, j;
   
   cout<<"\n";
    for(i=0; i<=sp[0][2]; i++)
    {
        for(j=0;j<3;j++)
		{
			cout<<" "<<sp[i][j];
		}
		cout<<"\n";
    }
}

sparse sparse::addition(sparse sp2)							//addtion of sparse matrix
{
	int i,j,k;
	sparse sp3;
	
	if(r!=sp2.r || c!=sp2.c)
	{
		cout<<"Addition not possible!!"<<endl;
		return sp3;
	}
	
	i=1,j=1,k=1;
	sp3.sp[0][0]=sp[0][0];
	sp3.sp[0][1]=sp[0][1];
	
	while(i<=l && j<=sp2.l)
	{
		if(sp[i][0]==sp2.sp[j][0] && sp[i][1]==sp2.sp[j][1])
		{
			sp3.sp[k][0]=sp[i][0];
			sp3.sp[k][1]=sp[i][1];
			sp3.sp[k][2]=sp[i][2]+sp2.sp[j][2];
			i++;
			j++;
			k++;
		}

		else if(sp[i][0]==sp2.sp[j][0])
		{
			if(sp[i][1]<sp2.sp[i][1])
			{
				sp3.sp[k][0]=sp[i][0];
				sp3.sp[k][1]=sp[i][1];
				sp3.sp[k][2]=sp[i][2];
				i++;
				k++;
			}

			else
			{
				sp3.sp[k][0]=sp2.sp[j][0];
				sp3.sp[k][1]=sp2.sp[j][1];
				sp3.sp[k][2]=sp2.sp[j][2];

				j++;
				k++;
			}
		}

		else
		{
			if(sp[i][0]<sp2.sp[j][0])
			{
				sp3.sp[k][0]=sp[i][0];
				sp3.sp[k][1]=sp[i][1];
				sp3.sp[k][2]=sp[i][2];

				i++;
				k++;
			}

			else
			{
				sp3.sp[k][0]=sp2.sp[j][0];
				sp3.sp[k][1]=sp2.sp[j][1];
				sp3.sp[k][2]=sp2.sp[j][1];
				j++;
				k++;
		    }
		}
	}
	
	while(i<=l && j>=l)
	{
		sp3.sp[k][0]=sp[i][0];
		sp3.sp[k][1]=sp[i][1];
		sp3.sp[k][2]=sp[i][2];

		i++;
		k++;
	}
	
	while(j<=l && i<=l)
	{
		sp3.sp[k][0]=sp2.sp[j][0];
		sp3.sp[k][1]=sp2.sp[j][1];
		sp3.sp[k][2]=sp3.sp[j][2];
		
		j++;
		k++;
	}

	sp3.sp[0][2]=(k-1);

}

sparse sparse::transpose()						//transpose of sparse matrix
{
    sparse sp3;

    int i, j;
	int k=1;

    sp3.sp[0][0]=sp[0][1];
    sp3.sp[0][1]=sp[0][0];
    sp3.sp[0][2]=sp[0][2];

    for(i=0; i<=sp[0][2]; i++)
    {
        for(j=1; j<=sp[0][2]; j++)
        {
            if(sp[j][1]==i)
            {
                sp3.sp[k][0]=sp[j][1];
                sp3.sp[k][1]=sp[j][0];
                sp3.sp[k][2]=sp[j][2];

                k++;
            }
        }
    }

    return sp3;
}

sparse sparse::multiply(sparse sp2)							//multiplication of sparse matrix
{
	int i, j, t1, t2;
	int t3=1;
	sparse sp3;
	
	if(sp[0][1]!=sp2.sp[0][1])
	{
		cout<<"Multiplication is not possible!!";	
		return sp3;
	}
	
	sp3.sp[0][0]=sp2.sp[0][0];	
	sp3.sp[0][1]=sp2.sp[0][0];	
	
	for(i=0; i<sp3.sp[0][0]; i++)
	{
		for(j=0; j<sp3.sp[0][0]; j++)
		{
			int sum=0;
			int flag1=0, flag2=1;
			t1=t2=1;
			
			while(t1<sp[0][2])
			{
				if(sp[t1][0]==i)
				{
					flag1=1;
					break;
				}
			}//end of while
			
			while(t2<sp[0][2])
			{
				if(sp[t2][0]==j)
				{
					flag2=1;
					break;
				}
			}//end of while
			
			if(flag1==1 && flag2==1)
			{
				while(i==sp[t1][0] && j==sp2.sp[t2][0])
				{
					if(sp[t1][1]==sp2.sp[t2][1])
					{
						sum=sum+sp[t1][2]*sp2.sp[t2][2];
						
						t1++;
						t2++;
					}
					
					else if(sp[t1][1]<sp2.sp[t2][1])
					t1++;
					
					else
					t2++;
				}//end of while
				
				if(sum>0)
				{
					sp3.sp[t3][0]=i;
					sp3.sp[t3][1]=j;
					sp3.sp[t3][2]=sum;
					
					t3++;
				}
			}
		}//innner loop ends
	}//outer loop ends
	
	sp3.sp[0][2]=t3-1;
	return sp3;
}


int main()
{
    sparse sp1,sp2, sp3;
    int choice;

    
    do
    {
        cout<<"\n-------------------------------------------------------------------------------------------";
        cout<<"\n1. Accept matrix\n2. Display \n3. Convert and Display\n4. Addition\n5. Transpose\n6. Multiply\n0. Exit Program\n";

        cout<<"\nEnter the Choice : ";
        cin>>choice;

        switch (choice)
        {
	        case 1:
	        	//accept
	            sp1.accept();
	            break;
	
	        case 2:
	        	//display normal
	            sp1.display_normal();
	            break;
	
	        case 3:
	        	//covert to sparse
	            sp1.convert();
	            sp1.display();
	            break;
	
	        case 4:
	        	//addition
	        	sp1.accept();
	        	sp1.convert();
	        	sp2.accept();
	        	sp2.convert();
	        	sp3=sp1.addition(sp2);
	        	
	        	cout<<"\nAddition is -->\n";
	        	sp3.display();
	        	break;
	
	        case 5:
	        	//transpose
	            cout<<"Transpose is --->"<<endl;
	            sp3=sp1.transpose();
	            sp3.display();
	            break;
	        
	        case 6:
	        	//multiply
	        	cout<<"Enter another matrix -\n";
	        	sp2.accept();
	        	sp2.convert();
	        	sp2.transpose();
	        	
	        	cout<<"\nMultiplication is -->"<<endl;
				sp2=sp2.transpose();
				sp3=sp1.multiply(sp2);
				cout<<"\n";
				sp3.display();
				break;
	            
	        case 0:
	        	//exit
	            cout<<"Thank You";
	            exit(0);
	            break;
	
	        default:
				cout<<"\nWrong Selection!!!";
	            break;
        }
        
    }while(choice!=0);

    return 0;
}

/*
	OUTPUT :-

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 1

Enter the number of rows and columns -
3
4

Enter the 12 elements -
1
2
0
0
0
0
0
4
0
2
3
0

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display 
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 2

Normal matrix is -->

1       2       0       0
0       0       0       4
0       2       3       0

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 3

 3 4 5
 0 0 1
 0 1 2
 1 3 4
 2 1 2
 2 2 3

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 4

Enter the number of rows and columns -
2
3

Enter the 6 elements -
2
0
0
3 
4
5

Enter the number of rows and columns -
2
3

Enter the 6 elements -
0
0
3
0
4
0

Addition is -->

 2 3 6
 0 0 2
 0 2 2
 1 0 3
 1 1 8
 0 17239816 3
 1 1 8

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 5
Transpose is --->

 3 2 4
 0 0 2
 0 1 3
 1 1 4
 2 1 5

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 6
Enter another matrix -

Enter the number of rows and columns -
2
3

Enter the 6 elements -
1
0
0
0
5
0

Multiplication is -->
Multiplication is not possible!!

 3 2 2
 0 0 1
 1 1 5

-------------------------------------------------------------------------------------------
1. Accept matrix
2. Display
3. Convert and Display
4. Addition
5. Transpose
6. Multiply
0. Exit Program

Enter the Choice : 0
Thank You

*/