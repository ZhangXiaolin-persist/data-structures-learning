#include <stdio.h>
#include <stdlib.h>

// 头文件保护
#ifndef SEQLIST_H
#define SEQLIST_H

typedef int SLDataType; 
//重新定义数据类型的名字，方便修改以应对不同的数据类型

// 动态顺序表的结构体
typedef struct SeqList
{
    SLDataType* arr;
    int size;
    int capacity;
}SL;

//1.顺序表的初始化
void SLInit(SL* ps);

//2.顺序表的销毁
void SLDestroy(SL* ps);

//3.容量检查与扩容
void SLCheckCapacity(SL* ps);

//4.增删查改
//（1）尾插
void SLPushBack(SL* ps,SLDataType x);
//（2）头插
void SLPushFront(SL* ps,SLDataType x);
//（3）指定位置插入
void SLInsert(SL* ps,int pos,SLDataType x);
//（4）尾删
void SLPopBack(SL* ps);
//（5）头删
void SLPopFront(SL* ps);
//（6）任意位置删除
void SLErase(SL* ps,int pos);
//（7）查找
int SLFind(SL* ps,SLDataType x);

//5.打印数据
void SLPrint(SL* ps);



#endif