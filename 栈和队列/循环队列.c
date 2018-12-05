#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 256
#define ElemType int

typedef struct     
{
	ElemType data[MAXSIZE];  // ���ݵĴ洢��
	int front,rear;          //��ͷ��βָ��
}SeQueue;                    //ѭ����

extern int x=0;

SeQueue SeQueueInit()
{
	SeQueue Q;
	Q.front=Q.rear=0;
	return Q;
} 

SeQueue SeQueueIn(SeQueue Q,ElemType x)
{
	if((Q.rear+1) % MAXSIZE==Q.front)
	{
		printf("Full\n");
		exit(0);		//������,�˳�����
	}
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1) % MAXSIZE;
	return Q;
} 

int SeQueueGet(SeQueue Q)
{
	if(Q.front==Q.rear)
    {
		printf("Empty\n");   
		exit(0);		//���ѿ�,�˳�����
	}
	x=Q.data[Q.front]; //������ͷԪ
	return x;
}

SeQueue SeQueueOut(SeQueue Q)
{
	if(Q.front==Q.rear)
    {
		printf("Empty\n");   
		exit(0);		//���ѿ�,�˳�����
	}
	x=Q.data[Q.front]; //������ͷԪ
	Q.front=(Q.front+1) % MAXSIZE;
	
	return Q;           //�������
} 

int SeQueueEmpty (SeQueue Q)
{
	if(Q.front==Q.rear) 
		return 1;
	else
		return 0;
} 

int SeQueueLength(SeQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

void main_test4()
{
	int a;
	SeQueue Q = SeQueueInit();//��ʼ������

	printf("һ��ʼ�����Ƿ�Ϊ�գ�");//�ж��Ƿ�Ϊ��
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	Q = SeQueueIn(Q,100);//��ӵ�һ��Ԫ��

	printf("������һ��ֵ������Ƿ�Ϊ�գ�");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);//��ȡ����
	printf("��ʱ���еĳ���Ϊ��%d\n\n",a);

	x = SeQueueGet(Q);//��ȡ����Ԫ��
	printf("����Ԫ��ֵΪ��%d\n\n",x);

	Q = SeQueueIn(Q,200);//��ӵڶ���Ԫ��

	printf("�����ڶ���ֵ������Ƿ�Ϊ�գ�");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);
	printf("��ʱ���еĳ���Ϊ��%d\n\n",a);

	x = SeQueueGet(Q);
	printf("����Ԫ��ֵΪ��%d\n\n",x);

	Q = SeQueueOut(Q);//ɾ������Ԫ��
	printf("ɾ����һ��ֵ������Ƿ�Ϊ�գ�");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);
	printf("��ʱ���еĳ���Ϊ��%d\n\n",a);

	x = SeQueueGet(Q);
	printf("����Ԫ��ֵΪ��%d\n\n",x);

	Q = SeQueueOut(Q);
	printf("ɾ���ڶ���ֵ������Ƿ�Ϊ�գ�");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);
	printf("��ʱ���еĳ���Ϊ��%d\n\n",a);
}