#include <iostream>
#include <stdlib.h>
#include <sstream> 
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

struct node
{
		struct node *next;
		
    int index,arrivalTime,Burest,priority;
};
struct node * Create_Node(int, int, int,int);
struct node * insert_Back(struct node *,int,int, int,int);
struct node * BubbleSortNON(struct node *head);
struct node * PbubbleSort(struct node *head);
struct node * Read(struct node *);
void readOut();
void write(string n);
void FCFS(struct node *);//First Come First Served
void SJF(struct node *); //Shortes Jobt First
void PNP(struct node *); //priority Non Preemptive
void RR(struct node *); //round robin
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
FCFS(h); //First Come First Served		
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
SJF(h);//Shortes Jobt First
}
break;

