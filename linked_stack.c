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

// 压栈(进栈)
int push(stack* s, elementType push_data)
{
    stack* new_push = (stack*)malloc(sizeof(stack));
    new_push -> data = push_data;
    new_push -> next = s -> next;
    s -> next = new_push;
    return 1;
}

// 出栈
int pull(stack* s, elementType* pull_data)
{   
    if (s->next==NULL)
    {
        printf("该链式栈是空的");
        return 0;
    }
    stack* temp = s -> next;
    s -> next = temp -> next;
    *pull_data = temp -> data;
    free(temp);
    temp = NULL;
    return 1;
}

// 获取栈顶元素
int gettop(stack* s,elementType* get_data)
{
    if (s->next==NULL)
    {
        printf("该链式栈是空的");
        return 0;
    }
    *get_data = s -> next -> data;
    return 1;
}