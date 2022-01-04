#include <iostream>
using namespace std;

int main(){
	
	int a,b;
	
	cout<<"\n\t\t\tCPU Scheduler Simulator\n\n";

	cout<<"1) Scheduling Method (None)\n";
	cout<<"2) Preemptive Mode (Off)\n";
	cout<<"3) Show Result\n";
	cout<<"4) End Program\n";
	
	cout<<"\nChoose one [1-4] : ";
	
	cin>>a;
	cout<<"\n";
	
	if(a==1){
		cout<<"Scheduling Method Selected! \n";
		
		cout<<"1) First Come, First Served Scheduling\n";
		cout<<"2) Shortest-Job-First Scheduling \n";
		cout<<"3) Priority Scheduling \n";
		cout<<"4) Round-Robin Scheduling \n";
		cout<<"\nChoose one [1-4] : ";
		cin>>b;
	cout<<"\n";


//Finding the waiting time for all processes
void calculatingWaitingTime(int processes[], int n,
            int burestTimes[], int watingTime[], int quantum)
{
//Copying the burst times (burestTimes[]) to store remaining burst times.
    int remBurestTime[n];
    for (int i = 0 ; i < n ; i++)
        remburestTime[i] = burestTimes[i];
 
    int t = 0; 


 // Keep passing the processes in round robin until all of the processes arent done.
    while (1)
    {
        bool done = true;
 
        // pass all of the processes one by one
        for (int i = 0 ; i < n; i++)
        {
        	
            //burst time>0
            if (remBurestTime[i] > 0)
            {
                done = false; // There is a pending process
 
                if (remBurestTime[i] > quantum)
                {
                    
                    t += quantum;
 
                    
                   remBurestTime[i] -= quantum;
                }
 
                // If burst time is smaller than or equal to if burst time <= quantum
                else
                {
                    
                    t = t + remBurestTime[i];
 
                    //wating time formula
                    watingTime[i] = t - burestTime[i];
 
                    
                    // make the remaining burst time = 0
                    remBurestTime[i] = 0;
                }}}
        // Do only if all of the processes done
        if (done == true)
        break;
    }}

