package CodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class ChefAndThePatentsFebChallenge2018CHEFPTNT {

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

		int cases = userInput.nextInt();
		for (int line = 1; line <= cases; line++) {

			int numberOfPatents, months, limitOfWorkers, availableWorkers, oddWorkers = 0, evenWorkers = 0;
			numberOfPatents = userInput.nextInt();
			months = userInput.nextInt();
			limitOfWorkers = userInput.nextInt();
			availableWorkers = userInput.nextInt();
			String idOfWorkers = userInput.nextLine();

			for (int i = 0; i < idOfWorkers.length(); i++) {
				if (idOfWorkers.charAt(i) == 'O')
					oddWorkers++;
				else
					evenWorkers++;

			}
			int remainedPatents = numberOfPatents;
			int i = 1;

			while (i <= months && remainedPatents > 0) {

				if (i % 2 != 0) {
					remainedPatents -= Math.min(oddWorkers, limitOfWorkers);
					oddWorkers-=Math.min(oddWorkers, limitOfWorkers);
				} else {
					remainedPatents -= Math.min(evenWorkers, limitOfWorkers);
					evenWorkers-=Math.min(evenWorkers, limitOfWorkers);
				}
				// System.out.println(remainedPatents);
				i++;
			} // cases calculating
				// System.out.println(remainedPatents);
			if (remainedPatents > 0) {
				System.out.println("no");
			} else {
				System.out.println("yes");
			}

		} // cases
	}// main method

}
