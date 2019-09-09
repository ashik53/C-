package HackerRank;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ThePowerSumBacktracking {
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
	static int ara[] = new int[1001];
	static int count;
	static boolean taken[] = new boolean[1001];

	public static void main(String[] args) {

		int number = userInput.nextInt();
		int high = userInput.nextInt();
		int size = 0;

		for (int i = 1; i <= number; i++) {
			int value = power(i, high);
			if (value > number) {
				size = i - 1;
				break;
			}
			ara[i - 1] = i;
			//System.out.println(ara[i-1]+"->"+(i-1));
		}
  
		for (int i = 0; i < size; i++) {
			taken[i] = false;
		}

		count = 0;
		backtracking(0, number, size, high);
		System.out.println(count);

	}

	public static void backtracking(int sum, int number, int size, int high) {
		if (sum == number) {
			count++;
			return;
		}

		for (int i = 0; i < size; i++) {
			int value = power(ara[i], high);
			if (sum + value <= number && taken[i] == false) {
				sum += value;
                taken[i] = true;
                backtracking(sum, number, size, high);
                taken[i] = false;
                sum-=value;
			}
			
			else break;

			
		}

	}

	public static int power(int number, int limit) {
		int value = 1;

		for (int i = 1; i <= limit; i++) {
			value *= number;
		}
		return value;
	}

}
