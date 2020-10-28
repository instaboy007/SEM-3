#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class AdjListNode
{
	public:
	int dest;
	AdjListNode* next;
};
class AdjList
{
    public:
    AdjListNode *head;
};
class Graph
{
	public:
	int V;
	AdjList* array;
};
AdjListNode* newAdjListNode(int dest)
{
	AdjListNode* newNode=new(AdjListNode);
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}
Graph* createGraph(int V)
{
	Graph* graph =new(Graph);
	graph->V = V;

	graph->array =new(AdjList);

	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
	AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void AdjacentVertices(Graph *graph,int vertex)
{
    AdjListNode* temp = graph->array[vertex].head;
    cout<<"\nAdjacent nodes of vertex "<<vertex<<":";
    while (temp)
    {
        cout<<temp->dest<<",";
        temp = temp->next;
    }
    cout<<endl;
}
void VerticesDegree(Graph *graph, int degree)
{
    for (int i=0; i<graph->V; i++)
    {
        int tempdegree = 0;
        AdjListNode* temp = graph->array[i].head;
        while (temp)
        {
            tempdegree++;
            temp = temp->next;
        }
        if(degree==tempdegree)
        {
            cout<<"Vertex "<<i<<endl;
        }
    }
}
int SumDegree(Graph *graph)
{
    int degree = 0;
    for (int i=0; i<graph->V; i++)
    {
        AdjListNode* temp = graph->array[i].head;
        while (temp)
        {
            degree++;
            temp = temp->next;
        }
    }
    return degree;
}
void Path(Graph *graph,int vertex1,int vertex2)
{
    int flag1=0,flag2=0;
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* temp = graph->array[v].head;
        while (temp)
        {
            if(temp->dest==vertex1)
            {
                flag1=1;
            }
            if(temp->dest==vertex2)
            {
                flag2=1;
            }
            temp = temp->next;
        }
    }
    if(flag1==1 && flag2==1)
    {
        cout<<"Path exists\n";
    }
    else
    {
        cout<<"Path doesn't exist\n";
    }
}
void DFT(Graph *graph,int vertex)
{
    // Initially mark all verices as not visited
    bool* visited = new bool[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node.
    stack.push(vertex);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        vertex = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[vertex])
        {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        AdjListNode* temp = graph->array[vertex].head;
        while (temp)
        {
             if (!visited[temp->dest])
                stack.push(temp->dest);
            temp = temp->next;

        }
    }
}
void BFT(Graph *graph,int vertex)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[graph->V];
    for(int i = 0; i < graph->V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vertex] = true;
    queue.push_back(vertex);

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        vertex = queue.front();
        cout << vertex << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        AdjListNode* temp = graph->array[vertex].head;
        while (temp)
        {
             if (!visited[temp->dest])
                queue.push_back(temp->dest);
            temp = temp->next;

        }
    }
}
int main()
{
	int V,n;
	cout<<"Enter number of vertices.....";
	cin>>V;
	Graph* graph = createGraph(V);
	l1:cout<<"1)Enter vertice\n";
	cout<<"2)Find the vertices adjacent to a given vertex\n";
	cout<<"3)Find vertices of a particular degree\n";
	cout<<"4)Find the sum of degree of all vertices\n";
	cout<<"5)Find whether a vertex has a path to another vertex\n";
	cout<<"6)Depth first traversal\n";
	cout<<"7)Breadth first traversal\n";
	cout<<"Choice:";
	cin>>n;
	if(n==1)
    {
        int source,sub;
        l2:cout<<"Enter the source vertex...";
        cin>>source;
        if(source>=graph->V)
        {
           cout<<"Source should be between 0 and "<<graph->V-1<<endl;
           goto l2;
        }
        cout<<"Enter the sub-vertex...";
        cin>>sub;
        addEdge(graph,source,sub);
        goto l1;
    }
    if(n==2)
    {
        int vertex;
        cout<<"Enter the vertex....";
        cin>>vertex;
        AdjacentVertices(graph,vertex);
        goto l1;
    }
    if(n==3)
    {
        int degree;
        cout<<"Enter the degree..";
        cin>>degree;
        VerticesDegree(graph,degree);
        goto l1;
    }
    if(n==4)
    {
        cout<<SumDegree(graph)<<endl;
        goto l1;
    }
    if(n==5)
    {
        int vertex1,vertex2;
        cout<<"Enter vertex 1...";
        cin>>vertex1;
        cout<<"Enter vertex 2...";
        cin>>vertex2;
        Path(graph,vertex1,vertex2);
        goto l1;
    }
    if(n==6)
    {
        int vertex;
        cout<<"Enter the vertex....";
        cin>>vertex;
        DFT(graph,vertex);
        cout<<endl;
        goto l1;
    }
    if(n==7)
    {
        int vertex;
        cout<<"Enter the vertex....";
        cin>>vertex;
        BFT(graph,vertex);
        cout<<endl;
        goto l1;
    }
}