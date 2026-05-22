#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLTDataType;

typedef struct SLTNode
{
    SLTDataType data;
    struct SLTNode* next;
} SLTNode;

//创建新节点
SLTNode* BuySListNode(SLTDataType data);
//尾插
void SLTPushBack(SLTNode** pphead,SLTDataType x);
//头插
void SLTPushFront(SLTNode** pphead,SLTDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//指定位置之前插入
void SLTInsert(SLTNode** pphead,SLTNode* pos,SLTDataType x);
//指定位置之后插入
void SLTInsertAfter(SLTNode* pos,SLTDataType x);
//删除指定节点pop
void SLTErase(SLTNode** pphead,SLTNode* pos);
//删除指定结点之后的结点
void SLTEraseAfter(SLTNode* pos);
//查找（返回结点地址）
SLTNode* SLTFind(SLTNode* phead,SLTDataType x);
//打印链表
void SLTPrint(SLTNode* phead);
//销毁整个链表
void SListDestroy(SLTNode** pphead);

