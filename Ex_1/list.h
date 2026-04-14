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
int distanceFromHead(List *list, Node *node);
int distanceFromTail(List *list, Node *node);
void insertOnList(List *list, Node *node);
void freeList(List *list);
void printList(List *list);
