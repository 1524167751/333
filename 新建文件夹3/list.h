#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<io.h>
#define FILE_PATH "G:\\book\\allBooks.txt"
#define FILG_PATH "G:\\book\\index.txt"
struct Book
{
	int ID; //图书id 
	char name[100];//图书名 
	double price; //价格
	char author[100];//作者
	int num;	//总数量
	int year;//时间 
	int month;
	int day;
	char number[10];//学生号 
	int ifBorrowed;//是否借阅，0为没有，1为被借阅过
	int currentNum;//剩余图书的数量	
};
struct studentinfo
{
	char number[10];
	char name[20];
	char major[50];
}student[100];//学生
struct lendinfo
{
	char stunum[10];
	char booknum;
	int year;
	int month;
	int day;
 } lend[100];//借阅信息 
//图书数组全局
struct Book books[1000];
//图书ID
int bookID; 
//添加图书下标
int index;
//---------------------------管理员功能函数-------------------------------------------------
//增加图书
void addBook()
{

	//-------数据持久化操作 

	//如果文件不存在直接将全局数组写入文件中
/*	if(!access(FILE_PATH,F_OK))//F_OK :文件存在 R_OK: 写入权限  
	{
			FILE *p=fopen(FILE_PATH,"w");
			fwrite(books,sizeof(struct Book),index,p);
			fclose(p);
			FILE *m=fopen(FILG_PATH,"w");
			fprintf(m,"%d",index);
			fclose(m);
	} 
	else	//如果文件存在了将读出所有数据赋值给全局变量 
	{*/
			//读取 
				FILE *p=fopen(FILG_PATH,"r");
			fscanf(p,"%d",&index);
			bookID=index;
			fclose(p);
	
			FILE *m=fopen(FILE_PATH,"r");
			fread(books,sizeof(struct Book),1000,m);
			fclose(m);
			bookID=index;
			printf("请输入图书名字：");
			scanf("%s",books[index].name);
			printf("请输入图书的价格:");
			scanf("%lf",&(books[index].price));
			printf("请输入图书作者:");
			scanf("%s",books[index].author);
			printf("请输入图书的数量:");
			scanf("%d",&(books[index].num));
	
			books[index].ifBorrowed=0;
			books[index].currentNum=books[index].num;
			books[index].ID=++bookID;
			index++;

			//写入 ========================================== 
			FILE *n=fopen(FILE_PATH,"w");
			FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
			fprintf(q,"%d",index);
			fclose(n);
			fclose(q);
		//=================================================	
//	}
}
//删除图书 
void deleteBook(int delID)
{
	//文件不存在直接退出 
//	if(!access(FILE_PATH,F_OK))
//	{
//		printf("文件不存在!");
//		return;
//	}
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	int delIndex=delID-1;
	if(bookID==0)
	{
		printf("图书库为空！\n");
	}
	else if(delIndex>=index)
	{
		printf("不存在此图书!");
	}
	//删除顺序表中最后一本图书 

	else if(index-1==delIndex)
	{
		bookID --;
		index --;
		printf("删除成功!");
	}
	else
	{
		int i;
		for(i=delIndex;i<index-1;i++)
		{	
			books[i]=books[i+1];
			books[i].ID -= 1;
		}
		index --;
		bookID --;
			printf("删除成功!");
	}
		//写入 
			FILE *n=fopen(FILE_PATH,"w");
			FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
			fprintf(q,"%d",index);
			fclose(n);
			fclose(q);
}
//查看所有图书
void  showALLBooks()
{
//	if(!access(FILE_PATH,F_OK))
//	{
//		printf("文件不存在！");
//		return;
//	}
	//读取 
		FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	printf("|\t编号\t名称\t作者\t数量\t价格\t借阅\t余量|\n");
	int i;
	for(i=0;i<index;i++)
	{

		printf("\t%d\t%s\t%s\t%d\t￥%g\t",books[i].ID,books[i].name,books[i].author,books[i].num,books[i].price);
		printf("%s\t",books[i].ifBorrowed==1 ?"是":"否");
		printf("%d\n",books[i].currentNum);
	}
}
//查看所有借阅图书
void showALLBorrowedBooks()
{
//=====================================================	
/*	if(!access(FILE_PATH,F_OK))
	{
		printf("文件不存在！");
		return;
	}
*/	//读取 
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	int i;
		printf("----------------------借出图书预览--------------------------\n");
	printf("\t编号\t名称\t作者\t数量\t价格\t借阅\t余量\n");

	for(i=0;i<index;i++)
	{
		if(books[i].ifBorrowed==1)
		{
		printf("|\t%d\t%s\t%s\t%d\t￥%g\t",books[i].ID,books[i].name,books[i].author,books[i].num,books[i].price);
		printf("%s\t",books[i].ifBorrowed==1 ?"是":"否");
		printf("%d|\n",books[i].currentNum);	
		}
	}
		printf("------------------------------------------------------------\n");	
}

