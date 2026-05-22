#include "SinLinList.h"

int main()
{
    SLTNode* plist = NULL;   // 一开始空链表

    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPrint(plist);   // 1 -> 2 -> 3 -> NULL

    SLTPushFront(&plist, 0);
    SLTPrint(plist);   // 0 -> 1 -> 2 -> 3 -> NULL

    SLTPopBack(&plist);
    SLTPrint(plist);   // 0 -> 1 -> 2 -> NULL

    SLTPopFront(&plist);
    SLTPrint(plist);   // 1 -> 2 -> NULL

    SLTNode* pos = SLTFind(plist, 1);
    if (pos)
        SLTInsert(&plist, pos, 9);
    SLTPrint(plist);   // 9 -> 1 -> 2 -> NULL

    pos = SLTFind(plist, 1);
    if (pos)
        SLTInsertAfter(pos, 8);
    SLTPrint(plist);   // 9 -> 1 -> 8 -> 2 -> NULL

    pos = SLTFind(plist, 1);
    if (pos)
        SLTErase(&plist, pos);
    SLTPrint(plist);   // 9 -> 8 -> 2 -> NULL

    SListDestroy(&plist);
    return 0;
}