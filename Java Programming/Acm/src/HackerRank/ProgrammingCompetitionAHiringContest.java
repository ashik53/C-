package HackerRank;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class ProgrammingCompetitionAHiringContest {
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
    static class Score implements Comparable<Score>{
    	  int difference,janScore;
    	  String name;
    	  Score(String name,int janScore,int difference){
    		  this.name = name;
    		  this.difference = difference;
    		  this.janScore = janScore;
    		  
    	  }
    	  public int compareTo(Score score) {
    		  if(difference>score.difference) {
    			  return -1;
    		  }
    		  else if(difference <score.difference) {
    			  return 1;
    		  }
    		  
    		  return 0;
    	  }
    	  
    };
    static PriorityQueue<Score>priorityQueue = new PriorityQueue<Score>();
    static FastReader userInput = new FastReader();
	public static void main(String[] args) {
		  
		int n;
		n= userInput.nextInt();
		for(int i=0;i<n;i++) {
			String name = userInput.next();
			int desScore = userInput.nextInt();
			int janScore = userInput.nextInt();
			priorityQueue.add(new Score(name,janScore,janScore-desScore));
		}
		
		
		
		
		
		System.out.println(priorityQueue.peek().name+" "+priorityQueue.peek().difference);

	}

}
