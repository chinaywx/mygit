#include<stdio.h> 
#include<stdlib.h>

//#include <iostream>

typedef int ElemType;

typedef struct List
{
	ElemType *list;//����ַ 
	int size;//��С 
	int MaxSize;//��󳤶��Լ����� 
} SqList;

//��ʼ�����Ա� 
void InitList(SqList &L,int ms)
{
//��ms������󳤶� 
	if(ms<0)
	{
		printf("msֵ�Ƿ���\n");
		exit(1);
	}
	L.MaxSize=ms;
	
	L.list=new ElemType[ms];//Ϊ˳������ô�СΪms������ռ�
	if(!L.list) 
	{	
		printf("��̬�������ʧ�ܣ�");
		exit(1);
	}
	L.size=0;
	printf("���Ա��ʼ����ɣ�\n");
	
}

//����˳���
int  CreatList(SqList &L,int n)
{
	int i;
	if(!L.list||n<0||n>L.MaxSize) return 0;
	for(i=1;i<=n;i++)
	scanf("%d",&L.list[i-1]);
	L.size=n;
	return 0;
 } 
 
 
//˳���ȡֵ
int GetElem(SqList L,int i,ElemType &e)
{
	if(i<1||i>L.size) 
	{
		printf("ȡֵ���Ϸ�!");
		return 0; 
		} 
	e=L.list[i-1];
	return 1;
 } 
 
 //����
 int LocateElem(SqList L,ElemType e)
 {
 	for(int i=0;i<L.size;i++)
 		if(L.list[i]==e) return i+1;
  	printf("ȡֵ���Ϸ���");
 	return 0;
	 
  } 
 
 //����
 int ListInsert(SqList &L,int i,ElemType e)
 {
  if((i<1)||(i>L.size+1)) 
  {
  	printf("iֵ���Ϸ���");
  	return 0;//iֵ���Ϸ� 
  }
  
  if(L.size==L.MaxSize) //����ռ����� 
  {
  	printf("����ռ�����!");
  	return 0;
  }
//  printf("%d",L.size-1); 
  for(int j=L.size-1;j>=i-1;j--)
  	L.list[j+1]=L.list[j];
  	L.list[i-1]=e;
  	++L.size;
  printf("��������ɹ���");
  return 0;
  } 
  
   //�����Ա������ֵ��� 
 void traverse_list(SqList L)
 {
 	for(int i=0;i<L.size;i++)
 		printf("%d",L.list[i]);
	 printf("\n");
  } 
  
  //ɾ��
  int ListDelete(SqList &L,int i)
  {
  	if((i<1)||(i>L.size)) 
  	{
  		printf("iȡֵ���Ϸ���");
  		return 0;
	  }
	  for(int j=i;j<=L.size-1;j++)
	  	L.list[j-1]=L.list[j];
	  	--L.size;
	  	printf("ɾ��������ɣ�");
	  	return 0;
	  
   } 
   //����˳����� 
   int size_list(SqList &L)
{
	printf("���ڼ������Գ���:\n");
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
	InitList(list1,10);//��ʼ�� Ĭ�ϴ���ռ�Ϊ10 
	
	printf("��������Ҫ�����ֵ������˳����С\n");
	int n;
	scanf("%d",&n);
	CreatList(list1,n);
	printf("��������Ҫ�����λ�ü�Ҫ�����ֵ\n");//���� 
	int n1,n2;
	scanf("%d%d", &n1,&n2);
	ListInsert(list1,n1,n2);
//	printf("���б���");
//	traverse_list(list1);
	
	printf("��list1���в���\n"); 
	printf("��������Ҫȡֵ��λ��\n");//ȡֵ 
	scanf("%d",&n1);
	int s;
	GetElem(list1,n1,s);
	printf("ֵΪ%d\n",s); 
	
	printf("��������Ҫ���ҵ�Ԫ��\n");//����   
	scanf("%d",&n1);
	printf("λ��Ϊ%d\n",LocateElem(list1,n1));
	
	printf("��������Ҫɾ����λ��\n");
	scanf("%d",&n1);
	ListDelete(list1,n1);	
	printf("���Ա���Ϊ��%d\n",size_list);
	traverse_list(list1);
	
	printf("��list2���в���\n"); 
	InitList(list2,10);//��ʼ�� Ĭ�ϴ���ռ�Ϊ10 
	printf("��������Ҫ�����ֵ������˳����С\n");
	scanf("%d",&n);
	CreatList(list2,n);
	traverse_list(list2);
	
	MergeList(list1,list2,list3);
	traverse_list(list3);
}
