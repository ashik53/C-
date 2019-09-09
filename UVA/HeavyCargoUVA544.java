package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
public class HeavyCargoUVA544 {
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

		Node(int source, int destination, int distance) {

			this.source = source;
			this.destination = destination;
			this.distance = distance;
		}

		public int compareTo(Node node) {
			if (distance > node.distance)
				return -1;
			else if (distance < node.distance)
				return 1;
			return 0;
		}

	};
	
	static FastReader userInput = new FastReader();
	static HashMap<String, Integer> keyValue = new HashMap<String, Integer>();
	static String valueKey[]= new String[207];
	static PriorityQueue<Node>priorityQueue = new PriorityQueue<Node>();
    static int parent[] = new int[207];
    static int vis[] = new int[207];
    static int True = 0;
    
    static ArrayList<Integer>[]adjList = (ArrayList<Integer>[]) new ArrayList[207];
	public static void main(String[] args) {
		int line = 1;
		while (true) {
			int nodes = userInput.nextInt();
			int edges = userInput.nextInt();
			if (nodes == 0 && edges == 0)
				break;
			int count = 0;
			for(int i=0;i<207;i++) {
				parent[i] = i;
				valueKey[i] = null;
				adjList[i] = new ArrayList<Integer>();
			}
			priorityQueue = new PriorityQueue<Node>();
			keyValue.clear();
			for (int e = 0; e < edges; e++) {
				String srcString = userInput.next();
				String desString = userInput.next();
				int cost = userInput.nextInt();
                if(keyValue.get(srcString)==null) {
                	count++;
                	keyValue.put(srcString,count);
                	valueKey[count] = srcString;
                	
                }
                if(keyValue.get(desString)==null) {
                	count++;
                	keyValue.put(desString,count);
                	valueKey[count] = desString;
                }
                
               priorityQueue.add(new Node(keyValue.get(srcString),keyValue.get(desString),cost)); 
                
			}//all edges input
			
			String source = userInput.next();
			String destination = userInput.next();
			System.out.println("Scenario #"+(line) );
			System.out.println(solve(keyValue.get(source),keyValue.get(destination))+" tons\n\n");
			line++;

		} // cases

	}
	public static int solve(int source, int destination) {
		
		int count = 0;
		int ans = 1000000000;
		while(priorityQueue.size()!=0 ) {
			Node node = priorityQueue.peek();
		    priorityQueue.poll();
		    int a = find(node.source);
		    int b  = find(node.destination);
		    adjList[node.source].add(node.destination);
		    adjList[node.destination].add(node.source);
		    if(a!=b) {
		    	parent[a] = b;
		    	//System.out.println(valueKey[a]+" "+valueKey[b]);
		    	ans = Math.min(node.distance,ans);
		    }
		   
		    if(bfs(source,destination)==true) return ans;
		}
		
		return ans;
	}
	public static int find(int r) {
		if(parent[r]==r) return r;
		parent[r] = find(parent[r]);
		return parent[r];
	}
	
	public static boolean bfs(int source,int destination) {
		 True++;
		 Queue<Integer>queue = new LinkedList<Integer>();
		 
		 queue.add(source);
		 vis[source] = True;
		 while(queue.isEmpty()==false) {
			 int front = queue.peek();
			 if(front==destination) return true;
			 queue.poll();
			 
			 for(int i=0;i<adjList[front].size();i++) {
				 int next = adjList[front].get(i);
				 if(vis[next]!=True) {
					 queue.add(next);
					 vis[next] = True;
				 }
			 }
		 }
		 
		 return false;
		 
	}

}
