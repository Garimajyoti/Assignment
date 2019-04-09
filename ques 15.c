#include<stdio.h>
struct schedule
{
	int pid,at,bt,wt,tat,pr,flag,val;
}s[50];

float avg_tat=0,avg_wt=0;
int main()
{
	int i,j,a,b,k,t,n,c,st[50],time_quantum,min_pr,max_pr,min;//t = previous arrival time
	printf("Enter the number of process user want to enter: ");
	scanf("\t%d",&n);
	c=n;
	for(i=0;i<n;i++)
	{
		s[i].pid=i+1;
		s[i].val=2;
		printf("\nArrival time pid%d : \t",i+1);
		scanf("\t%d",&s[i].at);
		printf("\nBurst time pid%d : \t",i+1);
		scanf("\t%d",&s[i].bt);
		st[i]=s[i].bt;
		printf("\nPriority pid%d : \t",i+1);
		scanf("\t%d",&s[i].pr);
		s[i].flag=0;
	}
	printf("Process \tArrival time\tBurst time\tPriority");
	for(i=0;i<n;i++)
	{
		printf("\n		pid%d	\t%d	\t%d	\t%d",i+1,s[i].at,s[i].bt,s[i].pr);
	}
	printf("\n\n\nEnter the time qunatum: ");
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
	printf("\nProcess\t\tArrival time\tBurst time\tPriority\tTurnaround time\tWaiting time");
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
	}
	
}
