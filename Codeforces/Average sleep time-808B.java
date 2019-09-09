import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.StringTokenizer;



public class Codeforces808B {
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
    static int info[] = new int[2*100008];
    static double cumulativeSum[] = new double[2*100008];
	public static void main(String[] args) {
		FastReader userInput = new FastReader();
		
		int n,k;
		double addValue=0;
		n = userInput.nextInt();
		k = userInput.nextInt();
		
		for(int i=0;i<n;i++) {
			info[i] = userInput.nextInt();
		}
		
		//output processing starts 
		for(int i=0;i<n;i++) {
			addValue+= ((double)info[i]);
			cumulativeSum[i] = addValue;
		}
		
		addValue = 0;
		for(int i=0;i<n+1-k;i++) {
			addValue+= cumulativeSum[i+k-1];
			if(i>0) {
				addValue-= cumulativeSum[i-1];
			}
		}
		
		double res = addValue/(n-k+1);
		DecimalFormat df = new DecimalFormat("#.##########");
		System.out.print(df.format(res));
	}//main
}