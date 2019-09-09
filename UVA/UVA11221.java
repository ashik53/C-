package UVA;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.StringTokenizer;

import java.util.HashMap;

public class UVA11221 {

	static PrintWriter out;

	static class Reader {
		BufferedReader br;
		StringTokenizer st;

		public Reader() {
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

	static char[][] grid = new char[110][110];

	public static void main(String[] args) throws IOException {
		String str;
		Reader userInput = new Reader();
		out = new PrintWriter(new BufferedOutputStream(System.out), true);

		int line = userInput.nextInt();

		for (int cases = 1; cases <= line; cases++) {
			str = "";
			String s = userInput.nextLine();

			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
				if (ch == '?' || ch == '!' || ch == '.' || ch == ',' || ch == ' ' || ch == '(' || ch == ')' || ch == '['
						|| ch == ']' || ch == '{' || ch == '}') {
					continue;
				}
				str += s.charAt(i);
			}

			out.print("Case #" + "" + cases + ":\n");

			int k = (int) Math.sqrt(str.length());
			if (k * k != str.length()) {
				out.print("No magic :(\n");
				continue;
			}
			int index = 0;
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					grid[i][j] = str.charAt(index);
					index++;
				}
			}

			if (magicChecking(k, str))
				out.print(k + "\n");
			else
				out.print("No magic :(\n");

		} // cases
		out.close();
	}// main

	public static boolean magicChecking(int k, String str) {
		int index = 0;

		// traverse from 1,1 to right
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (str.charAt(index) != grid[i][j]) {
					return false;
				}
				index++;
			}
		}
		// traverse from 1,1 to bottom
		index = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (str.charAt(index) != grid[j][i]) {
					return false;
				}
				index++;
			}
		}
		// traverse (k,k) to left
		index = 0;
		for (int i = k - 1; i >= 0; i--) {
			for (int j = k - 1; j >= 0; j--) {
				if (str.charAt(index) != grid[i][j]) {
					return false;
				}
				index++;
			}
		}

		// traverse (k,k) to up
		index = 0;
		for (int i = k - 1; i >= 0; i--) {
			for (int j = k - 1; j >= 0; j--) {
				if (str.charAt(index) != grid[j][i]) {
					return false;
				}
				index++;
			}
		}

		return true;

	}// method
}
