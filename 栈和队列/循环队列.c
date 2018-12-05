#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 256
#define ElemType int

typedef struct     
{
	ElemType data[MAXSIZE];  // 数据的存储区
	int front,rear;          //队头队尾指针
}SeQueue;                    //循环队

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
		exit(0);		//队列满,退出运行
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
		exit(0);		//队已空,退出运行
	}
	x=Q.data[Q.front]; //读出队头元
	return x;
}

SeQueue SeQueueOut(SeQueue Q)
{
	if(Q.front==Q.rear)
    {
		printf("Empty\n");   
		exit(0);		//队已空,退出运行
	}
	x=Q.data[Q.front]; //读出队头元
	Q.front=(Q.front+1) % MAXSIZE;
	
	return Q;           //出队完成
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
	SeQueue Q = SeQueueInit();//初始化队列

	printf("一开始队列是否为空：");//判断是否为空
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	Q = SeQueueIn(Q,100);//添加第一个元素

	printf("添加完第一个值后队列是否为空：");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);//获取长度
	printf("此时队列的长度为：%d\n\n",a);

	x = SeQueueGet(Q);//获取队首元素
	printf("队首元素值为：%d\n\n",x);

	Q = SeQueueIn(Q,200);//添加第二个元素

	printf("添加完第二个值后队列是否为空：");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);
	printf("此时队列的长度为：%d\n\n",a);

	x = SeQueueGet(Q);
	printf("队首元素值为：%d\n\n",x);

	Q = SeQueueOut(Q);//删除队首元素
	printf("删除第一个值后队列是否为空：");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);
	printf("此时队列的长度为：%d\n\n",a);

	x = SeQueueGet(Q);
	printf("队首元素值为：%d\n\n",x);

	Q = SeQueueOut(Q);
	printf("删除第二个值后队列是否为空：");
	a = SeQueueEmpty(Q);
	if(a==1){
		printf("Empty\n");
	}else{
		printf("Not empty\n");
	}
	printf("\n");

	a=SeQueueLength(Q);
	printf("此时队列的长度为：%d\n\n",a);
}