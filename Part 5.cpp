#include <iostream>
#include <stdlib.h>
#include <sstream> 
#include <fstream>
#include <string>
#include <string.h>
#define LINE_MAX 1024

using namespace std;

struct node
{
		struct node *next;
		
    int index,arrivalTime,Burest,priority;
};
struct node * Creat_Node(int, int, int,int);
struct node * Back(struct node *,int,int, int,int);
struct node * BubbleSortNON(struct node *head);
struct node * PbubbleSort(struct node *head);
struct node * ReadF(struct node *);
void readOut();
void write(string n);
void FCFS(struct node *);
void SJF(struct node *); 
void PNP(struct node *); 
void RR(struct node *); 
void swap (struct node * node_1, struct node *node_2); 
int size(struct node *);


int main(void)
{
	int Choose;
	while(true)
	{

	
		
		cout<<"\n\t\t\tCPU Scheduler Simulator\n\n";
		cout<<"1) Scheduling Method (None)\n";
		cout<<"2) Preemptive Mode (Off)\n";
		cout<< "Show Result\n";
		cout<< "4) End Program (EXIT)\n ";
		cout<<"\nChoose one [1-4] : ";
		cin>>Choose;
		cout<<"\n";
		switch(Choose)
		{
			case 1:
				{
int sMethod;
cout<<"1) First Come, First Served Scheduling\n";
cout<<"2) Shortest-Job-First Scheduling \n";
cout<<"3) Priority Scheduling \n";
cout<<"4) Round-Robin Scheduling \n ";
cout<<"\nChoose one [1-4] : ";
cin>>sMethod;


switch(sMethod)
{
case 1:{
struct node *h=NULL;
h=Read(h);
FCFS(h); 	
}			
break;

case 2:
{					
cout<<"\n 1) Non Preemptive Method";
cout<<"\n 2) preemptive Method";
int select;
cout<<"\n please select a method [1-2]: ";
cin>>select;

switch(select)
{
case 1:
{
struct node *h=NULL;
h=Read(h);
SJF(h);
}
break;
////
default:
{
cout<<"Error";
}
break;
}
}
break;

////

case 3:
{	
cout<<"\n 1) Non Preemtive Method";
cout<<"\n 2) preemtive method";
int methods;
cout<<"\n select one of the methods [1-2] : ";
cin>>methods;

switch(methods)
{
case 1:
{
struct node *h=NULL;
h=Read(h);
PNP(h); 
}
break;
default:
{
cout<<"Enter a valid choice"<<endl;
}
break;
}
}
break;
				
////
case 4:
{
struct node *h=NULL;
h=Read(h);
RR(h); 
}						
break;
default:
{
cout<<" Enter a valid choice";
}
break;
}
}
break;
case 3:
{
readOut();
}
break;
case 4:
{
return 0;
}

break;
default:
break;		
}
}
}

struct node * Creat_Node(int Burest, int arrivalT, int Priority,intIndex)
{
	struct node *t =NULL;
	t=(struct node*)malloc(sizeof(node));
	t->burst=Burest;
	t->arrival=arrivalT;
	t->priority=Priority;
	t->index=Index;
	t->next=NULL;
	return t;
}

struct node * Back(struct node *h,int Burest,int arrivalT, int Priority,int Index)
{
	struct node * t=(Create_Node(Burest,arrivalT,Priority,Index));
	struct node * find;
	if(h==NULL)
		{
			h=t;
			return h;
		}
	find=h;
	while(find->next!=NULL)
    find=find->next;
	find->next=t;
	return h;
}
//Writing The output file
void write(string r)
{
	ofstream writef("outputFile.txt");
	if (writef) {
		writef <<r<<endl;
		writef.close(); 
		cout<<"The File is updated\n";
	}
	else {
		
		writef.open("outputFile.txt");
		writef <<r<<endl;
		writef.close(); 
		cout<<"The File is updated\n";
	}
}
// READ OUT 
void readOut(void)
{
	string out;
	ifstream read("outputFile.txt");
	if (read.is_open())
{
	string l;
	while (getline(read, l))
    {
    	cout << l << endl;
    }
}
	read.close();
	cout<<out;
}
int size(struct node *h)
{
	int x=0;
	while(h!=NULL)
	{
		x++;
		h=h->next;
	}
	return x;	
}

string toString(double x) {
   stringstream stream;
   stream << x;
   return stream.str();
   //From integer to String
}

void SwapFCFS (struct node * n1, struct node *n2)
{   



int Burest,arrivalT,Priority,Index;
	arrivalT=n1->arrival;
	Burest= n1->burst;
	Index=n1->index;
	Priority=n1->priority;
	n1->arrival= n2 -> arrival;
	n1->burst= n2 -> burst;
	n1->index= n2 -> index;
	n1->priority= n2 -> priority;
	n2 -> arrival= arrivalT;
	n2 -> burst= Burest;
	n2 -> index= Index;
	n2 -> priority= Priority;
}



struct node * bubble_sortFCFS(struct node *h)
{
			struct node *right_Pointer = NULL; 
	        struct node *left_Pointer;
		       int swap;
	do
	{	
		swap = 0;
		left_Pointer = h;
		while(left_Pointer->next != right_Pointer)
		{
			if (left_Pointer->arrival> left_Pointer->next->arrival) 
			{
				SwapFCFS(left_Pointer, left_Pointer->next); 
                swap = 1; 
			}
			left_Pointer = left_Pointer->next;
		}

		right_Pointer = left_Pointer;

	}while(swap);
}
		right_Pointer = left_Pointer;

	}while(swap);
}


void FCFS(struct node *h)
{    
    int r=1;
	int keeptrack=0;
	int waiting=0;
	double sum=0,avrage;
	int s=size(h);
	struct node * t=NULL;
	t=bubble_sortFCFSd(h);
	std::string out="\nMethod: First Come First Served (fcfs) \n The wating time of the process: \n";
	
	while(h!=NULL)
	{
		
			if(r==1)
			{
			
				if( h->next!=NULL)
				
				{		
					out=out+"P" +toString(h->index) +":" + toString(keeptrack) + " mele second \n";
					keeptrack+=h->burst;
					waiting+=h->burst-h->arrival;
					sum+=waiting;
					r=0;
				}
			}
			else if( h->next!=NULL)
				{
					out=out+"P" +toString(h->index) +":" + toString(keeptrack-h->arrival) + " mele second \n";
					keeptrack+=h->burst ;
					waiting+=h->burst-h->arrival;
					sum+=waiting;
				}
			else if(h->next==NULL)
				{
					out=out+"P" +toString(h->index)+":" + toString(keeptrack-h->arrival) + " mele second \n";
					keeptrack+=h->burst;
					waiting+=h->burst-h->arrival;
					
				}
				h=h->next;
		
	}
	avrage=sum/s;
	out=out+ "Average Waiting Time: "+ toString(avrage)+" mele second\n";
	cout<<out;
	write(out);
}
