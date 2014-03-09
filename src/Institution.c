#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Institution.h"

extern Stack stack;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	
	void *temp1;
	int flag = 0;
	
	if(inputList->head == NULL){
		return 0;
	}
	
	while((temp1 = List_removeHead(inputList)) != NULL){
		Stack_push(&stack, temp1);
		flag ++;
	}
	
	while(flag!=0){
	temp1 = Stack_pop(&stack);
	List_addTail(outputList, temp1);
	flag --;
	}

}

