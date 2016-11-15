#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int Elemtype;

typedef struct Node {
	Elemtype data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

