/**
 * @file Queue.h
 * @brief 队列的接口声明（链表实现）
 * @author zhangxiaolin
 * @date 2025-05-26
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 队列存储数据的类型（可修改）
typedef int QDataType;

// 队列节点
typedef struct QueueNode
{
    QDataType val;
    struct QueueNode* next;
} QNode;

// 队列结构体
typedef struct Queue
{
    QNode* phead;  // 队头（出队端）
    QNode* ptail;  // 队尾（入队端）
    int size;
} Queue;

// 初始化队列
void QueueInit(Queue* pq);

// 销毁队列
void QueueDestroy(Queue* pq);

// 入队
void QueuePush(Queue* pq, QDataType x);

// 出队
void QueuePop(Queue* pq);

// 获取队头元素
QDataType QueueFront(Queue* pq);

// 获取队尾元素
QDataType QueueBack(Queue* pq);

// 判空
bool QueueEmpty(Queue* pq);

// 获取队列中元素个数
int QueueSize(Queue* pq);
