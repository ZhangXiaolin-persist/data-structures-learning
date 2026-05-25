/**
 * @file Stack.c
 * @brief 栈的实现（动态数组）
 * @author zhangxiaolin
 * @date 2025-05-25
 * @version 1.0
 */

#include "Stack.h"

/**
 * @brief  初始化栈
 * @param ps 栈的结构体指针
 * @return 无
 * @note 注意不要传入空指针
*/
void STInit(ST* ps)
{
    assert(ps != NULL );//防御性编程，确保指针有效
    ps->arr = NULL;
    ps->capacity = 0;
    ps->top = 0;
}

/**
 * @brief  销毁栈
 * @param ps 栈的结构体指针
 * @return 无
 * @note 注意不要传入空指针
*/
void STDestroy(ST* ps)
{
    assert(ps != NULL );//防御性编程，确保指针有效
    free(ps->arr);
    ps->arr = NULL;
    ps->capacity = 0;
    ps->top = 0;
}

/**
 * @brief  入栈
 * @param ps 栈的结构体指针
 * @param x 需要存储的数据
 * @return 无
 * @note 1、注意不要传入空指针。2、如果内存申请失败则打印错误信息并且退出程序
*/
void STPush(ST* ps,STDataType x)
{
    assert(ps != NULL );//防御性编程，确保指针有效
    if(ps->capacity == ps->top)//判断容量是否足够
    {
        int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity*2);
        ps->capacity = newcapacity;
        STDataType* newarr = realloc(ps->arr,ps->capacity*sizeof(STDataType));//扩容
        if(newarr == NULL)
        {
            perror("realloc fail");
            exit (-1);
        }
        ps->arr = newarr;
    }

    //将数据放入栈顶
    ps->arr[ps->top] = x;
    ps->top++;
}

/**
 * @brief  出栈
 * @param ps 栈的结构体指针
 * @return 无
 * @note 1、注意不要传入空指针。2、注意不要传入空栈。
*/
void STPop(ST* ps)
{
    assert(ps != NULL );//防御性编程，确保指针有效
    assert(ps->top != 0);
    ps->top--;
}

/**
 * @brief  获取栈顶元素
 * @param ps 栈的结构体指针
 * @return 栈顶存储的数据
 * @note 1、注意不要传入空指针。2、注意不要传入空栈。
*/
STDataType STTop(ST* ps)
{
    assert(ps != NULL );//防御性编程，确保指针有效
    assert(ps->top != 0);

    return ps->arr[ps->top-1];
}

/**
 * @brief  判断栈是否为空
 * @param ps 栈的结构体指针
 * @return true 栈为空, false 栈非空
 * @note 注意不要传入空指针
*/
bool STEmpty(ST* ps)
{
    assert(ps != NULL );//防御性编程，确保指针有效

    return ps->top == 0;
}

/**
 * @brief  获取栈中元素个数
 * @param ps 栈的结构体指针
 * @return 栈元素的个数
 * @note 注意不要传入空指针
*/
int STSize(ST* ps)
{
    assert(ps != NULL );//防御性编程，确保指针有效

    return ps->top;
}

