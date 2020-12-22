#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node 
{
    int info;
    struct node *next;
}stack;

void createEmptyStack(stack **ps)
{
    *ps = NULL;
}

int isEmptyStack(stack *ps)
{
    if (ps == NULL)
        return 1;

    return 0;
}

int push(stack **top, int val)
{
    stack *ptr;
    ptr = (stack*) malloc(sizeof(stack));

    if (ptr == NULL)
    {
        printf("Unable to allocate mem \n");
        return 0;
    }
    else
    {
        ptr->info = val;
        ptr->next = *top;
        *top = ptr;
        return 1;
    }
}

int pop(stack **top)
{
    if (isEmptyStack(*top))
    {
        printf("EMPTY\n");
        return 0;
    }
    else
    {
        int temp = (*top)->info;
        stack *ptr = *top;
        *top = (*top)->next;
        free(ptr);
        return temp;
    }
}

int main()
{
    int totalQuery = 0;
    stack *s;
    int i, num, min = 0;
    char query[10];

    scanf("%d", &totalQuery);
    createEmptyStack(&s);
    fflush(stdin);

    for (i = 1; i <= totalQuery; i++)
    {
        scanf("%s", query);

        if (query[1] == 'U') // *PUSH query
        {
            scanf("%d",&num);

            if (isEmptyStack(s))
            {
                min = num;
                push(&s, num);
            }
            else if (num < min)
            {
                push(&s, num - min);
                min = num;
            }   
            else
                push(&s, num);
        }
        else if (query[1] == 'O') // POP query
        {
            num = pop(&s);
            if (num < 0)
                min -= num;

            if (isEmptyStack(s))
                min = 0;
        }
        else if (query[1] == 'I') // MIN query
        {
            if (isEmptyStack(s))
                printf("EMPTY\n");
            else
                printf("%d\n", min);
        }
    }

    return 0;

}
