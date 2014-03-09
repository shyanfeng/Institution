#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Institution.h"

Stack stack;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	
	void *temp1;
	int flag = 0;

	
	if(inputList->head == NULL){
		return 0;
	}
	
	if((temp1 = List_removeHead(inputList)) != NULL){
		Stack_push(&stack, temp1);
		flag ++;
	}
	
	while(flag!=0){
	List_addTail(outputList, temp1);
	temp1 = Stack_pop(&stack);
	
	}


}

