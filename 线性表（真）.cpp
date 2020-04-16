#include<stdio.h> 
#include<stdlib.h>

//#include <iostream>

typedef int ElemType;

typedef struct List
{
	ElemType *list;//基地址 
	int size;//大小 
	int MaxSize;//最大长度自己设置 
} SqList;

//初始化线性表 
void InitList(SqList &L,int ms)
{
//用ms设置最大长度 
	if(ms<0)
	{
		printf("ms值非法！\n");
		exit(1);
	}
	L.MaxSize=ms;
	
	L.list=new ElemType[ms];//为顺序表设置大小为ms的数组空间
	if(!L.list) 
	{	
		printf("动态储存分配失败！");
		exit(1);
	}
	L.size=0;
	printf("线性表初始化完成！\n");
	
}

//创建顺序表
int  CreatList(SqList &L,int n)
{
	int i;
	if(!L.list||n<0||n>L.MaxSize) return 0;
	for(i=1;i<=n;i++)
	scanf("%d",&L.list[i-1]);
	L.size=n;
	return 0;
 } 
 
 
//顺序表取值
int GetElem(SqList L,int i,ElemType &e)
{
	if(i<1||i>L.size) 
	{
		printf("取值不合法!");
		return 0; 
		} 
	e=L.list[i-1];
	return 1;
 } 
 
 //查找
 int LocateElem(SqList L,ElemType e)
 {
 	for(int i=0;i<L.size;i++)
 		if(L.list[i]==e) return i+1;
  	printf("取值不合法！");
 	return 0;
	 
  } 
 
 //插入
 int ListInsert(SqList &L,int i,ElemType e)
 {
  if((i<1)||(i>L.size+1)) 
  {
  	printf("i值不合法！");
  	return 0;//i值不合法 
  }
  
  if(L.size==L.MaxSize) //储存空间已满 
  {
  	printf("储存空间已满!");
  	return 0;
  }
//  printf("%d",L.size-1); 
  for(int j=L.size-1;j>=i-1;j--)
  	L.list[j+1]=L.list[j];
  	L.list[i-1]=e;
  	++L.size;
  printf("插入操作成功！");
  return 0;
  } 
  
   //将线性表的所有值输出 
 void traverse_list(SqList L)
 {
 	for(int i=0;i<L.size;i++)
 		printf("%d",L.list[i]);
	 printf("\n");
  } 
  
  //删除
  int ListDelete(SqList &L,int i)
  {
  	if((i<1)||(i>L.size)) 
  	{
  		printf("i取值不合法！");
  		return 0;
	  }
	  for(int j=i;j<=L.size-1;j++)
	  	L.list[j-1]=L.list[j];
	  	--L.size;
	  	printf("删除操作完成！");
	  	return 0;
	  
   } 
   //计算顺序表长度 
   int size_list(SqList &L)
{
	printf("正在计算线性长度:\n");
	return L.size; 
}


void MergeList(SqList LA,SqList LB,SqList &LC)
{
	int *pa,*pb,*pc;
	int *pa_last,*pb_last;
	pa=LA.list;
	pb=LB.list;
	LC.size=LC.MaxSize=LA.size+LB.size;
	pc=LC.list=new ElemType[LC.size];
	if(!LC.list) exit(0);
	pa_last=LA.list+LA.size-1; 
	pb_last=LB.list+LB.size-1; 
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<=*pb)
			*pc++=*pa++;
		else
		*pc++=*pb++;
	}
	while(pa<=pa_last)
		*pc++==*pa++;
	while(pb<=pb_last)
		*pc++=*pb++;
 } 
 
 
int main()
{
	SqList list1,list2,list3;
	InitList(list1,10);//初始化 默认储存空间为10 
	
	printf("请输入你要输入的值及设置顺序表大小\n");
	int n;
	scanf("%d",&n);
	CreatList(list1,n);
	printf("请输入你要插入的位置及要插入的值\n");//插入 
	int n1,n2;
	scanf("%d%d", &n1,&n2);
	ListInsert(list1,n1,n2);
//	printf("进行遍历");
//	traverse_list(list1);
	
	printf("对list1进行操作\n"); 
	printf("请输入你要取值的位置\n");//取值 
	scanf("%d",&n1);
	int s;
	GetElem(list1,n1,s);
	printf("值为%d\n",s); 
	
	printf("请输入你要查找的元素\n");//查找   
	scanf("%d",&n1);
	printf("位置为%d\n",LocateElem(list1,n1));
	
	printf("请输入你要删除的位置\n");
	scanf("%d",&n1);
	ListDelete(list1,n1);	
	printf("线性表长度为：%d\n",size_list);
	traverse_list(list1);
	
	printf("对list2进行操作\n"); 
	InitList(list2,10);//初始化 默认储存空间为10 
	printf("请输入你要输入的值及设置顺序表大小\n");
	scanf("%d",&n);
	CreatList(list2,n);
	traverse_list(list2);
	
	MergeList(list1,list2,list3);
	traverse_list(list3);
}
