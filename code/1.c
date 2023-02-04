#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h> 
#include<math.h>
#define MAX_EXPR_SIZE 100
#define BLANK ' '
#define TAB '\t'
#define MAX 50
long int pop();
char infx[MAX],prefix[MAX];
long int stack[MAX];
int top;
int isempty();
int white_space(char symbol);
void infix_to_prefix();
int priority(char symbol);
void push(long int symbol);
void infix_to_prefix()
{
    int i,j,p,n;
    char next ;
    char symbol;
    char temp;
    n=strlen(infx);
    p=0;
    for(i=n-1; i>=0; i--)
    {
        symbol=infx[i]; 
        if(!white_space(symbol)) 
        {
            switch(symbol)
            {
                case ')':
                    push(symbol);
                    break;
                case '(':
                    while( (next=pop()) != ')')
                        prefix[p++] = next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while( !isempty( ) && priority(stack[top])> priority(symbol) )
                        prefix[p++] = pop();
                    push(symbol);
                    break;
                default:
                    prefix[p++] = symbol;
            }
        }
    }
    while(!isempty( ))
        prefix[p++] = pop();
    prefix[p] = '\0';
    for(i=0,j=p-1;i<j;i++,j--)
    {
        temp=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=temp;
    }
}
int priority(char symbol)
{
    switch(symbol) {
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
        case '$':
            return 3;
        default :
            return 0;
    }
}
void push(long int symbol)
{
    if(top > MAX)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    else
    {
        top=top+1;
        stack[top] = symbol;
    }
}
long int pop()
{
    if(top == -1 )
    {
        printf("Stack underflow \n");
        exit(2);
    }
    return (stack[top--]);
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int white_space(char symbol)
{
    if(symbol==BLANK || symbol==TAB || symbol=='\0')
        return 1;
    else
        return 0;
}
int precedence(char operator)
{
    switch (operator)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return -1;
    }
}
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '$');
}
char *infixToPostfix(char *infix)
{
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;
    for (i = 0, j = 0;i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            stack[++top] = infix[i];
        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }
        else if (isOperator(infix[i])) 
        {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
    while (top > -1) 
        postfix[j++] = stack[top--]; 
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    long int value;
    top = -1;
    char infix[MAX_EXPR_SIZE]; printf("Enter an infix expression: ");
    gets(infix);
    char *postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix); 
    free(postfix);
    printf("Enter infix : "); 
    gets(infx);
    infix_to_prefix();
    printf("prefix : %s\n",prefix);
    return 0;
}