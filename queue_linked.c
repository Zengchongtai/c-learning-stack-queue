#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int elementType;

/*
链式队列:  头节点 ->  [data|next] -> [data|next] -> [data|next] -> NULL
                        ↑                             ↑
                        front                         rear
*/

// 头节点一边是对头,尾节点一边是队尾

typedef struct QUEUENODE{
    elementType data;
    struct QUEUENODE* next;
}queuenode;

typedef struct QUEUE{
    queuenode* front;
    queuenode* rear;
}queue;

// 初始化队列的链式结构
/*
内存布局：
┌─────────────────┐
│  queue结构体     │  ← q指向这里
│ [front][rear]   │
└─────────────────┘
        │      │
        ▼      ▼
┌─────────────────┐  ┌─────────────────┐
│ queuenode结构体  │  │ queuenode结构体  │
│ [data][next]    │  │ [data][next]    │
└─────────────────┘  └─────────────────┘
    ↑                   ↑      │
head_node指向这里        │      ▼
                       ...   NULL
head_node 本身虽然消失了，
但它指向的内存通过 q->front 和 q->rear 被保存下来，
最终传递出去了。
这就是动态内存分配的核心机制。
*/
queue* initialize_queue()
{
    queuenode* head_node = (queuenode*)malloc(sizeof(queuenode));
    queue* q = (queue*)malloc(sizeof(queue));
    q -> front = head_node;
    q -> rear = head_node;
    head_node -> next = NULL;
    head_node -> data = 114514;
    return q;
}

// 入队
void add_data(queue* q, elementType add_data)
{
    queuenode* new_node = (queuenode*)malloc(sizeof(queuenode));
    new_node -> data = add_data;
    new_node -> next = NULL;
    q -> rear -> next = new_node;
    q -> rear = new_node;
}

// 出队
elementType out_data(queue* q)
{   
    // 判断队列是否为空
    if (q -> front == q -> rear)
    {
        printf("\n\n队列是空的\n\n");
        return 0;
    }
    else
    {
        queuenode* delete_q = q -> front -> next;
        elementType out_data_ = delete_q -> data;
        q -> front -> next = q -> front -> next -> next;
        if (q -> rear == delete_q)
        {
            q -> rear = q -> front;
        }
        free(delete_q);
        delete_q = NULL;
        return out_data_;
    }
}

// 获取对头元素
elementType get_head_data(queue *q)
{
    if (q -> front == q -> rear)
    {
        printf("\n\n是空的\n\n");
        return 0;
    }
    else
    {
        return q -> front -> next -> data;
    }
}



int main()
{




    return 0;
}

