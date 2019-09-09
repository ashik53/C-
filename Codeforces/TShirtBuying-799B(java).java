import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

public class Codeforces799B {
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

	public static void main(String[] args) {
		FastReader userInput = new FastReader();
		int numberOfShirts, numberOfCustomers;
		ArrayList<Integer> priceList = new ArrayList<>();
		ArrayList<Integer> customerList = new ArrayList<>();
		TreeSet<Integer>[] frontProcessingSet = (TreeSet<Integer>[]) new TreeSet[4];
		TreeSet<Integer>[] backProcessingSet = (TreeSet<Integer>[]) new TreeSet[4];

		// initialization
		for (int i = 0; i < 4; i++) {
			frontProcessingSet[i] = new TreeSet<Integer>();
			backProcessingSet[i] = new TreeSet<Integer>();
		}

		// input
		numberOfShirts = userInput.nextInt();
		for (int i = 0; i < numberOfShirts; i++) {
			int price = userInput.nextInt();
			priceList.add(price);
		}
		for (int i = 0; i < numberOfShirts; i++) {
			int color = userInput.nextInt();
			frontProcessingSet[color].add(priceList.get(i));
		}
		for (int i = 0; i < numberOfShirts; i++) {
			int color = userInput.nextInt();
			backProcessingSet[color].add(priceList.get(i));
		}

		// customer
		numberOfCustomers = userInput.nextInt();
		for (int i = 0; i < numberOfCustomers; i++) {
			int color = userInput.nextInt();
			customerList.add(color);
		}

		// output processing
		for (int i = 0; i < numberOfCustomers; i++) {
			int color = customerList.get(i);
			// System.out.println(color+"->");
			int front = -1;
			int back = -1;
			if (frontProcessingSet[color].size() != 0) {
				front = Math.max(front, frontProcessingSet[color].first());
			}
			if (backProcessingSet[color].size() != 0) {
				back = Math.max(back, backProcessingSet[color].first());
			}

			// System.out.println("fb->"+front+","+back);
			if (front == -1) {
				System.out.print(back + " ");
				// System.out.println(" +removed");
				for (int index = 0; index < 4; index++) {
					frontProcessingSet[index].remove(back);
					backProcessingSet[index].remove(back);
				}
			} else if (back == -1) {
				System.out.print(front + " ");
				// System.out.println(" ,removed");
				for (int index = 0; index < 4; index++) {
					frontProcessingSet[index].remove(front);
					backProcessingSet[index].remove(front);
				}
			} else {

				System.out.print(Math.min(front, back) + " ");

				// System.out.println(" :removed");
				for (int index = 0; index < 4; index++) {
					frontProcessingSet[index].remove((Math.min(front, back)));
					backProcessingSet[index].remove((Math.min(front, back)));
				}

			}

			// System.out.println();
		} // output
		System.out.println();
	}// main

}