//---------------------------------------------------------------------------------
//------------------------------------用户功能函数-------------------------------
void showAllBooks_User()
{
	//=====================================================	
//	if(!access(FILE_PATH,F_OK))
//	{
//		printf("文件不存在！");
//		return;
//	}
	//读取 
		FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	
	printf("|\t编号\t名称\t作者\t数量\t可借阅\t余量|\n");
	int i;
	for(i=0;i<index;i++)
	{

		printf("\t%d\t%s\t%s\t%d\t%d.%d.%d\t%d.%d.%d\t",books[i].ID,books[i].name,books[i].author,books[i].num,
		        lend[i].year,lend[i].month,lend[i].day,lend[i].year,lend[i].month,lend[i].day);
		printf("%s\t",books[i].currentNum!=0 ?"是":"否");
		printf("%d\n",books[i].currentNum);
	}
	/*printf("|学号\t图书编号\t借阅日期\t应还日期\n");
	for(i=0;i<index;i++0)
	{
		printf("%s\t%s\t\t%d.%d.%d\t%d.%d.%d\n",lend[i]);
	}*/
}
void borrowBook()//借书 
{
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	printf("请输入所借图书ID：");
	int borrowID;
	scanf("%d",&borrowID);
	
	printf("请输入借阅的数量:");
	int borrowNum;
	scanf("%d",&borrowNum);
	if(borrowID>index||borrowID<=0)
	{
		printf("选择错误");
	}
	else
	{
		if(borrowNum>books[borrowID-1].currentNum)
		{
			printf("图书余量不够!\n");
		}
		else
		{   printf("请输入学号：\n");
		    scanf("%s",books[index].number);
		    printf("请输入入借年：\n");
		    scanf("%s",books[index].year);
		    printf("请输入入借月：\n");
		    scanf("%s",books[index].month);
		    printf("请输入入借日：\n");
		    scanf("%s",books[index].day);
			books[borrowID-1].currentNum-=borrowNum;
			books[borrowID-1].ifBorrowed=1;
			printf("借阅成功！\n");
		}
	}
			//写入 ========================================== 
			FILE *n=fopen(FILE_PATH,"w");
		//	FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
		//	fprintf(q,"%d",index);
			fclose(n);
		//	fclose(m);
		//=================================================	
}
void returnBook()//还书 
{
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	printf("请输入要还书的ID:");
	int returnID;
	int returnNum;
	scanf("%d",&returnID);
	printf("\n请输入还书的数量:");
	scanf("%d",&returnNum);
	if(returnID<=0||returnID>index) 
	{
		printf("不存在这本书\n");
	}
 	else
 	{//如果还书的数量大于借出的总量，错误 
    	if(returnNum>(books[returnID-1].num-books[returnID-1].currentNum))
    	{
	    	printf("还书错误\n"); 
	    }
	    else if(returnNum==(books[returnID-1].num-books[returnID-1].currentNum))
	    {//如果全部还完  是否借阅设为  否 
    		books[returnID-1].currentNum+=returnNum;
    		books[returnID-1].ifBorrowed=0;
    		printf("还书成功\n"); Sleep(3000);
    	}
    	else{// 
	    		books[returnID-1].currentNum+=returnNum;
	    			printf("还书成功\n"); Sleep(3000);
	    }

 	}
 		//写入 
			FILE *n=fopen(FILE_PATH,"w");
			FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
			fprintf(q,"%d",index);
			fclose(n);
			fclose(q);
}

