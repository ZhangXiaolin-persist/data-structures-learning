#include "SinLinList.h"


//创建新节点
SLTNode* BuySListNode(SLTDataType x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit (-1);
    }
    //必须用malloc函数开辟出一块堆区内存，这样函数运行结束后你创建的新节点才会被保留
    newnode->data = x;
    newnode->next = NULL; 
    return newnode;
    //创建了指针变量后一定要先初始化
}

//尾插
void SLTPushBack(SLTNode** pphead,SLTDataType x)
{
    SLTNode* newnode = BuySListNode(x);
    
    //1.链表还没有节点，头指针为空
    if(*pphead == NULL)
    {
        *pphead = newnode;
    }
    //2.链表已经有节点了
    else
    {
        SLTNode* tail = *pphead;
    while(tail->next != 0)
    {
        tail = tail->next;
    }
    tail->next = newnode;
    }
}

//头插
void SLTPushFront(SLTNode** pphead,SLTDataType x)
{
    SLTNode* newnode = BuySListNode(x);
    newnode->next = *pphead;
    *pphead = newnode; 
}

//尾删
void SLTPopBack(SLTNode** pphead)
{
    //单链表无节点，头指针为空
    if(*pphead == NULL)
    return;

    //单链表只有一个节点
    if((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    //单链表有多个节点
    else
    {
        SLTNode* tail = *pphead;
        while((tail->next)->next != NULL)
        {
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

//头删
void SLTPopFront(SLTNode** pphead)
{
    //单链表无节点
    assert(*pphead != NULL);
    //单链表有多个节点
    SLTNode* pcur = (*pphead)->next;
    free(*pphead);
    *pphead = pcur;
}

//指定位置之前插入
void SLTInsert(SLTNode** pphead,SLTNode* pos,SLTDataType x)
{   
    //单链表中无节点，头指针为空，需要防止空指针被解引用
    assert(pos != NULL);
    //单链表中只有一个节点,相当于头插
    if(*pphead == pos)
    {
        SLTPushFront(pphead,x);
        return;
    }
    //单链表中有多个节点
    SLTNode* newnode = BuySListNode(x);
    SLTNode* pcur = *pphead;
    while(pcur->next != pos)
    {
        pcur = pcur->next;
    }
    newnode->next = pcur->next;
    pcur->next = newnode;
}

//指定位置之后插入
void SLTInsertAfter(SLTNode* pos,SLTDataType x)
{
    assert(pos != NULL);
    SLTNode* newnode = BuySListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

//删除指定节点pop
void SLTErase(SLTNode** pphead,SLTNode* pos)
{   
    //防御性编程，防止传入空头指针和空节点
    assert(*pphead != NULL && pos != NULL);
    //链表只有一个节点（相当于头删）
    if(*pphead == pos)
    {
        SLTPopFront(pphead);
        return;
    }
    //链表有多个节点
    SLTNode* prev = *pphead;
    while(prev->next != pos)
    {
        prev = prev->next;
    }
    prev->next = pos->next;
    free(pos);
}

//删除指定节点之后的节点
void SLTEraseAfter(SLTNode* pos)
{
    assert(pos != NULL && pos->next != NULL);
    SLTNode* cur = pos->next;
    pos->next = (pos->next)->next;
    free(cur);
}

//查找
SLTNode* SLTFind(SLTNode* phead,SLTDataType x)
{
    while(phead)
    {
        if(phead->data == x)
        return phead;
        phead = phead->next;
    }
    return NULL;
}

//打印数据
void SLTPrint(SLTNode* phead)
{
    SLTNode* cur = phead;
    while(cur)
    {
        printf("%d -> ",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

//销毁
void SListDestroy(SLTNode** pphead)
{
    SLTNode* cur = *pphead;
    while(cur)
    {
        SLTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}