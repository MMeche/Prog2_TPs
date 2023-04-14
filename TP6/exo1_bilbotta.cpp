#include <time.h>
#include "../lib/graph.h"
#include <iostream>


void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */
	for(int i=0 ; i<nodeCount ;i++)
	{
		GraphNode* node =  new GraphNode(i);
		this->appendNewNode(node);
	}
	for(int i=0 ; i<nodeCount ; i++)
	{
		for(int j=0 ; j<nodeCount ; j++){
			if(adjacencies[j][i]!=0)
			{
				this->nodes[i]->appendNewEdge(this->nodes[j],adjacencies[j][i]);
			}
		}
	}
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	  */
	if(visited[first->value])
	{
		return;
	}
	nodes[nodesSize] = first;
	visited[first->value] = true;
	nodesSize++;
	Edge* current = first->edges; 
	while(current!=nullptr)
	{
		deepTravel(current->destination,nodes,nodesSize,visited);
		current = current->next;
	}
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);
	while(nodeQueue.size()!=0)
	{
		GraphNode* current_node = nodeQueue.front();
		visited[current_node->value]=true;
		if(current_node->edges!= nullptr)
		{
			Edge* current_edge = current_node->edges;
			while(current_edge->destination!=nullptr)
			{	
				nodeQueue.push(current_node->edges->destination);
				current_edge = current_edge->next;
			}
		}
		nodeQueue.pop();
	}
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
	if(visited[first->value])
	{
		return true;
	}
    visited[first->value]=true;
	Edge* current = first->edges;
	while(current !=nullptr)
	{
		detectCycle(current->destination,visited);
		current = current->next;
	}
	
	return false;
}

int main(int argc, char *argv[])
{
	int n=7;
    int** matrix = new int*[n];
    for (int i=0; i<n; ++i)
	{
        matrix[i] = new int[n];
        for (int j=0; j<n; ++j)
		{
			matrix[i][j] = (rand() % 300 - 230) / 2;
			if (matrix[i][j] < 0)
				matrix[i][j] = 0;
		}
	}
	for(int i =0; i<n;i++)
	{
		std::cout<<"[";
		for(int j=0; j<n;j++)
		{
			std::cout<<", "<<matrix[j][i];
		}
		std::cout<<"]"<<"\n";
	}

	return 0;
}
