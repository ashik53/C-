//Working program with FastReader
import java.util.*;
import java.util.Random;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Collections;
import static java.util.Arrays.sort;
import java.util.*;
import java.io.*;
import java.util.Random;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Collections;

public class Codeforces111A {
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
	}

	static void prln(Object any) {

		System.out.println(any);

	}

	static void pr(Object any) {

		System.out.print(any);

	}

	private static Scanner m;

	public static void main(String[] args) {

		FastReader userInput = new FastReader();

		int size,midSum = 0,finalSum = 0,result = 0;

		size = userInput.nextInt();

		int coins[] = new int[size];

		for(int i=0;i<size;i++) {
			coins[i] = userInput.nextInt();
			midSum+= coins[i];
		}

		midSum= midSum/2 +1;
		Arrays.sort(coins);

		for(int i = size-1;i>=0;i-- ) {
			finalSum += coins[i];
			result+=1;

			if(finalSum>=midSum) {
				break;
			}
		}


		System.out.println(result);


	}
}
