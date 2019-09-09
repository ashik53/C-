package TopSort;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class TopSort {
	static HashSet<Integer> nodeList = new HashSet<>();
	static int[] inDegree = new int[1007];
	static ArrayList<Integer>[] adjList = (ArrayList<Integer>[]) new ArrayList[1007];
	static ArrayList<Integer> list = new ArrayList<Integer>();
	static int edges, nodes;
	static HashMap<String, Integer> keyValue = new HashMap<String, Integer>();
	static String[] valueKey = new String[1007];
	static Scanner userInput = new Scanner(System.in);

	public static void main(String[] args) {

		for (int i = 0; i < 1007; i++)
			adjList[i] = new ArrayList<Integer>();
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

	}// main method

	public static void topsort() {
		while (list.size() != 0) {
			for (int i = 0; i < list.size(); i++) {
				int node = list.get(i);
				if (inDegree[node] == 0) {
					System.out.println(valueKey[node]);
					list.remove(i);
					for (int j = 0; j < adjList[node].size(); j++)
						inDegree[adjList[node].get(j)] -= 1;
					break;

				} // if

			} // for
		} // while

	}// topsort

}
