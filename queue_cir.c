#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 8

typedef int elementType;

typedef struct QUEUE{
    elementType* data;
    int front;
    int rear;
}queue;

// 初始化队列
queue* initialize_queue()
{
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue -> data = (elementType*)malloc(sizeof(elementType)*MAXSIZE);
    new_queue -> front = 0;
    new_queue -> rear = 0;
    return new_queue;
}

// 入队
int add_data(queue* q, elementType add_data)
{
    // 判断队列是否满了
    if ((q -> rear + 1)%MAXSIZE == q -> front)
    {
        printf("\n\n真满了\n\n");
        return 0;
    }
    else
    {
        q -> data[q -> rear] = add_data;
        q -> rear = (q -> rear + 1)%MAXSIZE;
        return 1;
    }
}

// 出队
int out_data(queue* q, elementType* out_data)
{
    // 判断队列是否为空
    if (q -> rear == q -> front)
    {
        printf("\n\n队列为空\n\n");
        return 0;
    }
    else
    {
        *out_data = q -> data [q -> front];
        q -> front = (q -> front + 1) % MAXSIZE;
        return 1;
    }
}


int main()
{

    queue* q = initialize_queue();
    add_data(q,114);
    add_data(q,1);
    add_data(q,4);
    add_data(q,5);
    add_data(q,1);
    add_data(q,4);
    int out;
    out_data(q,&out);
    printf("\n\nout_data is: %d\n\n",out);
    out_data(q,&out);
    printf("\n\nout_data is: %d\n\n",out);
    add_data(q,11);
    add_data(q,45);
    add_data(q,14);
    add_data(q,19);
    add_data(q,19);
    add_data(q,81);
    add_data(q,0);
    add_data(q,0);




}