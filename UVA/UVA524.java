package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class UVA524{

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
	static boolean prime[] = new boolean[100];
	static int ara[] = new int[100];
	static boolean taken[] = new boolean[100];
	static int result[] = new int[100];
	public static void main(String[] args) throws IOException  {
        

		int cases = 1;
		String line;
		for (int i = 2; i <= 100; i++) {
			ara[i - 2] = i;
		}
		
		for(int i=1;i<100;i++) {
			if(primeChecking(i)==true) prime[i] = true;
			else prime[i] = false;
		}
		 BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String input;
		//while (true) {
		while((input = r.readLine()) != null) {
		
			if(cases!=1) System.out.println();
			int size;
			size = Integer.parseInt(input);
		
			for (int i = 0; i <= 20; i++) {
				taken[i] = false;
			}
			System.out.println("Case "+cases+":");
			per(size,1,1);
			cases++;
			
		} // cases
		
	}

	 public static void per( int size,int len,int last) {
		if (len == size) {
			
			if (prime[1 + result[size-2]  ]==true) {
                System.out.print("1 ");
				for (int j = 0; j < size-1; j++) {
					if (j == size - 2) {
						System.out.println( result[j]);
					} else
						System.out.print(result[j] + " ");
				}

				
			}
           return ;
		}

		for (int i = 0; i < size - 1; i++) {
			int sum =last;
			sum += ara[i];
			if (prime[sum] == true && taken[ara[i]] == false) {
				
					
					result[len-1] = ara[i];
					taken[ara[i]] = true;
					per( size, len+1,ara[i]);
					taken[ara[i]] = false;
					
				
			}

		}
	}

	public static boolean primeChecking(int sum) {
        if(sum==1) return false;
		for(int i=2;i*i<=sum;i++) {
			if(sum%i==0) return false;
		}
		
		return true;
	}
}
