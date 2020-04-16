#include<stdio.h> 
#include<stdlib.h>
#include <malloc.h>
#include <windows.h> 


#define MAXSIZE 100
#define OVERFLOW 0
#define OK 1
#define ERROR 0

typedef int Status ;
/*typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;*/

typedef struct
{
	char name[20];//姓名 
	char sex;		//性别，'F'表示女性，‘M’表示男性 
}Person;


typedef Person QElemType ;


typedef struct 
{
	Person *base;
	int front;
	int rear; 
 }SqQueue;

 
 //初始化 
 Status InitQueue(SqQueue &Q)
 {
 	Q.base=new QElemType[MAXSIZE];
 	if(!Q.base)
	 {
	 	printf("储存分配失败！\n");
	 	exit(OVERFLOW);
	 }
 	Q.front=Q.rear=0;
 	printf("初始化完成！\n"); 
 	return OK;
 }
 
 //求队列长度
 int QueueLength(SqQueue Q)
 {
 	//返回Q的元素个数，即队列的长度
	 return (Q.rear-Q.front+MAXSIZE)%MAXSIZE; 
  } 
  
  //入队
   Status EnQueue(SqQueue &Q,QElemType e)
   {
   	//插入元素e为Q的新队尾元素
	   if((Q.rear+1)%MAXSIZE==Q.front)
	   {
	   	printf("队满\n"); 
	   	return ERROR;
	   } 

	   Q.base[Q.rear]=e;
	   Q.rear=(Q.rear+1)%MAXSIZE;
	   printf("入队操作完成！\n");
	   return OK;
   }
   
   //出队
    Status DeQueue(SqQueue &Q,QElemType &e)
	{
		//删除Q的队头元素，用e返回其值
		if(Q.front==Q.rear) return ERROR;
		e=Q.base[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
		return OK;
	 } 
	 
	 //取队头元素
	  QElemType GetHead(SqQueue Q)
	  {
	  	//返回Q的队头元素，不修改队头指针
		  if(Q.front!=Q.rear)
		   return Q.base[Q.front]; 
	   } 
	   
	   //判断队列是否为空 
	 Status QueueEmpty(SqQueue Q)
	 {
	 	if(Q.front==Q.rear) return OK;
	 	else return ERROR;
	 }
	 
	 
	 
	 	Person p; SqQueue Mdancers,Fdancers;
	void DancerPartner(Person dancer[],int num)
	{
		
		
		InitQueue(Mdancers);	//男士队列初始化 
		InitQueue(Fdancers);	//女士队列初始化 
		for(int i=0;i<num;i++)  	//依次将跳舞者根据其性别入队 
		{
			p=dancer[i];
			if(p.sex=='F'){
			EnQueue(Fdancers,p);//插入女队 
			//printf("女队人数%d\n",QueueLength(Fdancers));
			}
			else 
			{
				EnQueue(Mdancers,p);
			//	printf("男队人数%d\n",QueueLength(Mdancers));
			}		// 插入男队 
		}
		/*if(QueueEmpty(Fdancers)) printf("kong"); 
		printf("女队人数%d\n",QueueLength(Fdancers));
		printf("男队人数%d\n",QueueLength(Mdancers));*/ 

		printf("正在跳舞的舞者是：\n");
	/*	if(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
		printf("666");
		else
		printf("cnm");*/
		while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
		{
			//依次输出男女舞伴的姓名
			DeQueue(Fdancers,p);//女士出队 
			printf("%s",p.name);//输出女生名字 
			DeQueue(Mdancers,p);//男士出队
			printf("%s\n",p.name);//输出男士名字 
		 }
		 if(!QueueEmpty(Fdancers))
		 {
		 	p=GetHead(Fdancers) ;
		 	printf("第一个出场的女士是%s",p.name);
		  }
		  else if(!QueueEmpty(Mdancers))
		  {
			p=GetHead(Mdancers) ;
		 	printf("第一个出场的男士是%s",p.name);
		   } 
	 } 
	
	   
	   int main()
	   {
	/*SqQueue queue;  
	printf("正在初始化\n");
	InitQueue(queue);
	printf("         |$$$队列的储存                 |     \n");
	printf("         |该程序有一下几种功能：        |      \n");
	printf("         |1.创建一个有n个数的队列；     |     \n");
	printf("         |2.入队；                      |     \n");
	printf("         |3.出队；                      |     \n");
	printf("         |4.取队顶元素；                |     \n");
	printf("         |5.求队列长度；                |     \n");	
	printf("         |0.退出程序！                  |\n\n\n\n"); 
	printf("请输入要运行的功能：");
	
	
	int x,e;
	scanf("%d",&x); 
		while(x){
		switch(x){
			case 1:{
			
				break; 
				
			}
			case 2:{
				printf("请输入你要压入的元素\n"); 
				scanf("%d",&e);
		     	EnQueue(queue,e);	
				break;
			}
			case 3:{
				printf("进行出队操作\n");
			    DeQueue(queue,e);
			    printf("删除的值为 %d\n",e);
				break;
			}	
			case 4:{
				printf("取出队顶元素：\n"); 
				e=GetHead(queue); 
				printf("队顶元素为%d\n",e);
				break;
			}
			case 5:{
				printf("求队列长度\n"); 
				e=QueueLength(queue); 
				printf("队列长度为%d\n",e);
				break;
			}
				
		}
		printf("请输入要执行的程序：");
		scanf("%d",&x); 
	}	
	printf("程序运行完毕,感谢您的使用！\n"); 
	 
	system("PAUSE"); */
	

	/*int i=0; 
	while(i<11)
	{
		if(i%2==0)
		{
		dancer[i].name="张三"+i;
		dancer[i].sex='F';
		}
		else 
		{
		dancer[i].name="李四"+i;
		dancer[i].sex='M';
		}		
	} */
		Person dancer[5] = {{"小红", 'F'}, {"小明", 'M'}, {"小七", 'F'}, {"小欣", 'F'}, {"小天", 'M'}};
	
		DancerPartner(dancer,5);
	 return 0;
	   }
	   
	   

	
 
