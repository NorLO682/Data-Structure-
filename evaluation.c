#include<stdio.h>
#include "queue.h"
#include "stack.h"
//function declaration 
long long evaluate(char* expression);//written/ Under devlopment /Un-tested
int intger(ST_queueInfo* qu);//Complet&Tested

int  checkForBalancedParantheses(char* expression); //Complet&Tested

void Get_nuPhase(ST_queueInfo* qu);//Under devlopment /Un-tested

void determent_phase(ST_queueInfo* qu);//Under devlopment /Un-tested

int evaluation(void); //Under devlopment /Un-tested



// phase2__Determent operation__ define 

#define OPERATIN_MASK 0xF8
#define OPERATIN_ALLWDED_VALUE_RANGE 0x38

//evaluate functn 

// phase1__GETNumbe Phase__variable 
static int nu1_ex=0;
static int  nu2_ex=0;
static char phase1_flag=1;

static int nu1=0;
 static int nu2=0;

 

// phase2__operation_Determnation Phase __Variable 
static char  change_sing_flag=0;
static char  sing_data=0;

static char sum_coun_before=0;
static char sum_coun_after=0;
 
static char sub_coun_before=0;
static char sub_coun_after=0;
 
static char mult_coun=0;

static char div_coun=0;

 



//phase3_EVALUATION phase __variable 
static char exe_flag=5;


//Untested  functions 

long long evaluate(char* expression){
	//ST_stackInfo *st_par=NULL;
	ST_queueInfo *qu_nu_op=NULL;
	int count =0,cheak_par=0;
	int   active=1;
	//createStack(&st_par, 255);
	createQueue(&qu_nu_op, 255);
	while (expression[count]!='\0'){
		switch (expression[count]){
				case '(':
				case '[':
				case '{':
				// push(st_par,expression[count]);
				break;
				default:
	enqueue(qu_nu_op,expression[count]);
	break;
	}
	count++;
}
enqueue(qu_nu_op,'\0');
 cheak_par=checkForBalancedParantheses(expression);
if(cheak_par==1){
 while ((active==1)&&(qu_nu_op->arr[qu_nu_op->qe_head]!='\0')){
	 if((qu_nu_op->arr[qu_nu_op->qe_head] <=0x39)&&(qu_nu_op->arr[qu_nu_op->qe_head] >=0x30))
		 Get_nuPhase(qu_nu_op);
	 else 
		 determent_phase(qu_nu_op);
	 
	     active= evaluation();
 }
 if (active==1){
	printf(" valid"); 
	return nu1;
 }
}
else{
printf("not valid");
	return 0xFFFFFF;
	}
	}



void Get_nuPhase(ST_queueInfo* qu){
	switch(phase1_flag){
		case 1:
		//if(nu1_ex==0){//is it important !
			 nu1=intger(qu);
			nu1_ex=1;
			if (change_sing_flag==1)
			phase1_flag=2;
			else 
				phase1_flag=3;
		//if(nu1_ex==0)braket }
 break;
 
 case 2:
 if(nu1_ex==1){
 if (change_sing_flag==1){//not im
	 change_sing_flag=3;// or 0
 nu1*=-1;
 phase1_flag=3;
 }
 //may anther action 
 }
 else 
	 phase1_flag=1;
		 break;
		 
		 case 3:
		 //if(nu2_ex==0){//is it important !
			nu2=intger(qu);
			nu2_ex=1;
			if (change_sing_flag==1)
			phase1_flag=4;
			else 
				phase1_flag=6;
		// }//if nu1_ex==0  braket
      break;
  case 4:
   if(nu2_ex==1){
 if (change_sing_flag==1){//not im
	 change_sing_flag=3;//or 0
 nu2*=-1;
 phase1_flag=6;
 }
 //may anther action 
 }
 else 
	 phase1_flag=3;
		 break;	
/*case 5 :
 if((nu1_ex==1)&&(nu2_ex==2)){
	nu1^=nu2;
    nu2^=nu1;
     nu1^=nu2;
phase1_flag=6;	  
 }
 break;*/

}
}


