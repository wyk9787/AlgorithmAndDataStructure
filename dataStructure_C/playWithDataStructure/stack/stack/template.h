#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000

typedef int Status;
typedef int Elemtype;

typedef struct StackNode {
	Elemtype data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
	LinkStackPtr top;
	int count;
}LinkStack;