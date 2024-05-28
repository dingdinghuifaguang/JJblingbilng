#define _CRT_SECURE_NO_WARNINGS
#include"library.h"

void menu()
{
	printf("******************************************\n");
	printf("*********1.添加         2.删除    ********\n");
	printf("*********3.查找         4.显示    *******\n");
	printf("*********5.借阅         6.归还    ********\n");
	printf("*********7.保存         8.排列    ********\n");
	printf("*********0.退出***************************\n");
	printf("请选择：>\n");
}
int main()
{
	int input=0;
	struct Node* result=NULL;
	struct BookInfo tempbook;
	struct Node* HeadNode = creatHead();
	readInfoFromFile("bookinfo.txt", HeadNode);
	do
	{
		menu();
		scanf("%d", &input);

		switch (input)//Switch函数选择界面
		{
		case ADD:
			printf("请输入要录入书名\n");
			scanf("%s", tempbook.name);
			printf("请输入价格\n");
			scanf("%lf", &tempbook.price);
			printf("请输入数量\n");
			scanf("%d", &tempbook.num);
			insertNodeByHead(HeadNode, tempbook);
			break;
		case DEL:
			printf("请输入要删除的书名\n");
			scanf("%s", tempbook.name);
			delNodeByname(HeadNode, tempbook.name);
			break;
		case SEARCH:
			printf("请输入要查找的书名\n");
			scanf("%s", tempbook.name);
			SearchBook(HeadNode, tempbook.name);
			break;
		case MODIFY:
			Print(HeadNode);
			break;
		case BORROW:
			printf("请输入借阅的书名：");
			scanf("%s", tempbook.name);
			result = SearchBook(HeadNode, tempbook.name);
			if (result == NULL)
			{
				printf("没有找到相关书籍，无法借阅。\n");
			}
			else
			{
				if (result->data.num >= 1)
				{
					result->data.num--;
					printf("借阅成功。\n");
				}
				else
				{
					printf("当前书本暂无库存，借阅失败！\n");
				}
			}
			break;
		case RETURN:
			printf("请输入归还的书名：");
			scanf("%s", tempbook.name);
			result = SearchBook(HeadNode, tempbook.name);
			if (result == NULL)
			{
				printf("该书不属于图书馆！");
			}
			else
			{
				result->data.num++;
				printf("归还成功。\n");
			}
			break;

		case SAVE:
			Savelibrary("bookinfo.txt",HeadNode);
			break;
		case SORT:
			bubbleSortlistBook(HeadNode);
			break;
		case EXIT:
			break;

		}
	} while (input);

	return 0;
}
