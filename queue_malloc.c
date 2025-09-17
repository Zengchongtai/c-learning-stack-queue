#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100


typedef int elementType;

typedef struct QUEUE{
    elementType* data;
    int front;
    int rear;
}queue;

// 初始化队列 动态内存分配
queue* initialize_queue()
{
    queue* new = (queue*)malloc(sizeof(queue));
    new -> front = 0;
    new -> rear = 0;
    new -> data = (elementType*)malloc(sizeof(elementType)*MAXSIZE);
    return new;
}

// 判断队列是否为空
int isempty(queue* q)
{
    if (q -> front == q -> rear)
    {
        printf("\n\n队列是空的\n\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// 判断是否真的满 若假满会调整 0 未满或假满(并调整) 1 真满
int isrealfull(queue* q)
{
    if (q->rear>=MAXSIZE-1)
    {
        if (q->front==0)
        {
            printf("\n\n真满了\n\n");
            return 1;
        }
        else
        {
            int step = q -> rear - q -> front + 1;
            int front_ = q -> front;
            for (int i=0;i<step;i++,front_++)
            {
                q -> data[i] = q -> data[front_];
            }
            q -> front = 0;
            q -> rear = step - 1;
            return 0;
        }
    }
    else
    {
        printf("\n\n还未满\n\n");
        return 0;
    }
}

// 入队
void add_queue(queue* q, elementType add_data)
{
    // 先判断有没有真的满
    if (isrealfull(q))
    {
        printf("\n\n队列已满\n入队失败\n\n");
        return;
    }
    else
    {
        q -> data[++ q -> rear] = add_data;
        printf("\n\n入队成功!\n当前入队内容下标序号 %d\n\n",q -> rear);
    }
}

// 出队
int out_queue(queue* q, elementType* out_data)
{
    // 先判断队列是不是空
    if (isempty(q))
    {
        printf("\n\n出队失败\n没有可用的项目\n\n");
        return 0;
    }
    else
    {   
        *out_data = q -> data[q -> front++];
        printf("\n\n出队成功!\n\n");
        return 1;
    }
}


// 获取对头数据
int get_front_data(queue* q, elementType* out_data)
{
    // 先判断队列是不是空
    if (isempty(q))
    {
        printf("\n\n没有可用的项目\n\n");
        return 0;
    }
    else
    {
        * out_data = q -> data [q -> front];
        return 1;
    }
}



int main()
{




    return 0;
}