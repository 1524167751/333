#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<io.h>
#define FILE_PATH "G:\\book\\allBooks.txt"
#define FILG_PATH "G:\\book\\index.txt"
struct Book
{
	int ID; //ͼ��id 
	char name[100];//ͼ���� 
	double price; //�۸�
	char author[100];//����
	int num;	//������
	int year;//ʱ�� 
	int month;
	int day;
	char number[10];//ѧ���� 
	int ifBorrowed;//�Ƿ���ģ�0Ϊû�У�1Ϊ�����Ĺ�
	int currentNum;//ʣ��ͼ�������	
};
struct studentinfo
{
	char number[10];
	char name[20];
	char major[50];
}student[100];//ѧ��
struct lendinfo
{
	char stunum[10];
	char booknum;
	int year;
	int month;
	int day;
 } lend[100];//������Ϣ 
//ͼ������ȫ��
struct Book books[1000];
//ͼ��ID
int bookID; 
//���ͼ���±�
int index;
//---------------------------����Ա���ܺ���-------------------------------------------------
//����ͼ��
void addBook()
{

	//-------���ݳ־û����� 

	//����ļ�������ֱ�ӽ�ȫ������д���ļ���
/*	if(!access(FILE_PATH,F_OK))//F_OK :�ļ����� R_OK: д��Ȩ��  
	{
			FILE *p=fopen(FILE_PATH,"w");
			fwrite(books,sizeof(struct Book),index,p);
			fclose(p);
			FILE *m=fopen(FILG_PATH,"w");
			fprintf(m,"%d",index);
			fclose(m);
	} 
	else	//����ļ������˽������������ݸ�ֵ��ȫ�ֱ��� 
	{*/
			//��ȡ 
				FILE *p=fopen(FILG_PATH,"r");
			fscanf(p,"%d",&index);
			bookID=index;
			fclose(p);
	
			FILE *m=fopen(FILE_PATH,"r");
			fread(books,sizeof(struct Book),1000,m);
			fclose(m);
			bookID=index;
			printf("������ͼ�����֣�");
			scanf("%s",books[index].name);
			printf("������ͼ��ļ۸�:");
			scanf("%lf",&(books[index].price));
			printf("������ͼ������:");
			scanf("%s",books[index].author);
			printf("������ͼ�������:");
			scanf("%d",&(books[index].num));
	
			books[index].ifBorrowed=0;
			books[index].currentNum=books[index].num;
			books[index].ID=++bookID;
			index++;

			//д�� ========================================== 
			FILE *n=fopen(FILE_PATH,"w");
			FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
			fprintf(q,"%d",index);
			fclose(n);
			fclose(q);
		//=================================================	
//	}
}
//ɾ��ͼ�� 
void deleteBook(int delID)
{
	//�ļ�������ֱ���˳� 
//	if(!access(FILE_PATH,F_OK))
//	{
//		printf("�ļ�������!");
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
		printf("ͼ���Ϊ�գ�\n");
	}
	else if(delIndex>=index)
	{
		printf("�����ڴ�ͼ��!");
	}
	//ɾ��˳��������һ��ͼ�� 

	else if(index-1==delIndex)
	{
		bookID --;
		index --;
		printf("ɾ���ɹ�!");
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
			printf("ɾ���ɹ�!");
	}
		//д�� 
			FILE *n=fopen(FILE_PATH,"w");
			FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
			fprintf(q,"%d",index);
			fclose(n);
			fclose(q);
}
//�鿴����ͼ��
void  showALLBooks()
{
//	if(!access(FILE_PATH,F_OK))
//	{
//		printf("�ļ������ڣ�");
//		return;
//	}
	//��ȡ 
		FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	printf("|\t���\t����\t����\t����\t�۸�\t����\t����|\n");
	int i;
	for(i=0;i<index;i++)
	{

		printf("\t%d\t%s\t%s\t%d\t��%g\t",books[i].ID,books[i].name,books[i].author,books[i].num,books[i].price);
		printf("%s\t",books[i].ifBorrowed==1 ?"��":"��");
		printf("%d\n",books[i].currentNum);
	}
}
//�鿴���н���ͼ��
void showALLBorrowedBooks()
{
//=====================================================	
/*	if(!access(FILE_PATH,F_OK))
	{
		printf("�ļ������ڣ�");
		return;
	}
*/	//��ȡ 
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	int i;
		printf("----------------------���ͼ��Ԥ��--------------------------\n");
	printf("\t���\t����\t����\t����\t�۸�\t����\t����\n");

	for(i=0;i<index;i++)
	{
		if(books[i].ifBorrowed==1)
		{
		printf("|\t%d\t%s\t%s\t%d\t��%g\t",books[i].ID,books[i].name,books[i].author,books[i].num,books[i].price);
		printf("%s\t",books[i].ifBorrowed==1 ?"��":"��");
		printf("%d|\n",books[i].currentNum);	
		}
	}
		printf("------------------------------------------------------------\n");	
}

