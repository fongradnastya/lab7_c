#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"structure.h"
#include"output_proc.h"
#include"add_func.h"
#include"input_proc.h"
#include"connects.h"


void DeleteAll(Product* prod, Order* order)
{
    while (prod)
    {
        Product* tmp = prod;
        prod = prod->next;
        free(tmp);
    }
    while (order)
    {
        Order* tmp = order;
        order = order->next;
        free(tmp);
    }
}

Product* DeleteProduct(Product* products)
{
    if(!products) {
        printf("Nothing to delete.\n");
        return NULL;
    }
    int number;
    printf("Please, enter product's name: ");
    char dev = '\n';
    char* del_str = ConsoleInput(&dev, stdin);
    if(del_str[0] == '\0') printf("Your input is incorrect.\n");
    Product* del = FindProduct(products, del_str);
    Product* first = products;
    if (del)
    {
        if (del == first)
        {
            first = first->next;
            del->next = NULL;
            return first;
        }
        Product* tmp = first;
        while (tmp->next != NULL)
        {
            if (tmp->next == del)
            {
                break;
            }
            tmp = tmp->next;
        }
        tmp->next = del->next;
        del->next = NULL;
        products = first;
    }
    else printf("No maching products.\n");
    return products;
}

Order* DeleteOrder(Order* orders)
{
    if(!orders) {
        printf("Nothing to delete.\n");
        return NULL;
    }
    if(!orders) return NULL;
    int number;
    printf("Please, enter order's id: ");
    int del_id = 0;
    int res = GetInteger(&del_id, stdin);
    Order* del = FindOrder(orders, del_id);
    Order* first = orders;
    if (del)
    {
        if (del == first)
        {
            first = first->next;
            del->next = NULL;
            return first;
        }
        Order* tmp = first;
        while (tmp->next != NULL)
        {
            if (tmp->next == del)
            {
                break;
            }
            tmp = tmp->next;
        }
        tmp->next = del->next;
        del->next = NULL;
        orders = first;
    }
    else printf("No maching orders.\n");
    return orders;
}

enum ACTIONS
{
    add_prod = 1,
    add_order = 2,
    print_pr = 3,
    print_or = 4,
    del_prod = 5,
    del_order = 6,
    connect = 7,
    file_inp = 8,
    file_outp = 9,
    c_exit = -1,
    c_menu = -2
}actions;

FILE* ChoiseInput()
{
    printf("To console input print 1.\n");
    printf("To file input print 2.\n");
    int input_mode = 0;
    while(input_mode != 1 && input_mode != 2)
    {
        GetInteger(&input_mode, stdin);
    }
    if(input_mode == 2)
    {
        FILE* input = fopen("input.txt", "r");
        if(!input) printf("Error opening file\n");
        return input;
    }
    return stdin;
}


int main()
{
    system("chcp 1251");
    Product* products = NULL;
    Order* orders = NULL;
    Connection* connects = NULL;
    PrintAnimeGirl();
    PrintMenu();
    int end = 0;
    while(!end)
    {
        int command = 0;
        printf("Your command: ");
        int res = GetInteger(&command, stdin);
        if(command == c_exit)
        {
            DeleteAll(products, orders);
            end = 1;
        }
        else if(command == add_prod)
        {
            Product* new_product = ProductInput(stdin);
            if(new_product->name)
                products = AddProduct(products, new_product);
        }
        else if(command == add_order)
        {
            Order* new_order = OrderInput(stdin);
            if(new_order->customer_name){
                orders = AddOrder(orders, new_order);
            }
        }
        else if(command == del_prod) products = DeleteProduct(products);
        else if(command == del_order) orders = DeleteOrder(orders);
        else if(command == print_pr) PrintProducts(products, stdout);
        else if(command == print_or) PrintOrders(orders, stdout);
        else if(command == connect){
            Connection* new = ConnectInput(products, orders, stdin);
            PrintConnect(connects, stdout);
            if(new)connects = AddConnection(connects, new);
        }
        else if(command == file_inp){
            FILE* input = fopen("input.txt", "r");
            if(!input) {
                printf("Error opening file\n");
                break;
            }
            enum INPUT{prod = 1, order = 2, connect = 3}cmd;
            int loc_cmd = FileInput();
            if(loc_cmd == prod)
            {
                Product* new_product = ProductInput(input);
                if(new_product)
                    products = AddProduct(products, new_product);
            }
            else if(loc_cmd == order)
            {
                Order* new_order = OrderInput(input);
                if(new_order){
                    orders = AddOrder(orders, new_order);
                }
            }
            else
            {
                Connection* new = ConnectInput(products, orders, input);
                PrintConnect(connects, stdout);
                if(new)connects = AddConnection(connects, new);
            }
            fclose(input);
        }
        else if(command == c_menu) PrintMenu();
        else printf("Wrong command.\n");
    }
    return 0;
}