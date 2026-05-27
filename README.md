# 数据结构学习笔记（C语言实现）

## 项目简介
本项目是我学习数据结构的代码记录，使用C语言实现，目标是为嵌入式开发打基础。

> 详细学习笔记及代码解析见博客：
> - [双向链表（带头循环）学习笔记](https://blog.csdn.net/2601_95570258/article/details/161393272?fromshare=blogdetail&sharetype=blogdetail&sharerId=161393272&sharerefer=PC&sharesource=2601_95570258&sharefrom=from_link)
> - [栈（Stack）学习笔记](https://blog.csdn.net/2601_95570258/article/details/161399200?fromshare=blogdetail&sharetype=blogdetail&sharerId=161399200&sharerefer=PC&sharesource=2601_95570258&sharefrom=from_link)
> - [队列（Queue）学习笔记](https://blog.csdn.net/2601_95570258/article/details/) <!-- TODO: 替换为实际博客链接 -->

## 已完成的数据结构
- [已完成] 顺序表（动态数组）
- [已完成] 单链表（无头单向非循环）
- [已完成] 双向链表
- [已完成] 栈（动态数组）
- [已完成] 队列（链表）
- [待完成] 二叉树

## 环境
- 编译器：clang
- 编辑器：VS Code
- 调试：VS Code + CodeLLDB

## 目录结构
- `01_SeqList/` - 顺序表
- `02_SinglyLinkedList/` - 单链表
- `03_DoublyLinkedList/` - 带头双向循环链表
- `04_Stack/` - 栈（动态数组实现）
- `05_Queue/` - 队列（链表实现）

## 如何编译运行
```bash
cd 03_DoublyLinkedList
make
```
或手动编译：
```bash
cd 03_DoublyLinkedList
clang -g -O0 -Wall -o test *.c
./test