//--------------------------------------------------------------------------------
//主页面 
int  indexViewShow()
{
	system("cls");
	printf("-----------欢迎使用图书管理系统-----------------\n"); 
	printf("|                                               |\n"); 
	printf("|               管理员请选 1                    |\n");
	printf("|                用户请选 2                     |\n");
	printf("|                 退出请选 3                    |\n");
	printf("------------------------------------------------\n");
	int chioce;
	printf("请选择: ");
	scanf("%d",&chioce);
	return chioce;
}
//管理员
int managerViewShow()
{
	system("cls");
	printf("----------------管理员---------------------------\n"); 
	printf("|                                               |\n"); 
	printf("|              增加图书请选1                    |\n");
	printf("|              删除图书请选2                    |\n");
	printf("|              查看图书请选3                    |\n");
	printf("|              查看借阅图书 4                   |\n"); 
	printf("|              返回上级页面请按5                |\n");
	printf("------------------------------------------------\n");
	int chioce;
	printf("请选择: ");
	scanf("%d",&chioce);
	return chioce;
	
} 
//用户页面
int userViewShow()
{
	system("cls");
	printf("----------------用--户---------------------------\n"); 
	printf("|                                               |\n"); 
	printf("|              查看图书请选1                    |\n");
	printf("|              借阅图书请选2                    |\n");
	printf("|              归还图书请选3                    |\n");
	printf("|              返回上级页面请按4                |\n");
	printf("-------------------------------------------------\n");
	int chioce;
	printf("请选择: ");
	scanf("%d",&chioce);
	return chioce;
	
} 
int main()
{	
	int chose;
	do{
		chose=indexViewShow();
		switch(chose)
		{
			case 1://管理员 
			{
				int manageChose;
				do
				{
					manageChose=managerViewShow();
					switch(manageChose)
					{
						case 1:	//增加图书
						{
							char chioce[20];
							do
							{
									addBook();
									printf("\n继续添加请按： y，否则请选： n：");
						
									scanf("%s",chioce); 
							}while(strcmp(chioce,"y")==0);
						
						}	break;
						case 2://删除图书
						{
							showALLBooks();
							printf("输入要删除图书的ID,退出请选esc");
							int deleteID;
							scanf("%d",&deleteID);
							printf("确认删除编号为%d的书请按 :y\t",deleteID);
							char chose[2];
							scanf("%s",chose);
							if((strcmp(chose,"y")==0)||(strcmp(chose,"Y")==0))
							{
									deleteBook(deleteID);
								Sleep(2000);
							}
					
						} break;
						case 3://查看图书
						{
							
							char chioce[20];
							showALLBooks();
							printf("退出请选y: ");
							do
							{									
								scanf("%s",chioce); 
							}while(strcmp(chioce,"y")!=0);

						//	Sleep(5000);
						}	break;
						case 4://查看所有借阅图书 
						{
				      		
							
							char chioce[20];
							showALLBorrowedBooks();
							printf("退出请选y: ");
							do
							{									
								scanf("%s",chioce); 
							}while(strcmp(chioce,"y")!=0);
				      		
						} break;
						case 5: break;
						default:printf("输入有误,请重新选择");Sleep(2000);
					}
				}while(manageChose!=5);
			}
		
	 		 break;
			case 2://
			{
				int userChose;//用户 
				do
				{
					userChose=userViewShow();
					switch(userChose)
					{
						case 1://查看图书 
						{
							char chioce[20];
							showAllBooks_User();
							printf("退出请选y: ");
							do
							{									
								scanf("%s",chioce); 
							}while(strcmp(chioce,"y")!=0);
						} 	break;
					
						case 2://借阅 
						{
							
							showAllBooks_User();
							char chioce[20];
							do
							{
							   borrowBook();
							   printf("继续借阅请选y，退出请选n");
							   scanf("%s",chioce);								
							}while(strcmp(chioce,"y")==0);

							
						}	break;
						case 3:
						{
							returnBook();
						}	break;//归还 
						case 4:	break;//返回上级 
						default:printf("输入有误,请重新选择");Sleep(2000);break;	 
					}
				}while(userChose!=4);
    		}break;
			case 5:
			{
					break;
			}
			default: printf("输入有误，请重新选择\n");Sleep(1000);break;
		}
   
   	}while(chose!=3);
	printf("谢谢使用图书管理系统\n5秒后将自动退出\n");Sleep(5000);
	return 0;
} 
