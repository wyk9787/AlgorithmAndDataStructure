#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Status InitStack(LinkStack *S) {
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	S->top = p;
	S->top = NULL;
	S->count = 0;
	return OK;
}

Status DestroyStack(LinkStack *S) {
	LinkStackPtr p, q;
	p = S->top;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	S->top = NULL;
	S->count = 0;
	return OK;
}

Status ClearStack(LinkStack *S) {
	LinkStackPtr p;
	p = S->top;
	while (p) {
		p->data = 0;
		p = p->next;
	}
	return OK;
}

Status GetTop(LinkStack S, Elemtype *e) {
	LinkStackPtr p;
	p = S.top;
	if (!p)
		return ERROR;
	*e = p->data;
	return OK;
}

Status Push(LinkStack *S, Elemtype e) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S->top;
	S->top = p;
	S->count++;
	return OK;
}

Status Pop(LinkStack *S, Elemtype *e) {
	LinkStackPtr p;
	if (!S->top)
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}

int main() {
	LinkStack S;
	InitStack(&S);
	srand(time(0));
	for (int i = 0; i < MAXSIZE; i++) {
		int e;
		e = rand() % 100 + 1;
		printf("%d ", e);
		Push(&S, e);
	}
	printf("\n");
	printf("%d\n", S.count);
	int a;
	GetTop(S, &a);
	printf("%d\n", a);
	//for (int i = 0; i < MAXSIZE; i++) {
	//	int e;
	//	Pop(&S, &e);
	//	printf("%d ", e);
	//}
	printf("\n");
	ClearStack(&S);
	DestroyStack(&S);
}