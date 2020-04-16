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
	char name[20];//���� 
	char sex;		//�Ա�'F'��ʾŮ�ԣ���M����ʾ���� 
}Person;


typedef Person QElemType ;


typedef struct 
{
	Person *base;
	int front;
	int rear; 
 }SqQueue;

 
 //��ʼ�� 
 Status InitQueue(SqQueue &Q)
 {
 	Q.base=new QElemType[MAXSIZE];
 	if(!Q.base)
	 {
	 	printf("�������ʧ�ܣ�\n");
	 	exit(OVERFLOW);
	 }
 	Q.front=Q.rear=0;
 	printf("��ʼ����ɣ�\n"); 
 	return OK;
 }
 
 //����г���
 int QueueLength(SqQueue Q)
 {
 	//����Q��Ԫ�ظ����������еĳ���
	 return (Q.rear-Q.front+MAXSIZE)%MAXSIZE; 
  } 
  
  //���
   Status EnQueue(SqQueue &Q,QElemType e)
   {
   	//����Ԫ��eΪQ���¶�βԪ��
	   if((Q.rear+1)%MAXSIZE==Q.front)
	   {
	   	printf("����\n"); 
	   	return ERROR;
	   } 

	   Q.base[Q.rear]=e;
	   Q.rear=(Q.rear+1)%MAXSIZE;
	   printf("��Ӳ�����ɣ�\n");
	   return OK;
   }
   
   //����
    Status DeQueue(SqQueue &Q,QElemType &e)
	{
		//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
		if(Q.front==Q.rear) return ERROR;
		e=Q.base[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
		return OK;
	 } 
	 
	 //ȡ��ͷԪ��
	  QElemType GetHead(SqQueue Q)
	  {
	  	//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
		  if(Q.front!=Q.rear)
		   return Q.base[Q.front]; 
	   } 
	   
	   //�ж϶����Ƿ�Ϊ�� 
	 Status QueueEmpty(SqQueue Q)
	 {
	 	if(Q.front==Q.rear) return OK;
	 	else return ERROR;
	 }
	 
	 
	 
	 	Person p; SqQueue Mdancers,Fdancers;
	void DancerPartner(Person dancer[],int num)
	{
		
		
		InitQueue(Mdancers);	//��ʿ���г�ʼ�� 
		InitQueue(Fdancers);	//Ůʿ���г�ʼ�� 
		for(int i=0;i<num;i++)  	//���ν������߸������Ա���� 
		{
			p=dancer[i];
			if(p.sex=='F'){
			EnQueue(Fdancers,p);//����Ů�� 
			//printf("Ů������%d\n",QueueLength(Fdancers));
			}
			else 
			{
				EnQueue(Mdancers,p);
			//	printf("�ж�����%d\n",QueueLength(Mdancers));
			}		// �����ж� 
		}
		/*if(QueueEmpty(Fdancers)) printf("kong"); 
		printf("Ů������%d\n",QueueLength(Fdancers));
		printf("�ж�����%d\n",QueueLength(Mdancers));*/ 

		printf("��������������ǣ�\n");
	/*	if(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
		printf("666");
		else
		printf("cnm");*/
		while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
		{
			//���������Ů��������
			DeQueue(Fdancers,p);//Ůʿ���� 
			printf("%s",p.name);//���Ů������ 
			DeQueue(Mdancers,p);//��ʿ����
			printf("%s\n",p.name);//�����ʿ���� 
		 }
		 if(!QueueEmpty(Fdancers))
		 {
		 	p=GetHead(Fdancers) ;
		 	printf("��һ��������Ůʿ��%s",p.name);
		  }
		  else if(!QueueEmpty(Mdancers))
		  {
			p=GetHead(Mdancers) ;
		 	printf("��һ����������ʿ��%s",p.name);
		   } 
	 } 
	
	   
	   int main()
	   {
	/*SqQueue queue;  
	printf("���ڳ�ʼ��\n");
	InitQueue(queue);
	printf("         |$$$���еĴ���                 |     \n");
	printf("         |�ó�����һ�¼��ֹ��ܣ�        |      \n");
	printf("         |1.����һ����n�����Ķ��У�     |     \n");
	printf("         |2.��ӣ�                      |     \n");
	printf("         |3.���ӣ�                      |     \n");
	printf("         |4.ȡ�Ӷ�Ԫ�أ�                |     \n");
	printf("         |5.����г��ȣ�                |     \n");	
	printf("         |0.�˳�����                  |\n\n\n\n"); 
	printf("������Ҫ���еĹ��ܣ�");
	
	
	int x,e;
	scanf("%d",&x); 
		while(x){
		switch(x){
			case 1:{
			
				break; 
				
			}
			case 2:{
				printf("��������Ҫѹ���Ԫ��\n"); 
				scanf("%d",&e);
		     	EnQueue(queue,e);	
				break;
			}
			case 3:{
				printf("���г��Ӳ���\n");
			    DeQueue(queue,e);
			    printf("ɾ����ֵΪ %d\n",e);
				break;
			}	
			case 4:{
				printf("ȡ���Ӷ�Ԫ�أ�\n"); 
				e=GetHead(queue); 
				printf("�Ӷ�Ԫ��Ϊ%d\n",e);
				break;
			}
			case 5:{
				printf("����г���\n"); 
				e=QueueLength(queue); 
				printf("���г���Ϊ%d\n",e);
				break;
			}
				
		}
		printf("������Ҫִ�еĳ���");
		scanf("%d",&x); 
	}	
	printf("�����������,��л����ʹ�ã�\n"); 
	 
	system("PAUSE"); */
	

	/*int i=0; 
	while(i<11)
	{
		if(i%2==0)
		{
		dancer[i].name="����"+i;
		dancer[i].sex='F';
		}
		else 
		{
		dancer[i].name="����"+i;
		dancer[i].sex='M';
		}		
	} */
		Person dancer[5] = {{"С��", 'F'}, {"С��", 'M'}, {"С��", 'F'}, {"С��", 'F'}, {"С��", 'M'}};
	
		DancerPartner(dancer,5);
	 return 0;
	   }
	   
	   

	
 
