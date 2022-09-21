#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"

int outStackPriority(char sym)
{
    if (sym == '+' || sym == '-')
        return 1;
    if (sym == '*' || sym == '/')
        return 3;
    if (sym == '^')
        return 6;
    if (sym == '(')
        return 7;
    if (sym == ')')
        return 0;
    return 0;
}

int inStackPriority(char sym)
{
    if (sym == '+' || sym == '-')
        return 2;
    if (sym == '*' || sym == '/')
        return 4;
    if (sym == '^')
        return 5;
    if (sym == '(')
        return 0;
    if (sym == ')')
        return 7;
    return 0;
}
int isOperand(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    else if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
char *inFixToPostFix(char exp[])
{
    char *postfix;
    int i, index;
    index = 0;
    i = 0;
    postfix = (char *)malloc(strlen(exp) * sizeof(char));
    // for (i = 0; i < strlen(exp); i++)
    while (i < strlen(exp))
    {

        if (isOperand(exp[i]))
        {
            postfix[index++] = exp[i++];
        }
        else if (top == NULL)
        {
            push(exp[i++]);
        }
        else if (inStackPriority(top->data) > outStackPriority(exp[i]))
        {
            postfix[index++] = pop();
        }
        else if (inStackPriority(top->data) < outStackPriority(exp[i]))
        {
            push(exp[i++]);
        }
        else
        {
            pop();
            i++;
        }
        // printf("\n instack %c=%d and outstack %c=%d\n", top->data, inStackPriority(top->data), exp[i], outStackPriority(exp[i]));
    }
    while (top != NULL)
    {
        postfix[index++] = pop();
    }
    return postfix;
}

int evaluate(char exp[])
{
    int x1, x2;
    int i;
    for (i = 0; i < strlen(exp); i++)
    {
        if (isOperand(exp[i]))
        {
            push((exp[i] - '0'));
        }
        else
        {
            x1 = pop();
            x2 = pop();
            if (exp[i] == '+')
                push(x2 + x1);
            else if (exp[i] == '-')
            {

                push(x2 - x1);
            }
            else if (exp[i] == '*')
            {

                push(x2 * x1);
            }
            else if (exp[i] == '/')
            {

                push(x2 / x1);
            }
        }
    }
    return pop();
}

void main()
{
    char in[] = "35*62/+4-";
    // char *post;
    // int i;
    // post = inFixToPostFix(in);
    // printf("\n");
    // for (i = 0; i < strlen(post); i++)
    // {
    //     printf("%c", post[i]);
    // }

    printf("\n result = %d\n", evaluate(in));
}