#ifndef CONNECTS_H_INCLUDED
#define CONNECTS_H_INCLUDED

#include"structure.h"

int FindConnect(Connection* connects, Connection* new_c);

Connection* CreateConnect(Order* order, Product* product);

Connection* AddConnection(Connection* list, Connection* new);

Connection* ConnectInput(Product* products, Order* orders, FILE* file);

void PrintConnect(Connection* connect, FILE* file);

#endif