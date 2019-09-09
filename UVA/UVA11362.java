package UVA;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.*;  
import java.util.LinkedList;
import java.util.Queue;
class UVA11362 {

	static class FastReader
	 {
	     BufferedReader br;
	     StringTokenizer st;

	     public FastReader()
	     {
	         br = new BufferedReader(new InputStreamReader(System.in));
	     }

	     String next()
	     {
	         while (st == null || !st.hasMoreElements())
	         {
	             try
	             {
	                 st = new StringTokenizer(br.readLine());
	             }
	             catch (IOException  e)
	             {
	                 e.printStackTrace();
	             }
	         }
	         return st.nextToken();
	     }

	     int nextInt()
	     {
	         return Integer.parseInt(next());
	     }

	     long nextLong()
	     {
	         return Long.parseLong(next());
	     }

	     double nextDouble()
	     {
	         return Double.parseDouble(next());
	     }

	     String nextLine()
	     {
	         String str = "";
	         try
	         {
	             str = br.readLine();
	         }
	         catch (IOException e)
	         {
	             e.printStackTrace();
	         }
	         return str;
	     }
	 }
	static final int ALPHABET_SIZE = 10;


	static class TrieNode {
		TrieNode[] children = new TrieNode[ALPHABET_SIZE];

		
		boolean endMark;
		

		TrieNode() {
			endMark = false;
			//count = 0;
			for (int i = 0; i < ALPHABET_SIZE; i++)
				children[i] = null;
		}
	};

	static TrieNode root;
	static ArrayList<String> stringList = new ArrayList<>();

	
	static void insert(String str) {
		int level;
		int length = str.length();
		int id;

		TrieNode current = root;

		for (int i = 0; i < length; i++) {
			id = str.charAt(i) - '0';
			if (current.children[id] == null) {
				current.children[id] = new TrieNode();

			}
			current = current.children[id];
		
		}

	
		current.endMark = true;
	}

	
	static boolean search(String str) {

		int length = str.length();
		int id;
		TrieNode current = root;

		for (int i = 0; i < length; i++) {
			id = str.charAt(i) - '0';

			current = current.children[id];
		}
        for(int i=0;i<ALPHABET_SIZE;i++) {
        	if(current.children[i]!=null) return false;
        }
		return true;

	}// search

	static void del(TrieNode current) {
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (current.children[i] != null) {
				del(current.children[i]);
			}
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			current.children[i] = null;
			System.gc();
		}

	}

	public static boolean prefixChecking() {

		for (int i = 0; i < stringList.size(); i++) {
			if (search(stringList.get(i))==false) {
				return false ;
			}
		}

		return true;

	}
	static final FastReader userInput=new FastReader();
	// Driver
	public static void main(String args[]) {

		int cases;
		
		String str;

		cases = userInput.nextInt();

		for (int line = 1; line <= cases; line++) {
			stringList.clear();
			
			root = new TrieNode();
			
			int numberOfWords = userInput.nextInt();
			//str = userInput.nextLine();
			for (int i = 0; i < numberOfWords; i++) {
				str = userInput.nextLine();
				insert(str);
				stringList.add(str);
			}
			//System.out.println(stringList);

			if (prefixChecking()==true)
				System.out.print("YES");
			else
				System.out.print("NO");
			System.out.println();
			del(root);

		} // cases,lines
	}
}