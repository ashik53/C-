package BackTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class SimplePermutationOfaString {

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

	static FastReader userInput = new FastReader();
	static int ara[] = new int[30];

	public static void main(String[] args) {

		int cases = 1;
		while (true) {
			int size;
			size = userInput.nextInt();
			boolean taken[] = new boolean[100];
			for (int i = 0; i < 100; i++) {
				taken[i] = false;
			}
			for (int i = 2; i <= size; i++) {
				ara[i - 2] = i;
			}
			ArrayList<Integer> ring = new ArrayList<Integer>();
			ring.add(1);
			System.out.println("Case "+cases+":");
			per(ring, size, taken,1);
			cases++;
		} // cases
	}

	public static void per(ArrayList<Integer> ring, int size, boolean taken[],int len) {
		if (len == size) {
			if (primeChecking(1 + ring.get(size - 1))) {
            
				for (int j = 0; j < size; j++) {
					if (j == size - 1) {
						System.out.println(ring.get(j));
					} else
						System.out.print(ring.get(j) + " ");
				}

				return;
			}

		}

		for (int i = 0; i < size - 1; i++) {
			int sum = ring.get(len - 1);
			sum += ara[i];
			if (primeChecking(sum) == true) {
				if (taken[ara[i]] == false) {
					ring.add(ara[i]);
					taken[ara[i]] = true;
					per(ring, size, taken,len+1);
					taken[ara[i]] = false;
					ring.remove(len);
				}
			}

		}
	}

	public static boolean primeChecking(int sum) {

		if (sum == 2 || sum == 3 || sum == 5 || sum == 7 || sum == 11 || sum == 13 ||

				sum == 17 || sum == 19 || sum == 23 || sum == 29 || sum == 31 || sum == 37) {

			return true;
		}

		return false;
	}
}
