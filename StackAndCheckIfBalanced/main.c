#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "STD_TYPES.h"

#define MAX 20


struct stack
{
    char stk[MAX];
    int top;
}s;

void push(char item)
{
    if (s.top == (MAX - 1))
    {
        printf ("Stack is Full\n");
    }

    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = item;
    }
}

void pop()
{
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
    }
    else
    {
        s.top = s.top - 1;
    }
}

uint8_t * balancedParentheses(uint8_t * exp);


int main()
{
    s.top = -1;
    uint8_t exp[MAX];

    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);


    uint8_t * x= NULL;
    x= balancedParentheses(exp);
    printf("%s", x);

}



uint8_t * balancedParentheses(uint8_t * exp)
{
    static uint8_t NBAL[13] = "Not Balanced";
    static uint8_t BAL[9] = "Balanced";
    uint8_t i = 0;
    for(i = 0;exp[i] != '\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);

        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(exp[i] == ')')
            {
                if(s.stk[s.top] == '(')
                {
                    pop();
                }
                else
                {
                   return NBAL;

                }
            }
            if(exp[i] == ']')
            {
                if(s.stk[s.top] == '[')
                {
                    pop();
                }
                else
                {
                    return NBAL;

                }
            }
            if(exp[i] == '}')
            {
                if(s.stk[s.top] == '{')
                {
                    pop();
                }
                else
                {
                   return NBAL;

                }
            }
        }
    }
    if(s.top == -1)
    {
        return BAL;
    }
}





