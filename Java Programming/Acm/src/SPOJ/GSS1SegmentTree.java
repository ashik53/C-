package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class GSS1SegmentTree {

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

	static int max = 100001;
	static int ara[] = new int[max];
	static int tree[] = new int[max * 3];

	static void buildTree(int node, int begin, int end) {
		if (begin == end) {
			tree[node] = ara[begin];
			return;
		}
		int Left = node * 2;
		int Right = node * 2 + 1;
		int mid = (begin + end) / 2;
		buildTree(Left, begin, mid);
		buildTree(Right, mid + 1, end);
		tree[node] = maxOfTwo(tree[Left], tree[Right]);
	}

	static int maxOfTwo(int first, int second) {
		if (first == second)
			return first;
		else if (first > second)
			return first;
		return second;
	}

	static int query(int node, int begin, int end, int i, int j) {
		if (i > end || j < begin)
			return 0;
		if (begin >= i && end <= j)
			return tree[node];
		int Left = node * 2;
		int Right = node * 2 + 1;
		int mid = (begin + end) / 2;
		int p1 = query(Left, begin, mid, i, j);
		int p2 = query(Right, mid + 1, end, i, j);
		return maxOfTwo(p1, p2);
	}

	static void update(int node, int begin, int end, int i, int newvalue) {
		if (i > end || i < begin)
			return;
		if (begin >= i && end <= i) {
			tree[node] = newvalue;
			return;
		}
		int Left = node * 2;
		int Right = node * 2 + 1;
		int mid = (begin + end) / 2;
		update(Left, begin, mid, i, newvalue);
		update(Right, mid + 1, end, i, newvalue);
		tree[node] = maxOfTwo(tree[Left], tree[Right]);
	}

	public static void main(String[] args) {
		//while (true) {
			int size = userInput.nextInt();
			for (int i = 0; i < size; i++) {
				ara[i] = userInput.nextInt();
			}
			buildTree(1, 0, size-1);
			int querySize = userInput.nextInt();
			for (int i = 0; i < querySize; i++) {
				int a = userInput.nextInt();
				int b = userInput.nextInt();

				int ans = query(1, 0, size - 1, a - 1, b - 1);
				System.out.println(ans);

			}

		//}
	}// main method

}// main class
