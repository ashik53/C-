package TopSort;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class TopSortUsingDFS {
	static class Node implements Comparable<Node> {
		int finishTime, source;

		Node(int finishTime, int source) {
			this.finishTime = finishTime;
			this.source = source;
		}

		public int compareTo(Node node) {
			if (finishTime < node.finishTime)
				return 1;
			else if (finishTime > node.finishTime)
				return -1;
			return 0;
		}

	};

	static HashSet<Integer> nodeList = new HashSet<>();
	static int[] finishTime = new int[1007];
	static int[] vis = new int[1007];
	static ArrayList<Integer>[] adjList = (ArrayList<Integer>[]) new ArrayList[1007];
	static PriorityQueue<Node> pq;
	static int edges, nodes, time;
	static HashMap<String, Integer> keyValue = new HashMap<String, Integer>();
	static String[] valueKey = new String[1007];
	static Scanner userInput = new Scanner(System.in);

	public static void main(String[] args) {
		// vis
		for (int i = 0; i < 1006; i++) {
			adjList[i] = new ArrayList<Integer>();
			vis[i] = 0;
		}
		System.out.println("Enter total number of edges");
		edges = userInput.nextInt();
		String getChar = userInput.nextLine();
		int count = 0;
		for (int i = 0; i < edges; i++) {
			String str = userInput.nextLine();
			String parent = "";
			String child = "";
			int j = 0;
			for (;; j++) {
				if (str.charAt(j) == ' ') {
					break;
				}
				parent += str.charAt(j);
			}
			j++;
			for (; j < str.length(); j++) {

				child += str.charAt(j);
			}
			// System.out.println(parent+" "+child);
			if (keyValue.get(parent) == null) {
				count++;
				keyValue.put(parent, count);
			}
			if (keyValue.get(child) == null) {
				count++;
				keyValue.put(child, count);
			}
			nodeList.add(keyValue.get(parent));
			nodeList.add(keyValue.get(child));
			valueKey[keyValue.get(parent)] = parent;
			valueKey[keyValue.get(child)] = child;
			adjList[keyValue.get(parent)].add(keyValue.get(child)); // insert parent's child nodes

		} // loop

		// -----------------in-degree counting
		time = -1;
		Iterator<Integer> itr = nodeList.iterator();

		pq = new PriorityQueue<>();
		while (itr.hasNext()) {
			int n = itr.next();
			if (vis[n] == 0) {
				topsort(n);
			}
		}

		Iterator<Integer> itr1 = nodeList.iterator();

		while (itr1.hasNext()) {
			int n = itr1.next();
			//System.out.println(valueKey[n] + "->" + finishTime[n]);
		}

		Iterator<Node> pqItr = pq.iterator();

		while (pq.size()!=0) {
			Node n = pq.poll();
			System.out.println("node: " + valueKey[n.source] + ", time ->" + n.finishTime);

		}

	}// main method

	// trying to implement topSort by dfs
	public static void topsort(int node) {
		time++;
		vis[node] = 1;
		// System.out.println(valueKey[node]);
		for (int i = 0; i < adjList[node].size(); i++) {

			if (vis[adjList[node].get(i)] == 0) {
				topsort(adjList[node].get(i));
			}
		}
		time += 1;
		finishTime[node] = time;
		// System.out.print("work->"+valueKey[node]+"->");
		// System.out.println(time);
		pq.add(new Node(time, node));
	}// topsort

}
