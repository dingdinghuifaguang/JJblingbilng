#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	BORROW,//5
	RETURN,//6
	SAVE,//7
	SORT//8
};

typedef struct BookInfo//图书信息结构体
{
	char name[10] = { 0 };
	double price;
	int num;

}BookInfo;

typedef struct Node
{
	BookInfo data;
	struct Node* next;
}Node;




struct Node* creatHead();//创建表头
struct Node* creatNode(struct BookInfo data);//创建节点
void insertNodeByHead(struct Node* head, struct BookInfo tempbook);//从头插入节点
struct Node* SearchBook(struct Node* headNode, char* bookname);//查找节点
void delNodeByname(struct Node* headNode, char* bookname);//删除节点
void Print(struct Node* headNode);//打印信息
void bubbleSortlistBook(struct Node* headNode);//排序
void Savelibrary(const char* fileName, struct Node* headNode);//文件储存
void readInfoFromFile(const char* fileName, struct Node* headNode);//文件浏览


