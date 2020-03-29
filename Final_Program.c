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
void Time_Minimum()
{
	minimumArrvTime=65537;
	
	for(i=0;i<n;i++)                      //Time complexity- O(n)
	{
		if(Object[i].prior==-1)
			continue;
		if(minimumArrvTime==Object[i].arrival_time)
		{
			if(Object[i].burst_time<run_time)
			{
				strcpy(currentProcs,Object[i].procs);  //CopiesOnject[i].procs into currentProcess
				run_time=Object[i].burst_time;
				minimumArrvTime=Object[i].arrival_time;		
			}
		}
		else if(minimumArrvTime>Object[i].arrival_time)
		{
			strcpy(currentProcs,Object[i].procs);
			run_time=Object[i].burst_time;
			minimumArrvTime=Object[i].arrival_time;
		}
	
	}
	currentTime=minimumArrvTime;
	return;                             //function returns nothing(void)
}
  
void main()
{            //Main Function - Executed First
                printf("\t\t\t\t@@@@@@@@@@@@@ SCHEDULING ALGORITHM @@@@@@@@@@@@@\n\n");
	printf("For Scheduling, Enter the number of Processes: ");
	scanf("%d",&n);
	printf("\n\t\tEnter the Process Details- Process_Name, Arrival Time and Estimated RunTime\n\n",n);
	
	Object=(struct StrcProcs*)malloc(sizeof( struct StrcProcs)*n); //Assigning dymanic memory to the object for process.
	for(i=0;i<n;i++)
	{
		printf("Process Name for %d: ",i+1);
		scanf("%s",Object[i].procs);
		printf("Enter Arrival Time for process %s: ",Object[i].procs);
		scanf("%d",&(Object[i].arrival_time));
		if(Object[i].arrival_time<0)
		{
			printf("\n\t\t\tArrival Time should be a positive value");
			exit(0);
		}
		printf("Enter Burst Time for process %s : ",Object[i].procs);
		scanf("%lf",&(Object[i].burst_time));
		if(Object[i].burst_time<0)
		{
			printf("\n\t\t\tBurst Time should be a positive value");
			exit(0);
		}
		printf("\n@$@$@$@$@$@$@$@$@$$@$@\n\n");
		if(minimumArrvTime==Object[i].arrival_time)
		{
			if(Object[i].burst_time<run_time)
			{
				strcpy(currentProcs,Object[i].procs);
				run_time=Object[i].burst_time;
				minimumArrvTime=Object[i].arrival_time;		
			}
		}
		else if(minimumArrvTime>Object[i].arrival_time)
		{
			strcpy(currentProcs,Object[i].procs);
			run_time=Object[i].burst_time;
			minimumArrvTime=Object[i].arrival_time;
		}
	}
	currentTime=minimumArrvTime;
	minimumArrvTime=65537;
	for(j=0;j<n;j++)                                  //Time Complexity - O(n)
	{ 
		for(i=0;i<n;i++)                        //Time Complexity - O(n^2)
		{
			if(Object[i].prior!=-1 && strcmp(Object[i].procs,currentProcs)==0)
			{
				Object[i].prior=-1;
				Object[i].waiting_time=currentTime-Object[i].arrival_time;
				currentTime=currentTime+(int)Object[i].burst_time;
				Object[i].tatTime=currentTime-Object[i].arrival_time;
			}
		}
		for(i=0;i<n;i++)                        //Time Complexity - O(n^2)
		{
			if(Object[i].prior==-1)
				continue;
			else if(currentTime<Object[i].arrival_time)
			{
				p=1;
				continue;
			}
			else
			{
				p=-1;
				break;
			}
		}
		if(p==1)
		{
			Time_Minimum();
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(Object[i].prior!=-1 && currentTime>Object[i].arrival_time)
				{
					Object[i].waiting_time=currentTime-Object[i].arrival_time;
					Object[i].prior=1+(Object[i].waiting_time/Object[i].burst_time);
				}
			}
			Prior_Maximum();
		}
		
	}	
	/*Final Order of Process after scheduling*/
	
	printf("\n\t\t\t\t/*/*/*/*/*SCHEDULED PROCESS/*/*/*/*/*/*/*\n\n");
	printf("\t\t/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/");
	printf("\n   |   Process | Arrival time |  Burst Time |  WaitingTime  |   TurnAroundTime  | StartTime |");
	printf("\t\t/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/\n");
	for(i=0;i<n;i++)
	{
		printf("\n     |     %s    |    %3d     |      %3.0lf   |     %6d    |      %4.0lf  |  %3d  ",Object[i].procs,Object[i].arrival_time,Object[i].burst_time,Object[i].waiting_time,Object[i].tatTime,Object[i].arrival_time+Object[i].waiting_time);
		avgTATime=avgTATime+Object[i].tatTime;
	                avrgWaitingTime=avrgWaitingTime+Object[i].waiting_time;
	}
	
                // Average Waiting Time= (Sum of Waiting Time of all Process)/number of process(n) 
	printf("\n\n\n\t\tAverage Waiting Time is %.2lf units",avrgWaitingTime/n);
	
	// Average Turnaround Time= (Sum of Turnaround Time of all Process)/number of process(n)
	printf("\n\n\t\tAverage TurnAround Time is %.2lf units\n\n\n\n",avgTATime/n);
	
}