//---------------------------------------------------------------------------------
//------------------------------------�û����ܺ���-------------------------------
void showAllBooks_User()
{
	//=====================================================	
//	if(!access(FILE_PATH,F_OK))
//	{
//		printf("�ļ������ڣ�");
//		return;
//	}
	//��ȡ 
		FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	
	printf("|\t���\t����\t����\t����\t�ɽ���\t����|\n");
	int i;
	for(i=0;i<index;i++)
	{

		printf("\t%d\t%s\t%s\t%d\t%d.%d.%d\t%d.%d.%d\t",books[i].ID,books[i].name,books[i].author,books[i].num,
		        lend[i].year,lend[i].month,lend[i].day,lend[i].year,lend[i].month,lend[i].day);
		printf("%s\t",books[i].currentNum!=0 ?"��":"��");
		printf("%d\n",books[i].currentNum);
	}
	/*printf("|ѧ��\tͼ����\t��������\tӦ������\n");
	for(i=0;i<index;i++0)
	{
		printf("%s\t%s\t\t%d.%d.%d\t%d.%d.%d\n",lend[i]);
	}*/
}
void borrowBook()//���� 
{
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	printf("����������ͼ��ID��");
	int borrowID;
	scanf("%d",&borrowID);
	
	printf("��������ĵ�����:");
	int borrowNum;
	scanf("%d",&borrowNum);
	if(borrowID>index||borrowID<=0)
	{
		printf("ѡ�����");
	}
	else
	{
		if(borrowNum>books[borrowID-1].currentNum)
		{
			printf("ͼ����������!\n");
		}
		else
		{   printf("������ѧ�ţ�\n");
		    scanf("%s",books[index].number);
		    printf("����������꣺\n");
		    scanf("%s",books[index].year);
		    printf("����������£�\n");
		    scanf("%s",books[index].month);
		    printf("����������գ�\n");
		    scanf("%s",books[index].day);
			books[borrowID-1].currentNum-=borrowNum;
			books[borrowID-1].ifBorrowed=1;
			printf("���ĳɹ���\n");
		}
	}
			//д�� ========================================== 
			FILE *n=fopen(FILE_PATH,"w");
		//	FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
		//	fprintf(q,"%d",index);
			fclose(n);
		//	fclose(m);
		//=================================================	
}
void returnBook()//���� 
{
	FILE *p=fopen(FILG_PATH,"r");
	fscanf(p,"%d",&index);
	bookID=index;
	fclose(p);
	
	FILE *m=fopen(FILE_PATH,"r");
	fread(books,sizeof(struct Book),1000,m);
	fclose(m);
	//==========================================================
	printf("������Ҫ�����ID:");
	int returnID;
	int returnNum;
	scanf("%d",&returnID);
	printf("\n�����뻹�������:");
	scanf("%d",&returnNum);
	if(returnID<=0||returnID>index) 
	{
		printf("�������Ȿ��\n");
	}
 	else
 	{//���������������ڽ�������������� 
    	if(returnNum>(books[returnID-1].num-books[returnID-1].currentNum))
    	{
	    	printf("�������\n"); 
	    }
	    else if(returnNum==(books[returnID-1].num-books[returnID-1].currentNum))
	    {//���ȫ������  �Ƿ������Ϊ  �� 
    		books[returnID-1].currentNum+=returnNum;
    		books[returnID-1].ifBorrowed=0;
    		printf("����ɹ�\n"); Sleep(3000);
    	}
    	else{// 
	    		books[returnID-1].currentNum+=returnNum;
	    			printf("����ɹ�\n"); Sleep(3000);
	    }

 	}
 		//д�� 
			FILE *n=fopen(FILE_PATH,"w");
			FILE *q=fopen(FILG_PATH,"w");
			fwrite(books,sizeof(struct Book),index,n);
			fprintf(q,"%d",index);
			fclose(n);
			fclose(q);
}

