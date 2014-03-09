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





 List_removeHead_CMockExpectAndReturn(21, &inputList, &inst1);

 Stack_push_CMockExpect(22, &stack, &inst1);



 List_removeHead_CMockExpectAndReturn(24, &inputList, &inst2);

 Stack_push_CMockExpect(25, &stack, &inst2);



 List_removeHead_CMockExpectAndReturn(27, &inputList, &inst3);

 Stack_push_CMockExpect(28, &stack, &inst3);



 List_removeHead_CMockExpectAndReturn(30, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(32, &stack, &inst3);

 List_addTail_CMockExpect(33, &outputList, &inst3);



 Stack_pop_CMockExpectAndReturn(35, &stack, &inst2);

 List_addTail_CMockExpect(36, &outputList, &inst2);



 Stack_pop_CMockExpectAndReturn(38, &stack, &inst1);

 List_addTail_CMockExpect(39, &outputList, &inst1);



 Institution_reverse(&inputList, &outputList);



}



void test_Institution_reverse_4_elememt(){

 LinkedList inputList;

 LinkedList outputList;





 Institution inst1;

 Institution inst2;

 Institution inst3;

 Institution inst4;





 List_removeHead_CMockExpectAndReturn(56, &inputList, &inst1);

 Stack_push_CMockExpect(57, &stack, &inst1);



 List_removeHead_CMockExpectAndReturn(59, &inputList, &inst2);

 Stack_push_CMockExpect(60, &stack, &inst2);



 List_removeHead_CMockExpectAndReturn(62, &inputList, &inst3);

 Stack_push_CMockExpect(63, &stack, &inst3);



 List_removeHead_CMockExpectAndReturn(65, &inputList, &inst4);

 Stack_push_CMockExpect(66, &stack, &inst4);



 List_removeHead_CMockExpectAndReturn(68, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(70, &stack, &inst4);

 List_addTail_CMockExpect(71, &outputList, &inst4);



 Stack_pop_CMockExpectAndReturn(73, &stack, &inst3);

 List_addTail_CMockExpect(74, &outputList, &inst3);



 Stack_pop_CMockExpectAndReturn(76, &stack, &inst2);

 List_addTail_CMockExpect(77, &outputList, &inst2);



 Stack_pop_CMockExpectAndReturn(79, &stack, &inst1);

 List_addTail_CMockExpect(80, &outputList, &inst1);



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

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);



 InstitutionType instType2 = University;

 compare = isUniversityCollege(&inst2, &instType2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);



 InstitutionType instType3 = UniversityCollege;

 compare = isUniversityCollege(&inst3, &instType3);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);



 InstitutionType instType4 = College;

 compare = isUniversityCollege(&inst4, &instType4);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

}



void test_isUniversity_should_return_0_compare_of_institutions_is_not_same(){



 int compare;



 Institution inst1 = {.type = College};

 Institution inst2 = {.type = UniversityCollege};

 Institution inst3 = {.type = University};

 Institution inst4 = {.type = Unknown};



 InstitutionType instType1 = Unknown;

 compare = isUniversityCollege(&inst1, &instType1);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);



 InstitutionType instType2 = University;

 compare = isUniversityCollege(&inst2, &instType2);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);



 InstitutionType instType3 = UniversityCollege;

 compare = isUniversityCollege(&inst3, &instType3);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);



 InstitutionType instType4 = College;

 compare = isUniversityCollege(&inst4, &instType4);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

}



void test_Institution_select_Unknown_only(){



 LinkedList inputList;

 LinkedList outputList;



 Institution inst1 = {.type = Unknown};

 Institution inst2 = {.type = University};

 Institution inst3 = {.type = UniversityCollege};

 Institution inst4 = {.type = College};



 InstitutionType instType = University;



 List_removeHead_CMockExpectAndReturn(150, &inputList, &inst1);

 List_removeHead_CMockExpectAndReturn(151, &inputList, &inst2);

 Stack_push_CMockExpect(152, &stack, &inst2);

 List_removeHead_CMockExpectAndReturn(153, &inputList, &inst3);

 List_removeHead_CMockExpectAndReturn(154, &inputList, &inst4);



 List_removeHead_CMockExpectAndReturn(156, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(158, &stack, &inst3);

 List_addTail_CMockExpect(159, &outputList, &inst3);



 Institution_select( &inputList, &outputList,

      &instType, isUniversityCollege);

}
