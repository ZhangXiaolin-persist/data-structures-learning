#include <stdio.h>
#include "Stack.h"

int main() {
    printf("===== 栈测试开始 =====\n\n");

    // 1. 初始化栈
    ST st;
    STInit(&st);
    printf("1. 初始化完成\n");

    // 2. 判断栈是否为空（应该是空）
    printf("2. 栈是否为空？ %s\n", STEmpty(&st) ? "是" : "否");

    // 3. 入栈 10, 20, 30
    printf("3. 入栈 10, 20, 30\n");
    STPush(&st, 10);
    STPush(&st, 20);
    STPush(&st, 30);

    // 4. 获取栈顶元素（应该是30）
    printf("4. 栈顶元素：%d\n", STTop(&st));

    // 5. 获取栈中元素个数（应该是3）
    printf("5. 栈中元素个数：%d\n", STSize(&st));

    // 6. 出栈一次，再查看栈顶
    printf("6. 执行出栈一次\n");
    STPop(&st);
    printf("   出栈后栈顶元素：%d\n", STTop(&st));
    printf("   出栈后元素个数：%d\n", STSize(&st));

    // 7. 继续入栈 40, 50
    printf("7. 入栈 40, 50\n");
    STPush(&st, 40);
    STPush(&st, 50);

    // 8. 打印全部栈元素（通过循环出栈）
    printf("8. 依次弹出栈顶元素：");
    while (!STEmpty(&st)) {
        printf("%d ", STTop(&st));
        STPop(&st);
    }
    printf("\n");

    // 9. 此时栈应为空
    printf("9. 栈是否为空？ %s\n", STEmpty(&st) ? "是" : "否");

    // 10. 销毁栈
    STDestroy(&st);
    printf("10. 栈已销毁\n");

    // ======================================================
    // 边界测试：扩容（push 超过初始容量 4 个）
    // ======================================================
    printf("\n===== 边界测试：扩容 =====\n");
    ST st2;
    STInit(&st2);
    printf("初始容量：%d\n", st2.capacity);
    for (int i = 1; i <= 10; i++)
    {
        STPush(&st2, i * 10);
        printf("push %d, size=%d, capacity=%d\n", i * 10, STSize(&st2), st2.capacity);
    }
    // 全部弹出，验证顺序：后进先出
    printf("依次弹出：");
    while (!STEmpty(&st2))
    {
        printf("%d ", STTop(&st2));
        STPop(&st2);
    }
    printf("\n扩容测试通过\n");
    STDestroy(&st2);

    // ======================================================
    // 边界测试：只剩一个元素时 Pop
    // ======================================================
    printf("\n===== 边界测试：单元素 Pop =====\n");
    ST st3;
    STInit(&st3);
    STPush(&st3, 100);
    printf("入栈 100，size=%d，空？ %s\n", STSize(&st3), STEmpty(&st3) ? "是" : "否");
    STPop(&st3);
    printf("出栈后，size=%d，空？ %s\n", STSize(&st3), STEmpty(&st3) ? "是" : "否");
    printf("单元素测试通过\n");
    STDestroy(&st3);

    printf("\n===== 测试完成 =====\n");
    return 0;
}
