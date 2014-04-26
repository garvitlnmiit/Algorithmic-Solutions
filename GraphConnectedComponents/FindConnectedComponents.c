#include <stdio.h>
#include <stdlib.h>

struct FinishTime
{
    int vertex;
    int ft;
    struct FinishTime *next;
};
typedef struct FinishTime FTime;

struct AdjListNode{ 

    int dest;
    struct AdjListNode* next;

};
typedef struct AdjListNode Node;
 
 
struct AdjList{

	struct AdjListNode *head; 
};


struct Graph{

	int V;
    struct AdjList* array;

};
typedef struct Graph Graph;

FTime *fTime=NULL;		// stores vertices in descending order of finish time
int *color=NULL;		
int count=0;			// total number of connected components

void DfsTVisit(Graph *, int);
void DfsTranspose(Graph *);
Graph* getTranspose(Graph *);
void DfsVisit(Graph *, int, int *);
void DFS(Graph *);
void addEdge(Graph *, int, int);
Graph* createGraph(int);
Node* newAdjListNode(int);
void freeGraph(Graph **);

// Graph utility
Node* newAdjListNode(int dest)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create graph 
Graph* createGraph(int V)
{
    Graph* graph = (Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
	{
        graph->array[i].head = NULL;
 	}
    return graph;
}

// Add edge between two vertices of a graph
void addEdge(Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 }

// Depth First Search for original graph 
void DFS(Graph *graph)
{
	int time=0, i;
	for(i=0; i<graph->V; i++)
	{
		if(color[i]==0)
			DfsVisit(graph, i, &time);
	}
}

// Depth First Search Visit for original graph
void DfsVisit(Graph *graph, int v, int *time)
{
	Node *node;
	FTime *temp;
	*time=(*time)+1;
	color[v]=1; 				// gray
	node=graph->array[v].head;
	while(node!=NULL)
	{
		if(color[node->dest]==0)
		{
				DfsVisit(graph, node->dest, time);
		}
        node=node->next;
	}
	color[v]=2; 		//black
	*time=(*time)+1;
	temp=(FTime *)malloc(sizeof(FTime));
	temp->ft=(*time);
	temp->vertex=v;
	temp->next=fTime;
	fTime=temp;
}

// Get the transpose of a graph
Graph* getTranspose(Graph* graph)
{
	int v;
	Node *ptr;
	Graph* revGraph = createGraph(graph->V);	

	for(v=0; v<graph->V; v++)
	{
		ptr = graph->array[v].head;

		while(ptr!=NULL)
		{
			addEdge(revGraph, ptr->dest, v);
			ptr=ptr->next;
		}	
	}

	return revGraph;	
}

// Depth First Search for graph transpose
void DfsTranspose(Graph *graph)
{
		while(fTime!=NULL)
		{
			if(color[fTime->vertex]==0)
            {
                printf("%d ", fTime->vertex);    
				DfsTVisit(graph, fTime->vertex);
                count++;
                printf("\n");
            }
            fTime=fTime->next;	
		}
}

// Depth First Search Visit for graph transpose
void DfsTVisit(Graph *graph, int v)
{
	Node *node;
	FTime *temp;
	color[v]=1; 				// gray
	node=graph->array[v].head;

	while(node!=NULL)
	{
		if(color[node->dest]==0)
		{
            printf("%d ", node->dest);
			DfsTVisit(graph, node->dest);
		}
        node=node->next;
	}
    
	color[v]=2; 		//black

}

void freeGraph(Graph **graph)
{
	int i=0;
	Node *node, *tnode;
	Graph *temp;
	temp=*graph;
	
	for(i=0; i<temp->V; i++)
	{
		node = temp->array[i].head;
		while(node!=NULL)
		{
			tnode=node->next;
			free(node);
			node=tnode;
		}
	}
	free(temp->array);
	free(*graph);
	*graph=NULL;
}
 
// Driver program
int main()
{
	int V=7, i;
	FTime *temp;
	fTime=NULL;

	color=(int*)calloc(V, sizeof(int));

	Graph* graph = createGraph(V);

	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 0);
	addEdge(graph, 1, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);

	DFS(graph);
	
    for(i=0; i<V; i++)
        color[i]=0;

	Graph *revGraph=getTranspose(graph);

	DfsTranspose(revGraph);

    printf("Total Connected Components %d\n", count);
	
	freeGraph(&graph);
	freeGraph(&revGraph);
	free(color);
	while(fTime!=NULL)
	{
		temp=fTime->next;
		free(fTime);
		fTime=temp;
	}
	
	return 0;
}
