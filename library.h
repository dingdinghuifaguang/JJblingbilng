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

typedef struct BookInfo//ͼ����Ϣ�ṹ��
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




struct Node* creatHead();//������ͷ
struct Node* creatNode(struct BookInfo data);//�����ڵ�
void insertNodeByHead(struct Node* head, struct BookInfo tempbook);//��ͷ����ڵ�
struct Node* SearchBook(struct Node* headNode, char* bookname);//���ҽڵ�
void delNodeByname(struct Node* headNode, char* bookname);//ɾ���ڵ�
void Print(struct Node* headNode);//��ӡ��Ϣ
void bubbleSortlistBook(struct Node* headNode);//����
void Savelibrary(const char* fileName, struct Node* headNode);//�ļ�����
void readInfoFromFile(const char* fileName, struct Node* headNode);//�ļ����


