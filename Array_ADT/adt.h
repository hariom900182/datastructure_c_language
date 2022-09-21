#ifndef ADT_H

#define ADT_H

struct Array
{
    int *arr;
    int size;
    int length;
};
void initArray(int length);
void append(int value);
void display();
void insertElementAt(int index, int value);
int deleteElementFrom(int index);
int linearSearch(int key)
{
}
#endif