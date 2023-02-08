#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"structure.h"

char* StringInput(char* dev, FILE* file)
{
    char chr;
    char* str = (char*) malloc(sizeof(char));
    int str_len = 1;
    int end = 0;
    //setbuf(file, NULL);
    while (!end)
    {
        chr = fgetc(file);
        if(chr == *dev || chr == '\n' || chr == EOF)
        {
            if(chr == '\n') *dev = '\n';
            end = 1;
            break;
        }
        if(!(str_len == 1 && chr == ' ')){
            str[str_len - 1] = chr;
            str_len++;
            str = (char*) realloc(str, str_len);
        }
    }
    str[str_len - 1] = '\0';
    return str;
}

int GetInteger(int* val, FILE* file)
{
    char dev = '\n';
    char* str = StringInput(&dev, file);
    for(int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]) && !(i == 0 && str[0] == '-')) return 0;
    }
    *val = atoi(str);
    return 1;
}

Date GetDate(char* str)
{
    int day;
    int mounth;
    int year;
    int res = sscanf(str, ", %d.%d.%d\n", &day, &mounth, &year);
    if(res == 3)
    {
        if(day < 32 && mounth < 13 && year > 1900 && day > 0 && mounth > 0)
        {
            Date date;
            date.day = day;
            date.mounth = mounth;
            date.year = year;
            return date;
        }
        else printf("Wrong data field values\n");
    }else printf("Unabel to get data. Frong format.\n");
}

int FileInput()
{
    int command = 0;
    printf("To prod input press 1\n");
    printf("To order input print 2\n");
    printf("To connection input press 3\n");
    while(command < 1 || command > 3)
        GetInteger(&command, stdin);
    return command;
}