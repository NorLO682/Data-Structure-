
#ifndef LINKED_LIST__H
#define QUEUWE__H
#include <stdlib.h>

typedef struct ST_node {
	int data;
	
	struct ST_node * ptr_next;
	
} ST_node;


typedef struct  {
	
	int count;
	
	ST_node * head;

} ST_list ;

    char createList(ST_list **list);
	
	void insertToList(ST_node **listHead, unsigned char position, int data);
	
	void deleteFromList(ST_node **listHead, unsigned char position, int* data);
	ST_node* searchIntoList(ST_node *listHead, int data); 

	#endif 