#include "linkedLhist.h"
#include <stdio.h>
#define INITIAL_VALUE -1
#define EMPTY 0

char createList(ST_list  **list){
	* list= ( ST_list*) malloc(sizeof(ST_list));
	if(*list!=NULL)
	(*list)->head=NULL;
}

void insertToList(ST_node **listHead, unsigned char position, int data){
	//if(listHead!=NULL){
		unsigned char index=1;
		ST_node *temp1=NULL,*temp2=NULL;
		if((*listHead)==NULL){
			(*listHead)= ( ST_node*) malloc(sizeof(ST_node));
		    (*listHead)->ptr_next=NULL;
			(*listHead)->data=data;
			//(*listHead)->count++;
		}
		else if (position==1){
			temp1=( ST_node*) malloc(sizeof(ST_node));
			temp1->ptr_next=(*listHead);
		(*listHead)=temp1;
		temp1->data=data;
			//(*listHead)->count++;
		}
		else {
		    //  printf("hjhkj\n");
			temp2=(*listHead);
			for (;(index<position-1 );index++){
				//printf("%d",temp2->ptr_next);
					if(temp2->ptr_next==NULL)
			        	break;
			//	printf("%d",index);
			temp2=temp2->ptr_next;
			//printf(" y %d",index);
		
			}
		temp1=( ST_node*) malloc(sizeof(ST_node));
			temp1->ptr_next=temp2->ptr_next;
			temp2->ptr_next=temp1;
			(temp1)->data=data;
			//(*listHead)->count++;
		}
	//}
}


// deleteFromList: untested function 
void deleteFromList(ST_node **listHead, unsigned char position, int* data){ 
		ST_node *temp1=*listHead,*temp2=NULL;
		unsigned char index=1;
		if(*listHead!=NULL){
			
			if(position==1){
				*listHead=(*listHead)->ptr_next;
			}
			
			else{
				for(;index<position;index++){
					if(temp1->ptr_next!=NULL){
					temp2=temp1;
					temp1=temp1->ptr_next;}
					else 
						break;
				}
				if(index==position){
					temp2->ptr_next=temp1->ptr_next;
				}
			}
			
		}
		//empty list
	}

// searchIntoList: untested function 	
ST_node* searchIntoList(ST_node *listHead, int data){
	if(listHead!=NULL){
		while (listHead->ptr_next!=NULL){
		if(listHead->data==data)
			return listHead;
		else
		listHead=listHead->ptr_next;
		}
		if(listHead->data==data)
		return listHead;
	else 
		return NULL;
	}
	//emty list
	return NULL;
	}
	
	