/**
 * @file Queue.c
 * @brief 队列的实现（链表）
 * @author zhangxiaolin
 * @date 2025-05-26
 * @version 1.0
 */

#include "Queue.h"

/**
 * @brief 初始化队列
 * @param pq 队列结构体指针
 * @return 无
 * @note 注意不要传入空指针
*/
void QueueInit(Queue* pq)
{
    assert(pq != NULL);

    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

/**
 * @brief 销毁队列
 * @param pq 队列结构体指针
 * @return 无
 * @note 1、注意不要传入空指针。
*/
void QueueDestroy(Queue* pq)
{
    assert(pq != NULL);

    QNode* cur = pq->phead;
    QNode* tem = NULL;
    while(cur != NULL)
    {
        tem = cur;
        cur = cur->next;
        free(tem);
    }

    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

/**
 * @brief 入队
 * @param pq 队列结构体指针 
 * @param x 需存储的数据
 * @return 无
 * @note 1、注意不要传入空指针。2、队列为空时特殊处理。
*/
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq != NULL);

    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newnode->val = x;
    newnode->next = NULL;

    if(pq->ptail == NULL)//队列为空，特殊处理
    {
        pq->ptail = newnode;
        pq->phead = newnode;
        pq->size++;
    }
    else
    {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
        pq->size++;
    }
}

/**
 * @brief 出队
 * @param pq 队列结构体指针
 * @return 无
 * @note 1、注意不要传入空指针。2、要有节点才能出队。
 * @note 如果队列只存在一个节点，出队后会出现特殊情况，需要特殊处理
*/
void QueuePop(Queue* pq)
{
    assert(pq != NULL);
    assert(pq->phead != NULL);//要有节点才能出队

    QNode* cur = pq->phead;
    pq->phead = pq->phead->next;
    pq->size--;

    if(pq->phead == NULL)//如果队列只存在一个节点，出队后会出现特殊情况，需要特殊处理
        pq->ptail = NULL;

    free(cur);
}

/**
 * @brief 获取队头元素
 * @param pq 队列结构体指针
 * @return 队头元素数据
 * @note 1、注意不要传入空指针。2、要有节点才能获取
*/
QDataType QueueFront(Queue* pq)
{
    assert(pq != NULL);
    assert(pq->phead != NULL);

    return pq->phead->val;
}

/**
 * @brief 获取队尾元素
 * @param pq 队列结构体指针
 * @return 队尾元素数据
 * @note 1、注意不要传入空指针。2、要有节点才能获取
*/
QDataType QueueBack(Queue* pq)
{
    assert(pq != NULL);
    assert(pq->ptail != NULL);
    return pq->ptail->val;
}

/**
 * @brief 判断队列是否为空
 * @param pq 队列结构体指针
 * @return true 为空, false 非空
 * @note 注意不要传入空指针
*/
bool QueueEmpty(Queue* pq)
{
    assert(pq != NULL);
    return pq->phead == NULL;
}

/**
 * @brief 获取队列中元素个数
 * @param pq 队列结构体指针
 * @return 队列元素个数
 * @note 注意不要传入空指针
*/
int QueueSize(Queue* pq)
{
    assert(pq != NULL);
    return pq->size;
}
