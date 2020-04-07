#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int QDataType;
typedef struct QNode{
	struct QNode* _next;
	QDataType _data;
}QNode;
typedef struct Queue{
	QNode* _front;
	QNode* _rear;
}Queue;

void  queueInit(Queue* q){
	// 初始化队列
	q->_front = q->_rear = NULL;
}
QNode* createNode(QDataType data){
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
// 队尾入队
void queuePush(	Queue* q,QDataType data){
	QNode* node = createNode(data);
	if ( q->_front == NULL){
		q->_front = q->_rear = node;
	}
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
}
// 队头出队
void queuePop(Queue* q){
	if (NULL == q || q->_front == NULL){
		return;
	}
	//if (q->_front->_next == NULL){
	//	q->_front = NULL;
	//	q->_rear = NULL;
	//	return;
	//}
	QNode* cur = q->_front->_next;
	free(q->_front);
	q->_front = cur;

	// 处理野指针
	// 头指针被删除，尾指针也指向NULL，不能使其随意指向
	if (q->_front == NULL){
		q->_rear = NULL;
	}
}

// 判断是否还有元素对外提供接口

// 获取队头元素
QDataType queueFront(Queue* q){
	return q->_front->_data;
}

// 队尾元素
QDataType queueBack(Queue* q){
	return q->_rear->_data;
}
// 一般判空用的是指针是否为NULL来判空

size_t queueSize(Queue* q){
	int num = 0;
	QNode* cur = q->_front;
	while (cur){
		++cur;
		cur = cur->_next;
	}
	return num;
}
int queueEmpty( Queue* q){
	if (q->_front == NULL){
		return 1;
	}
	return 0;
}
void queueDestory(Queue* q){
	QNode* cur = q->_front;
	while ( cur ){
		// 存放下一个结点
		QNode* next = cur->_next;
		// 释放当前结点
		free(cur);
		// 更新当前结点
		cur = next;
	}
	// 使首位结点指向NULL
	q->_front = q->_rear = NULL;
}

void queueDestoryqq(Queue* q){
	QNode* cur = q->_front;
	while ( cur ){
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}
int main(){

	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
	system("pause");
	return 0;
}