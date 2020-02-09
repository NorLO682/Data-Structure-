#ifndef QUEUWE__H
#define QUEUWE__H
#include <stdlib.h>

typedef struct  {
	int size;
	int nu_qe_element;
	int qe_head;
	int qe_tail;
	char * arr;
} ST_queueInfo;
/**
 * Description:Creat Queqe control block and queqe element (array based )
 * @param info :The address of the queqe pointer passed NOT it's value
 *                i.e.(ST_queueInfo *que=NULL;createQueue(&que,maxSize);)
 *@param size: Number of queqe element 
 */
void createQueue(ST_queueInfo** info, int maxSize);
/**
 * Description:Passing data to queqe
 * @param info :Queqe pointer "value"
 *@param deta: the data that written to queqe 
 */
	void enqueue(ST_queueInfo *info, char data);
/**
 * Description:Getting data from  queqe
 * @param info :Queqe pointer "value"
 *@param deta: the data's adress that resivses data form queqe 
 */
	void dequeue(ST_queueInfo *info, char* data);

	
	#endif 
	