package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

import UVA.UVA524.FastReader;

public class UVA10305TopSort {
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

	//static FastReader userInput = new FastReader();
	static Scanner userInput = new Scanner(System.in);
	static HashSet<Integer> nodeList = new HashSet<>();
	static int[] inDegree = new int[1007];
	static ArrayList<Integer>[] adjList = (ArrayList<Integer>[]) new ArrayList[1007];
	static ArrayList<Integer> list = new ArrayList<Integer>();
	static int edges, nodes;

	public static void main(String[] args) {

		while (true) {
			for (int i = 1; i <= nodes; i++)
				adjList[i] = new ArrayList<Integer>();
			nodes = userInput.nextInt();
			edges = userInput.nextInt();
            if(nodes==0 && edges ==0) break;
			for (int i = 1; i <= nodes; i++) {
				adjList[i] = new ArrayList<Integer>();
				nodeList.add(i);
				inDegree[i] = 0;
			}

			for (int i = 0; i < edges; i++) {
				int source = userInput.nextInt();
				int des = userInput.nextInt();
				adjList[source].add(des);
			}

			// -----------------in degree counting
			Iterator<Integer> itr = nodeList.iterator();
			list.clear();
			while (itr.hasNext()) {
				int parentNode = itr.next();
				list.add(parentNode);
				for (int i = 0; i < adjList[parentNode].size(); i++) {
					inDegree[adjList[parentNode].get(i)] += 1;
				}
			}
			topsort();
		} // cases
	}// main method

	public static void topsort() {
		while (list.size() != 0) {
			for (int i = 0; i < list.size(); i++) {
				int node = list.get(i);
				if (inDegree[node] == 0) {
					System.out.print(node + " ");
					list.remove(i);
					for (int j = 0; j < adjList[node].size(); j++)
						inDegree[adjList[node].get(j)] -= 1;
					break;

				} // if

			} // for
		} // while
		System.out.println();

	}// topsort

}
