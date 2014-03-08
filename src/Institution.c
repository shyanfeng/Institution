#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Institution.h"

Stack stack;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	
	void *temp1;
	int counter;
	
	if(inputList->head == NULL){
		return 0;
	}
		
	for(counter = 0; counter <= 3; counter++)
		temp1 = List_removeHead(inputList);
		Stack_push(&stack, temp1);
		
		temp1 = Stack_pop(&stack);
		List_addTail(outputList, temp1);
		
		return 1;
}

