#this code is for the processes having arrival time and burst time already given in the program.

/*
Process 	Arrival time 	Burst time
P1 			    0 				   10
P2 			    3				     26
P3 			   11 				    9
P4 			   14 				   24
*/

#include<stdio.h>

main()
{
	
	int processes[4]={1,2,3,4};   //list all the processes that are available with the user.
	int arrival_time[4]={0,3,11,14};  // list the arrival time of each process.
	int burst_time[4]={10,26,9,24};  //list the estimated run time of each process.
	int burst[4]={10,26,9,24};   
	int arrived_process[4]={1};
	double priority[4]={0};  //list the priority of each process.
	int complete[4]={0}; //list the complete processes.
  int tm=0,i=0,bt=0;
	while(1)
	{
		int k;
		for(k=0;k<4;k++)
		{
			if(tmr>=arrival[k] && burst[k]!=(-1)) 
			{
				priority[k]=1+((tmr-arrival_time[k])/burst[k]);
			}
		}
		
		
	}	
	int turnaround_time[4]={0};
	int waiting_time[4]={0};
	for(i=0;i<4;i++)
	{
		turnaround_time[i]=complete[i]-arrival[i];
		waiting_time[i]=turnaround_time[i]-burst_time[i];
	}
	printf("process\tarrival_time\tburst_time\tturnaround_time\twaiting_time\n");
	for(i=0;i<4;i++)
	{
		printf("i\t%d\t\t%d\t\t%d\t\t%d\n",i,arrival[i],burst_time[i],turnaround_time[i],waiting_time[i]);
	}
	printf("average waiting time is %f .",(waiting_time[0]+waiting_time[1]+waiting_time[2]+waiting_time[3])/4.0);
	printf("average turnaround time is %f .",(turnaround_time[0]+turnaround_time[1]+turnaround_time[2]+turnaround_time[3])/4.0);
		
}