void determent_phase(ST_queueInfo* qu){
	if(phase1_flag!=6){
		if((qu->arr[qu->qe_head]&OPERATIN_MASK)==OPERATIN_ALLWDED_VALUE_RANGE){
			dequeue(qu,&sing_data);
			
			switch(sing_data){
				case '+':
				if(nu1_ex==0){
					if(sum_coun_before==0){
					exe_flag=5;
					phase1_flag	=1;
					sum_coun_before++;
				}
				else if((sum_coun_before==1)||(sub_coun_before==1))
					exe_flag=0;
				break;
				}
				else if(nu1_ex==1){
					if(sum_coun_after==0){
						
						if(sub_coun_after==1){
							exe_flag=2;
							sum_coun_after++;
							phase1_flag	=3;
							break;
						}
						else if(sub_coun_after>1){
							exe_flag=0;
							break;
						}
						else if(mult_coun==1){
							exe_flag=3;
							sum_coun_after++;
							phase1_flag	=3;
							break;
						}
						else if(div_coun==1){
							exe_flag=4;
							sum_coun_after++;
							phase1_flag	=3;
							break;
						}
						else{
							exe_flag=1;
							sum_coun_after++;
							phase1_flag	=3;
							break;
						}
					}
					else if(sum_coun_after>0){
						if( (sub_coun_after==0)&&(mult_coun==0)&&(div_coun==0)){
							if(sum_coun_after==1){
								exe_flag=1;
							sum_coun_after++;
							phase1_flag	=3;
							break;
							}
							else {
								exe_flag=0;
								break;
							}
						}
						else {
							exe_flag=0;
								break;
						}
					}
			}
			
		case '-':
				if(nu1_ex==0){
					if(sub_coun_before==0){
					exe_flag=5;
					phase1_flag	=2;
					change_sing_flag=1;
					sub_coun_before++;
				}
				else if((sub_coun_before==1)||(sum_coun_before==1))
					exe_flag=0;
				break;
				}
				else if(nu1_ex==1){
					if(sub_coun_after==0){
						
						if(sum_coun_after==1){
							exe_flag=1;
							sub_coun_after++;
							change_sing_flag=1;
							phase1_flag	=4;
							break;
						}
						else if(sum_coun_after>1){
							exe_flag=0;
							break;
						}
						else if(mult_coun==1){
							exe_flag=3;
							sub_coun_after++;
							phase1_flag	=4;
							change_sing_flag=1;
							break;
						}
						else if(div_coun==1){
							exe_flag=4;
							sub_coun_after++;
							phase1_flag	=4;
							change_sing_flag=1;
							break;
						}
						else{
							exe_flag=2;
							sub_coun_after++;
							phase1_flag	=3;
							
							break;
						}
					}
					else if(sub_coun_after>0){
						if( (sum_coun_after==0)&&(mult_coun==0)&&(div_coun==0)){
							if(sub_coun_after==1){
								exe_flag=2;
							sum_coun_after++;
							phase1_flag	=4;
							break;
							}
							else {
								exe_flag=0;
								break;
							}
						}
						else {
							exe_flag=0;
								break;
						}
					}
			}
			
			
			case '*':
			
			if(nu1_ex==0){
				exe_flag=0;
				break;
			}
			else{
				if((sum_coun_after==0)||(sub_coun_after==0)||(mult_coun==0)||(div_coun==0)){
					exe_flag=0;
				break;
				}
				else {
					mult_coun++;
					exe_flag=3;
					phase1_flag	=3;
							break;
				}
			}
			
			case '/':
			if(nu1_ex==0){
				exe_flag=0;
				break;
			}
			else{
				if((sum_coun_after==0)||(sub_coun_after==0)||(mult_coun==0)||(div_coun==0)){
					exe_flag=0;
				break;
				}
				else {
					div_coun++;
					exe_flag=4;
					phase1_flag	=3;
							break;
				}
			}
			
			
			}
		}
	}
}

int evaluation(void){
	char reset=0;
	if(phase1_flag==6){
		switch(exe_flag){
			case 1:
			nu1+=nu2;
			reset=1;
			break;
			case 2:
			nu1-=nu2;
			reset=1;
			break;
			case 3:
			nu1*=nu2;
			reset=1;
			break;
			case 4:
			if(nu2==0)
				return 0;
			else{
			nu1/=nu2;
			reset=1;
			break;}
			case 0:
			return 0;
			
			
		}
		if(reset==1){
			sum_coun_after=0;
			sub_coun_after=0;
			mult_coun=0;
			div_coun=0;
			phase1_flag=3;
			return 1;
		}
	}
}









//Tested And work functions 

int intger(ST_queueInfo* qu){
int nu=0;
char data=0;
 while ((qu->arr[qu->qe_head] <=0x39)&&(qu->arr[qu->qe_head] >=0x30)){
 nu*=10;
 dequeue(qu,& data);
 nu +=(data-48);
 }
 return nu;
}

