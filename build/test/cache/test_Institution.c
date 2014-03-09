#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"
#include "CException.h"






void setUp(){}

void tearDown(){}



void test_Institution_reverse_3_elememt(){

 LinkedList inputList;

 LinkedList outputList;





 Institution inst1;

 Institution inst2;

 Institution inst3;









 List_removeHead_CMockExpectAndReturn(23, &inputList, &inst1);

 Stack_push_CMockExpect(24, &stack, &inst1);





 List_removeHead_CMockExpectAndReturn(27, &inputList, &inst2);

 Stack_push_CMockExpect(28, &stack, &inst2);





 List_removeHead_CMockExpectAndReturn(31, &inputList, &inst3);

 Stack_push_CMockExpect(32, &stack, &inst3);





 List_removeHead_CMockExpectAndReturn(35, &inputList, ((void *)0));





 Stack_pop_CMockExpectAndReturn(38, &stack, &inst3);

 List_addTail_CMockExpect(39, &outputList, &inst3);





 Stack_pop_CMockExpectAndReturn(42, &stack, &inst2);

 List_addTail_CMockExpect(43, &outputList, &inst2);





 Stack_pop_CMockExpectAndReturn(46, &stack, &inst1);

 List_addTail_CMockExpect(47, &outputList, &inst1);





 Institution_reverse(&inputList, &outputList);



}



void test_Institution_reverse_4_elememt(){

 LinkedList inputList;

 LinkedList outputList;





 Institution inst1;

 Institution inst2;

 Institution inst3;

 Institution inst4;









 List_removeHead_CMockExpectAndReturn(67, &inputList, &inst1);

 Stack_push_CMockExpect(68, &stack, &inst1);





 List_removeHead_CMockExpectAndReturn(71, &inputList, &inst2);

 Stack_push_CMockExpect(72, &stack, &inst2);





 List_removeHead_CMockExpectAndReturn(75, &inputList, &inst3);

 Stack_push_CMockExpect(76, &stack, &inst3);





 List_removeHead_CMockExpectAndReturn(79, &inputList, &inst4);

 Stack_push_CMockExpect(80, &stack, &inst4);





 List_removeHead_CMockExpectAndReturn(83, &inputList, ((void *)0));





 Stack_pop_CMockExpectAndReturn(86, &stack, &inst4);

 List_addTail_CMockExpect(87, &outputList, &inst4);





 Stack_pop_CMockExpectAndReturn(90, &stack, &inst3);

 List_addTail_CMockExpect(91, &outputList, &inst3);





 Stack_pop_CMockExpectAndReturn(94, &stack, &inst2);

 List_addTail_CMockExpect(95, &outputList, &inst2);





 Stack_pop_CMockExpectAndReturn(98, &stack, &inst1);

 List_addTail_CMockExpect(99, &outputList, &inst1);





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

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);





 InstitutionType instType2 = University;

 compare = isUniversityCollege(&inst2, &instType2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);





 InstitutionType instType3 = UniversityCollege;

 compare = isUniversityCollege(&inst3, &instType3);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);





 InstitutionType instType4 = College;

 compare = isUniversityCollege(&inst4, &instType4);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

}



void test_isUniversity_should_return_0_compare_of_institutions_is_not_same(){



 int compare;



 Institution inst1 = {.type = College};

 Institution inst2 = {.type = UniversityCollege};

 Institution inst3 = {.type = University};

 Institution inst4 = {.type = Unknown};









 InstitutionType instType1 = Unknown;

 compare = isUniversityCollege(&inst1, &instType1);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);





 InstitutionType instType2 = University;

 compare = isUniversityCollege(&inst2, &instType2);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);





 InstitutionType instType3 = UniversityCollege;

 compare = isUniversityCollege(&inst3, &instType3);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);





 InstitutionType instType4 = College;

 compare = isUniversityCollege(&inst4, &instType4);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

}



void test_Institution_select_Unknown_only(){



 LinkedList inputList;

 LinkedList outputList;



 Institution inst1 = {.type = Unknown};

 Institution inst2 = {.type = University};

 Institution inst3 = {.type = UniversityCollege};

 Institution inst4 = {.type = College};



 InstitutionType instType = University;









 List_removeHead_CMockExpectAndReturn(185, &inputList, &inst1);

 List_removeHead_CMockExpectAndReturn(186, &inputList, &inst2);

 Stack_push_CMockExpect(187, &stack, &inst2);

 List_removeHead_CMockExpectAndReturn(188, &inputList, &inst3);

 List_removeHead_CMockExpectAndReturn(189, &inputList, &inst4);



 List_removeHead_CMockExpectAndReturn(191, &inputList, ((void *)0));





 Stack_pop_CMockExpectAndReturn(194, &stack, &inst2);

 List_addTail_CMockExpect(195, &outputList, &inst2);



 Institution_select( &inputList, &outputList,

      &instType, isUniversityCollege);

}



void test_wasEstablishBefore_2014_and_after_1950_should_return_0(){



 int year = 1970;



 Institution inst1 = {.yearEstablished = 1974};

 Institution inst2 = {.yearEstablished = 1989};

 Institution inst3 = {.yearEstablished = 1999};

 Institution inst4 = {.yearEstablished = 2012};



 wasEstablishBefore(&inst1, &year);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)211, UNITY_DISPLAY_STYLE_INT);



 wasEstablishBefore(&inst2, &year);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT);



 wasEstablishBefore(&inst3, &year);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);



 wasEstablishBefore(&inst4, &year);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);



}



void test_wasEstablishBefore_2014_and_after_1950_should_return_1(){



 int year = 1970;



 Institution inst1 = {.yearEstablished = 1964};

 Institution inst2 = {.yearEstablished = 1959};

 Institution inst3 = {.yearEstablished = 1969};

 Institution inst4 = {.yearEstablished = 1962};



 wasEstablishBefore(&inst1, &year);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);



 wasEstablishBefore(&inst2, &year);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);



 wasEstablishBefore(&inst3, &year);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);



 wasEstablishBefore(&inst4, &year);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishBefore(&inst1, &year))), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);



}



void test_wasEstablishBefore_should_throw_exception_error_after_2014(){



 int year = 1970;

 ExceptionError exception;



 Institution inst1 = {.yearEstablished = 2168};



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  wasEstablishBefore(&inst1, &year);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { exception = CExceptionFrames[MY_ID].Exception; exception=exception; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERROR_YEAR_ESTABLISHED)), (_U_SINT)((exception)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT);

 }



}
