#ifndef INPUT_PROC_H_INCLUDED
#define INPUT_PROC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

char* ConsoleInput(char* dev, FILE* file);

int GetInteger(int* val, FILE* file);

Date GetDate(char* str);

int FileInput();

#endif // INPUT_PROC_H_INCLUDED