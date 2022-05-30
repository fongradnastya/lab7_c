#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include"input_proc.h"

Product* CreateProduct(char* name, float price, float weight)
{
    Product* new_product = (Product*)malloc(sizeof(Product));
    new_product->name = name;
    new_product->price = price;
    new_product->weight = weight;
    new_product->next = NULL;
    return new_product;
}

Product* FindProduct(Product* products, char* prod_name)
{
    while(products != NULL)
    {
        printf("%s, %s\n", products->name, prod_name);
        if(!strcmp(products->name, prod_name)){
            Product* finded = products;
            return finded;
        }
        products = products->next;
    }
    return NULL;
}

Order* FindOrder(Order* orders, int order_id)
{
    while(orders != NULL)
    {
        printf("id%d", orders->id);
        if(orders->id == order_id) {
            Order* finded = orders;
            return finded;
        }
        orders = orders->next;
    }
    return NULL;
}

Product* AddProduct(Product* list, Product* new_r)
{
    if(!list) return new_r;
    Product* finded = FindProduct(list, new_r->name);
    if(finded)
    {
        printf("Product with this name is already exist.\n");
        return list;
    }
    Product* last = list;
    while (last->next != NULL)
        last = last->next;
    new_r->next = last->next;
    last->next = new_r;
    return list;
}

Product* ProductInput(FILE* file)
{
    char* prod_name = NULL;
    printf("Enter product data according to the format: ");
    printf("NAME, PRISE(rub), WEIGHT(kg)\n");
    printf("For example: Table, 125.0, 1.75\n");
    char dev = ',';
    prod_name = ConsoleInput(&dev, file);
    dev = '\n';
    char* input_str = ConsoleInput(&dev, file);
    float prise;
    float weight;
    int res = sscanf(input_str, "%f, %f", &prise, &weight);
    if(res < 2 || prod_name[0] == '\0') {
        printf("Wrong input format.\n");
        return NULL;
    }
    else {
        printf("Correct\n");
        Product* product = CreateProduct(prod_name, prise, weight);
        //PrintProduct(product, stdout);
        return product;
    }
}

Order* CreateOrder(char* customer, int deliv_period, Date date)
{
    Order* new_order = (Order*)malloc(sizeof(Order));
    new_order->customer_name = customer;
    new_order->id = 0;
    new_order->deliv_period = deliv_period;
    new_order->order_date = date;
    new_order->next = NULL;
    return new_order;
}

int CountId(Order* orders)
{
    int max = 0;
    while(orders->next != NULL)
    {
        if(orders->id > max) max = orders->id;
        orders = orders->next;
    }
    return max + 1;
}

Order* AddOrder(Order* list, Order* new_r)
{
    if(!list)
    {
        new_r->id = 1;
        return new_r;
    }
    Order* last = list;
    while (last->next != NULL) last = last->next;
    new_r->next = last->next;
    last->next = new_r;
    int id = CountId(list);
    printf("%d", id); 
    new_r->id = id;
    return list;
}

Order* OrderInput(FILE* file)
{
    char* customer = NULL;
    printf("Enter order data according to the format: ");
    printf("CUSTOMER_NAME, DELIV_PERIOD, ORDER_DATE(dd.mm.yyyy)\n");
    printf("For example: Matvey Nomow, 12, 14.05.2022\n");
    char dev = ',';
    customer = ConsoleInput(&dev, file);
    int del_period = 0;
    fscanf(file, " %d", &del_period);
    dev = '\n';
    char* date_str = ConsoleInput(&dev, file);
    printf("%s", date_str);
    Date date = GetDate(date_str);
    if(!del_period) return NULL;
    if(customer[0] != '\0' && date.day && del_period > 0)
    {
        Order* order = CreateOrder(customer, del_period, date);
        //PrintOrder(order, stdout);
        return order;
    }
    return NULL;    
}