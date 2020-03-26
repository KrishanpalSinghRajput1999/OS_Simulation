#include<conio.h>    //console input/output
#include<stdio.h>    //Standard Input Output

int main()
{
  printf("\t\t\t*********************Scheduling Algorithm*********************\n\n\n\n");
  
  long int n,i=0,j=0;
  /*
  prior = priority pf the processes , wait_time= waiting timing of each process, birst_time = estimated run time
  turnaround_time=completion time = arrival time
   
  */
  double prior[n],avg_wait_time,avg_taround_time,burst_time[n],arrv_time[n],wait_time[n],t_around_time[n];
  double procs[n], temp, completionTime[n],min,add=0,add2=0,wait_final, turnaround_final, wait_avg_time, turnaround_avg_time;
  
  printf("For Scheduling, Enter the requirements(Processes to be scheduled): ");
  scanf("%ld",&n ); 
  
 
  for(i=0;i<n;i++)
  {
    printf("\nBurst Time for Process No.[%d] : ", i+1 );
    scanf("%lf", &burst_time[i]);
    printf("Arrival Time for Process No.[%d] : ", i+1 );
    scanf("%lf", &arrv_time[i] );
    procs[i]=i+1;
  }
  }
