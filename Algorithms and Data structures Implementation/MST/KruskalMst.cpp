/*How to compile
g++ -o main main.cpp, then main
*/

//#include "stdafx.h"
#include<bits/stdc++.h>
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

int source, cost, edges, destination, ans;
int parent[1007];
int kruskal();
int findFriends(int r);

class Node {
public:
	int source,destination, distance;
	Node(int a, int b,int cost) {
		this->source = a;
		this->destination = b;
		this->distance =cost;
	}
	bool operator<(const Node x) const {
		return distance > x.distance;
	}
};
priority_queue<Node>nodeList;
int main() {


		printf("Enter total number of edges: ");
		scanf("%d",&edges);

		for (int i = 0; i < edges; i++) {
			scanf("%d%d%d",&source,&destination,&cost);
			nodeList.push({source,destination,cost});
		}

		printf("MST is %d\n",kruskal());

	}

int kruskal()
{

    for (int i = 1; i < 1007; i++)
        parent[i] = i;
    ans = 0;

    while (!nodeList.empty()) {
        Node node = nodeList.top();
        nodeList.pop();
        int src = findFriends(node.source);
        int des = findFriends(node.destination);

        if (src != des) {
            parent[src] = des;
            ans += node.distance;
        }
    } // queue process
		return ans;

	}

int findFriends(int r)
{
    if (parent[r] == r)
        return r;

    parent[r] = findFriends(parent[r]);
    return parent[r];

}



