// C program for
// Adjacency list representation of Directed graph
#include <stdio.h>
#include <stdlib.h>

struct AjlistNode
{
	int id;
	// Vertices id
	struct AjlistNode *next;
};
struct Vertices
{
	int data;
	struct AjlistNode *next;
	struct AjlistNode *last;
};
struct Graph
{
	int size;
	struct Vertices *node;
};
// create structure of queue node
struct QNode
{
	// data
	int data;
	// pointer
	struct QNode *next;
};
// Create structure of queue
struct MyQueue
{
	// data
	struct QNode *head;
	struct QNode *tail;
	int count;
	// pointer
	struct MyQueue *next;
};
struct MyQueue *newMyQueue()
{
	struct MyQueue *q = (struct MyQueue *) malloc(sizeof(struct MyQueue));
	q->head = NULL;
	q->tail = NULL;
	q->count = 0;
};
// Insert new Queue element
void enqueue(struct MyQueue *q, int value)
{
	// Create dynamic node
	struct QNode *node = (struct QNode *) malloc(sizeof(struct QNode));
	if (node == NULL)
	{
		printf("Memory overflow\n");
	}
	else
	{
		// set new node data
		node->data = value;
		node->next = NULL;
		if (q->head == NULL)
		{
			// Add first element into queue
			q->head = node;
		}
		else
		{
			// Add node at the end using tail pointer
			q->tail->next = node;
		}
		q->count++;
		q->tail = node;
	}
}
// Delete a element into queue
int dequeue(struct MyQueue *q)
{
	if (q->head == NULL)
	{
		printf("Empty Queue\n");
		return -1;
	}
	// Pointer variable which are storing
	// the address of deleted node
	struct QNode *temp = q->head;
	int info = temp->data;
	// Visit next node
	q->head = q->head->next;
	if (q->head == NULL)
	{
		// When deleting a last node of linked list
		q->tail = NULL;
	}
	free(temp);
	temp = NULL;
	q->count--;
	return info;
}
int size(struct MyQueue *q)
{
	return q->count;
}
int isEmpty(struct MyQueue *q)
{
	return q->count == 0;
}
int peek(struct MyQueue *q)
{
	if (q->head == NULL)
	{
		return -1;
	}
	return q->head->data;
}
//set node key value
void setData(struct Graph *g)
{
	if (g->node != NULL)
	{
		int index = 0;
		for (int index = 0; index < g->size; index++)
		{
			// Set vertic node data
			g->node[index].data = index;
			// Set NULL Value
			g->node[index].next = NULL;
			g->node[index].next = NULL;
		}
	}
	else
	{
		printf("Vertic Node is Empty");
	}
}
// Return new graph
struct Graph *newGraph(int size)
{
	if (size < 1)
	{
		printf("\n Invalid graph size ");
		exit(0);
	}
	struct Graph *g = (struct Graph *)
	malloc(sizeof(struct Graph));
	g->size = size;
	g->node = (struct Vertices *)
	malloc(sizeof(struct Vertices) *size);
	setData(g);
	return g;
}
// Connect two nodes
void connect(struct Graph *g, int start, int last)
{
	// First create Adjacency node
	struct AjlistNode *edge =
      (struct AjlistNode *) malloc(sizeof(struct AjlistNode));
	if (edge != NULL)
	{
		edge->id = last;
		edge->next = NULL;
		if (g->node[start].next == NULL)
		{
			g->node[start].next = edge;
		}
		else
		{
			// Add edge at the end
			g->node[start].last->next = edge;
		}
		// Get last edge
		g->node[start].last = edge;
	}
	else
	{
		printf("\n Memory overflow to create edge");
	}
}
// Add Edge from Two given Nodes
void addEdge(struct Graph *g, int start, int last)
{
	if (start < g->size && last < g->size)
	{
		connect(g, start, last);
	}
	else
	{
		//not valid Vertices
		printf("Invalid Node Vertices %d  %d", start, last);
	}
}
//Display Adjacency list of vertex
void printGraph(struct Graph *g)
{
	if (g != NULL)
	{
		struct AjlistNode *temp = NULL;
		for (int index = 0; index < g->size; index++)
		{
			printf("\n Adjacency list of vertex %d  :", index);
			temp = g->node[index].next;
			while (temp != NULL)
			{
				printf("  %d", g->node[temp->id].data);
				temp = temp->next;
			}
		}
	}
	else
	{
		printf("Empty Graph");
	}
}
// Breadth first traversal for a graph
void bfs(struct Graph *g, int point)
{
	if (point > g->size || g->size <= 0) return;
	struct MyQueue *q = newMyQueue();
	struct AjlistNode *temp = NULL;
	int *visit = (int *) calloc(g->size, sizeof(int));
	// Add first element into queue
	enqueue(q, point);
	printf("\n BFS :");
	while (!isEmpty(q))
	{
		temp = g->node[peek(q)].next;
		while (temp != NULL)
		{
			if (visit[temp->id] == 0)
			{
				visit[temp->id] = 1;
				enqueue(q, temp->id);
			}
			// visit to next node
			temp = temp->next;
		}
		visit[peek(q)] = 1;
		printf("  %d", peek(q));
		dequeue(q);
	}
}
int main()
{
	struct Graph *g = newGraph(6);
	addEdge(g, 0, 1);
	addEdge(g, 0, 5);
	addEdge(g, 1, 1);
	addEdge(g, 2, 1);
	addEdge(g, 3, 0);
	addEdge(g, 3, 3);
	addEdge(g, 4, 2);
	addEdge(g, 4, 3);
	addEdge(g, 5, 1);
	printGraph(g);
	bfs(g, 4);
	return 0;
}
