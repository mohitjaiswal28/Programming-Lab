
//Name - Mohit Jaiswal
//Principle of Inclusion and Exclusion

#include <iostream>
#define max 30
using namespace std;

class sport
{
	public:
		int cricket[max];
		int basketball[max];
		int kabaddi[max];
		int c,b,k;
		
		void getData();                      
		void displayData();                         
};

void sport::getData()                       
{
    cout<<"\nCRICKET";
	cout<<"\nEnter the number of player in cricket team - "<<endl;
	cin>>c;
	cout<<"Enter the roll number of student in cricket team -"<<endl;
	for(int i=0;i<c;i++)
	{
		cin>>cricket[i];	
	}
	
    cout<<"\nBASKETBALL";
	cout<<"\nEnter the number of player in basketball team - "<<endl;
	cin>>b;
	cout<<"Eneter the roll number of student in basketball team -"<<endl;
	for(int i=0;i<b;i++)
	{
		cin>>basketball[i];
	}
	
    cout<<"\nKABBADI";
	cout<<"\nEnter the number of player in kabaddi team -"<<endl;
	cin>>k;
	cout<<"Enter the roll number of student in kabaddi team -"<<endl;
	for(int i=0;i<k;i++)
	{
		cin>>kabaddi[i];
	}
}

void sport::displayData()
{
	cout<<"\n\n****Cricket Team*****"<<endl;
	cout<<"\nNumber of player in cricket team = ";
	cout<<c<<endl;
	cout<<"Roll number of student in cricket team -"<<endl;
	for(int i=0;i<c;i++)
	{
		cout<<cricket[i]<<endl;	
	}
	
	cout<<"\n\n****Basketball Team*****"<<endl;
	cout<<"Number of player in basketball team = ";
	cout<<b<<endl;
	cout<<"Roll number of student in basketball team -"<<endl;
	for(int i=0;i<b;i++)
	{
		cout<<basketball[i]<<endl;	
	}
	
	cout<<"\n\n****Kabaddi Team*****"<<endl;
	cout<<"Number of player in kabaddi team = ";
	cout<<k<<endl;
	cout<<"Roll number of student in kabaddi team -"<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<kabaddi[i]<<endl;	
	}
}

class intersection
{
	public:
        int intersection_2set(int array1[],int array2[],int a,int b);        //Intersection of 2 sets
        int intersection_3set(int array1[],int array2[],int array3[],int a,int b,int c);  //Intersection of 3 sets

};

int intersection::intersection_2set(int array1[],int array2[],int a,int b)  
{
	int result=0;
	for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            if(array1[i]==array2[j])
            {
                result++;		
            }	
        }
    }	
 	
 	return result;
}

int intersection::intersection_3set(int array1[],int array2[],int array3[],int a,int b,int c)
{
	int result=0;
	for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            for(int k=0; k<c; k++)
            {
                if(array1[i]==array2[j] && array1[i] ==array3[k])
                {
                    result++;
                }
                
            }	
        }
    }
    
    return result;
}

int main()
{
    int intersect_1,intersect_2,intersect_3,intersect_4;
    int Union;
  
	sport s;
	intersection i;
	
	s.getData();
	s.displayData();
	
	
	
    intersect_1=i.intersection_2set(s.cricket, s.basketball, s.c, s.b);  //Intersection of cricket and basketball
    intersect_2=i.intersection_2set(s.basketball , s.kabaddi, s.b, s.k); //Intersection of kabaddi and basketball
    intersect_3=i.intersection_2set(s.cricket , s.kabaddi, s.c, s.k);   //Intersection of cricket and kabaddi
  
    intersect_4=i.intersection_3set(s.cricket , s.basketball, s.kabaddi,s.c, s.b,s.k);  //Intersection of all 3 games
                              

  cout<<"\n----------------------------------------------------------"<<endl;
  cout<<"\n";
  cout<<"No. of Students playing both Criket and basketball -"<<endl;
  cout<<">>Intersection of Set cricket and Set basketball ="<<intersect_2<<endl;
  
  
  cout<<"\nNo. of Students playing both basketball and kabaddi -"<<endl;
  cout<<">>Intersection of Set basketball and Set kabaddi = "<<intersect_2<<endl;
  
  cout<<"\nNo. of Students playing both cricket and kabaddi -"<<endl;
  cout<<">>Intersection of Set cricket and Set kabaddi = "<<intersect_3<<endl;
  
  cout<<"\nNo. of Students playing all sports -"<<endl;
  cout<<">>Intersection of Set Cricket, Set Basketball and Set Kabaddi = "<<intersect_4<<endl;
  
  cout<<"\n-----------------------------------------------------------"<<endl;
  
  //Union of sets
  Union=s.c+s.b+s.k-(intersect_1+intersect_2+intersect_3)+intersect_4;  
  
  cout<<"\nNumber of student who play any of the game -"<<endl;   
  cout<<"\n>>UNION of set Cricket, set Basketball and set Kabaddi = "<<Union<<endl;
  
  cout<<"\n-----------------------------------------------------------"<<endl;

  return 0;
}