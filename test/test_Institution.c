#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"



void setUp(){}
void tearDown(){}

void test_Institution_reverse_should_remove_head_and_put_in_stack(){
	LinkedList inputList;
	LinkedList outputList;
	
	Institution inst1;
	Institution inst2;
	Institution inst3;
	
	List_removeHead_ExpectAndReturn(&inputList, &inst1);
	Stack_push_Expect(&stack, &inst1);
	
	//List_removeHead_ExpectAndReturn(&inputList, &inst2);
	//Stack_push_Expect(&stack, &inst2);
	
	//List_removeHead_ExpectAndReturn(&inputList, &inst3);
	//Stack_push_Expect(&stack, &inst3);
	
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	//Stack_pop_ExpectAndReturn(&stack, &inst3);
	//List_addTail_Expect(&outputList, &inst3);
	
	//Stack_pop_ExpectAndReturn(&stack, &inst2);
	//List_addTail_Expect(&outputList, &inst2);
	
	Stack_pop_ExpectAndReturn(&stack, &inst1);
	List_addTail_Expect(&outputList, &inst1);
	
	Institution_reverse(&inputList, &outputList);

}