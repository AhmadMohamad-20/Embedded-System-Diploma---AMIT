#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "stdtypes.h"
#include "bitmath.h"

typedef struct node node_t;

struct node
{
    int num;
    node_t *next;
};

void Push(int num);
void Insert(int num,int position);
void Append(int num);
void Pop();
void Delete(int position);
void ReverseList();
node_t *ReverseListRecursive(node_t *node);
void PrintList();
void PrintReversed();
void PrintReversedRecursive(node_t *node);
#endif