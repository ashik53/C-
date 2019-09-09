package Codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;

public class QualifyingContest659B {
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

	static ArrayList<Team>[] teamList = (ArrayList<Team>[]) new ArrayList[10009];
	static FastReader userInput = new FastReader();

	public static void main(String[] args) {

		int n, m;
		n = userInput.nextInt();
		m = userInput.nextInt();
		// n = 100000;
		// m = 1;
		for (int i = 0; i < m; i++)
			teamList[i] = new ArrayList<>();

		for (int i = 0; i < n; i++) {

			/*
			 * String name = "abcvfr"; int region = 1; int score =((int) Math.random())%801;
			 */
			String name = userInput.next();
			int region = userInput.nextInt();
			int score = userInput.nextInt();
			teamList[region - 1].add(new Team(score, name));
			// userInput.nextLine();

		}

		
			
		sollution(n, m);

	}// main method

	public static void sollution(int n, int m) {

		for (int i = 0; i < m; i++) {
			Collections.sort(teamList[i], new MyScoreComp());
			if (teamList[i].size() == 2) {
				System.out.println(teamList[i].get(0).name + " " + teamList[i].get(1).name);
			} else if (teamList[i].get(0).score == teamList[i].get(1).score
					&& teamList[i].get(1).score == teamList[i].get(2).score) {
				System.out.println("?");
			} else if (teamList[i].get(1).score == teamList[i].get(2).score) {
				System.out.println("?");
			} else {
				System.out.println(teamList[i].get(0).name + " " + teamList[i].get(1).name);
			}

		} // loop

	}// sollution

}
