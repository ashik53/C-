package Codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.StringTokenizer;



public class DaVinciPowers656A {
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
	static class Team {
		int score;
		String name;

		Team(int score, String name) {
			this.score = score;
			this.name = name;
		}

	}

	static class MyScoreComp implements Comparator<Team> {

		@Override
		public int compare(Team t1, Team t2) {
			if (t1.score < t2.score) {
				return 1;
			} else if (t1.score > t2.score){
				return -1;
			}
			return 0;
		}
	};
	static FastReader userInput = new FastReader();
	public static void main(String[] args) {
		int a;
		a= userInput.nextInt();
         Long ara[] = {(long)1, (long)2,(long) 4, (long)8,(long) 16,(long) 32, (long)64,
        		  (long)128, (long)256, (long)512, (long)
        		  1024,(long) 2048,(long) 4096, (long)8092,(long) 16184, (long) 32368, 
        		  (long)64736,(long) 129472,(long) 258944,(long) 517888, (long)1035776,
        		  (long) 2071552,(long) 4143104,(long)
        	8286208,
        		  (long)16572416,(long) 33144832, 
        		  (long)66289664, (long)132579328, (long)265158656,(long) 530317312,(long)
        		  1060634624,(long)2121269248,
        		  };
          if(a<32) System.out.println(ara[a]);
          else if(a==32) System.out.println("4242538496");
          else if(a==33) System.out.println("8485076992");
          else if(a==34) System.out.println("16970153984");
          else System.out.println("33940307968");
          
	}
}