//--------------------------------------------------------------------------------
//��ҳ�� 
int  indexViewShow()
{
	system("cls");
	printf("-----------��ӭʹ��ͼ�����ϵͳ-----------------\n"); 
	printf("|                                               |\n"); 
	printf("|               ����Ա��ѡ 1                    |\n");
	printf("|                �û���ѡ 2                     |\n");
	printf("|                 �˳���ѡ 3                    |\n");
	printf("------------------------------------------------\n");
	int chioce;
	printf("��ѡ��: ");
	scanf("%d",&chioce);
	return chioce;
}
//����Ա
int managerViewShow()
{
	system("cls");
	printf("----------------����Ա---------------------------\n"); 
	printf("|                                               |\n"); 
	printf("|              ����ͼ����ѡ1                    |\n");
	printf("|              ɾ��ͼ����ѡ2                    |\n");
	printf("|              �鿴ͼ����ѡ3                    |\n");
	printf("|              �鿴����ͼ�� 4                   |\n"); 
	printf("|              �����ϼ�ҳ���밴5                |\n");
	printf("------------------------------------------------\n");
	int chioce;
	printf("��ѡ��: ");
	scanf("%d",&chioce);
	return chioce;
	
} 
//�û�ҳ��
int userViewShow()
{
	system("cls");
	printf("----------------��--��---------------------------\n"); 
	printf("|                                               |\n"); 
	printf("|              �鿴ͼ����ѡ1                    |\n");
	printf("|              ����ͼ����ѡ2                    |\n");
	printf("|              �黹ͼ����ѡ3                    |\n");
	printf("|              �����ϼ�ҳ���밴4                |\n");
	printf("-------------------------------------------------\n");
	int chioce;
	printf("��ѡ��: ");
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
			case 1://����Ա 
			{
				int manageChose;
				do
				{
					manageChose=managerViewShow();
					switch(manageChose)
					{
						case 1:	//����ͼ��
						{
							char chioce[20];
							do
							{
									addBook();
									printf("\n��������밴�� y��������ѡ�� n��");
						
									scanf("%s",chioce); 
							}while(strcmp(chioce,"y")==0);
						
						}	break;
						case 2://ɾ��ͼ��
						{
							showALLBooks();
							printf("����Ҫɾ��ͼ���ID,�˳���ѡesc");
							int deleteID;
							scanf("%d",&deleteID);
							printf("ȷ��ɾ�����Ϊ%d�����밴 :y\t",deleteID);
							char chose[2];
							scanf("%s",chose);
							if((strcmp(chose,"y")==0)||(strcmp(chose,"Y")==0))
							{
									deleteBook(deleteID);
								Sleep(2000);
							}
					
						} break;
						case 3://�鿴ͼ��
						{
							
							char chioce[20];
							showALLBooks();
							printf("�˳���ѡy: ");
							do
							{									
								scanf("%s",chioce); 
							}while(strcmp(chioce,"y")!=0);

						//	Sleep(5000);
						}	break;
						case 4://�鿴���н���ͼ�� 
						{
				      		
							
							char chioce[20];
							showALLBorrowedBooks();
							printf("�˳���ѡy: ");
							do
							{									
								scanf("%s",chioce); 
							}while(strcmp(chioce,"y")!=0);
				      		
						} break;
						case 5: break;
						default:printf("��������,������ѡ��");Sleep(2000);
					}
				}while(manageChose!=5);
			}
		
	 		 break;
			case 2://
			{
				int userChose;//�û� 
				do
				{
					userChose=userViewShow();
					switch(userChose)
					{
						case 1://�鿴ͼ�� 
						{
							char chioce[20];
							showAllBooks_User();
							printf("�˳���ѡy: ");
							do
							{									
								scanf("%s",chioce); 
							}while(strcmp(chioce,"y")!=0);
						} 	break;
					
						case 2://���� 
						{
							
							showAllBooks_User();
							char chioce[20];
							do
							{
							   borrowBook();
							   printf("����������ѡy���˳���ѡn");
							   scanf("%s",chioce);								
							}while(strcmp(chioce,"y")==0);

							
						}	break;
						case 3:
						{
							returnBook();
						}	break;//�黹 
						case 4:	break;//�����ϼ� 
						default:printf("��������,������ѡ��");Sleep(2000);break;	 
					}
				}while(userChose!=4);
    		}break;
			case 5:
			{
					break;
			}
			default: printf("��������������ѡ��\n");Sleep(1000);break;
		}
   
   	}while(chose!=3);
	printf("ллʹ��ͼ�����ϵͳ\n5����Զ��˳�\n");Sleep(5000);
	return 0;
} 
