#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"



void setUp(){}
void tearDown(){}

void test_Institution_reverse_3_elememt(){
	LinkedList inputList;
	LinkedList outputList;
	
	// Element
	Institution inst1;
	Institution inst2;
	Institution inst3;
	
	// =========Mocking=========
	
	// RemoveHead from Element1 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst1);
	Stack_push_Expect(&stack, &inst1);
	
	// RemoveHead from Element2 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst2);
	Stack_push_Expect(&stack, &inst2);
	
	// RemoveHead from Element3 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst3);
	Stack_push_Expect(&stack, &inst3);
	
	// inputList is NULL 
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	// Pop Element1 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst3);
	List_addTail_Expect(&outputList, &inst3);
	
	//Pop Element2 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst2);
	List_addTail_Expect(&outputList, &inst2);
	
	//Pop Element3 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst1);
	List_addTail_Expect(&outputList, &inst1);
	
	// Function call
	Institution_reverse(&inputList, &outputList);

}

void test_Institution_reverse_4_elememt(){
	LinkedList inputList;
	LinkedList outputList;
	
	// Element
	Institution inst1;
	Institution inst2;
	Institution inst3;
	Institution inst4;
	
	// RemoveHead from Element1 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst1);
	Stack_push_Expect(&stack, &inst1);
	
	// RemoveHead from Element2 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst2);
	Stack_push_Expect(&stack, &inst2);
	
	// RemoveHead from Element3 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst3);
	Stack_push_Expect(&stack, &inst3);
	
	// RemoveHead from Element4 and push into stack
	List_removeHead_ExpectAndReturn(&inputList, &inst4);
	Stack_push_Expect(&stack, &inst4);
	
	// inputList is NULL
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	// Pop Element1 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst4);
	List_addTail_Expect(&outputList, &inst4);
	
	// Pop Element2 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst3);
	List_addTail_Expect(&outputList, &inst3);
	
	// Pop Element3 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst2);
	List_addTail_Expect(&outputList, &inst2);
	
	// Pop Element4 from stack and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst1);
	List_addTail_Expect(&outputList, &inst1);
	
	// Function call
	Institution_reverse(&inputList, &outputList);

}

void test_isUniversity_should_return_1_compare_of_institutions_is_same(){
	
	int compare;
	
	Institution inst1 = {.type = Unknown};
	Institution inst2 = {.type = University};
	Institution inst3 = {.type = UniversityCollege};
	Institution inst4 = {.type = College};

	InstitutionType instType1 = Unknown;
	compare = isUniversityCollege(&inst1, &instType1);
	TEST_ASSERT_EQUAL(1, compare);
	
	InstitutionType instType2 = University;
	compare = isUniversityCollege(&inst2, &instType2);
	TEST_ASSERT_EQUAL(1, compare);
	
	InstitutionType instType3 = UniversityCollege;
	compare = isUniversityCollege(&inst3, &instType3);
	TEST_ASSERT_EQUAL(1, compare);
	
	InstitutionType instType4 = College;
	compare = isUniversityCollege(&inst4, &instType4);
	TEST_ASSERT_EQUAL(1, compare);
}

void test_isUniversity_should_return_0_compare_of_institutions_is_not_same(){
	
	int compare;

	Institution inst1 = {.type = College};
	Institution inst2 = {.type = UniversityCollege};
	Institution inst3 = {.type = University};
	Institution inst4 = {.type = Unknown};

	InstitutionType instType1 = Unknown;
	compare = isUniversityCollege(&inst1, &instType1);
	TEST_ASSERT_EQUAL(0, compare);
	
	InstitutionType instType2 = University;
	compare = isUniversityCollege(&inst2, &instType2);
	TEST_ASSERT_EQUAL(0, compare);
	
	InstitutionType instType3 = UniversityCollege;
	compare = isUniversityCollege(&inst3, &instType3);
	TEST_ASSERT_EQUAL(0, compare);
	
	InstitutionType instType4 = College;
	compare = isUniversityCollege(&inst4, &instType4);
	TEST_ASSERT_EQUAL(0, compare);
}

void test_Institution_select_Unknown_only(){
	
	LinkedList inputList;
	LinkedList outputList;
	
	Institution inst1 = {.type = Unknown};
	Institution inst2 = {.type = University};
	Institution inst3 = {.type = UniversityCollege};
	Institution inst4 = {.type = College};
	
	InstitutionType instType = University;
	
	List_removeHead_ExpectAndReturn(&inputList, &inst1);
	List_removeHead_ExpectAndReturn(&inputList, &inst2);
	Stack_push_Expect(&stack, &inst2);
	List_removeHead_ExpectAndReturn(&inputList, &inst3);
	List_removeHead_ExpectAndReturn(&inputList, &inst4);
	
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &inst3);
	List_addTail_Expect(&outputList, &inst3);
	
	Institution_select(	&inputList, &outputList, 
						&instType, isUniversityCollege);
}


