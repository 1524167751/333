#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<onio.h>
int a=b=c=0;
//结构体
struct bookinfo 
{
	char num[10];//编号 
	char name[20];//书名 
	char publish[50];
	float price;
}book[100],abook;//图书

struct studentinfo
{
	char number[10];
	char name[20];
	char major[50];//院 
 } student[100];//学生 
 
 struct lendinfo
 {
 	char stunum[10];
 	char booknum[10];
 	int year;
 	int month;
 	int day;
} lend[100;//借阅信息
 //主函数
 void mian()
 {
 	menu();
  } 
  //菜单
  void menu()
  {
  	int k;
  	system("cls");
  	printf(" \n\n\n                   **********************************\n");  
    printf("                   *                                *\n");  
    printf("                   *     欢迎进入图书信息管理系统   *\n");  
    printf("                   *                                *\n");  
    printf("                   **********************************\n");  
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t2----------图书信息显示\n");
  	printf("\t\t\t1----------增加图书信息\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");
  	printf("\t\t\t1----------图书信息录入\n");printf("\t\t\t1----------图书信息录入\n");
  	
   } 

