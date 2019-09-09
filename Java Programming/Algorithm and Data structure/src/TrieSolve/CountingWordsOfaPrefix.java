package TrieSolve;


import java.util.Scanner;

import TrieSolve.Trie.TrieNode;

//Java implementation of search and insert operations
//on Trie
public class CountingWordsOfaPrefix {

	// Alphabet size (# of symbols)
	static final int ALPHABET_SIZE = 26;

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

	static TrieNode root;

	// If not present, inserts key into trie
	// If the key is prefix of trie node,
	// just marks leaf node
	static void insert(String str) {
		int level;
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

			if (current.children[id] == null)
				return false;

			current = current.children[id];
		}

		return current.endMark;
	}

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

	// Driver
	public static void main(String args[]) {

		Scanner userInput = new Scanner(System.in);
		String str;
		while (1 < 2) {
			System.out.println("New case");
			root = new TrieNode();
			System.out.println("How many words do you need: ");
			int numberOfWords = userInput.nextInt();
			str = userInput.nextLine();
			for (int i = 0; i < numberOfWords; i++) {

				str = userInput.nextLine();
				insert(str);
			}

			System.out.println("How many queries: ");
			int query = userInput.nextInt();
			str = userInput.nextLine();
			for (int i = 0; i < query; i++) {
				str = userInput.nextLine();
				if (search(str))
					System.out.println("yes");
				else
					System.out.println("no");
			}
			del(root);
			System.out.println("again queries: ");
			for (int i = 0; i < query; i++) {
				str = userInput.nextLine();
				if (search(str))
					System.out.println("yes");
				else
					System.out.println("no");
			}
		} // cases
	}
}
//
