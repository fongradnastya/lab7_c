#ifndef CONNECTS_H_INCLUDED
#define CONNECTS_H_INCLUDED

#include"structure.h"

/*!
* создаёт новый элемент списка Connection
* \param[in] order заказ для связи
* \param[in] product продукт для связи
* \return новая связь
*/
Connection* CreateConnect(Order* order, Product* product);

/*!
* Добавляет элемент связи в конец связного списка
* \param[in] connects список связей
* \param[in] new добавляемая связь
* \return новая связь
*/
Connection* PushBaskConnection(Connection* connects, Connection* new);

/*!
* Расширяет исходный список связей
* \param[in] list список связей
* \param[in] new добавляемая связь
* \return обновлённый список
*/
Connection* AddConnection(Connection* list, Connection* new);

/*!
* Запрашивает ввод данных и создаёт новую связь
* \param[in] products список всех продуктов
* \param[in] orders список всех заказов 
* \param[in] file поток, из которого считываем связи
* \return новый элемент списка связей
*/
Connection* ConnectInput(Product* products, Order* orders, FILE* file);

/*!
* Отищает все связи и освобождает память
* \param[in] prod список всех продуктов
* \param[in] order список всех заказов
* \param[in] connnects список всех связей 
*/
void DeleteAll(Product* prod, Order* order, Connection* connect);

#endif