#include <stdio.h>  
#include <time.h>  
clock_t start,stop;     //clock_t��clock�����������صı�������  
double duration;  
  
int main(int argc, const char * argv[]) {  
    // insert code here...  
    start = clock();  
    MyFunction();  
    stop = clock();  
    //CLOCKS_PER_SEC��һ����������ʾ����ʱ��ÿ�����ߵ�ʱ�Ӵ�������е�IDE�½�CLK_TCK  
    duration = (double)(stop-start)/CLOCKS_PER_SEC;  
    printf("��������ʱ���ǣ�%lf��\n",duration);  
    return 0;  
}  

//�㷨���� 
void sorted(int a[],int n)
{ 
    int i,j,k,t;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(a[k]>a[j])k=j;} 
        if(k!=i){t=a[k];a[k]=a[i];a[i]=t;}}
}
int main(){
    int n,i,a[255];
    printf("��������������n(1-254)��");
	scanf("%d",&n);    
    printf("������%d������",n);
    for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    printf("����ǰ�����飺");
    } 
    for(i=0;i<n;i++)
	{printf("%d ",a[i]);
	printf("\n");      
    sorted(a,n);
	printf("���������飺");
	} 
    for(i=0;i<n;i++)
    {
	printf("%d ",a[i]);
	printf("\n");    
   }
    return 0;
}
