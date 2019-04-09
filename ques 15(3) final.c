#include<stdio.h>
struct schedule
{
	int p,at,bt,wt,tat,pr,flag,val;
}s[50];

float avg_tat=0,avg_wt=0;
int main()
{
	int i,j,a,b,k,t,n,c,st[50],time_quantum,min_pr,max_pr,min;//t = previous arrival time
	printf("Enter the number of process: ");
	scanf("\t%d",&n);
	c=n;
	for(i=0;i<n;i++)
	{
		s[i].p=i+1;
		s[i].val=2;
		printf("\nArrival time p%d : \t",i+1);
		scanf("\t%d",&s[i].at);
		printf("\nBurst time p%d : \t",i+1);
		scanf("\t%d",&s[i].bt);
		st[i]=s[i].bt;
		printf("\nPriority p%d : \t",i+1);
		scanf("\t%d",&s[i].pr);
		s[i].flag=0;
	}
	printf("Process  \tAT\t\tBT\t\tPR");
	for(i=0;i<n;i++)
	{
		printf("\np%d	\t%d	\t%d	\t%d",i+1,s[i].at,s[i].bt,s[i].pr);
	}
	printf("\n\n\nEnter the time quantum: ");
	scanf("\t%d",&time_quantum);
	min=s[0].at;
	min_pr=s[0].at;
	for(i=1;i<n;i++)
	{
		if(s[i].at<min)
		{
			min = s[i].at;
			k=i;
		}
		if(s[i].at==min)
		{
			s[i].val=1;
		}
	}
	printf("\nProcess\t\tArrival time\tBurst time\tPriority\tTurnaround time\t\tWaiting time");
	for(t=min;c!=0;)
	{
		for(i=0;i<n;i++)
		{
			if(s[i].flag>n && s[i].val==1)
			{
				s[i].pr=s[i].pr+2;
				s[i].flag--;
			}
			if(s[i].at<=t && s[i].val!=0)
			{
				s[i].val=1;
			}
			if(s[i].pr<=min_pr && s[i].val==1)
			{
				min_pr=s[i].pr;
			}
			if(s[i].pr<=max_pr && s[i].val==1)
			{
				max_pr=s[i].pr;
				a=i;
			}
		}
		if(st[a]<=time_quantum && st[a]>0)
		{
			t=t+st[a];
			st[a]=0;
			s[a].val=1;
			s[a].flag=0;
		}
		else if(st[a]>0)
		{
			st[a]=st[a]-time_quantum;
			t=t+time_quantum;
			if(s[a].flag>0)
				s[a].flag=s[a].flag-1;
		}
		for(j=0;j<n;j++)
		{
			if(j!=a && s[j].val==1)
			{
				s[b].flag=s[b].flag+1;
			}
		}
		if(st[a]==0 && s[a].val==1)
		{
			c--;
			s[a].tat=t-s[a].at;
			s[a].wt=s[a].tat-s[a].bt;
			avg_tat=avg_tat+s[a].tat;
			avg_wt=avg_wt+s[a].wt;
			printf("\n p%d \t\t\t%d  \t\t%d  \t\t%d  \t\t%d  \t\t%d",a+1,s[a].at,s[a].bt,s[a].pr,s[a].tat,s[a].wt);
			s[a].val=0;
		}
		
		max_pr=min_pr;
	}
	printf("\n\nAverage turn around time is \t%0.2f",avg_tat/n);
	printf("\nAverage waiting time is \t%0.2f",avg_wt/n);
}
