package Dijkstra;



import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;


public class Dijkstra {
	static class Node {
		int distance, source;

		Node(int distance, int source) {
			this.distance = distance;
			this.source = source;
		}

	}

	static TreeSet<Node> nodeList = new TreeSet<Node>(new DistanceComparator());
	static int[] distance = new int[1007];
	static ArrayList<Integer>[] adjList = (ArrayList<Integer>[]) new ArrayList[1007];
	static int edges, nodes;

	static int[][] costArray = new int[1007][1007];
	static int inf = 1000000000;

	public static int dijkstra(int source, int destination) {

		for (int i = 0; i < 1007; i++) {
			distance[i] = inf;
		}

		distance[source] = 0;

		nodeList.add(new Node(distance[source], source));

		while (nodeList.size() != 0) {

			Node node = nodeList.first();
			nodeList.pollFirst();
			int currentNode = node.source;

			for (int i = 0; i < adjList[currentNode].size(); i++) {
				int neighbourNode = adjList[currentNode].get(i);
				int pathCostToNeighbour = costArray[neighbourNode][currentNode];
				if (distance[neighbourNode] > Math.max(pathCostToNeighbour, distance[currentNode])) {
					distance[neighbourNode] = Math.max(pathCostToNeighbour, distance[currentNode]);
					nodeList.add(new Node(distance[neighbourNode], neighbourNode));
				}

			} // for

		} // while

		return distance[destination];

	}

	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);
		

		int source, destination, cost;
		System.out.println("Enter total number of edges: ");
		edges = userInput.nextInt();
		System.out.println("Enter edges: ");
		for (int i = 0; i < edges; i++) {
			source = userInput.nextInt();
			destination = userInput.nextInt();
			cost = userInput.nextInt();
			adjList[destination].add(source);
			adjList[source].add(destination);
			costArray[source][destination] = cost;
			costArray[destination][source] = cost;
		}
		System.out.println("Enetr source and destination");
		source = userInput.nextInt();
		destination = userInput.nextInt();

		System.out.println("Shortest path is : " + dijkstra(source, destination));

	}

	static class DistanceComparator implements Comparator {

		@Override
		public int compare(Object o1, Object o2) {
			Node n1 = (Node) o1;
			Node n2 = (Node) o2;

			if (n1.distance == n2.distance)
				return 0;
			else if (n1.distance > n2.distance)
				return 1;

			return -1;

		}

	};

}