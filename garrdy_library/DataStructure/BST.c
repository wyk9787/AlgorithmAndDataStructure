#include "BST.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

status SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    if (!T) {
        *p = f;
        return false;
    } else if (key == T->data) {
        *p = T;
        return true;
    } else if (key < T->data) {
        return SearchBST(T->lchild, key, T, p);
    } else {
        return SearchBST(T->rchild, key, T, p);
    }
}

status InsertBST(BiTree *T, int key) {
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p)) {
        s = (BiTree) malloc (sizeof (BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p) {
            *T = s;
        } else if (key < p->data) {
            p->lchild = s;
        } else {
            p->rchild = s;
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;
    for(int i = 0; i<10; i++) {
        InsertBST(&T, a[i]);
    }
    BiTree p;
    if(SearchBST(T, 35, NULL, &p)) {
        printf("data: %d\n", p->data);
    }
}
