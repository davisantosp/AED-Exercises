#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node *newNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->ID = value;
    node->prev = node->next = NULL;
    return node;
}

List *newList(Node *head)
{
    List *list = (List *)malloc(sizeof(List));
    list->head = list->tail = head;
    return list;
}

void insertBefore(Node *isInListAfter, Node *isNotInList)
{
    Node *isInListBefore = isInListAfter->prev;
    isInListAfter->prev = isNotInList;
    isNotInList->next = isInListAfter;
    if (isInListBefore != NULL)
    {
        isInListBefore->next = isNotInList;
        isNotInList->prev = isInListBefore;
    }
}

void insertAfter(Node *isInListBefore, Node *isNotInList)
{
    Node *isInListAfter = isInListBefore->next;
    isInListBefore->next = isNotInList;
    isNotInList->prev = isInListBefore;
    if (isInListAfter != NULL)
    {
        isInListAfter->prev = isNotInList;
        isNotInList->next = isInListAfter;
    }
}

int distanceFromHead(List *list, Node *node)
{
    Node *temp = list->head;
    int NEP = 0;
    while (temp != NULL)
    {
        if (temp->ID == node->ID)
        {
            break;
        }
        temp = temp->next;
        NEP++;
    }
    temp = NULL;
    free(temp);
    return NEP;
}

int distanceFromTail(List *list, Node *node)
{
    Node *temp = list->tail;
    int NEP = 0;
    while (temp != NULL)
    {
        if (temp->ID == node->ID)
        {
            break;
        }
        temp = temp->prev;
        NEP++;
    }
    temp = NULL;
    free(temp);
    return NEP;
}

void insertOnList(List *list, Node *node)
{
    // Se lista vazia, cria lista
    if (!list)
    {
        list = newList(node);
        return;
    }

    Node *fromHead = list->head;
    Node *fromTail = list->tail;

    // Verificação se não está no começo ou fim
    if (fromHead->ID > node->ID)
    {
        insertBefore(fromHead, node);
        list->head = node;
        return;
    }
    else if (fromTail->ID < node->ID)
    {
        insertAfter(fromTail, node);
        list->tail = node;
        return;
    }

    // Inserção no meio
    int NEPfromHead = 0;
    int NEPfromTail = 0;
    while (fromHead != NULL && fromTail != NULL)
    {
        if (fromHead->ID < node->ID)
        {
            fromHead = fromHead->next;
            NEPfromHead++;
        }
        else if (fromHead->ID > node->ID)
        {
            insertBefore(fromHead, node);
            return;
        }

        if (fromTail->ID > node->ID)
        {
            fromTail = fromTail->prev;
            NEPfromTail++;
        }
        else if (fromTail->ID > node->ID)
        {
            insertAfter(fromTail, node);
            return;
        }
    }
}

void printList(List *list)
{
    Node *temp = list->head;

    printf("\n");
    while (temp)
    {
        printf("%d ", temp->ID);
        temp = temp->next;
    }
}

void freeList(List *list)
{
    Node *temp = list->head;
    while (temp)
    {
        Node *prev = temp;
        temp = temp->next;
        temp->prev = NULL;
        free(prev);
    }
    free(list);
}
