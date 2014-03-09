#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include "CException.h"


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
	
	// =========Mocking=========
	
	// Compare the Unknown with the Institution
	InstitutionType instType1 = Unknown;
	compare = isUniversityCollege(&inst1, &instType1);
	TEST_ASSERT_EQUAL(1, compare);
	
	// Compare the University with the Institution
	InstitutionType instType2 = University;
	compare = isUniversityCollege(&inst2, &instType2);
	TEST_ASSERT_EQUAL(1, compare);
	
	// Compare the UniversityCollege with the Institution
	InstitutionType instType3 = UniversityCollege;
	compare = isUniversityCollege(&inst3, &instType3);
	TEST_ASSERT_EQUAL(1, compare);
	
	// Compare the College with the Institution
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
	
	// =========Mocking=========
	
	// Compare the Unknown with the Institution(College)
	InstitutionType instType1 = Unknown;
	compare = isUniversityCollege(&inst1, &instType1);
	TEST_ASSERT_EQUAL(0, compare);
	
	// Compare the University with the Institution(UniversityCollege)
	InstitutionType instType2 = University;
	compare = isUniversityCollege(&inst2, &instType2);
	TEST_ASSERT_EQUAL(0, compare);
	
	// Compare the UniversityCollege with the Institution(University)
	InstitutionType instType3 = UniversityCollege;
	compare = isUniversityCollege(&inst3, &instType3);
	TEST_ASSERT_EQUAL(0, compare);
	
	// Compare the College with the Institution(Unknown)
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
	
	// =========Mocking=========
	
	List_removeHead_ExpectAndReturn(&inputList, &inst1);
	List_removeHead_ExpectAndReturn(&inputList, &inst2);
	Stack_push_Expect(&stack, &inst2);
	List_removeHead_ExpectAndReturn(&inputList, &inst3);
	List_removeHead_ExpectAndReturn(&inputList, &inst4);
	
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	// Pop the selected inst2 and addTail
	Stack_pop_ExpectAndReturn(&stack, &inst2);
	List_addTail_Expect(&outputList, &inst2);
	
	// Function Call
	Institution_select(	&inputList, &outputList, 
						&instType, isUniversityCollege);
}

void test_wasEstablishBefore_2014_and_after_1950_should_return_0(){
	
	int year = 1970;
	
	Institution inst1 = {.yearEstablished = 1974};
	Institution inst2 = {.yearEstablished = 1989};
	Institution inst3 = {.yearEstablished = 1999};
	Institution inst4 = {.yearEstablished = 2012};
	
	// =========Mocking=========
	
	// Test the inst1 with year more than 1970
	wasEstablishBefore(&inst1, &year);
	TEST_ASSERT_EQUAL(0, wasEstablishBefore(&inst1, &year));
	
	// Test the inst2 with year more than 1970
	wasEstablishBefore(&inst2, &year);
	TEST_ASSERT_EQUAL(0, wasEstablishBefore(&inst1, &year));
	
	// Test the inst3 with year more than 1970
	wasEstablishBefore(&inst3, &year);
	TEST_ASSERT_EQUAL(0, wasEstablishBefore(&inst1, &year));
	
	// Test the inst4 with year more than 1970
	wasEstablishBefore(&inst4, &year);
	TEST_ASSERT_EQUAL(0, wasEstablishBefore(&inst1, &year));
	
}

void test_wasEstablishBefore_2014_and_before_1950_should_return_1(){
	
	int year = 1970;
	
	// =========Mocking=========
	
	Institution inst1 = {.yearEstablished = 1964};
	Institution inst2 = {.yearEstablished = 1959};
	Institution inst3 = {.yearEstablished = 1969};
	Institution inst4 = {.yearEstablished = 1962};
	
	// Test the inst1 with year less than 1970
	wasEstablishBefore(&inst1, &year);
	TEST_ASSERT_EQUAL(1, wasEstablishBefore(&inst1, &year));
	
	// Test the inst2 with year less than 1970
	wasEstablishBefore(&inst2, &year);
	TEST_ASSERT_EQUAL(1, wasEstablishBefore(&inst1, &year));
	
	// Test the inst3 with year less than 1970
	wasEstablishBefore(&inst3, &year);
	TEST_ASSERT_EQUAL(1, wasEstablishBefore(&inst1, &year));
	
	// Test the inst4 with year less than 1970
	wasEstablishBefore(&inst4, &year);
	TEST_ASSERT_EQUAL(1, wasEstablishBefore(&inst1, &year));
	
}

void test_wasEstablishBefore_should_throw_exception_error_after_2014(){

	int year = 1970;
	ExceptionError exception;
	
	Institution inst1 = {.yearEstablished = 2854};
	
	// Throw the exception when it is error
	Try{
		wasEstablishBefore(&inst1, &year);
	}
	Catch(exception){
		TEST_ASSERT_EQUAL(ERROR_YEAR_ESTABLISHED, exception);
	}
	
}

void test_wasEstablishBefore_should_throw_exception_error_for_selected_is_after_2014(){
	LinkedList inputList;
	LinkedList outputList;
	
	int year = 1970;
	ExceptionError exception;

	
	Institution inst1 = {.yearEstablished = 1964};
	Institution inst2 = {.yearEstablished = 2111};
	Institution inst3 = {.yearEstablished = 1969};
	Institution inst4 = {.yearEstablished = 1962};
	
	// No error detected
	List_removeHead_ExpectAndReturn(&inputList, &inst1);
	Stack_push_Expect(&stack, &inst1);
	
	// Error detected and throw
	List_removeHead_ExpectAndReturn(&inputList, &inst2);

	Try{
		Institution_select(	&inputList, &outputList, 
							&year, wasEstablishBefore);
	}
	Catch(exception){
		TEST_ASSERT_EQUAL(ERROR_YEAR_ESTABLISHED, exception);
	}
	
}