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
    printf("3 to print products\n");
    printf("4 to print orders\n");
    printf("5 to delete a product\n");
    printf("6 to delete an order\n");
    printf("7 to add a product to the order\n");
    printf("8 to file input\n");
    printf("9 to load information into the file\n");
    printf("10 to print products in the order\n");
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
    fprintf(file, "---------------------------PRODUCTS---------------------------\n");
    if (orders == NULL)
    {
        fprintf(file, "There are no product.\n");
    }
    while(orders != NULL)
    {
        PrintProduct(orders, file);
        orders = orders->next;
    }
    fprintf(file, "--------------------------------------------------------------\n");
}

void PrintOrders(Order* orders, FILE* file)
{
    fprintf(file, "--------------------------ORDERS---------------------------\n");
    if (orders == NULL)
    {
        fprintf(file, "There are no order.\n");
    }
    while(orders != NULL)
    {
        PrintOrder(orders, file);
        orders = orders->next;
    }
    fprintf(file, "-----------------------------------------------------------\n");
}

void ProdsInOrder(Connection* connect)
{
    printf("Please, enter order's id: ");
    int order_id;
    int res = scanf("%d", &order_id);
    setbuf(stdin, NULL);
    int is_exist = 0;
    if(!connect) {
        printf("No connects.\n");
        return NULL;
    }
    else printf("----------------Connects---------------\n");
    while(connect != NULL)
    {
        if(connect->order->id == order_id){
            is_exist = 1;
            printf("Order #%d: ", connect->order->id);
            printf("%s\n", connect->product->name);
        }
        connect = connect->next;
    }
    printf("\n"); 
    if(!is_exist)printf("No maching orders\n");
    printf("---------------------------------------\n");
}

void OrdsWithProd(Connection* connect)
{
    printf("Please, enter product's name: ");
    char end = '\n';
    char* name = ConsoleInput(&end, stdin);
    setbuf(stdin, NULL);
    int is_exist = 0;
    if(!connect) {
        printf("No connects.\n");
        return NULL;
    }
    else printf("----------------Connects---------------\n");
    while(connect != NULL)
    {
        if(!strcmp(connect->product->name, name)){
            is_exist = 1;
            printf("Product %s: ", connect->product->name);
            printf("#%d\n", connect->order->id);
        }
        connect = connect->next;
    }
    printf("\n"); 
    if(!is_exist)printf("No maching products\n");
    printf("---------------------------------------\n");
}

void PrintConnects(Connection* connect, FILE* file)
{
    if(!connect)fprintf(file, "There are no connects.\n");
    while(connect != NULL){
        int od_id = connect->order->id;
        char* str = connect->product->name;
        fprintf(file, "Connection: Order #%d - %s\n", od_id, str);
        connect = connect->next;
    }
}


void SaveToTheFile(Product* prods, Order* orders, Connection* connects){
    FILE* output = fopen("output.txt", "wt");
    if(output){
        PrintProducts(prods, output);
        PrintOrders(orders, output);
        PrintConnects(connects, output);
    }
    fclose(output);
}