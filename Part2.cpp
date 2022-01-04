#include <iostream>
using namespace std;

//Finding the waiting time for all processes
void calculatingWaitingTime(int processes[], int n, int burestTimes[], int watingTime[], int quantum)
{
//Copying the burst times (burestTimes[]) to store remaining burst times.
    int remBurestTime[n];
    for (int i = 0 ; i < n ; i++)
    remBurestTime[i] = burestTimes[i];
 
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
                    watingTime[i] = t - burestTimes[i];
 
                    
                    // make the remaining burst time = 0
                    remBurestTime[i] = 0;
                }}}


        // Do only if all of the processes done
        if (done == true)
        break;
    
	}}
	//Turn around time calculating
void calculatingTurnAroundTime(int processes[], int n, int burestTimet[], int watingTime[], int turnAroundTime[])
{
    // calculating turn around time by adding burest time and waiting time 
    for (int i = 0; i < n ; i++)
        turnAroundTime[i] = burestTimet[i] + watingTime[i];
}

void findTurnAroundTime(int processes[], int n,
                        int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}


// calculating average time
void calculatingAvgTime(int processes[], int n, int burestTimet[], int quantum)
{
    int watingTime[n], turnAroundTime[n], totalWatingTime = 0, totalTurnAroundTime = 0;

    // calculating waiting time of all processes
    calculatingWaitingTime(processes, n, burestTimet, watingTime, quantum);
 
    // calculating turn around time for all processes
    calculatingTurnAroundTime(processes, n, burestTimet, watingTime, turnAroundTime);
 
    
    cout << "Processes "<< " Burst time "
        << " Waiting time " << " Turn around time\n";


    for (int i=0; i<n; i++)
    {
        totalWatingTime = totalWatingTime + watingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        cout << " " << i+1 << "\t\t" << burestTimet[i] <<"\t "
            << watingTime[i] <<"\t\t " << turnAroundTime[i] <<endl;
    }
 
    cout << "Average waiting time = "
        << (float)totalWatingTime / (float)n;
    cout << "\nAverage turn around time = "
        << (float)totalTurnAroundTime / (float)n;
        
        
        
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//struct node 
















}

	
	
