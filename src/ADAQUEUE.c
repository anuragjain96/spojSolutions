#include <stdio.h>
#include <malloc.h>
#include <string.h>

int mode = 0;

typedef struct node
{
    int info;
    struct node *prev, *next;
}node;

void createEmpty(node **head, node **tail)
{
    *head = *tail = NULL;
}

void insertAtBeg(node **head, node **tail, int val)
{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->info = val;

    if (*head == NULL)
    {
        ptr->next=ptr->prev=NULL;
        *head = *tail = ptr;
    }
    else
    {
        ptr->prev = NULL;
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
}

void insertAtEnd(node **head, node **tail, int val)
{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->info = val;

    if (*head == NULL)
    {
        ptr->next = ptr->prev = NULL;
        *head = *tail = ptr;
    }
    else
    {
        ptr->next = NULL;
        ptr->prev = *tail;
        (*tail)->next = ptr;
        *tail = ptr;
    }
}

void delFromBeg(node **head, node **tail)
{
    node *ptr;

    if (*head == NULL)
    {
        printf("No job for Ada?\n");
        return;
    }

    ptr = *head;

    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        (ptr->next)->prev = NULL;
        *head = ptr->next;
    }

    printf("%d\n", ptr->info);
    free(ptr);
}

void delFromEnd(node **head, node **tail)
{
    node *ptr;

    if (*head == NULL)
    {
        printf("No job for Ada?\n");
        return;
    }

    ptr = *tail;

    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        (ptr->prev)->next = NULL;
        *tail = ptr->prev;
    }

    printf("%d\n", ptr->info);
    free(ptr);
}

void insertFront(node **head, node **tail, int val)
{
    if (mode == 0)
    {
        insertAtEnd(head, tail, val);
    }
    else
    {
        insertAtBeg(head, tail, val);
    }
}

void insertBack(node **head, node **tail, int val)
{
    if (mode == 0)
    {
        insertAtBeg(head, tail, val);
    }
    else
    {
        insertAtEnd(head, tail, val);
    }
}

void deleteFront(node **head, node **tail)
{
    if (mode == 0)
    {
        delFromEnd(head, tail);
    }
    else
    {
        delFromBeg(head, tail);
    }
}

void deleteBack(node **head, node **tail)
{
    if (mode == 0)
    {
        delFromBeg(head, tail);
    }
    else
    {
        delFromEnd(head, tail);
    }
}

void reverseQ()
{
    mode = mode + 1;
    mode = mode % 2;
}


void printList(node *head)
{
    printf("LIST : ");

    while (head!=NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int totalQueries, val, i;
    char query[50];
    node *head, *tail;
    createEmpty(&head, &tail);

    scanf("%d", &totalQueries);

    for (i = 0; i < totalQueries; i++)
    {
        scanf("%s", query);
        //printList(head);

        if (strcmp(query, "back") == 0)
        {
            deleteBack(&head, &tail);
        }
        else if (strcmp(query, "front") == 0)
        {
            deleteFront(&head, &tail);
        }
        else if (strcmp(query, "reverse") == 0)
        {
            reverseQ();
        }
        else if (strcmp(query, "push_back") == 0)
        {
            scanf("%d", &val);
            insertBack(&head, &tail, val);
        }
        else if (strcmp(query, "toFront") == 0)
        {
            scanf("%d", &val);
            insertFront(&head, &tail, val);
        }
    }

    return 0;
}
