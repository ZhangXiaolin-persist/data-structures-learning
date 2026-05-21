#include "SeqList.h"

int main()
{
    SL sl;
    SLInit(&sl);

    SLPushBack(&sl, 10);
    SLPushBack(&sl, 20);
    SLPushBack(&sl, 30);
    SLPrint(&sl);  // 10 20 30

    SLPushFront(&sl, 5);
    SLPrint(&sl);  // 5 10 20 30

    SLInsert(&sl, 2, 15);
    SLPrint(&sl);  // 5 10 15 20 30

    SLErase(&sl, 3);
    SLPrint(&sl);  // 5 10 15 30

    int pos = SLFind(&sl, 20);
    printf("20的位置: %d\n", pos);  // -1

    SLPopBack(&sl);
    SLPrint(&sl);  // 5 10 15

    SLDestroy(&sl);
     return 0;
}