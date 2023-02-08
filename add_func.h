#ifndef ADD_FUNC_H_INCLUDED
#define ADD_FUNC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

/*!
* Создаёт новый элемент продукта
* \param[in] name название продукта
* \param[in] prise цена продукта
* \param[in] weight вес продукта
* \return созданный продукт
*/
Product* CreateProduct(char* name, float price, float weight);

/*!
* Ищет продукт по его названию
* \param[in] products список всех продуктов
* \param[in] prod_name имя искомого продукта
* \return найденный продукт
*/
Product* FindProduct(Product* products, char* prod_name);

/*!
* Добавляет продукт в двусвязный список
* \param[in] list список продуктов
* \param[in] new_r новый продукт
*/
Product* AddProduct(Product* list, Product* new_r);

/*!
* Считывает данные о продукте и создаёт его
* \param[in] file поток ввода
* \return созданный продукт
*/
Product* ProductInput(FILE* file);

/*!
* Создаёт новый элемент заказа
* \param[in] customer имя заказчика
* \param[in] deliv_period время доставки
* \param[in] date дата заказа
* \return Новый заказ
*/
Order* CreateOrder(char* customer, int deliv_period, Date date);

/*!
* Вычисляет Id для нового заказа
* \param[in] orders список всех заказов
* \return вычесленное Id
*/
int CountId(Order* orders);

/*!
* Добавляет заказ в список
* \param[in] list список всех закозов
* \param[in] new_r добавляемый заказ
* \return список заказов
*/
Order* AddOrder(Order* list, Order* new_r);

/*!
* Ищет заказ в списке
* \param[in] orders список заказов
* \param[in] order_id номер искомого заказа
* \return найденный заказ
*/
Order* FindOrder(Order* orders, int order_id);

/*!
* Считывает данные о заказе и создаёт его
* \param[in] file поток ввода
* \return созданный заказ
*/
Order* OrderInput(FILE* file);

/*!
* Удаляет продукт с определённым именем
* \param products список всех продуктов
* \return удаляемый продукт
*/
Product* DeleteProduct(Product* products);

/*!
* Удаляет заказ по номеру
* \param[in] orders список всех заказов
* \return удаляемый заказ
*/
Order* DeleteOrder(Order* orders);
#endif