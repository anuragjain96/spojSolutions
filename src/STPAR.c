#include <stdio.h>
#define MAX 1000

int top;
int elements[MAX];

void createEmptyStack()
{
    top = -1;
}

int isEmptyStack()
{
    if (top == -1)
        return 1;

    return 0;
}

int push(int val)
{
    top++;
    elements[top] = val;
}

int peek()
{
    if (isEmptyStack())
        return 0;
    else
        return elements[top];
}

int pop()
{
    if (isEmptyStack())
    {
        return 0;
    }
    else
    {
        int temp = elements[top];
        top--;
        return temp;
    }
}

int main()
{
    int totalCars = 0, i;
    int currReqCar = 1, currCar;

    createEmptyStack();

    scanf("%d", &totalCars);

    while (totalCars != 0)
    {
        int success = 1;
        currReqCar = 1;

        for (i = 0; i < totalCars; i++)
        {
            scanf("%d", &currCar);

            if (!success)
                continue;

            while (peek() == currReqCar)
            {
                currReqCar++;
                pop();
            }

            if (currCar == currReqCar)
            {
                currReqCar++;
            }
            else if (!isEmptyStack() && peek() < currCar)
            {
                success = 0;
                //break;
            }
            else
            {
                push(currCar);
            }
        }

        if (success == 1)
            printf("yes\n");
        else
            printf("no\n");

        createEmptyStack();

        scanf("%d", &totalCars);
    }

    return 0;
}
