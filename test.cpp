#define _CRT_SECURE_NO_WARNINGS
#include"library.h"



struct Node* creatHead()//创建表头
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}

struct Node* creatNode(struct BookInfo data)//创建节点
{	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertNodeByHead(struct Node* head,struct BookInfo tempbook)//头插法录入数据
{
	struct Node* node = creatNode(tempbook);
	node->next = head->next;
	head->next = node;
}
/*void insertNodeByTail(struct Node* headNode, int data)//尾插法,用不着
{
	struct Node* pMove = headNode;
	while (pMove->next != NULL)
	{
		pMove = pMove->next;
	}
	struct Node* newNode = createNode(data);
	pMove->next = newNode;

}*/
struct Node* SearchBook(struct Node* headNode, char* bookname)//查找节点
{
	struct Node* pMove = headNode->next;
	while (pMove != NULL && strcmp(pMove->data.name, bookname))
	{
		pMove = pMove->next;
	}
	return pMove;
}
void delNodeByname(struct Node* headNode, char* bookname)//删除节点
{
	struct Node* posLeftNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* posNode = SearchBook(headNode,bookname);
	if (posNode == NULL)
	{
		printf("未找到该书");
		return;
	}
	printf("删除成功");
	posLeftNode = posNode->next;
	free(posNode);
	posNode = NULL;
}

void Print(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("书名\t价格\t数量\n");
	while (pMove)
	{
		printf("%s\t%lf\t%d\n", pMove->data.name, pMove->data.price, pMove->data.num);
		pMove=pMove->next;
	}
}

void bubbleSortlistBook(struct Node* headNode)//排序
{
	for (struct Node* p = headNode->next; p != NULL; p->next)
	{
		for (struct Node* q = p; q->next != NULL; q = q->next)
		{
			if (q->data.price > q->next->data.price)
			{
				struct BookInfo tempData = q->data;
				q->data = q->next->data;
				q->next->data = tempData;
			}
		}
	}
}

void Savelibrary(const char* fileName,struct Node*headNode)//文件储存
{
	FILE* fp = fopen(fileName, "w");
	struct Node* pMove = headNode->next;
	while (pMove)
	{
		fprintf(fp, "%s\t%.1f\t%d\n", pMove->data.name, pMove->data.price, pMove->data.num);
		pMove = pMove->next;
	}
	fclose(fp);
}
void readInfoFromFile(const char* fileName, struct Node* headNode)//文件浏览
{
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL)//创建文件
	{
		fp = fopen(fileName, "w+");
	}
	struct BookInfo tempData;
	while (fscanf(fp, "%s\t%f\t%d\n", tempData.name, &tempData.price, &tempData.num) != EOF)
	{
		insertNodeByHead(headNode, tempData);
	}
	fclose(fp);

}
















