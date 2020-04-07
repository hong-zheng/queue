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
	// ��ʼ������
	q->_front = q->_rear = NULL;
}
QNode* createNode(QDataType data){
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
// ��β���
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
// ��ͷ����
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

	// ����Ұָ��
	// ͷָ�뱻ɾ����βָ��Ҳָ��NULL������ʹ������ָ��
	if (q->_front == NULL){
		q->_rear = NULL;
	}
}

// �ж��Ƿ���Ԫ�ض����ṩ�ӿ�

// ��ȡ��ͷԪ��
QDataType queueFront(Queue* q){
	return q->_front->_data;
}

// ��βԪ��
QDataType queueBack(Queue* q){
	return q->_rear->_data;
}
// һ���п��õ���ָ���Ƿ�ΪNULL���п�

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
		// �����һ�����
		QNode* next = cur->_next;
		// �ͷŵ�ǰ���
		free(cur);
		// ���µ�ǰ���
		cur = next;
	}
	// ʹ��λ���ָ��NULL
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