package CodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class MaximumScoreJan18B {
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

	static ArrayList<Integer>[] elementList = (ArrayList<Integer>[]) new ArrayList[707];
	//static FastReader userInput = new FastReader();
	static Scanner userInput = new Scanner(System.in);
	public static void main(String[] args) {
		int cases, size;
		cases = userInput.nextInt();
		for (int line = 1; line <= cases; line++) {
			size = userInput.nextInt();
			for (int j = 0; j <= size; j++) {
				elementList[j] = new ArrayList<Integer>();
			} // make memory free

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					elementList[i].add(userInput.nextInt());
				}
			} // take all inputs

			// ------------------output processing
			// first sort so that binarySearch can be applied
			for (int i = 0; i < size; i++) {
				Collections.sort(elementList[i]);
			}
			// traverse the whole 2-d arrayList from behind
			int element = elementList[size - 1].get(size - 1);
			Long addValue = (long) element;
			for (int i = size - 2; i >= 0; i--) {
				
				//System.out.print("prev->"+element);
				element = binarySearch(element, i, size);
				//System.out.println(", pre->"+element);
				if(element==-1) {
					addValue = (long)-1;
					break;
				}
				addValue +=  (long) element;
			}
			
			 System.out.println(addValue);
			
		} // cases
	}// main

	public static int binarySearch(int element, int index, int size) {
		int began = 0;
		int end = size - 1;

		while (began <= end) {
			int mid = (began + end) / 2;
			if (elementList[index].get(mid) >= element) {
				end = mid - 1;
			} else {
				began = mid + 1;
			}
		} // search algo
		if (end < 0)
			return -1;
		return elementList[index].get(end);
	}
}
