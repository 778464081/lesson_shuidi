#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <conio.h> 
/*#include "stdafx.h"*/
#define  N  2
struct  PCB
{
	char name[8];
	int  arrive_time;
	int  run_time;
   	int finish_time;
	int  zhouzhuan_time;
	float daiquan_time;
	float ave_time;
	float daiquan_ave_time;
	
};
int  total=0; 
struct  PCB  pcb[N],temp;
void  output()
{ 
    printf("----------------------------------------------------------------------------------------------\n");
    printf("进程名   到达时间  运行时间  完成时间  周转时间  带权周转时间  平均周转时间  平均带权周转时间 \n");
	printf("----------------------------------------------------------------------------------------------\n");
    for(int  i=0;i<N;i++)
	{
	for(int a=0;a<N-1;a++)
		{
			for(int b=0;b<N-a-1;b++)
			{
				if(pcb[b].arrive_time>pcb[b+1].arrive_time)
				{	
					temp=pcb[b];
					pcb[b]=pcb[b+1];
					pcb[b+1]=temp;
				}
			}
		}
		printf(" %s        %d         %d         %d         %d         %.1f         %.1f           %.1f \n",pcb[i].name,pcb[i].arrive_time,pcb[i].run_time,pcb[i].finish_time,pcb[i].zhouzhuan_time,pcb[i].daiquan_time,pcb[i].ave_time,pcb[i].daiquan_ave_time);
	}
    printf("----------------------------------------------------------------------------------------------\n");
}
void  main()
{   
   
	int i,j;
	for ( i=0;i<N;i++)
	{
		printf("请输入进程名\n" );
        scanf("%s",&pcb[i].name);
		printf("请输入到达时间:");
		scanf("%d",&pcb[i].arrive_time);
		printf("请输入要运行时间");
		scanf("%d",&pcb[i].run_time);		
	}
	for( i=0;i<N;i++)
	{  	
		printf("%s    ",pcb[i].name);
        printf("%d    ",pcb[i].arrive_time);
		printf("%d \n",pcb[i].run_time);
    }

	pcb[0].finish_time=pcb[0].arrive_time+pcb[0].run_time;
	pcb[0].zhouzhuan_time=pcb[0].finish_time-pcb[0].arrive_time;
	pcb[0].daiquan_time=(float)pcb[0].zhouzhuan_time/pcb[0].run_time;
	pcb[0].ave_time=0;
	pcb[0].daiquan_ave_time=0;

  	for(i=1;i<N;i++)
	{	 
		if(pcb[i-1].finish_time<pcb[i].arrive_time)
		{
		float a=pcb[i].arrive_time-pcb[i-1].finish_time;	
		pcb[i].zhouzhuan_time=pcb[i].finish_time-pcb[i].arrive_time+a;
		
		}
        pcb[i].finish_time=pcb[i-1].finish_time+pcb[i].run_time;
        pcb[i].zhouzhuan_time=pcb[i].finish_time-pcb[i].arrive_time;
	    pcb[i].daiquan_time=(float)pcb[i].zhouzhuan_time/pcb[i].run_time;
	    pcb[i].ave_time=(pcb[i-1].zhouzhuan_time+pcb[i].zhouzhuan_time)/2;	
		pcb[i].daiquan_ave_time=(pcb[i-1].daiquan_time+pcb[i].daiquan_time)/2;
	
	}	
	output();
}
