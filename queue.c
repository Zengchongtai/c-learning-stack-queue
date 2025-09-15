#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int elementType;

typedef struct QUEUE{
    elementType data[MAXSIZE];
    int front;
    int rear;
}queue;

// 初始化 顺序结构的队列
void initialize_queue(queue* q)
{
    q -> front = 0;
    q -> rear = 0;
}

// 判断队列是否为空
int isempty(queue* q)
{
    if (q -> front == q -> rear)
    {
        printf("队列是空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// 判断队列是否存在假溢出
// 未使用循环队列
int isqueuerealfull(queue* q)
{
    if (q -> front > 0)
    {
        int step = q -> front;
        int num = q -> rear - q -> front;
        for (int i=0;i<num;i++,step++)
        {
            q -> data[i] = q -> data[step];
        }
        q -> front = 0;
        q -> rear = num;
        return 0;
    }
    else
    {
        printf("真满了,会真溢出\n");
        return 1;
    }
}


// 队列中加入
int add_queue(queue* q, elementType add_data)
{
    if (q -> rear >= MAXSIZE)
    {   
        if (isqueuerealfull(q))
        {
            printf("队列已满,无法再加入\n");
            return 0;
        }
    }
        
    q -> data[q -> rear] = add_data;
    q -> rear ++;
    return 1;

}

// 队列中出
int out_queue(queue* q, elementType* out_data)
{
    if (q->rear==q->front)
    {
        printf("队列已空,无法再出\n");
        return 0;
    }
    else
    {   
        *out_data = q -> data[q -> front];
        q -> front ++;
        return 1;
    }
}

// 获取对头数据
int getdata_queue_front(queue* q, elementType* queue_front_data)
{   
    if (q -> front == q -> rear)
    {
        printf("队列是空的\n");
        return 0;
    }
    *queue_front_data = q -> data[q -> front];
    return 1;
}


int main()
{
    queue myqueue;
    initialize_queue(&myqueue);
    add_queue(&myqueue,116572);
    add_queue(&myqueue,1);
    add_queue(&myqueue,2);
    add_queue(&myqueue,3);
    add_queue(&myqueue,4);
    add_queue(&myqueue,5);
    elementType test1;
    getdata_queue_front(&myqueue,&test1);
    printf("\n\n获取对头数据: %d \n\n",test1);
}