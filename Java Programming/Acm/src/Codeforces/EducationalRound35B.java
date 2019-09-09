package Codeforces;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
//import java.util.TreeSet;

public class EducationalRound35B {
	static Scanner userInput = new Scanner(System.in);

	public static void main(String[] args) {

		int a, b, n;
		n = userInput.nextInt();
		a = userInput.nextInt();
		b = userInput.nextInt();

		ArrayList<Integer> list = new ArrayList<Integer>();

		list.add(a);
		list.add(b);
		int lowest = (a + b) / n;

		/*
		 * while (list.size() != n) { Collections.sort(list); int big =
		 * list.get(list.size() - 1); list.remove(list.size() - 1); list.add(big / 2);
		 * if (big % 2 == 0) list.add(big / 2);
		 * 
		 * else list.add((big / 2) + 1);
		 * 
		 * } // loop
		 */
		if (lowest > Math.min(a, b)) {
			System.out.println(Math.min(a, b));
		} else {
			while (list.size() != n) {
				Collections.sort(list);
				int big = list.get(list.size() - 1);
             //   System.out.print(big+"->");
				if (list.size() == n - 1) {
					list.remove(list.size() - 1);
					list.add(big / 2);
					if (big % 2 == 0) {
						list.add(big / 2);

					} else {
						list.add((big / 2) + 1);
					}
				} else {
					list.remove(list.size() - 1);
					list.add(lowest);
					list.add(big - lowest);
				}
				Collections.sort(list);
				// System.out.println(list);
			} // loop

			Collections.sort(list);
			// System.out.println(list);
			System.out.println(list.get(0));
		}
	}
}