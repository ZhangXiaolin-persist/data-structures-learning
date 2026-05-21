#include "SeqList.h"

//顺序表的初始化
void SLInit(SL* ps)
{
    ps->arr = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//顺序表的销毁
void SLDestroy(SL* ps)
{
    //对指针操作前，检查指针是否为空，是个好习惯，可以避免一些不必要的错误
   if(ps->arr)        
   {
       free(ps->arr);
       ps->arr = NULL;
   }
    ps->size = 0;   
    ps->capacity = 0;
}

//顺序表的容量检查与扩容
void SLCheckCapacity(SL* ps)
{
    //先检查容量是否足够，如果够则结束
    if (ps->capacity > ps->size)
        return;
    //容量不够就扩容。1.如果当前容量为0，则扩容为4；2.如果当前容量不为0，则扩容为当前容量的2倍
    ps->capacity=(ps->capacity == 0 ? 4 : ps->capacity*2);
    int* new_arr = (int*)realloc(ps->arr, ps->capacity*sizeof(SLDataType));
    if (new_arr == NULL)
    {
        perror("realloc fail");
        exit(-1);
    }
    ps->arr = new_arr;
}

//顺序表从尾部插入数据
void SLPushBack(SL* ps,SLDataType x)
{
    SLCheckCapacity(ps);
    ps->arr[ps->size] = x;
    ps->size++;
}

//顺序表从头部插入数据
void SLPushFront(SL* ps,SLDataType x)
{
    SLCheckCapacity(ps);
    for(int size=ps->size ; size > 0 ;size--)
    {
        ps->arr[size]=ps->arr[size-1];
    }
    ps->arr[0] = x;
    ps->size++;
}

//顺序表从指定位置插入数据
void SLInsert(SL* ps,int pos,SLDataType x)
{
    //提前考虑好函数的安全运行范围 1、插入的指定位置是否合理。2、容量是否足够
    if(pos < 0 || pos > ps->size)
    return;
    SLCheckCapacity(ps);
    for(int size=ps->size ; size > pos ;size--)
    //size=11   pos=10(在arr[110]里面插入)
    {
        ps->arr[size]=ps->arr[size-1];
        //arr[11]=arr[10]

    }
    ps->arr[pos] = x;
    ps->size++;
}

//顺序表的尾部删除
void SLPopBack(SL* ps)
{
    if(ps->size == 0)
    return;
    ps->size--;
}

//顺序表的头部删除
void SLPopFront(SL* ps)
{
    if(ps->size == 0)
    {
        return;
    }
    for(int x = 0;x < ps->size-1;x++)
    {
        ps->arr[x] = ps->arr[x+1];
    }
    ps->size--;
}

//顺序表的任意位置删除
void SLErase(SL* ps,int pot)
{
    if(pot < 0 || pot >= ps->size)
    return;
    for(int x = pot ; x < ps->size - 1 ; x++)
    {
        ps->arr[x] = ps->arr[x+1];
    } 
    ps->size--;
}

//顺序表的元素查找
int SLFind(SL* ps,SLDataType x)
{   
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->arr[i] == x) return i;
    }   
    return -1;
}

//顺序表的打印
void SLPrint(SL* ps)
{
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    printf("\n");
}
