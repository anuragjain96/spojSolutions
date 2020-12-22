#include<stdio.h>

typedef struct stack
{
    char str[400]; // max length of the expr
    int top;       // the stack idx
}stack;


void create(stack *s)
{
    s->top=-1;     // init the stack idx
}

void convert(char *st, stack *s)
{
    int i,arr[400],j=-1,k;

    for (i=0;st[i]!=NULL;i++)
    {
        if (st[i]=='+' || st[i]=='-')
        {
            if (s->str[s->top]=='*' || s->str[s->top]=='/' || s->str[s->top]=='^' || s->str[s->top]=='-' || s->str[s->top]=='+')
            {
                printf("%c",s->str[s->top]);
                s->top--;
            }
            s->top++;
            s->str[s->top]=st[i];
        }
        else if (st[i]=='*' || st[i]=='/' || st[i]=='^')
        {
            if (s->str[s->top]=='*' || s->str[s->top]=='/' || s->str[s->top]=='^')
            {
                printf("%c",s->str[s->top]);
                s->top--;
            }
            s->top++;
            s->str[s->top]=st[i];
        }

        if (st[i]=='(' || st[i]=='{' || st[i]=='[')
        {
            s->top++;
            s->str[s->top]=st[i];
            arr[++j]=s->top;
        }

        else if (st[i]==')' || st[i]=='}' || st[i]==']')
        {
            for (k=s->top;k!=arr[j];k--)
            {
                printf("%c",s->str[k]);
                s->top--;
            }
            j--;
            s->top--;
        }
        else if ((st[i] >= 65 && st[i] <= 90) ||
                 (st[i] >= 97 && st[i] <= 122))
        {
            printf("%c",st[i]);
        }
    }
    if (s->top!=-1)
    {
        for (k=s->top;s->top!=-1;k--)
        {
            printf("%c",s->str[k]);
            s->top--;
        }
    }
}



int main()
{
    char st[400];
    int t = 0;
    stack s;
    scanf("%d",&t);
    create(&s);

    while (t != 0)
    {
        scanf("%s", &st);
        convert(st,&s);
        printf("\n");
        create(&s);
        t--;
    }

    return 0;
}
