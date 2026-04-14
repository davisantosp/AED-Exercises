// Davi dos Santos Pinto RA 185623 AED2 - Noturno
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int ID;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List
{
    struct Node *head;
    struct Node *tail;
} List;

Node *newNode(int value);
List *newList(Node *head);
void insertBefore(Node *isInListAfter, Node *isNotInList);
void insertAfter(Node *isInListBefore, Node *isNotInList);
void insertOnList(List *list, Node *node, int *NEP);
void freeList(List *list);
void printList(List *list);

int main()
{
    int N;
    scanf("%d", &N);

    List *list = newList(NULL);
    int ID, NEP = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &ID);
        Node *node = newNode(ID);
        insertOnList(list, node, &NEP);
    }
    printList(list);
    printf("\n%d", NEP);
    freeList(list);
    return 0;
}

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

int listExist(List *list)
{
    return list->head != NULL;
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

void insertOnList(List *list, Node *node, int *NEP)
{
    // Se lista vazia, cria lista
    if (!listExist(list))
    {
        list->head = list->tail = node;
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

    // Inserção no meio verificando a partir do Tail ou do Head
    int distanceFromHead = abs(node->ID - list->head->ID);
    int distanceFromTail = abs(node->ID - list->tail->ID);
    if (distanceFromHead <= distanceFromTail)
    {
        Node *temp = fromHead;
        while (temp != NULL && temp->ID < node->ID)
        {
            temp = temp->next;
            (*NEP)++;
        }
        insertBefore(temp, node);
    }
    else
    {
        Node *temp = fromTail;
        while (temp != NULL && temp->ID > node->ID)
        {
            temp = temp->prev;
            (*NEP)++;
        }
        insertAfter(temp, node);
    }
}

void printList(List *list)
{
    if (!listExist(list))
        return;
    Node *temp = list->head;

    while (temp)
    {
        printf("%d ", temp->ID);
        temp = temp->next;
    }
}

void freeList(List *list)
{
    if (!listExist(list))
        return;
    Node *temp = list->head;
    while (temp)
    {
        Node *prev = temp;
        temp = temp->next;
        free(prev);
    }
    free(list);
}