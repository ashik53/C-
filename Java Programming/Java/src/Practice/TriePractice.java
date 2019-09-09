package Practice;
import java.util.ArrayList;
import java.util.Scanner;

//suppose we have a dictionary, we have to check any single word is a prefix of another word , or not
//UVA11362
public class TriePractice  {

	// Alphabet size (# of symbols)
	static final int ALPHABET_SIZE = 10;

	// trie node
	static class TrieNode {
		TrieNode[] children = new TrieNode[ALPHABET_SIZE];

		// isEndOfWord is true if the node represents
		// end of a word
		boolean endMark;
        int count ;
		TrieNode() {
			endMark = false;
			count = 0;
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
			current.count++;
		}

		// mark last node as leaf
		current.endMark = true;
	}

	// Returns true if key presents in trie, else false
	static int search(String str) {
	
		int length = str.length();
		int id;
		TrieNode current = root;

		for (int i = 0; i < length; i++) {
			id = str.charAt(i) - '0';

			if (current.children[id] == null)
				return 0;

			current = current.children[id];
		}
		
		
        System.out.println("string-> "+str+", count = "+current.count);  
		return current.count;
		
		
	}//search

	static void del(TrieNode current) {
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (current.children[i] != null) {
				del(current.children[i]);
			}
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			current.children[i] = null;
			current.count = 0;
			System.gc();
		}

	}

	public static boolean prefixChecking() {

		for (int i = 0; i < stringList.size(); i++) {
			if (search(stringList.get(i))>1  ) {
				return false;
			}
		}

		return true;

	}

	// Driver
	public static void main(String args[]) {
        
		int cases;
		Scanner userInput = new Scanner(System.in);
		String str;
		//cases = userInput.nextInt();
		while (true) {
			stringList.clear();
			System.out.println("New case");
			root = new TrieNode();
			System.out.println("How many words you wanna insert: ");
			int numberOfWords = userInput.nextInt();
			str = userInput.nextLine();
			for (int i = 0; i < numberOfWords; i++) {

				str = userInput.nextLine();
				insert(str);
				stringList.add(str);
			}

			if (prefixChecking())
				System.out.println("you can safely dial");
			else
				System.out.println("Number dialling is impossible");
			del(root);

		} // cases,lines
	}
}
