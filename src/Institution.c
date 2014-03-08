#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Institution.h"

Stack stack;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	
	void *temp1;
	
	for(inputList->head;  inputList!= NULL; inputList->head++)
		temp1 = List_removeHead(inputList);
		Stack_push(&stack, temp1);
		
		temp1 = List_removeHead(inputList);
		Stack_push(&stack, temp1);
		
		temp1 = List_removeHead(inputList);
		Stack_push(&stack, temp1);
		
		temp1 = Stack_pop(&stack);
		List_addTail(outputList, temp1);
		
		temp1 = Stack_pop(&stack);
		List_addTail(outputList, temp1);
		
		temp1 = Stack_pop(&stack);
		List_addTail(outputList, temp1);
		
		return 1;
}

