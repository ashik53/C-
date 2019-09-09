package CodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CarPalTunnelFebChallenge2018 {

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
		for (int line = 0; line < cases; line++) {

			Long first = 0L;
			Long sumOfToolTime = 0L;
			int numberOfTunnels = userInput.nextInt();
			Long big = -999L;
			for (int n = 0; n < numberOfTunnels; n++) {
                Long num = userInput.nextLong();
				sumOfToolTime += num;
                if(num>big) big = num;
			} // all tunnelTime taking ends here
			int numberOfCars = userInput.nextInt();
			Long tunnelDistance = userInput.nextLong();
			Long velocity = userInput.nextLong();
			double chefTime = 0;

			double totalTime = 0;
			for (int i = 0; i < numberOfCars; i++) {

				if (i == 0) {
					chefTime = sumOfToolTime + ((tunnelDistance / velocity) * (numberOfTunnels - 1));
					totalTime = chefTime;
				} else {
					totalTime += big;
				}

			} // result processing
			double answer = totalTime - chefTime;

			System.out.printf("%.10f\n", answer);
		} // cases

	}// main method

}
