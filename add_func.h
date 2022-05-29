#ifndef ADD_FUNC_H_INCLUDED
#define ADD_FUNC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

Product* CreateProduct(char* name, float price, float weight);

Product* FindProduct(Product* products, char* prod_name);

Product* AddProduct(Product* list, Product* new_r);

Product* ProductInput(FILE* file);

Order* CreateOrder(char* customer, int deliv_period, Date date);

int CountId(Order* orders);

Order* AddOrder(Order* list, Order* new_r);

Order* FindOrder(Order* orders, int order_id);

Order* OrderInput(FILE* file);

#endif