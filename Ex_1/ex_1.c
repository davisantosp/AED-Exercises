#include <stdio.h>

#include "list.h"

int main()
{
    int N;
    scanf("%d", &N);

    List *list = NULL;
    int ID;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &ID);
        Node *node = newNode(ID);
        if (!list)
            list = newList(node);

        insertOnList(list, node);
    }
    printList(list);
    freeList(list);
    return 0;
}
