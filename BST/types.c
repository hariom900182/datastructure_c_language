
#ifndef PARSER_H // header guard
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
struct NodeB
{
    struct NodeB *left;
    int value;
    struct NodeB *right;
} *root = NULL;

struct Node
{
    struct NodeB *data;
    struct Node *next;
} *top = NULL;
#endif // PARSER_H