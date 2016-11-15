#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Status InitQueue(LinkQueue *Q) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return ERROR;
	Q->front = p;
	Q->rear = p;
	Q->front->next = NULL;
	Q->rear->next = NULL;
	return OK;
}


Status DestroyQueue(LinkQueue *Q) {
	QueuePtr p = Q->front->next;
	QueuePtr r;
	if (Q->front == Q->rear)
		return ERROR;
	while (p != Q->rear) {
		r = p->next;
		free(p);
		p = r;
	}
	free(Q->rear);
	Q->front->next = NULL;
	Q->rear = Q->front;
	Q->rear->next = NULL;
	return OK;
}

Status ClearQueue(LinkQueue *Q) {
	QueuePtr p = Q->front->next;
	if (Q->front == Q->rear)
		return ERROR;
	while (p != Q->rear) {
		p->data = 0;
		p = p->next;
	}
	Q->rear->data = 0;
	return OK;
}

Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

Status GetHead(LinkQueue Q, Elemtype *e) {
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue *Q, Elemtype e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, Elemtype *e) {
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

int QueueLength(LinkQueue Q) {
	int count = 0;
	QueuePtr p = Q.front->next;
	while (p && p != Q.rear ) {
		count++;
		p = p->next;
	}
	if(Q.front != Q.rear)
		count++;
	return count;
}

int main() {
	LinkQueue Q;
	InitQueue(&Q);
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int e = rand() % 100 + 1;
		printf("%d ", e);
		EnQueue(&Q, e);
	}
	printf("\n");
	if (!QueueEmpty(Q))
		printf("%d\n", QueueLength(Q));
	int a;
	GetHead(Q, &a);
	printf("%d\n", a);
	//for (int i = 0; i < 10; i++) {
	//	int e;
	//	DeQueue(&Q, &e);
	//	printf("%d ", e);
	//}
	//printf("\n");
	//if(!QueueEmpty(Q))
	//	printf("%d\n", QueueLength(Q));
	//printf("%d\n", QueueLength(Q));
	ClearQueue(&Q);
	DestroyQueue(&Q);
}
