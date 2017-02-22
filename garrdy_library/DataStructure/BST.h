#define true 1
#define false 0
typedef int status;
typedef struct BitNode {
    int data;
    struct BitNode *lchild, *rchild;
} BiTNode, *BiTree;
