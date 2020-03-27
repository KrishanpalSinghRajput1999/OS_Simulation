
#include<conio.h>    //console input/output
#include<stdio.h>    //Standard Input Output

int main()
{
  printf("\t\t\t*********************Scheduling Algorithm*********************\n\n\n\n");
  
  long int n,i=0,j=0;
  /*
  prior = priority of the processes.
  wait_time= waiting timing of each process. 
  burst_time = estimated run time.
  turnaround_time=completion time - arrival time 
  procs- variable for a process.
  completion= time of completion of a process.
   */
  printf("For Scheduling, Enter the requirements(Processes to be scheduled): ");
  scanf("%ld",&n ); 
  
  //double avg_waiting,avg_turnaround;
  double prior[n] ,burst_time[n],arrv_time[n],wait_time[n],tatTime[n];
  double procs[n], temp, completion_time[n],min,add=0,add2=0,final_wait, final_tat, wait_avg_time, ta_avg_time;
  
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%lf", &burst_time[i]);
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%lf", &arrv_time[i] );
    procs[i]=i+1;
  }

  printf("\n\n\t\t *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_Values entered by User are *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n\n");
  printf("\t\t\t*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n");
  printf("\t\t\t| Process | Burst Time | Arrival Time |\n");
  printf("\t\t\t*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\n");
  
   //Displaying the values entered for each process - arrival time and burst time by the user. 
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",procs[i],arrv_time[i],burst_time[i]);
  }
    printf("\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}
