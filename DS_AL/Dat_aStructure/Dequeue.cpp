#include <iostream>
#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _dlDeque
{
	Node* head;
	Node* tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq) 
{
	pdeq->head = nullptr;
	pdeq->tail = nullptr;

}
int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == nullptr) 
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}

void DQAddFirst(Deque* pdeq, Data data) 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (DQIsEmpty(pdeq)) 
	{
		pdeq->tail = newNode;
	}
	else 
	{
		pdeq->head->prev = newNode;
	}

	newNode->prev = nullptr;
	pdeq->head = newNode;
}
void DQAddLast(Deque* pdeq, Data data) 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (DQIsEmpty(pdeq))
	{
		pdeq->head = newNode;
	
	}
	else
	{
		pdeq->tail->next = newNode;
		//newNode->prev = pdeq->tail;
	}
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq) 
{
	Node* delNode = pdeq->head;
	Data _data = delNode->data;
	if (DQIsEmpty(pdeq))
	{
		printf("큐가 비었음");
		exit(-1);
	}
	pdeq->head = pdeq->head->next;
	//pdeq->head->prev = nullptr;
	free(delNode);
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return _data;
}
Data DQRemoveLast(Deque* pdeq) 
{
	Node* delNode = pdeq->tail;
	Data _data = delNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("큐가 비었음");
		exit(-1);
	}

	pdeq->tail = pdeq->tail->prev;
	//pdeq->tail->next = nullptr;
	free(delNode);
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	return _data;
}

Data DQGetFirst(Deque* pdeq) 
{
	if (DQIsEmpty(pdeq))
	{
		printf("큐가 비었음");
		exit(-1);
	}

	return pdeq->head->data;
}
Data DQGetLast(Deque* pdeq) 
{
	if (DQIsEmpty(pdeq))
	{
		printf("큐가 비었음");
		exit(-1);
	}
	return pdeq->tail->data;
}