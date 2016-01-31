// MemCpy_Example.cpp : Defines the entry point for the console application.
//

/* memcpy example */
#include <stdio.h>
#include <string.h>
#include <iostream>

struct {
	 char name[40];
	 int age;
} person, person_copy;

int main()
{
	 char myname[] = "Pierre de Fermat";

	 /* using memcpy to copy string: */
	 memcpy(person.name, myname, strlen(myname) + 1);
	 person.age = 46;

	 /* using memcpy to copy structure: */
	 memcpy(&person_copy, &person, sizeof(person));

	 printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	 std::cin.get();

	 return 0;
}

