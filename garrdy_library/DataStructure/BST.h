#define true 1
#define false 0
typedef int status;
typedef struct BitNode {
    int data;
    struct BitTnode *lchild, *rchild;
} BiTNode, *BiTree;
