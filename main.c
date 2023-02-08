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


enum ACTIONS
{
    add_prod = 1,
    add_order,
    print_pr,
    print_or,
    del_prod,
    del_order,
    connect,
    file_inp,
    file_outp,
    prods_in_ord,
    ords_with,
    c_exit = -1,
    c_menu = -2
}actions;

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
            DeleteAll(products, orders, connects);
            end = 1;
        }
        else if(command == add_prod)
        {
            Product* new_product = ProductInput(stdin);
            if(new_product)
                products = AddProduct(products, new_product);
        }
        else if(command == add_order)
        {
            Order* new_order = OrderInput(stdin);
            if(new_order){
                orders = AddOrder(orders, new_order);
            }
        }
        else if(command == del_prod) products = DeleteProduct(products);
        else if(command == del_order) orders = DeleteOrder(orders);
        else if(command == print_pr) PrintProducts(products, stdout);
        else if(command == print_or) PrintOrders(orders, stdout);
        else if(command == connect){
            Connection* new = ConnectInput(products, orders, stdin);
            PrintConnects(connects, stdout);
            if(new != NULL)connects = AddConnection(connects, new);
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
                PrintConnects(connects, stdout);
                if(new)connects = AddConnection(connects, new);
            }
            fclose(input);
        }
        else if(command == file_outp)SaveToTheFile(products, orders, connects);
        else if(command == prods_in_ord)ProdsInOrder(connects);
        else if(command == ords_with)OrdsWithProd(connects);
        else if(command == c_menu) PrintMenu();
        else printf("Wrong command.\n");
    }
    return 0;
}