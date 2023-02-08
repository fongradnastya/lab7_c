#ifndef OUTPUT_PROC_H_INCLUDED
#define OUTPUT_PROC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

/*!
* Печатает приветственное сообщение
*/
void PrintAnimeGirl();

/*!
* Выводит меню пользователя
*/
void PrintMenu();

/*!
* Печатает информацию о продукте
* \param[in] product продукт
* \param[in] file поток вывода
*/
void PrintProduct(Product* product, FILE* file);

/*!
* \param[in] order 
* \param[in] file
* \return 
*/
void PrintOrder(Order* order, FILE* file);

/*!
* Выводит список продуктов
* \param[in]
* \param[in]
*/
void PrintProducts(Product* products, FILE* file);

/*!
* Выводит список продуктов
* \param[in]
* \param[in]
*/
void PrintOrders(Order* orders, FILE* file);

/*!
* Выводит список продуктов
* \param[in]
*/
void ProdsInOrder(Connection* connect);

/*!
* Выводит список продуктов
* \param[in]
*/
void OrdsWithProd(Connection* connect);

/*!
* Выводит список продуктов
* \param[in]
*/
void PrintConnects(Connection* connect, FILE* file);

/*!
* Сохраняет 
* \param[in]
*/
void SaveToTheFile(Product* prods, Order* orders, Connection* connects);

#endif