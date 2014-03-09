#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"






void setUp(){}

void tearDown(){}



void test_Institution_reverse_3_elememt(){

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

 Stack_push_CMockExpect(26, &stack, &inst3);



 List_removeHead_CMockExpectAndReturn(28, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(30, &stack, &inst3);

 List_addTail_CMockExpect(31, &outputList, &inst3);



 Stack_pop_CMockExpectAndReturn(33, &stack, &inst2);

 List_addTail_CMockExpect(34, &outputList, &inst2);



 Stack_pop_CMockExpectAndReturn(36, &stack, &inst1);

 List_addTail_CMockExpect(37, &outputList, &inst1);



 Institution_reverse(&inputList, &outputList);



}
