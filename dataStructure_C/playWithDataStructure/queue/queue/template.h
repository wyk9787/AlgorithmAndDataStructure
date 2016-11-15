#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Elemtype;

typedef struct QNode{
	Elemtype data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;
}LinkQueue;