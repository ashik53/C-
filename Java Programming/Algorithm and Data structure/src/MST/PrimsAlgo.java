package MST;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;






public class PrimsAlgo {
	static class Node  implements Comparable<Node>{
		int distance, source;

		Node(int distance, int source) {
			this.distance = distance;
			this.source = source;
		}
		
		public int compareTo(Node node) {
			 if(distance>node.distance) return 1;
			 else if(distance<node.distance) return -1;
			 return 0;
		}
   	
	};

	
	
	static int source, cost, edges, destination;
	static int[] id = new int[1007];
	static int[] distance = new int[1007];
	static int inf = 1000000000;
	static int[] vis = new int[1007];
	static ArrayList<Integer>[] adjList = (ArrayList<Integer>[]) new ArrayList[1007];
	static PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
	
	static TreeSet<Integer> nodeList = new TreeSet<Integer>();
	static int[][] costArray = new int[1007][1007];
	static int ans;

	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);

		//while (true) {// every cases
			for (int i = 0; i < 1007; i++) {
				for (int j = 0; j < 1007; j++) {
					costArray[i][j] = 0;
				}
				id[i] = -1;
				adjList[i] = new ArrayList<Integer>();
				distance[i] = inf;
				vis[i] = 0;
			}
			System.out.println("Enter total nubmer of edges: ");
			edges = userInput.nextInt();
			for (int i = 0; i < edges; i++) {
				source = userInput.nextInt();
				destination = userInput.nextInt();
				cost = userInput.nextInt();
				adjList[destination].add(source);
				adjList[source].add(destination);
				costArray[destination][source] = cost;
				costArray[source][destination] = cost;
				nodeList.add(source);
				nodeList.add(destination);
			}
		while(true) { 	
			for (int i = 0; i < 1007; i++) {
				
				id[i] = -1;
	
				distance[i] = inf;
				vis[i] = 0;
			}
			System.out.println("Enter source node");
			source = userInput.nextInt();
			ans = 0;
			prim(source);
            
			Iterator<Integer> itr = nodeList.iterator();
			while (itr.hasNext()) {
				int node = itr.next();
			//	System.out.println("node " + node + "->" + distance[node]);
                ans+= distance[node];
			}
			//System.out.println();

			System.out.println(ans);

		} // every cases
	}// main method

	public static void prim(int source) {
		priorityQueue = new PriorityQueue<>();
		distance[source] = 0;
		priorityQueue.add(new Node(distance[source], source));
		// ans = 0;
		while (priorityQueue.size() != 0) {// 14
			
			Node node =  priorityQueue.peek();
			priorityQueue.poll(); // delete first Node
			int currentNode = node.source;
			//System.out.println("current node->" + currentNode + ": distance ->" + node.distance);
			vis[currentNode] += 1;
			// ans += distance[currentNode];
			if (vis[currentNode] == 1) {
				for (int i = 0; i < adjList[currentNode].size(); i++) {
					int neighbourNode = adjList[currentNode].get(i);
					/*System.out.println("child node = " + neighbourNode);
					//System.out.println("present distance : " + currentNode + "->" + neighbourNode + "  -cost->"
							+ costArray[currentNode][neighbourNode]);
					System.out.println("previous distance = " + distance[neighbourNode]); */

					int pathCostToTheNeighbour = costArray[currentNode][neighbourNode];
					if (distance[neighbourNode] > pathCostToTheNeighbour && vis[neighbourNode] == 0) {
						distance[neighbourNode] = pathCostToTheNeighbour;
						id[neighbourNode] = currentNode;
						Node n = new Node(pathCostToTheNeighbour, neighbourNode);
						priorityQueue.add(n);
						/*System.out.println("new node - " + neighbourNode + ", cost = " + pathCostToTheNeighbour+ " niye queue te add holo");
					     System.out.println();
						int src = -1, d = -1;
						//all elements printing priorityQueue
							src = priorityQueue.peek().source;
							d = priorityQueue.peek().distance;
							System.out.println("all present node in Queue----");
							for(Node x:priorityQueue) {
								System.out.println(x.source+" "+x.distance);
							}
							
							System.out.println("-----"); */
							
						
					}
					

				} // for
				//System.out.println();
			}
		} // while
	}// prim algo
}
