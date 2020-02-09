
#ifndef STACK__H
#define STACK__H

#include <stdlib.h>
#define INITIAL_VALUE -1
typedef struct stack {
	int size;
	int stack_pointer;
	char * arr;
} ST_stackInfo;

/**
 * Description:Creat stack control block and stack element (array based )
 * @param info :The address of the stack pointer passed NOT it's value
 *                i.e.(ST_stackInfo *st=NULL;createStack(&st,size);)
 *@param size: Number of stack element 
 */
void createStack(ST_stackInfo **info, int size);
/**
 * Description:Passing data to stack
 * @param info :Stack pointer "value"
 *@param deta: the data that written to stack  
 */
	void push(ST_stackInfo *info, int data);
/**
 * Description:Getting data from  stack 
 * @param info :Stack pointer "value"
 *@param deta: the data's adress that resivses data form  stack  
 */
	void pop(ST_stackInfo *info, int* data);

#endif 