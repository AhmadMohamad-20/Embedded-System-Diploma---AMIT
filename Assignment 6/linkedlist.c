#include "linkedlist.h"

node_t *head = NULL;
node_t *temp = NULL;
void Push(int num)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->num = num;
        node->next = head;
        head = node;
    }
    else
    {
    }
}

void Insert(int num, int position)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->num = num;
        if (position == 1)
        {
            node->next = head;
            head = node;
        }
        else
        {
            node_t *traverse = head;
            int counter = 1;
            while (counter < (position - 1))
            {
                traverse = traverse->next;
                counter++;
            }
            node->next = traverse->next;
            traverse->next = node;
        }
    }
    else
    {
    }
}

void Append(int num)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->num = num;
        node_t *traverse = head;
        if (head != NULL)
        {
            while (traverse->next != NULL)
            {
                traverse = traverse->next;
            }
            node->next = NULL;
            traverse->next = node;
        }
        else
        {
            node->next = NULL;
            head = node;
        }
    }
    else
    {
        node->next = head;
        head = node;
    }
}

void Pop()
{
    if (head != NULL)
    {
        node_t *temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
    }
}

void Delete(int position)
{
    node_t *traverse = head;
    node_t *temp = NULL;
    uint8 counter = 0;

    while (traverse != NULL)
    {
        counter++;
        traverse = traverse->next;
    }

    if (counter >= position)
    {
        traverse = head;
        if (head != NULL)
        {
            if (position == 1)
            {
                head = traverse->next;
                traverse->next = NULL;
                free(traverse);
            }
            else
            {
                int counter = 1;
                while (counter < (position - 1))
                {
                    traverse = traverse->next;
                    counter++;
                }
                temp = traverse->next;
                traverse->next = (traverse->next)->next;
                free(temp);
            }
        }
        else
        {
        }
    }
    else
    {
    }
}

void ReverseList()
{
    node_t *prev = NULL;
    node_t *current = head;
    node_t *next = NULL;
    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

node_t *ReverseListRecursive(node_t *node)
{
    if (node == NULL)
        return NULL; // List does not exist.
    if (node->next == NULL)
        return node; // List with only one node.

    node_t *rest = ReverseListRecursive(node->next); // Recursive call on rest.
    node->next->next = node;                         // Make first's link point to the last node in the reversed rest.
    node->next = NULL;                               // Since first is the new last, make its link NULL.
    return rest;                                     // Rest now points to the head of the reversed list.
}

void PrintList()
{
    node_t *traverse = head;
    while (traverse != NULL)
    {
        printf("%d ", traverse->num);
        traverse = traverse->next;
    }
}

void PrintReversed()
{
    ReverseList();
    PrintList();
    ReverseList();
}

void PrintReversedRecursive(node_t *node)
{
    if (head != NULL)
    {
        if (node == NULL)
        {
            node = head;
        }
        if (node->next != NULL)
            PrintReversedRecursive(node->next);
        printf("%d ", node->num);
    }
    else
    {
    }
}
