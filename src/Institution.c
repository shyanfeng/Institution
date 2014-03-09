#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Institution.h"
#include "CException.h"

extern Stack stack;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	
	void *temp1;
	int flag = 0;
	
	// Return 0 if inputList->List is NULL
	if(inputList->head == NULL){
		return 0;
	}
	
	// Remove head if not NULL and push into stack
	while((temp1 = List_removeHead(inputList)) != NULL){
		Stack_push(&stack, temp1);
		flag ++;
	}
	
	// Pop from stack and add tail
	while(flag!=0){
		temp1 = Stack_pop(&stack);
		List_addTail(outputList, temp1);
		flag --;
	}

}

int isUniversityCollege(void *elem1, void *type){

	Institution *tempInst = (Institution*)elem1;
	InstitutionType *instType = (InstitutionType*)type;

	if(tempInst->type == *instType){
		return 1;
	}else{
		return 0;
	}
}

int Institution_select(	LinkedList *inputList,
						LinkedList *outputList,
						void *criterion,
						int (*compare)(void *, void *)){

	void *temp1;
	int flag = 0;
	
	if(inputList->head == NULL){
		return 0;
	}
	
	while((temp1 = List_removeHead(inputList)) != NULL){
		if(compare(temp1, criterion)){
		Stack_push(&stack, temp1);
		flag ++;
		}
	}

	while(flag!=0){
		temp1 = Stack_pop(&stack);
		List_addTail(outputList, temp1);
		flag --;
	}
	
}

int wasEstablishBefore(void *elem, void *year){
	Institution *inst = (Institution*)elem;
	// Change void year to int
	int *sYear = (int*)year;
	
	// More than 2014 will throw error
	if(inst->yearEstablished > 2014){
		Throw(ERROR_YEAR_ESTABLISHED);
	}else{
		if(inst->yearEstablished < *sYear){
			return 1;
		}else{
			return 0;
		}
	}
	
}


