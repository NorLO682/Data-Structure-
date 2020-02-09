

#include"stack.h"

#include <stdio.h>


void createStack(ST_stackInfo **info, int size){
	
	* info= (ST_stackInfo *) malloc(sizeof(ST_stackInfo));
	
	if(*info!=NULL){
	(*info)->arr=(char *)malloc((sizeof(int)*size));
	if((*info)->arr!=NULL){
	(*info)->size=size-1;
   (*info)->stack_pointer=INITIAL_VALUE;

	}
	else 
		info=NULL;	
	
}

}

	
	void push(ST_stackInfo *info, int data){
		if ((info!=NULL)&&(info->stack_pointer<info->size)){
			info->stack_pointer++;
		info->arr[info->stack_pointer]=data;
			
		}
		else 
			printf("stack is full\n");
	}
	
	
	void pop(ST_stackInfo *info, int* data){
		if ((info!=NULL)&&(info->stack_pointer>INITIAL_VALUE)){
			
		*data=info->arr[info->stack_pointer];
		
		info->stack_pointer--;
			
		}
		else 
			printf("stack is empty\n");
	}
	
	
