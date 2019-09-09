package Codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Codeforces805B {
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
	static char ara[] = new char[200008];

	public static void main(String[] args) {
		// while(true) {
		ara[0] = 'a';
		ara[1] = 'b';
		ara[2] = 'b';
		int n = userInput.nextInt();
		if (n == 1)
			System.out.println("a");
		else if (n == 2)
			System.out.println("ab");
		else if (n == 3)
			System.out.println("abb");
		else if (n > 3) {
			System.out.print(ara[0]);
			System.out.print(ara[1]);
			System.out.print(ara[2]);

			for (int i = 3; i < n; i++) {
				if (ara[i - 2] == 'a') {
					ara[i] = 'b';
					System.out.print('b');
				} else {
					ara[i] = 'a';
					System.out.print('a');
				}
			}

		} // else
		// }//while
	}
}
