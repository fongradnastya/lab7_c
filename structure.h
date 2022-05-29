#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct sProduct
{
    char* name;
    float price;
    float weight;
    struct sProduct* next;
}Product;

typedef struct sDate
{
    int day;
    int mounth;
    int year;
}Date;

typedef struct sOrder
{
    char* customer_name;
    int id;
    int deliv_period;
    Date order_date;
    struct sOrder* next;
}Order;

typedef struct sConnection
{
    Order* order;
    Product* product;
    struct sConnection* next;
}Connection;

#endif // STRUCTURE_H_INCLUDED