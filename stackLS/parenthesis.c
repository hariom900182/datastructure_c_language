#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"

int matchPenth(char str[])
{
    int i, x;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            x = pop();
            if (x == -1)
                break;
        }
    }
    if (count() > 0 || x < 0)
        return -1;
    return 0;
}

void main()
{
    int flag;
    char str[] = "((a+b)*(c-d)))";
    flag = matchPenth(str);
    if (flag < 0)
    {
        printf("Parenthesis does not match\n");
    }
    else
    {
        printf("valid expression\n");
    }
}