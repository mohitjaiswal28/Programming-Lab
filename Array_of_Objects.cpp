
/*
    Name - Mohit Jaiswal
    Date - 19/09/2022
    Practical 01 :- Array of Object and its Operations
*/

#include <iostream>
#define SIZE 5
using namespace std;

//class declaration
class Phone{

    public:
    string brand;
    int model_no;
    int price;
                                //members of class Phone 
    public:

    void getData();
    void displayData();
};

//defining functions of class Phone
void Phone::getData()
{
    cout<<"\nEnter the Brand name, Model number and Price of the phone :\n";
    cin>>brand>>model_no>>price;
}

void Phone::displayData()
{
    cout<<"\n";
    cout<<brand<<" \t\t "<<model_no<<" \t\t "<<price;
}

//main function
int main()
{   
    Phone p[SIZE], temp;
    int i, j, n, choice, flag=0, index;

    do
    {   
        cout<<"\n------------------------------------------------------------------------------------";
        cout<<"\n1. Read\n2. Display\n3. Insert\n4. Search\n5. Delete\n6. Update\n7. Sort\n0. Exit the Program\n";
        cout<<"\nEnter the Choice :\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                //read
                cout<<"\nEnter the number of phones to read : \n";
                cin>>n;

                for(i=0; i<n; i++)
                {
                    p[i].getData();
                }
                break;

            case 2:
                //display
                cout<<"\n\nBrand Name\tModel number\tPrice\n";

                for(i=0; i<n; i++){

                    p[i].displayData();
                }
                break;

            case 3:
                //insert
                int index; 
                
                cout<<"Enter the index where you want to add :\n";
	            cin>>index;
				
				if(index>SIZE)
				{
					cout<<"Overflow Condition!!\nCannot Insert an element!!";
				}
				
				else
				{
	                for(i=n-1; i>=index; i--)
	                {
	                    p[i+1]=p[i];
	                }
					n++;
	                p[index].getData();
	
	                cout<<"Inserted Succesfully!!";    
				}
				break;

            case 4:
                //search
                
                //first sorted the array
                for(i=0; i<n-1; i++)
                {
                    for(j=0; j<n-1; j++)
                    {
                        if(p[j].model_no>p[j+1].model_no)
                        {
                            temp=p[j+1];
                            p[j+1]=p[j];
                            p[j]=temp;
                        }
                    }
                }
                
                int key;

                cout<<"\nEnter model number of phone to search :\n";
                cin>>key;
                
                //binary serach
                int low, high, mid;
                low=0;
                high=n-1;
                mid=(low+high)/2;
                
                while(low<=high)
                {
                	if(p[mid].model_no==key)
                	{
                		cout<<"Model number "<<key<<" is found with Brand name "<<p[mid].brand;
                		break;
					}
				
					else
					{
						if(key>p[mid].model_no)
                        {
                            low=mid+1;
                        }
					
						else
						{
                            high=mid-1;
                        }
					
						mid=(low+high)/2;
					}
				}
				break;
	

            case 5:
                //delete by data
                
                int del;
                flag=0;

                cout<<"Enter the model number of phone to delete :\n";
                cin>>del;

                for(i=0; i<n; i++)
                {
                    if(p[i].model_no==del)
                    {
                        flag=1;
                        break;
                    }
                    
                }

                if(flag==0)
                cout<<"Phone not found!!";

                else
                {
                    int j;

                    for(j=i; j<n-1; j++)
                    {
                        p[i]=p[i+1];
                    }
                    n--;
                    cout<<"Deleted Successfully!!";
                }
                break;

            case 6:
                //update
                int update;

                cout<<"\nEnter the model number which you have to update :\n";
                cin>>update;

                for(i=0; i<n; i++)
                {
                    if(p[i].model_no==update)
                    flag=1;
                    break;
                }

                if(flag==0)
                cout<<"Phone not found!!";

                if (flag==1)
                {
                    p[i].getData();
                    cout<<"Updated Successfully!!";
                }
                break;

            case 7:
                //bubble sort
                for(i=0; i<n; i++)
                {
                    for(j=0; j<n-1; j++)
                    {
                        if(p[j].price>p[j+1].price)
                        {
                            temp=p[j];
                            p[j]=p[j+1];
                            p[j+1]=temp;
                        }
                    }
                }

                cout<<"Sorted Succesfully!!";
                break;
                
            case 0:
                //exit the program
                cout<<"Thank You!!";
                exit(0);
                break;

            default:
                //For the wrong selection
                cout<<"Wrong Selection!!\n";
                cout<<"Please select the appropriate option from above menu!!";
                break;
        }

    }while(choice!=0);

    return 0;
}

/*
    OUTPUT :-
    
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
1

Enter the number of phones to read : 
2

Enter the Brand name, Model number and Price of the phone :
Vivo
123
12000

Enter the Brand name, Model number and Price of the phone :
Oppo
456
10899

------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
2


Brand Name      Model number    Price

Vivo             123             12000
Oppo             456             10899
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
3
Enter the index where you want to add :
0

Enter the Brand name, Model number and Price of the phone :
Samsung
789
99000
Inserted Succesfully!!
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
2


Brand Name      Model number    Price

Samsung                  789             99000
Vivo             123             12000
Oppo             456             10899
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
4

Enter model number of phone to search :
123
Model number 123 is found with Brand name Vivo
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
5
Enter the model number of phone to delete :
789
Deleted Successfully!!
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
2


Brand Name      Model number    Price

Vivo             123             12000
Oppo             456             10899
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
6

Enter the model number which you have to update :
1

Enter the Brand name, Model number and Price of the phone :
Samsung 9000
9000
Updated Successfully!!
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
2


Brand Name      Model number    Price

Samsung                  9000            9000
Oppo             456             10899
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
7
Sorted Succesfully!!
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
2


Brand Name      Model number    Price

Samsung                  9000            9000
Oppo             456             10899
------------------------------------------------------------------------------------
1. Read
2. Display
3. Insert
4. Search
5. Delete
6. Update
7. Sort
0. Exit the Program

Enter the Choice :
0
Thank You!!

*/
