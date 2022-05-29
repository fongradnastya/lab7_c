#ifndef OUTPUT_PROC_H_INCLUDED
#define OUTPUT_PROC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

void PrintAnimeGirl();

void PrintMenu();

void PrintProduct(Product* product, FILE* file);

void PrintOrder(Order* order, FILE* file);

void PrintProducts(Product* products, FILE* file);

void PrintOrders(Order* orders, FILE* file);

void ProdsInOrder(Connection* connect, FILE* file);

void OrdsWithProd(Connection* connect, FILE* file);

#endif