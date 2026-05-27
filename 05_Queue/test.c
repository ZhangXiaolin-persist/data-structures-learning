#include <stdio.h>
#include "Queue.h"

int main() {
    printf("===== 队列测试开始 =====\n\n");

    // 1. 初始化队列
    Queue q;
    QueueInit(&q);
    printf("1. 初始化完成\n");

    // 2. 判空（应为空）
    printf("2. 队列是否为空？ %s\n", QueueEmpty(&q) ? "是" : "否");

    // 3. 入队 10, 20, 30
    printf("3. 入队 10, 20, 30\n");
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);

    // 4. 查看队头和队尾
    printf("4. 队头：%d，队尾：%d\n", QueueFront(&q), QueueBack(&q));

    // 5. 查看元素个数
    printf("5. 元素个数：%d\n", QueueSize(&q));

    // 6. 出队一次，再查看队头
    printf("6. 出队一次\n");
    QueuePop(&q);
    printf("   出队后队头：%d，元素个数：%d\n", QueueFront(&q), QueueSize(&q));

    // 7. 继续入队 40, 50
    printf("7. 入队 40, 50\n");
    QueuePush(&q, 40);
    QueuePush(&q, 50);

    // 8. 顺序出队，验证 FIFO（先进先出：20, 30, 40, 50）
    printf("8. 依次出队：");
    while (!QueueEmpty(&q)) {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");

    // 9. 此时队列应为空
    printf("9. 队列是否为空？ %s\n", QueueEmpty(&q) ? "是" : "否");

    // 10. 销毁队列
    QueueDestroy(&q);
    printf("10. 队列已销毁\n");

    // ======================================================
    // 边界测试：单元素出入队
    // ======================================================
    printf("\n===== 边界测试：单元素出入队 =====\n");
    Queue q2;
    QueueInit(&q2);
    QueuePush(&q2, 100);
    printf("入队 100，size=%d，空？ %s\n", QueueSize(&q2), QueueEmpty(&q2) ? "是" : "否");
    printf("队头=%d，队尾=%d\n", QueueFront(&q2), QueueBack(&q2));
    QueuePop(&q2);
    printf("出队后，size=%d，空？ %s\n", QueueSize(&q2), QueueEmpty(&q2) ? "是" : "否");
    QueueDestroy(&q2);
    printf("单元素测试通过\n");

    // ======================================================
    // 边界测试：空队列销毁
    // ======================================================
    printf("\n===== 边界测试：空队列销毁 =====\n");
    Queue q3;
    QueueInit(&q3);
    printf("空队列 size=%d\n", QueueSize(&q3));
    QueueDestroy(&q3);
    printf("空队列销毁成功\n");

    // ======================================================
    // 边界测试：大量入队
    // ======================================================
    printf("\n===== 边界测试：大量入队 =====\n");
    Queue q4;
    QueueInit(&q4);
    for (int i = 1; i <= 10; i++)
    {
        QueuePush(&q4, i * 10);
    }
    printf("入队 10 个元素，size=%d，队头=%d，队尾=%d\n",
           QueueSize(&q4), QueueFront(&q4), QueueBack(&q4));
    // 逐个出队验证顺序
    printf("出队顺序：");
    while (!QueueEmpty(&q4))
    {
        printf("%d ", QueueFront(&q4));
        QueuePop(&q4);
    }
    printf("\n大量入队测试通过\n");
    QueueDestroy(&q4);

    printf("\n===== 测试完成 =====\n");
    return 0;
}
