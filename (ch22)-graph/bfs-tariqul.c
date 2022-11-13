#include <stdio.h>
#include <stdlib.h>
#define white 0
#define gray 1
#define black 2

struct vertex_t{
	int value;
	int color;
	int distance;
	struct vertex_t * predecessor;
};
struct node{
	int value;
	struct node * next;
	struct node * prev;
};
struct queue_t{
	struct node * head;
	struct node * tail;
};
void enqueue(struct queue_t * q, int v){
	struct node * new = (struct node*) malloc(sizeof(struct node));
	new->value = v;
	new->next = NULL;
	new->prev = NULL;
	if(q->head==NULL){
		q->head = q->tail = new;
	}
	else{
		new->prev = q->head;
		q->head->next = new;
		q->head = new;
	}
}
int dequeue(struct queue_t * q){
	if(q->tail==NULL)
		return 0;
	else{
		int a = q->tail->value;
		struct node * tem = q->tail;
		if(q->head==q->tail){
			q->head=q->tail=NULL;
		}
		else{
			q->tail = q->tail->next;
			q->tail->prev = NULL;
		}
		free(tem);
		return a;
	}
}
void bfs(int graph[][5], int gVertex, struct vertex_t u[], int s){
	for(int i=0;i<gVertex;i++){
		u[i].color = white;
		u[i].distance = -1;
		u[i].predecessor =NULL;
	}
	u[s-1].color = gray;
	printf("%d ",s);
	u[s-1].distance = 0;
	struct queue_t q;
	q.head = q.tail = NULL;
	enqueue(&q,s);
	while(q.tail!=NULL){
		int i = dequeue(&q);
		i--;
		for(int v=0;v<gVertex;v++){
			if(graph[i][v]==0)
				continue;
			if(u[v].color==white){
				printf("%d ",u[v].value);
				u[v].color = gray;
				u[v].distance = u[i].distance+1;
				u[v].predecessor = &(u[i]);
				enqueue(&q,u[v].value);
			}
		}
		u[i].color = black;
	}
}

int main(){
	int gVertex = 5;
	struct vertex_t u[gVertex];
	for(int i=0;i<gVertex;i++){
		u[i].value = i+1;
	}
	int graph[5][5] = {{0,1,0,0,1},
					{1,0,1,1,1},
					{0,1,0,1,0},
					{0,1,1,0,1},
					{1,1,0,1,0}};
	bfs(graph,gVertex,u,5);

}
