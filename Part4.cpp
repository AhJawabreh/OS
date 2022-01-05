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

