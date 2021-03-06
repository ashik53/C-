// DijkstraWithPriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;



vector<int, int>adjList[1007];
int edges, nodes;
int costArray[1007][1007];
int inf = 1000000097;
int dijkstra(int source, int destination);
class Node {
public:
	int source, cost;
	Node(int node, int cost) {
		this->source = node;
		this->cost = cost;
	}
	bool operator<(const Node x) const {
		return cost > x.cost;
	}
};
int main()
{
	int source, destination, cost;
	puts("Enter total number of edges:");
	scanf_s("%d", &edges);
	puts("Enter edges");

	for (int i = 0; i < edges; i++) {
		scanf_s("%d%d%d", &source, &destination, &cost);
		adjList[source].push_back(destination);
		adjList[destination].push_back(source);
		costArray[source][destination] = cost;
		costArray[destination][source] = cost;
	}

	puts("Enter source and destination");
	scanf_s("%d%d", &source, &destination);
	
	int ans = dijkstra(source, destination);
	printf("Shortest path is %d\n", ans);
}
int dijkstra(int source, int destination) {
	priority_queue<Node>nodeList;
	int distance[1007];

	for (int i = 0; i < 1007; i++) distance[i] = inf;

	distance[source] = 0;

	nodeList.push(Node{distance[source],source});

	while (!nodeList.empty()) {
		Node node = nodeList.top();
		nodeList.pop();
		int currentNode = node.source;

		for (int i = 0; i < adjList[currentNode].size(); i++) {
			int neighbourNode = adjList[currentNode][i];
			int pathCostToNeighbour = costArray[neighbourNode][currentNode];
			if (distance[neighbourNode] > max(pathCostToNeighbour, distance[currentNode])) {
				distance[neighbourNode] = max(pathCostToNeighbour, distance[currentNode]);
				nodeList.push(Node{ distance[neighbourNode], neighbourNode });
			}

		} // for
	}//main loop

	return distance[destination];


}
