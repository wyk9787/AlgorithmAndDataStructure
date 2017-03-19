#define TRUE 1
#define FALSE 0
#define LH 1
#define EH 0
#define RH -1

typedef int Status;

typedef struct BitNode {
    int data;
    int bf;
    struct BitNode *lchild, *rchild;
} BiTNode, *BiTree;
