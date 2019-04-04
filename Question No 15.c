#include<stdio.h>
#include<stdbool.h>
int main()
{
	int i,j,n=5;
	int rr[5][2],c=0;
	int a[5][3] = {
                 {0,4,2},   
                 {1,3,3},  
                 {2,1,0},
                 {3,5,9},
                 {5,2,5},
              };
    int pr[]={0,2,3,5,9};
    i=0;
   for(i=0;i<=n-2;i++)
    {
		printf("p[%d] is running\n",i);
			if(a[i][2]<a[i+1][2])
			{
				int h=a[i][2]-a[i+1][0];
				if (h<=0)
				{
					//printf("the pprocess will run whole in this block only%d times \n",h);
					continue;
				}
				else
				{//whe h is bigger than 0 that is (first sec element)-(next fist element) is  bigger  
					int pos;
					//here im finding out the pos in priority array 
					for(j=0;j<=n-1;j++)
					{
						if(pr[j]==a[i][2])
						{
							pos=j;
						}
					}
					//fosision got
					
					printf("sjg %d hwj",pos);
					int our=pr[pos-1];
					//before the 2 what  number is present  okie?
					
					printf("\nds%dsd\n",our);
					int our2;
					int k=i;
					//our 2 basicallcally check what posiition our is present
					for(j=k+1;j<=n-1;j++)
					{
						if(a[j][2]==our)
						{
							our2=j;
						}
					}
					printf("our is present at %d\n",our2);
					int j=a[our2][0]-a[i][1];
					if(j>=0)
					{
						printf("this proces %d is going to go for all%d",i,j);
					}
					else
					{
						printf("\npreem");
						rr[i][0]=i;
						rr[i][1]=a[i][0];
						rr[i][2]=j;
						c++;
					}
				}
			}
			else
			{
				//printf("this one is going to be preemted\n");
				int h=a[i][2]-a[i+1][0];
				if(h<=0)
				{
					//printf("this whiole block will be running here only %d times \n",h);
				}
				else if(h>0)
				{
					printf("preemns\n");
					rr[i][0]=i;
					rr[i][1]=a[i][0];
					rr[i][2]=h;
					c++;
				}
			}
			printf("\njhs\n");
			
		}
		printf("\n c vaie is %d\n",c);
	for(i=0;i<=c-1;i++)
			{
				for(j=0;j<=2;j++)
				{
					printf("%d ",rr[i][j]);
				}
				printf("\n");
			}
	return 0;
}

