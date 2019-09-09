package CodeChef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;



public class FebChallenge2018PERMPAL {
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
	static String inputString;
	static ArrayList<Integer>[] indexList = (ArrayList<Integer>[]) new ArrayList[26];
	static int oddFrequency;
	static int resultArray[] = new int[100007];

	public static void main(String[] args) {
		int line = userInput.nextInt();
		for (int cases = 0;cases<line;cases++) {

			inputString = userInput.nextLine();
			int inputStringLength = inputString.length();
			indexPuttingMethod();

			if (oddFrequency > 1) {
				System.out.println("-1");
				continue;
			}
           // System.out.println("odd frequency "+oddFrequency);
			int first = 0;
			int i = 0;
			int last = inputStringLength - 1;
            
			while (i < 26) {
				int limit = indexList[i].size();
				if (limit % 2 == 0 && limit != 0) {
                   // System.out.println("i = "+(i)+" ->"+limit);
					for (int j = 0; j < limit; j += 2) {

						resultArray[first] = indexList[i].get(j);
						resultArray[last] = indexList[i].get(j+1);
						first++;
						last--;
					}

				}
				i++;
			} // loop for even calculation
			i = 0;
			while (i < 26) {
				int limit = indexList[i].size();
				if (limit % 2 != 0 && limit != 0) {

					for (int j = 0; j < limit; j += 1) {

						resultArray[first] = indexList[i].get(j);
						
						first++;
						
					}

				}
				i++;
			} // loop for even calculation
			
			
			for(int j=0;j<inputStringLength;j++) {
				System.out.print(resultArray[j]+" ");
			}
            System.out.println();
		} // cases
	}// main method

	static void indexPuttingMethod() {
		oddFrequency = 0;
		for (int i = 0; i < 26; i++) {
			indexList[i] = new ArrayList<Integer>();
		}
		int len = inputString.length();
		for (int i = 0; i < len; i++) {
			int id = inputString.charAt(i) - 'a';
			indexList[id].add(i + 1);
		}

		for (int i = 0; i < 26; i++) {
			int limit = indexList[i].size();
			if (limit % 2 != 0 && limit != 0)
				oddFrequency++;
			//else if(limit!=0) {
			//	System.out.println(i +"->count -> "+limit);
			//}
		}

	}// method
}// main class
