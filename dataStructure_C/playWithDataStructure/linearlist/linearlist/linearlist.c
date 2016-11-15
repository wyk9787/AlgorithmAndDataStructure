#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

Status InitList(LinkList *L) {
	int n;
	LinkList p, r;
	srand(time(0));
	n = rand() % 7 + 3;
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	if (!L) return ERROR;
	for (int i = 0; i < n;i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = r->next;
	}
	r->next = NULL;
	return OK;
}

Status ListEmpty(LinkList *L) {
	LinkList p;
	p = (*L)->next;
	while (p) {
		p->data = 0;
		p = p->next;
	}
	return OK;
}

Status ClearList(LinkList *L) {
	LinkList p, q;
	p = (*L)->next;

	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

Status getElem(LinkList L, int i, Elemtype *e) {
	LinkList p;
	p = L;
	while (i && p) {
		p = p->next;
		i--;
	}
	if (!p)
		return ERROR;
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, Elemtype e) {
	LinkList p;
	int i = 1;
	p = L->next;
	while (p && p->data != e) {
		p = p->next;
		i++;
	}
	if (!p)
		return ERROR;
	return i;
}

Status ListInsert(LinkList *L, int i, Elemtype e) {
	LinkList p, q;
	p = *L;
	while (i && p) {
		p = p->next;
		i--;
	}
	if (!p)
		return ERROR;
	q = (LinkList)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return OK;
}

Status ListDelete(LinkList *L, int i, Elemtype *e) {
	LinkList p, q;
	p = *L;
	while (i-1 && p) {
		p = p->next;
		i--;
	}
	if (!p)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

int ListLength(LinkList L) {
	LinkList p;
	p = L;
	int count = 0;
	while (p) {
		p = p->next;
		count++;
	}
	return count;
}


int main() {
	LinkList L;
	int i, j, k, m;
	InitList(&L);
	ListEmpty(&L);
	ClearList(&L);
	InitList(&L);
	getElem(L, 3, &i);
	j = LocateElem(L, 15);
	printf("%d %d\n",i, j);
	ListInsert(&L, 3, 44);
	ListDelete(&L, 2, &k);
	m = ListLength(L);
}