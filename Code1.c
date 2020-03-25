#this code is for the processes having arrival time and burst time already given in the program.

/*
Process 	Arrival time 	Burst time
P1 			 0 	  10
P2 			 3	  26
P3 			11         9
P4 			14 	  24
*/

#include<stdio.h>

main()
{
	
	int processes[4]={1,2,3,4};   //list all the processes that are available with the user.
	int arrival_time[4]={0,3,11,14};  // list the arrival time of each process.
	int burst_time[4]={10,26,9,24};  //list the estimated run time of each process.
	int burst[4]={10,26,9,24};   
	int arrived_process[4]={1};
	/*list the priority of each process.
	  double is choosen because of floating point values of priority*/
	double priority[4]={0};  
	int complete[4]={0}; //list the complete processes.
  int tm=0,i=0,bt=0;
	while(1)
	{
	  int k;
	  for(k=0;k<4;k++)
	   {
	      if(tm>=arrival_time[k] && burst[k]!=(-1)) 
		{
		  priority[k]=1+((tm-arrival_time[k])/burst[k]);
		}
	   }
	  int p,q;
	  for(p=0;p<4;p++)
	   {
	     for(q=0;q<4-1-p;q++)
		{
		  if(priority[q]<priority[q+1] && arrived_process[q]!=0 && arrived_process[q+1]!=0)
		      {
			double t1=priority[q];
			priority[q]=priority[q+1];
			priority[q+1]=t1;
			int t2=arrived_process[q];
			arrived_process[q]=arrived_process[q+1];
		        arrived_process[q+1]=t2;
		      }
		  else 
		      if(priority[q]==priority[q+1]  && arrived_process[q]!=0 && arrived_process[q+1]!=0)
			{
			  if(burst[q]<burst[q+1])
			     {
				int t=arrived_process[q];
				arrived_process[q]=arrived_process[q+1];
				arrived_process[q+1]=t;
			     }
			}
		}
	    }
		int y=arrived_process[0];
		bt=burst[y-1];
		do
		{
			//printf("timer : %d",tm);
			int x;
			for(x=0;x<4;x++)
			{
				if(tm==arrival_time[x])
				{		
					arrived_process[x]=x+1;
					printf("process %d arrived\n",x);
				}	
			}
			bt=bt-1;
			tm=tm+1;
			if(bt==0)
			{
				printf("process %d completed\n",y-1);
				complete[y-1]=tm;
				i=i+1;
				burst[y-1]=-1;
				//priority[0]=0;
				for(x=0;x<4;x++)
				{
					priority[x]=0;
					if(arrived_process[x]!=0)
					{
						arrived_process[x]=x+1;
					}
				}
				break;
			}
		}while(1);
		if(i==4)
			break;


		
	}	
	
	int tat[4]={0}; //turnaround_time
	int wait_time[4]={0};
	for(i=0;i<4;i++)
	{
		tat[i]=complete[i]-arrival_time[i];
		wait_time[i]=tat[i]-burst_time[i];
	}
	printf("process\tarrival_time\tburst_time\tturnaround_time\twaiting_time\n");
	for(i=0;i<4;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i,arrival_time[i],burst_time[i],tat[i],wait_time[i]);
	}
	printf("average waiting time is %f .",(wait_time[0]+wait_time[1]+wait_time[2]+wait_time[3])/4.0);
	printf("average turnaround time is %f .",(tat[0]+tat[1]+tat[2]+tat[3])/4.0);
		
}
