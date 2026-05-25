/**
 * @file test.c
 * @brief 带头双向循环链表的功能测试
 * @author zhangxiaolin
 * @date 2025-05-22
 * @version 1.0
 */

#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    printf("===== 双向链表测试开始 =====\n\n");

    // 1. 初始化链表（创建哨兵位）
    LTNode* plist = LTInit();
    printf("1. 初始化空链表: ");
    LTPrint(plist);   // 预期输出：哨兵位 <=> 哨兵位 或类似格式

    // 2. 测试判空
    printf("2. 链表是否为空？ %s\n", plist->next == plist ? "是" : "否");

    // 3. 尾插 3 个节点: 10, 20, 30
    printf("3. 尾插 10, 20, 30\n");
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPrint(plist);

    // 4. 头插 2 个节点: 5, 1
    printf("4. 头插 5, 1\n");
    LTPushFront(plist, 5);
    LTPushFront(plist, 1);
    LTPrint(plist);   // 预期: 1,5,10,20,30

    // 5. 查找值为 10 的节点，并在它之后插入 15
    printf("5. 查找 10，在其后插入 15\n");
    LTNode* pos = LTFind(plist, 10);
    if (pos) {
        LTInsert(pos, 15);
    } else {
        printf("未找到 10\n");
    }
    LTPrint(plist);   // 预期: 1,5,10,15,20,30

    // 6. 删除值为 15 的节点（通过 LTFind 找到后 LTErase）
    printf("6. 查找 15 并删除\n");
    pos = LTFind(plist, 15);
    if (pos) {
        LTErase(pos);
    } else {
        printf("未找到 15\n");
    }
    LTPrint(plist);   // 预期: 1,5,10,20,30

    // 7. 头删一次，尾删一次
    printf("7. 头删一次，尾删一次\n");
    LTPopFront(plist);
    LTPopBack(plist);
    LTPrint(plist);   // 预期: 5,10,20

    // 8. 再次判空
    printf("8. 链表是否为空？ %s\n", plist->next == plist ? "是" : "否");

    // 9. 连续尾删直到空
    printf("9. 连续删除节点直至空链表:\n");
    while (plist->next != plist) {
        LTPopBack(plist);
        LTPrint(plist);
    }
    printf("  此时链表应只有哨兵位: ");
    LTPrint(plist);

    // 10. 再次判空
    printf("10. 链表是否为空？ %s\n", plist->next == plist ? "是" : "否");

    // 11. 销毁链表
    printf("11. 销毁链表\n");
    LTDestroy(plist);
    plist = NULL;   // 调用者自己置空
    printf("   链表已销毁\n");

    printf("\n===== 测试完成 =====\n");
    return 0;
}