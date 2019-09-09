package TrieSolve;

import java.util.ArrayList;
import java.util.Scanner;

//suppose we have a dictionary, we have to check any single word is a prefix of another word , or not
//UVA11362
public class CheckAnyWordIsAprefixOfAnother {

	// Alphabet size (# of symbols)
	static final int ALPHABET_SIZE = 10;

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
	static ArrayList<String> stringList = new ArrayList<>();

	// If not present, inserts key into trie
	// If the key is prefix of trie node,
	// just marks leaf node
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

		// mark last node as leaf
		current.endMark = true;
	}

	// Returns true if key presents in trie, else false
	static boolean search(String str) {

		int length = str.length();
		int id;
		TrieNode current = root;

		for (int i = 0; i < length; i++) {
			id = str.charAt(i) - '0';

			if (current.children[id] == null)
				return false;

			current = current.children[id];
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (current.children[i] != null && current.endMark == true) {
				return true;
			}
		}

		return false;

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
			if (search(stringList.get(i))) {
				System.out.println("pref: "+true);
				return true;
			}
		}
		System.out.println("pref: "+false);
		return false;

	}

	// Driver
	public static void main(String args[]) {

		int cases;
		Scanner userInput = new Scanner(System.in);
		String str;
		cases = userInput.nextInt();
		for (int line = 0; line < cases; line++) {
			stringList.clear();
			// System.out.println("New case");
			root = new TrieNode();
			// System.out.println("How many words you wanna insert: ");
			int numberOfWords = userInput.nextInt();
			str = userInput.nextLine();
			for (int i = 0; i < numberOfWords; i++) {

				str = userInput.nextLine();
				insert(str);
				stringList.add(str);
			}
            System.out.println("sizeof stringList: "+stringList.size());
			if (prefixChecking())
				System.out.println("NO");
			else
				System.out.println("YES");
			del(root);

		} // cases,lines
	}
}