package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;





public class MSTMinimumSpanningTree {
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	};
	static class Node implements Comparable<Node> {
		int distance, source, destination;

		Node(int source,int destination,int distance) {

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

	static FastReader userInput = new FastReader();
	static int source, cost, edges, destination,nodes;
	static Long ans ;

	static PriorityQueue<Node> priorityQueue = new PriorityQueue<>();

	static int parent[] = new int[10007];
	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);

		nodes = userInput.nextInt();
		edges = userInput.nextInt();

		for (int i = 0; i < edges; i++) {
			source = userInput.nextInt();
			destination = userInput.nextInt();
			cost = userInput.nextInt();
			priorityQueue.add(new Node(source, destination, cost));
		}

		kruskal();

	}//main method
	public static void  kruskal() {

		for (int i = 1; i <= 1000; i++)
			parent[i] = i;
		ans = 0L;
		while (priorityQueue.size() != 0) {
			Node node = priorityQueue.peek();
			priorityQueue.poll();
			int src = find(node.source);
			int des = find(node.destination);

			if (src != des) {
				parent[src] = des;
				ans += (long)node.distance;
			}
		} // queue process
		System.out.println(ans);

	}

	public static int find(int r) {
		if (parent[r] == r)
			return r;

		parent[r] = find(parent[r]);
		return parent[r];

	}

}

//-------------------------------------------------
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;





 class Main {
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	};
	static class Node implements Comparable<Node> {
		int distance, source, destination;

		Node(int source,int destination,int distance) {

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

	static FastReader userInput = new FastReader();
	static int source, cost, edges, destination,nodes;
	static Long ans ;

	static PriorityQueue<Node> priorityQueue = new PriorityQueue<>();

	static int parent[] = new int[10007];
	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);

		nodes = userInput.nextInt();
		edges = userInput.nextInt();

		for (int i = 0; i < edges; i++) {
			source = userInput.nextInt();
			destination = userInput.nextInt();
			cost = userInput.nextInt();
			priorityQueue.add(new Node(source, destination, cost));
		}

		kruskal();

	}//main method
	public static void  kruskal() {

		for (int i = 1; i <= 1000; i++)
			parent[i] = i;
		ans = 0L;
		while (priorityQueue.size() != 0) {
			Node node = priorityQueue.peek();
			priorityQueue.poll();
			int src = find(node.source);
			int des = find(node.destination);

			if (src != des) {
				parent[src] = des;
				ans += (long)node.distance;
			}
		} // queue process
		System.out.println(ans);

	}

	public static int find(int r) {
		if (parent[r] == r)
			return r;

		parent[r] = find(parent[r]);
		return parent[r];

	}

}







