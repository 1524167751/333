#include <stdio.h>  
#include <time.h>  
clock_t start,stop;     //clock_t是clock（）函数返回的变量类型  
double duration;  
  
int main(int argc, const char * argv[]) {  
    // insert code here...  
    start = clock();  
    MyFunction();  
    stop = clock();  
    //CLOCKS_PER_SEC是一个常数，表示机器时钟每秒所走的时钟打点数，有的IDE下叫CLK_TCK  
    duration = (double)(stop-start)/CLOCKS_PER_SEC;  
    printf("函数运行时间是：%lf秒\n",duration);  
    return 0;  
}  

//算法排序 
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
    printf("请输入数据总量n(1-254)：");
	scanf("%d",&n);    
    printf("请输入%d个数：",n);
    for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    printf("排序前的数组：");
    } 
    for(i=0;i<n;i++)
	{printf("%d ",a[i]);
	printf("\n");      
    sorted(a,n);
	printf("排序后的数组：");
	} 
    for(i=0;i<n;i++)
    {
	printf("%d ",a[i]);
	printf("\n");    
   }
    return 0;
}
