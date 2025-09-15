// 栈的链式结构实现

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_HEAD_DATA 114514

typedef int elementType;

typedef struct STACK{
    elementType data;
    struct STACK* next;
}stack;

// 初始化链式栈
stack* initialize_stack()
{
    stack* s = (stack*)malloc(sizeof(stack));
    s -> next = NULL;
    s -> data = DEFAULT_HEAD_DATA;
    return s; 
}

// 判断链式栈是否为空 0 否 1 是
int isempty(stack* s)
{
    if (s->next==NULL)
    {
        printf("该链式栈是空的");
        return 1;
    }
    else
    {
        return 0;
    }
}