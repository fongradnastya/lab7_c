#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include"add_func.h"
#include"input_proc.h"

void PrintAnimeGirl()
{
    printf("MMMMSSSSSSSSSSSSSSSSSMSS;.     .dMMMMSSSSSSMMSSSSSSSSS\n");
    printf("MMSSSSSSSMSSSSSMSSSSMMMSS.'-.-':MMMMMSSSSMMMMSSMSSSMMS\n");
    printf("MSSSSSSSMSSSSMMMSSMMMPTMM;'-/|':MMM^'     MMMSSMMMSSMM\n");
    printf("SSSSSSSMMSSMMMMMMMMMP-.MMM :  ;.;P       dMMMMMMMMMP'\n");
    printf("SSMSSSMMMSMMMMMMMMMP   :M;`:  ;.'+'''t+dMMMMMMMMMMP\n");
    printf("MMMSSMMMMMMMMPTMMMM"""":P `.|// '    ""^^MMMMMMMP'\n");
    printf("MMMMMMPTMMMMP='TMMMsg,      |/   db`c'  dMMMMMP'\n");
    printf("MMMMMM  TMMM   d$$$b ^          /T$; ;-/TMMMP         |||   |||   |||   |||\n");
    printf("MMMMM; .^`M; d$P^T$$b          :  $$ ::  'T(          |||   |||   |||   |||\n");
    printf("MMMMMM   .-+d$$   $$$;         ; d$$ ;;  __           |||||||||   |||   |||\n");
    printf("MMMMMMb   _d$$$   $$$$         :$$$; :MmMMMMp.        |||   |||   |||\n");
    printf("MMMMMM'  ' T$$$._.$$$;          T$P.'MMMSSSSSSb.      |||   |||   |||   |||\n");
    printf("MMM`TMb   -')T$$$$$$P'       `._ ''  :MMSSSMMP'\n");
    printf("MMM / |    '  'T$$P'           /     :MMMMMMM\n");
    printf("MMSb`. ;                      '      :MMMMMMM|\n");
    printf("MMSSb_lSSSb.      | `.   .___.       MMMMMMMM\n");
    printf("MMMMSSSSSSSSb.                     .MMMMMMMMM\n");
    printf("MMMMMMMMMMMSSSb                  .dMMMMMMMMM'\n");
    printf("MMMMMMMMMMMMMSS;               .dMMMMMMMMMMP\n");
    printf("MMMMMMMMMMMMMSS;               .dMMMMMMMMMMP\n");
    printf("MMMMMMMMMMMMMMb    ''--.___.dMMMMMMMMMP^'\n");
    printf("\n");
}

void PrintMenu()
{
    printf("        ------MENU------\n");
    printf("1 to add new product\n");
    printf("2 to add new order\n");
    printf("3 to delete a product\n");
    printf("4 to delete an order\n");
    printf("5 to add a product to the order\n");
    //printf("6 to find the room with the number\n");
    //printf("7 to write product to the file\n");
    //printf("8 to invert a list\n");
    //printf("9 to find quantity of product\n");
    printf("-1 to exit\n");
    printf("-2 to print the menu\n");
    printf("        ----------------\n");
}

void PrintProduct(Product* product, FILE* file)
{
    fprintf(file, "%s, ", product->name);
    fprintf(file, "prise: %.2f rub, ", product->price);
    fprintf(file, "weight: %.2f kg\n", product->weight);
}

void PrintOrder(Order* order, FILE* file)
{
    fprintf(file, "id: #%d, ", order->id);
    fprintf(file, "customer: %s, ", order->customer_name);
    Date date = order->order_date;
    fprintf(file, "order date: %d.%d.%d\n", date.day, date.mounth, date.year);
    fprintf(file, "(will be delivered in %d days)\n", order->deliv_period);
}

void PrintProducts(Product* orders, FILE* file)
{
    printf("---------------------------PRODUCTS---------------------------\n");
    if (orders == NULL)
    {
        fprintf(file, "There are no product.\n");
    }
    while(orders != NULL)
    {
        PrintProduct(orders, file);
        orders = orders->next;
    }
    printf("--------------------------------------------------------------\n");
}

void PrintOrders(Order* orders, FILE* file)
{
    printf("--------------------------ORDERS---------------------------\n");
    if (orders == NULL)
    {
        fprintf(file, "There are no order.\n");
    }
    while(orders != NULL)
    {
        PrintOrder(orders, file);
        orders = orders->next;
    }
    printf("-----------------------------------------------------------\n");
}

void ProdsInOrder(Connection* connect, FILE* file)
{
    printf("Please, enter order's id: ");
    int order_id;
    int res = scanf("%d", &order_id);
    if(res)
    {
        Order* order = FindOrder(connect->order, order_id);
        if(order) {
            fprintf(file, "Order: #%d", order->id);
            while(connect != NULL)
            {
                if(connect->order->id == order_id){
                    fprintf(file, ", %s", connect->product->name);
                }
            }
            fprintf(file, "\n"); 
        }
    }
}

void OrdsWithProd(Connection* connect, FILE* file)
{
    printf("Please, enter product's name: ");
    char end = '\n';
    char* name = ConsoleInput(&end, stdin);
    Product* product = FindProduct(connect->product, name);
    if(product){
        fprintf(file, "Product %s:", product->name);
        while(connect != NULL)
        {
            if(!strcmp(connect->product->name, name)){
                fprintf(file, ", %d", connect->order->id);
            }
        }
        fprintf(file, "\n"); 
    }
}