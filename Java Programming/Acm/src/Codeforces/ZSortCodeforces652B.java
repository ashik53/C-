package Codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ZSortCodeforces652B {
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
	/*private static Scanner m;

	public static void main(String[] args){
		
		int n;
		m = new Scanner(System.in);
		n=m.nextInt();
		int ara[] = new int[n];
		for(int i=0;i<n;i++)
		{
			ara[i] = m.nextInt();
		}
		Arrays.sort(ara);
		for(int number:ara)System.out.println(number);
	  }*/
	
	
	
	public static void main(String[] args) {

		int n = userInput.nextInt();
		ArrayList<Integer>inputAra = new ArrayList<Integer>();
		int i,j;
		for ( i = 0; i < n; i++) {
			inputAra.add(userInput.nextInt());
		}

		Collections.sort(inputAra);
        
		
		System.out.println(inputAra); 
		
		i=n-1;
		j=n-1;
		if(i%2==0) i--;
		for(;i>0;i-=2,j--) {
			resultAra[i] = inputAra[j];
		}
		
		
		i=n;
		if(i%2==0) i--;
		for(;i>0;i-=2,j--) {
			resultAra[i] = inputAra[j];
		}

		for (i = 1; i <= n; i++) {
			System.out.print(resultAra[i ] + " ");
		}

	}// main 
	
	
}
