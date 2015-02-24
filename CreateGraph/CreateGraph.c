//Graph using adjacency list

#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int v;
	struct AdjList *array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int v)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->v = v;
	graph->array = (struct AdjList*)malloc(v * sizeof(struct AdjList));

	int i;

	for(i=0; i<v; i++) {
		graph->array[i].head = NULL;
	}

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* newNode;
	newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
}

void printGraph(struct Graph *graph)
{
	int i, v=graph->v;
	struct AdjListNode *head;

	for(i=0; i<v; i++){
		printf("%d -> ", i);
		head = graph->array[i].head;		
		while(head!=NULL){
			printf("%d ", head->dest);
			head=head->next;
		}
		printf("\n");
	}
}

int main()
{
	int v=5;
	struct Graph* graph = createGraph(v);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);
	
	return 0;
}
