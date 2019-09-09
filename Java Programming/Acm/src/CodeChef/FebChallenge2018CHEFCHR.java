package CodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class FebChallenge2018CHEFCHR {
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

	public static void main(String[] args) {
		
		int line;
		
		line = userInput.nextInt();
		for (int cases = 0; cases < line; cases++) {
			
			String input = userInput.nextLine();
			int len = input.length();
			int lovely = 0;
			String str = "";
			
			for (int i = 0; i < len; i++) {
				str += input.charAt(i);
				if (i >= 3) {
					if (lovelyStringChecking(str) == true) {
						lovely++;
					}
					str = str.substring(1);
				}

			}

			if (lovely == 0)
				System.out.println("normal");
			else
				System.out.println("lovely " + lovely);
		}
	}// main method

	public static boolean lovelyStringChecking(String str) {
		HashMap<Character, Integer> count = new HashMap<Character, Integer>();
		count.put('c', 0);
		count.put('h', 0);
		count.put('e', 0);
		count.put('f', 0);

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'c' || str.charAt(i) == 'h' || str.charAt(i) == 'e' || str.charAt(i) == 'f') {
				int sum = count.get(str.charAt(i));
				count.put(str.charAt(i), sum + 1);
			}
		}
		if (count.get('c') == 1 && count.get('h') == 1 && count.get('e') == 1 && count.get('f') == 1)
			return true;
		return false;
	}

}
