/**
 * @file DoublyLinkedList.h
 * @brief 带头双向循环链表的接口声明
 * @author zhangxiaolin
 * @date 2025-05-22
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//链表存储数据的类型（可修改）
typedef int LTDataType;

//链表的节点结构体
typedef struct ListNode
{
    LTDataType data;
    struct ListNode* next;
    struct ListNode* prev;
}LTNode;

//创建并初始化双向链表的哨兵位
LTNode* LTInit();

//创建并初始化新节点
LTNode* BuyNewNode(LTDataType x);

//插入新节点
//从尾部插入
void LTPushBack(LTNode* phead,LTDataType x);
//从头部插入
void LTPushFront(LTNode* phead,LTDataType x);
//在 pos 节点之后插入
void LTInsert(LTNode* pos,LTDataType x);

//删除节点
//从头部删除
void LTPopFront(LTNode* phead);
//从尾部删除
void LTPopBack(LTNode* phead);
//删除 pos 节点
void LTErase(LTNode* pos);
   
//查找数据所在的节点
LTNode* LTFind(LTNode* phead,LTDataType x);

//销毁链表
void LTDestroy(LTNode* phead);

//打印整个链表
void LTPrint(LTNode* phead);

