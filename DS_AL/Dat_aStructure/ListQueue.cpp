
#include <iostream>

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _lQueue
{
	Node* front;
	Node* rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);


void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* nextNode = (Node*)malloc(sizeof(Node));
	nextNode->next = NULL;
	nextNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = nextNode;
		pq->rear = nextNode;
	}
	else
	{
		pq->rear->next = nextNode;
		pq->rear = nextNode;
	}
}

Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data _data;

	if (QIsEmpty(pq))
	{
		printf("큐가 비었음");
		exit(-1);
	}

	delNode = pq->front;
	_data = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return _data;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("큐가 비었음");
		exit(-1);
	}

	return pq->front->data;
}
