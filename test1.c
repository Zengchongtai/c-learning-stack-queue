#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define elementType int


typedef struct STACK{
    elementType *data;
    int top;
}stack;


/*
// 栈初始化
void initialize_stack(stack* s)
{
    s -> top = -1;
}
*/

// 栈初始化 动态内存分配
stack* initialize_stack()
{
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack -> data = (elementType*)malloc(sizeof(elementType)*MAXSIZE);
    new_stack -> top = -1;
    return new_stack;
}

// 判断栈是否为空
int isempty(stack* s)
{
    if (s->top==-1)
    {
        printf("\n\n栈是空的\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// 压栈(进栈)
int push(stack* s, elementType push_data)
{
    if (s->top>=MAXSIZE-1)
    {
        printf("\n\n栈满了\n\n");
        return 0;
    }
    else
    {
        s -> top ++;
        s -> data[s -> top] = push_data;
        return 1;
    }
}

// 出栈
elementType pull(stack* s)
{
    if (s->top==-1)
    {
        printf("\n\n栈是空的\n\n");
        return 0;
    }
    else
    {
        return s -> data[s -> top --];
    }
}

// 获取栈顶元素
elementType gettopdata(stack* s)
{
    if (s->top==-1)
    {
        printf("\n\n栈是空的\n\n");
        return 0;
    }
    else
    {
        return s -> data[s -> top];
    }
}





int main()
{






    return 0;
}