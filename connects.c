#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"structure.h"
#include"output_proc.h"
#include"add_func.h"
#include"input_proc.h"


int FindConnect(Connection* connects, Connection* new)
{
    while(connects != NULL)
    {
        printf("%s, %s\n", connects->product->name, new->product->name);
        if(!strcmp(connects->product->name, new->product->name))
        {
            if(connects->order->id == new->order->id)
                return 1;
        }  
        connects = connects->next;
    }
    return 0;
}

Connection* CreateConnect(Order* order, Product* product)
{

    Connection* new_connect = (Connection*)malloc(sizeof(Connection));
    new_connect->order = order;
    new_connect->product = product;
    new_connect->next = NULL;
    //PrintConnect(new_connect, stdout);
    return new_connect;
}

Connection* PushBaskConnection(Connection* connects, Connection* new)
{
    if (connects == NULL)return NULL;
    while (connects->next != NULL)
        connects = connects->next;
    new->next = connects->next;
    connects->next = new;
    return new;
}

Connection* AddConnection(Connection* list, Connection* new)
{
    if(list == NULL){
        printf("New\n");
        return new;
    }
    else{
        PushBaskConnection(list, new);
        return list;
    }
}

Connection* ConnectInput(Product* products, Order* orders, FILE* file)
{
    printf("Please, enter order's id: ");
    int order_id;
    int res = fscanf(file, "%d, ", &order_id);
    if(res)
    {
        Order* order = FindOrder(orders, order_id);
        if(!order){
            printf("There are no matching orders\n");
            char end = '\n';
            ConsoleInput(&end, file);
            return NULL;
        }
        char end;
        printf("Order: %d, ", order_id);
        char* prod;
        end = '\n';
        prod = ConsoleInput(&end, file);
        Product* product = FindProduct(products, prod);
        if(product) {
            PrintOrder(order, stdout);
            PrintProduct(product, stdout);
            Connection* new = CreateConnect(order, product);
            return new;
        }
        else{
            printf("There are no matching products\n");
        }
        return NULL;
        printf("\n");
    }
}