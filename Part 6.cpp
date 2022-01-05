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
		
    int index,arrival,burst,priority; 
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
h=ReadF(h);
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
h=ReadF(h);
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
h=ReadF(h);
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
h=ReadF(h);
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

struct node * Create_Node(int bur, int arr, int pri,int ind)
{
	struct node *t =NULL;
	t=(struct node*)malloc(sizeof(node));
	t->burst=bur;
	t->arrival=arr;
	t->priority=pri;
	t->index=ind;
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
//Reading the INPUT  file
struct node *ReadF(struct node *h)
{
    char line[LINE_MAX];
	FILE *f;

	if ((f = fopen("inputFile.txt", "r")) == NULL){
	 cout<<"ERROR"<<endl;//
	 return 0;
			}
	int z=1;     
	while (fgets(line, LINE_MAX, f) != NULL) {
		        int n[3];
	        sscanf(line,"%d:%d:%d\n",&n[0],&n[1],&n[2]);
	    	h=Back(h,n[0],n[1],n[2],z);
	    	z=z+1;		
	}
	fclose(f);
	return h;
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

void SwapFirstComeFirstServed (struct node * n1, struct node *n2)
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







struct node * bubble_sortFCFSd(struct node *h)
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
				SwapFirstComeFirstServed(left_Pointer, left_Pointer->next); 
                swap = 1; 
			}
			left_Pointer = left_Pointer->next;
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
//////////////////////////////////////////////////////////////

struct node * BubbleSortPNP(struct node *h)
{
	struct node *Right_Pointer = NULL;
	struct node *Left_Pointer; 
	int swap;
	
	do
	{	
		swap = 0;
		Left_Pointer = h;
		while(Left_Pointer->next != Right_Pointer)
		{
			if (Left_Pointer->burst> Left_Pointer->next->burst) 
			{
				SwapFirstComeFirstServed(Left_Pointer, Left_Pointer->next); 
                swap = 1; 
			}
			Left_Pointer = Left_Pointer->next;
		}
		Right_Pointer = Left_Pointer;
	}while(swap);
}

void SJF(struct node * h)
{
    int keeptrack=0;
	int waiting=0;
	double sum=0,avrage;
	struct node * t=NULL;
	struct node * t1=NULL;
	int s=size(h);
	t=bubble_sortFCFSd(h);
	std::string out=" \nShortest Job First Scheduling (NON Preemptive) \n Phe wating time of the process: \n";
	while(h!=NULL)
	{
			out=out+"P"+toString(h->index) +":" + toString(keeptrack) + " mele second \n";
			keeptrack+=h->burst-h->arrival;
			waiting+=h->burst-h->arrival;
			sum+=waiting;
			break;

	}
	h=h->next;
	t1=BubbleSortPNP(h);	
	cout<<"\n"<<sum;
	while(h!=NULL)		
		{
			 if(h->next==NULL)
			{
				sum-=h->arrival;
				out=out+"P" +toString(h->index)+":" + toString(keeptrack-h->arrival) + " mele second\n";
				keeptrack+=h->burst;
				waiting+=h->burst-h->arrival;
						
			}
		
			 else if( h->next!=NULL  )
			{
				sum-=h->arrival;
				out=out+"P" +toString(h->index) +": " + toString(keeptrack-h->arrival) + " mele second\n";
				keeptrack+=h->burst ;
				waiting+=h->burst;
				sum+=waiting;
						
			}
			
		
			h=h->next;
	}
	avrage=sum/s;
	out=out+ "Average Waiting Time:"+ toString(avrage)+" mele second \n";
	cout<<out;
	write(out);
	
}



void the_swap (struct node * n1, struct node *n2)
{
	int bur,arr,pri,ind;
	bur= n1->burst;
	arr=n1->arrival;
	pri=n1->priority;
	ind=n1->index;
	n1->burst= n2 -> burst;
	n1->arrival= n2 -> arrival;
	n1->priority= n2 -> priority;
	n1->index= n2 -> index;
	n2 -> burst= bur;
	n2 -> arrival= arr;
	n2 -> priority= pri;
	n2 -> index= ind;
}
struct node *PbubbleSort(struct node *h)
{
	struct node *right_pointer = NULL; 
	struct node *left_pinter; 
	int swap;

	do
	{	
		swap = 0;
		left_pinter = h;
		while(left_pinter->next != right_pointer)
		{
			if (left_pinter->priority> left_pinter->next->priority) 
			{
				the_swap(left_pinter, left_pinter->next); 
                swap = 1; 
			}
			left_pinter = left_pinter->next;
		}

		right_pointer = left_pinter;

	}while(swap);
}
void PNP(struct node *h)
{
	int waiting=0;
	int keeptrack=0;
	double sum=0,avrage;
	struct node * t=NULL;
	struct node * t1=NULL;
		int s=size(h);
	t=bubble_sortFCFSd(h);	
	std::string out=" \n Method: Priority Scheduling (Non-Preemptive) \n the wating time of the process: \n";
	while(h!=NULL)
	{
out=out+"P" +toString(h->index) +":" + toString(keeptrack) + " mele second \n";
keeptrack+=h->burst-h->arrival;
waiting+=h->burst-h->arrival;
sum+=waiting;
break;

	}
	h=h->next;
	t1=PbubbleSort(h);
	while(h!=NULL)		
		{
		
			 if( h->next!=NULL  )
			{
				sum-=h->arrival;
				out=out+"P" +toString(h->index) +": " + toString(keeptrack-h->arrival) + " mele second \n";
				keeptrack+=h->burst ;
				waiting+=h->burst;
				sum+=waiting;
						
			}
			else if(h->next==NULL)
			{
				sum-=h->arrival;
				out=out+"P" +toString(h->index)+": " + toString(keeptrack-h->arrival) + " mele second \n";
				keeptrack+=h->burst;
				waiting+=h->burst-h->arrival;
						
			}
		
			h=h->next;
	}
	avrage=sum/s;
	out=out+ "Average Waiting Time:"+ toString(avrage)+" mele second \n";
	cout<<out;
	write(out);
}
/////////////////////
void RR(struct node *h)
{
	int s=size(h);
	int TQ =2;
	struct node * t=h;
	t=bubble_sortFCFSd(h);
	
	double sum=0,tsum=0;
	double avrage;
	std::string out="\n Method: Round Robin \n the wating time of the process: \n";
	int x;
	int y;
	int i=0;
	while(h!=NULL)
		{
			int time =TQ;
			
			if(h->index==y)
			{
				break;
			}
			y=h->index;
			
			
			
			if(h->burst !=0)
			{
				
				x=h->burst;
				if(x > 2)
				{
					x=x-2;
					Back(h,x,h->arrival,h->priority,h->index);
					tsum+=2;
					
					
					
				}
				else if(x==2)
				{
					x=x-2;
					sum+=tsum-h->arrival-(2*i);
					out=out+"P" +toString(h->index) +": " + toString(tsum-h->arrival-(2*i)) + " mele second \n";
					tsum+=2;
					
				}
				else if(x==1)
				{
					x=x-1;
					sum+=tsum-h->arrival-(2*i);
					out=out+"P" +toString(h->index) +": " + toString(tsum-h->arrival-(2*i)) + " mele second \n";
					tsum+=1;
				}
				if(h->index==5)
					i++;

			}
			h=h->next;
		}
		avrage=sum/s;
		out=out+ "Average Waiting Time: "+ toString(avrage)+" mele second\n";
		cout<<out;
		write(out);
}
