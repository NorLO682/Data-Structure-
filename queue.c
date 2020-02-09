#include "queue.h"
#include <stdio.h>
#define INITIAL_VALUE -1
#define EMPTY 0

void createQueue(ST_queueInfo** info, int maxSize){
	* info= (ST_queueInfo *) malloc(sizeof(ST_queueInfo));
	
	if(*info!=NULL){
	(*info)->arr=(char *)malloc((sizeof(int)*maxSize));
	if((*info)->arr!=NULL){
	(*info)->size=maxSize;
   (*info)->qe_head=INITIAL_VALUE;
   (*info)->qe_tail=INITIAL_VALUE;
   (*info)->nu_qe_element=EMPTY;

	}
	else 
		info=NULL;	
	
}
}
void enqueue(ST_queueInfo *info, char data){
		if (info!=NULL){
			 if (info->nu_qe_element<info->size){
				if(info->qe_tail<info->size-1)
					info->qe_tail++;
				else if (info->qe_tail==info->size-1)
					info->qe_tail=0;
					info->arr[info->qe_tail]=data;
					
				if(info->nu_qe_element==EMPTY)
					info->qe_head=info->qe_tail;
				info->nu_qe_element++;
			}
			//full
			}
			//no que
	}		

void dequeue(ST_queueInfo *info, char* data){
	if (info!=NULL){
		 if (info->nu_qe_element>EMPTY){
				
				*data=info->arr[info->qe_head];
					info->nu_qe_element--;
				
				if (info->qe_head<(info->size-1)){
				info->qe_head++;
				
				}
				else if (info->qe_head==(info->size-1)){
					info->qe_head=0;
				
			}
				
			}
		else 
			printf("queue is empty\n");
}
// no que 
}
