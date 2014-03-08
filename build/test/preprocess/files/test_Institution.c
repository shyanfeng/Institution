#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"




void setUp(){}

void tearDown(){}



void test_Institution_reverse_should_remove_head_and_put_in_stack(){

 LinkedList inputList;

 LinkedList outputList;



 Institution inst1;

 Institution inst2;

 Institution inst3;





 List_removeHead_CMockExpectAndReturn(19, &inputList, &inst1);

 Stack_push_CMockExpect(20, &stack, &inst1);



 List_removeHead_CMockExpectAndReturn(22, &inputList, &inst2);

 Stack_push_CMockExpect(23, &stack, &inst2);



 List_removeHead_CMockExpectAndReturn(25, &inputList, &inst3);

 Stack_push_CMockExpect(26, &stack, &inst2);



 Stack_pop_CMockExpectAndReturn(28, &stack, &inst3);

 List_addTail_CMockExpect(29, &outputList, &inst3);



 Stack_pop_CMockExpectAndReturn(31, &stack, &inst2);

 List_addTail_CMockExpect(32, &outputList, &inst2);



 Stack_pop_CMockExpectAndReturn(34, &stack, &inst1);

 List_addTail_CMockExpect(35, &outputList, &inst1);



 Institution_reverse(&inputList, &outputList);

}
