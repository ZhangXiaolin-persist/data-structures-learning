/**
 * @file DoublyLinkedList.c
 * @brief 双向链表的实现（带头循环）
 * @author zhangxiaolin
 * @date 2025-05-22
 * @version 1.0
 */

#include "DoublyLinkedList.h"

/** 
 * @brief  创建并初始化双向链表的哨兵位
 * @param  无
 * @return 指向哨兵位的指针
 * @note   如果内存分配失败则退出程序
*/
LTNode* LTInit()
{
    LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
    if(phead == NULL)
    {
        perror("malloc fail");
        exit(-1);
        //由于perror不会退出程序所以需要使用exit退出程序，防止程序继续进行出现错误
    }
    phead->data = 0;
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

/** 
 * @brief 创建并初始化新节点
 * @param x （新节点的数据）
 * @return 新节点的地址
 * @note 如果内存分配失败则退出程序
*/
LTNode* BuyNewNode(LTDataType x)
{
    LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit (-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

/** 
 * @brief 从尾部插入新节点
 * @param x （新节点的数据）
 * @return 无
 * @note 传入的指针不能为空
*/
void LTPushBack(LTNode* phead,LTDataType x)
{
    assert(phead != NULL);
    LTNode* newnode = BuyNewNode(x);
    LTNode* tail = phead->prev;// 尾节点 = 哨兵位的前一个

    // 链接关系： tail  <-> newnode  <-> phead
    newnode->next = phead;
    newnode->prev = tail;
    tail->next = newnode;
    phead->prev = newnode;
}

/** 
 * @brief 从头部插入新节点
 * @param x （新节点的数据）
 * @return 无
 * @note 传入的指针不能为空
*/
void LTPushFront(LTNode* phead,LTDataType x)
{
    assert(phead != NULL);
    LTNode* newnode = BuyNewNode(x);

    LTNode* first = phead->next;

    // phead  <-> newnode  <-> first
    newnode->next = first;
    newnode->prev = phead;

    first->prev = newnode;
    phead->next = newnode;

}

/** 
 * @brief 在 pos 节点之后插入新节点
 * @param pos (pos节点的指针)
 * @param x （新节点的数据）
 * @return 无
 * @note 传入的指针不能为空
*/
void LTInsert(LTNode* pos,LTDataType x)
{
    assert(pos != NULL);
    LTNode* newnode = BuyNewNode(x);
    LTNode* after = pos->next;

    //pos <-> newnode <-> after
    newnode->next = after;
    newnode->prev = pos;

    after->prev = newnode;
    pos->next = newnode;
}

/** 
 * @brief 从头部删除节点
 * @param phead (哨兵位指针)
 * @return 无
 * @note 传入的指针不能为空
 * @note 空链表不能删
*/
void LTPopFront(LTNode* phead)
{
    assert(phead != NULL);
    assert(phead->next != phead);
    LTNode* first = phead->next;

    phead->next = (phead->next)->next;
    (first->next)->prev = phead;

    free(first);
}

/** 
 * @brief 从尾部删除节点
 * @param phead (哨兵位指针)
 * @return 无
 * @note 传入的指针不能为空
 * @note 空链表不能删
*/
void LTPopBack(LTNode* phead)
 {
    assert(phead != NULL);
    assert(phead->next != phead);   
    
    LTNode* tail = phead->prev;
    LTNode* newTail = tail->prev;
    
    // newTail  <->  phead
    newTail->next = phead;
    phead->prev = newTail;
    
    free(tail);
}

/** 
 * @brief 删除 pos 节点
 * @param pos (pos节点指针)
 * @return 无
 * @note 传入的指针不能为空
*/
void LTErase(LTNode* pos) 
{
    assert(pos != NULL);
    // 注意：一般不会删除哨兵位，调用者需保证
    LTNode* prevNode = pos->prev;
    LTNode* nextNode = pos->next;
    
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    
    free(pos);
}

/** 
 * @brief 查找数据所在的节点
 * @param x (要查找的数据)
 * @return 若找到则返回数据所在的节点的指针，如果没有找到则返回空指针
 * @note 传入的指针不能为空
*/
LTNode* LTFind(LTNode* phead,LTDataType x)
{
    assert(phead != NULL);
    LTNode* cur = phead->next;
    while(cur != phead)//遍历所有节点后会回到phead，此时没找到停止循环
    {
        if(cur->data == x )
        return cur;
        cur = cur->next;
    }
    return NULL;
}

/** 
 * @brief 销毁整个链表
 * @param phead (哨兵位指针)
 * @return 无
 * @note 传入的指针不能为空
*/
void LTDestroy(LTNode* phead) 
{
    assert(phead != NULL);
    LTNode* cur = phead->next;
    while (cur != phead) {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);   // 释放哨兵位
}

/** 
 * @brief 打印整个链表
 * @param phead (哨兵位指针)
 * @return 无
 * @note 传入的指针不能为空
*/
void LTPrint(LTNode* phead) 
{
    assert(phead != NULL);
    printf("哨兵位 <=> ");
    LTNode* cur = phead->next;
    while (cur != phead) {
        printf("%d <=> ", cur->data);
        cur = cur->next;
    }
    printf("哨兵位\n");
}