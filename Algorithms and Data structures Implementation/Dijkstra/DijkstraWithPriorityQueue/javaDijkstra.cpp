

public class KruskalAlgorithmImplementation {

	static class Node implements Comparable<Node> {
		int distance, source, destination;

		Node(int source, int destination, int distance) {

			this.source = source;
			this.destination = destination;
			this.distance = distance;
		}

		public int compareTo(Node node) {
			if (distance > node.distance)
				return 1;
			else if (distance < node.distance)
				return -1;
			return 0;
		}

	};

	static int source, cost, edges, destination, ans;

	static PriorityQueue<Node> priorityQueue = new PriorityQueue<>();

	static int parent[] = new int[1007];

	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);

		System.out.println("Enter total nubmer of edges: ");
		edges = userInput.nextInt();

		for (int i = 0; i < edges; i++) {
			source = userInput.nextInt();
			destination = userInput.nextInt();
			cost = userInput.nextInt();
			priorityQueue.add(new Node(source, destination, cost));
		}

		System.out.println("MST is " + kruskal());

	}

	public static int kruskal() {

		for (int i = 1; i <= 1000; i++)
			parent[i] = i;
		ans = 0;
		while (priorityQueue.size() != 0) {
			Node node = priorityQueue.peek();
			priorityQueue.poll();
			int src = find(node.source);
			int des = find(node.destination);

			if (src != des) {
				parent[src] = des;
				ans += node.distance;
			}
		} // queue process
		return ans;

	}

	public static int find(int r) {
		if (parent[r] == r)
			return r;

		parent[r] = find(parent[r]);
		return parent[r];

	}
}
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
int parent[1007];
int source, cost, edges, destination, ans;

class Node {
public:
	int source,destination, cost;
	Node(int a,int b, int cost) {
		this->source = a;
		this->destination = b;
		this->cost = cost;
	}
	bool operator<(const Node x) const {
		return cost > x.cost;
	}
};
priority_queue<Node>nodeList;
int main()
{


		printf("Enter total number of edges: ");
		scanf("%d",&edges);

		for (int i = 0; i < edges; i++) {

			scanf("%d%d%d",&source,&destination,&cost);
			nodeList.push(Node{source, destination, cost});
		}

		printf("MST is %d\n" + kruskal());
}

int kruskal() {

		for (int i = 1; i <= 1007; i++)
			parent[i] = i;
		ans = 0;
		while (nodeList.empty()) {
			Node node = nodeList.top();
			nodeList.pop();
			int src = parentFinding(node.source);
			int des = parentFinding(node.destination);

			if (src != des) {
				parent[src] = des;
				ans += node.distance;
			}
		} // queue process
		return ans;

	}

	public static int find(int r) {
		if (parent[r] == r)
			return r;

		parent[r] = find(parent[r]);
		return parent[r];

	}
