#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<onio.h>
int a=b=c=0;
//�ṹ��
struct bookinfo 
{
	char num[10];//��� 
	char name[20];//���� 
	char publish[50];
	float price;
}book[100],abook;//ͼ��

struct studentinfo
{
	char number[10];
	char name[20];
	char major[50];//Ժ 
 } student[100];//ѧ�� 
 
 struct lendinfo
 {
 	char stunum[10];
 	char booknum[10];
 	int year;
 	int month;
 	int day;
} lend[100;//������Ϣ
 //������
 void mian()
 {
 	menu();
  } 
  //�˵�
  void menu()
  {
  	int k;
  	system("cls");
  	printf(" \n\n\n                   **********************************\n");  
    printf("                   *                                *\n");  
    printf("                   *     ��ӭ����ͼ����Ϣ����ϵͳ   *\n");  
    printf("                   *                                *\n");  
    printf("                   **********************************\n");  
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t2----------ͼ����Ϣ��ʾ\n");
  	printf("\t\t\t1----------����ͼ����Ϣ\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	printf("\t\t\t1----------ͼ����Ϣ¼��\n");printf("\t\t\t1----------ͼ����Ϣ¼��\n");
  	
   } 

