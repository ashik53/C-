package Practice;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeSet;

public class Test {
	static class Node implements Comparable<Node> {
		int distance, source, destination;

		Node(int source, int destination, int distance) {

			this.source = source;
			this.destination = destination;
			this.distance = distance;
		}

		public int compareTo(Node node) {
			if (distance > node.distance)
				return -1;
			else if (distance < node.distance)
				return 1;
			return 0;
		}

	};

	static Scanner userInput = new Scanner(System.in);
	static ArrayList<Integer> aList = new ArrayList<Integer>();
	static PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
	static double x1, y1, x2, y2;

	public static void main(String[] args) {

		while (true) {
			int num = userInput.nextInt();
            int count = 0;
			for (int i = 1; i <= num; i++) {

				if (num % i == 0) {
					System.out.println(i);
					count++;

				}
			}
			System.out.println();
			System.out.println(count);
		}

	}

	public static double distance() {
		double ans = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
		ans = Math.sqrt(ans);

		return ans;
	}

}
