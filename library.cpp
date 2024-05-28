#define _CRT_SECURE_NO_WARNINGS
#include"library.h"

void menu()
{
	printf("******************************************\n");
	printf("*********1.���         2.ɾ��    ********\n");
	printf("*********3.����         4.��ʾ    *******\n");
	printf("*********5.����         6.�黹    ********\n");
	printf("*********7.����         8.����    ********\n");
	printf("*********0.�˳�***************************\n");
	printf("��ѡ��>\n");
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

		switch (input)//Switch����ѡ�����
		{
		case ADD:
			printf("������Ҫ¼������\n");
			scanf("%s", tempbook.name);
			printf("������۸�\n");
			scanf("%lf", &tempbook.price);
			printf("����������\n");
			scanf("%d", &tempbook.num);
			insertNodeByHead(HeadNode, tempbook);
			break;
		case DEL:
			printf("������Ҫɾ��������\n");
			scanf("%s", tempbook.name);
			delNodeByname(HeadNode, tempbook.name);
			break;
		case SEARCH:
			printf("������Ҫ���ҵ�����\n");
			scanf("%s", tempbook.name);
			SearchBook(HeadNode, tempbook.name);
			break;
		case MODIFY:
			Print(HeadNode);
			break;
		case BORROW:
			printf("��������ĵ�������");
			scanf("%s", tempbook.name);
			result = SearchBook(HeadNode, tempbook.name);
			if (result == NULL)
			{
				printf("û���ҵ�����鼮���޷����ġ�\n");
			}
			else
			{
				if (result->data.num >= 1)
				{
					result->data.num--;
					printf("���ĳɹ���\n");
				}
				else
				{
					printf("��ǰ�鱾���޿�棬����ʧ�ܣ�\n");
				}
			}
			break;
		case RETURN:
			printf("������黹��������");
			scanf("%s", tempbook.name);
			result = SearchBook(HeadNode, tempbook.name);
			if (result == NULL)
			{
				printf("���鲻����ͼ��ݣ�");
			}
			else
			{
				result->data.num++;
				printf("�黹�ɹ���\n");
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