#include"stack.h"
#include <stdio.h>
# define COMPARE_MASK 0xF0
#define SI_OF_STACK 255
#define zERO 0
#define ONE 1
	int  checkForBalancedParantheses(char* expression){
		ST_stackInfo *st=NULL;
		createStack(&st,SI_OF_STACK);
		int count =zERO ;
		int data=zERO ;
		char flag= 1;
		
		while (expression[count]!='\0'){
			if(flag){
			switch (expression[count]){
				case '(':
				case '[':
				case '{':
				push(st, expression[count]);
				break;
				case ')':
				case']':
				case'}':
	
				if((expression[count]&COMPARE_MASK)==((st->arr[st->stack_pointer])&COMPARE_MASK)){
					
			pop(st,&data);
			 break;}
		     else {
					flag= 0;
			 break;}
			}
		count++;
		}
	
           else 
			break;
		}
		
		if(((st->stack_pointer)==INITIAL_VALUE)&&(flag!=0)){
		return 1;
		printf("palanced ");}
	
		else {
		printf("unpalance ");
		return 0;
		}
}










