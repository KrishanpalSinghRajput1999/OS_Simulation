#include<stdio.h>   //memory allocation
#include<string.h>  //for string manipulation
#include<stdlib.h>  //Standard Input Output

int n;              // n for number of processes
struct StrcProcs    //Structure for each process.
{ /*
   burst_time = estimated run time.
   tatTime = turnaround_time=completion time - arrival time 
   prior = priority of the processes.
   waiting_time= waiting timing of each process.
   arrival_time= the time at which the process arrives.
   procs- variable for a process.
 */
  double burst_time,tatTime,prior; 	
  int waiting_time,arrival_time;
  char procs[5];
};

struct StrcProcs *Object;    //Object of structure StrcProcs
double run_time=100000000.0;  //Runtime is taken as 100000000.0
int currentTime=0,i=0,j=0,p=0,minimumArrvTime=65537; 
char currentProcs[5];
double avgTATime=0,avrgWaitingTime=0;  //(Sum of Waiting Time of all Process)/number of process(n) 
  // (Sum of Turnaround Time of all Process)/number of process(n)

void Prior_Maximum()
{              /* This is the function to find the maximum priority.
                  Priority= 1 + WaitingTime/ Estimated Run Time(Burst Time)
               */
                double max_prior=-10000000.0;   //maximum priority is taken as -10000000.0
	for(i=0;i<n;i++)                  // time complexoty - O(n)
	{
		if(Object[i].prior==-1)
		{
		    continue;
		}
		else
		{
			if(max_prior<Object[i].prior)
			{
			    max_prior=Object[i].prior;
			    strcpy(currentProcs,Object[i].procs);   //Copies Object[i].procs into currentProcess
			}
		}
	}
	return;  //function returns nothing(void)
}
