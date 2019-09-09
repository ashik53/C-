package GFG;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TransFormStringDirecti {
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

	public static void main(String[] args) throws Exception {
		FastReader userInput = new FastReader();
		int line = userInput.nextInt();
		//String buffer = userInput.nextLine();
		for (int cases = 0; cases < line; cases++) {

			String str = userInput.nextLine();

			String str1, str2;
			str1 = "";
			str2 = "";
			boolean get = false;
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == ' ') {
					get = true;
				}

				if (get == false && str.charAt(i) != ' ')
					str1 += str.charAt(i);
				else if (get == true && str.charAt(i) != ' ')
					str2 += str.charAt(i);

			}
			// 100System.out.println(str1+" "+str2);
			int frequency1[] = new int[26];
			int frequency2[] = new int[26];

			if (str1.length() != str2.length()) {
				System.out.println("-1");
				continue;
			}

			for (int i = 0; i < str1.length(); i++) {
				char ch = str1.charAt(i);
				int id = (int) str1.charAt(i) - (int) 'a';
				frequency1[id] += 1;
				ch = str2.charAt(i);
				id = (int) str2.charAt(i) - (int) 'a';
				frequency2[id] += 1;
			}
			int ans = str1.length();
			for (int i = 0; i < 26; i++) {
				if (frequency1[i] != frequency2[i]) {
					ans = -1;
					System.out.println("-1");
					break;
				}
			}

			if (ans != -1) {

				int i = str1.length() - 1;

				int j = str2.length() - 1;
				while (i >= 0) {
					if (str1.charAt(i) == str2.charAt(j)) {
						i--;
						j--;
					} else
						i--;

				} // loop
				System.out.println(j + 1);

			} // process final if ans!=-1
		} // input
	}// main
}
