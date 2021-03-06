#ifndef __INSTITUTION_H__
#define __INSTITUTION_H__

#include "LinkedList.h"
#include "Stack.h"

Stack stack;

typedef enum{
	ERROR_YEAR_ESTABLISHED
}ExceptionError;

typedef enum{
	Unknown, 
	University, 
	UniversityCollege, 
	College
}InstitutionType;

typedef struct Institution_t{
	char *name;
	char *address;
	unsigned long postcode;
	unsigned long int telephone;
	InstitutionType type;
	int yearEstablished;
}Institution;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList);
int isUniversityCollege(void *elem1, void *type);
int Institution_select(	LinkedList *inputList,
						LinkedList *outputList,
						void *criterion,
						int (*compare)(void *, void *));
int wasEstablishBefore(void *elem, void *year);

#endif  //__INSTITUTION_H__