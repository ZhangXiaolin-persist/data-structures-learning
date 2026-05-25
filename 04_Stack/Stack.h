/**
 * @file Stack.h
 * @brief 栈的接口声明（动态数组实现）
 * @author zhangxiaolin
 * @date 2025-05-25
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//栈存储数据的类型（可修改）
typedef int STDataType;

//栈的结构体
typedef struct Stack
{
    STDataType* arr;
    int top;        //栈顶下标
    int capacity;   //当前容量
}ST;

//初始化栈
void STInit(ST* ps);

//销毁栈
void STDestroy(ST* ps);

//入栈
void STPush(ST* ps,STDataType x);

//出栈
void STPop(ST* ps);

//获取栈顶元素
STDataType STTop(ST* ps);

//判空
bool STEmpty(ST* ps);

//获取栈中元素个数
int STSize(ST* ps);

