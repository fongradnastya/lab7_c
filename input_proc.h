#ifndef INPUT_PROC_H_INCLUDED
#define INPUT_PROC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

/*!
* Динамически считывает строку из потока
* \param[in] dev разделитель, до которого считываем
* \param[in] file поток, из которого читаем
* \return считанная строка
*/
char* StringInput(char* dev, FILE* file);

/*!
* Считывает числовую команду из потока
* \param[in] val переменная для сохранения результата
* \param[in] file поток, из которого читаем
* \return 0, если не удалось считать, 1 - если корректно
*/
int GetInteger(int* val, FILE* file);

/*!
* Считывает дату из строки в соответствии с форматом
* \param[in] str строка для считывания
* \return структара, хранящая дату
*/
Date GetDate(char* str);

/*!
* Получает команду для считывания из файла
* \return команда (1-3)
*/
int FileInput();

#endif // INPUT_PROC_H_INCLUDED