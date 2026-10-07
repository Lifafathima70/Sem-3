#include<iostream>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

#define max 100

int stack[max];
char postfix[max];
int top = -1;

int evaluationofpost();
void push(int);
int pop();
int empty();

int main()
{
    int i;

    cout<<"enter the postfix expression"<<endl;
    gets(postfix);

    cout<<"postfix expression"<<endl;
    puts(postfix);

    int result = evaluationofpost();

    cout<<"result\t"<<result;

    getch();
    return 0;
}

void push(int t)
{
    if(top == max-1)
    {
        cout<<"overflow";
        return;
    }

    top++;
    stack[top] = t;
}

int pop()
{
    int t;

    if(top == -1)
    {
        cout<<"underflow";
        exit(0);
    }

    t = stack[top];
    top--;

    return t;
}

int empty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int evaluationofpost()
{
    int i;
    int a, b;

    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();

            switch(postfix[i])
            {
                case '+': push(b+a); break;
                case '-': push(b-a); break;
                case '*': push(b*a); break;
                case '/': push(b/a); break;
                case '^': push(pow(b,a)); break;
            }
        }
    }

    return pop();
}