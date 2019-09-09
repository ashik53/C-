package TrieSolve;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

import TrieSolve.TrieWordsOfPrefix.TrieNode;

//Java implementation of search and insert operations
//on Trie
public class TrieWordsOfPrefix {

	// Alphabet size (# of symbols)
	static final int ALPHABET_SIZE = 26;
	static ArrayList<Character> word = new ArrayList<>();

	// trie node
	static class TrieNode {
		TrieNode[] children = new TrieNode[ALPHABET_SIZE];

		// isEndOfWord is true if the node represents
		// end of a word
		boolean endMark;

		TrieNode() {
			endMark = false;
			for (int i = 0; i < ALPHABET_SIZE; i++)
				children[i] = null;
		}
	};

	static TrieNode root, lastNode;

	// If not present, inserts key into trie
	// If the key is prefix of trie node,
	// just marks leaf node
	static void insert(String str) {
		int length = str.length();
		int id;

		TrieNode current = root;

		for (int i = 0; i < length; i++) {
			id = str.charAt(i) - 'a';
			if (current.children[id] == null) {
				current.children[id] = new TrieNode();
			}
			current = current.children[id];
		}

		// mark last node as leaf
		current.endMark = true;
	}

	// Returns true if key presents in trie, else false
	static boolean search(String str) {
		int i;
		int length = str.length();
		int id;
		TrieNode current = root;
		for (i = 0; i < length; i++) {
			id = str.charAt(i) - 'a';
			// System.out.println(id);
			if (current.children[id] == null)
				return false;

			current = current.children[id];
			lastNode = current;
		}

		return true;
	}

	// a function which works like a phonebook of your mobile phone,it shows
	// suggestions 
	static void wordPrintingByPrefix(TrieNode current,char ch) { //here I have used simple dfs approach
        
		word.add(ch);
		
		if (current.endMark==true) {
			for (Character x : word) {
				System.out.print(x);
			}
			System.out.println();
		}

		// traverse
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (current.children[i] != null) {
                 ch = (char)(i+97);
				 wordPrintingByPrefix(current.children[i],ch);

			}
		} // loop
		word.remove(word.size() - 1);
	}

	// Driver
	public static void main(String args[]) {

		Scanner userInput = new Scanner(System.in);
		String str;
		while (true) {
			
			System.out.println("New case");
			root = new TrieNode();
			System.out.println("How many words do you need: ");
			int numberOfWords = userInput.nextInt();
			str = userInput.nextLine();
			for (int i = 0; i < numberOfWords; i++) {

				str = userInput.nextLine();
				insert(str);
			}
			// System.out.println((char)root.children[0]);
			System.out.println("How many queries: ");
			int query = userInput.nextInt();
			str = userInput.nextLine();
			// search all the word by prefix
			for (int i = 0; i < query; i++) {
				str = userInput.nextLine();
				word.clear();
				
				if (search(str)) {
					int len = str.length();

					for (int j = 0; j < len-1; j++)
						word.add(str.charAt(j));
					
					wordPrintingByPrefix(lastNode,str.charAt(len-1));

				} //search all the word by prefix

				else 
					System.out.println("no");
			
			} // for

		} // cases
	}// man

	static void del(TrieNode current) {

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (current.children[i] != null) {
				// System.out.println((char)(i+97));
				del(current.children[i]);
			}
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			current.children[i] = null;
			System.gc();
		}

	}
}