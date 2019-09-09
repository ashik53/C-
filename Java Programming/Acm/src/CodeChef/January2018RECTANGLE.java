package CodeChef;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class January2018RECTANGLE {
	static Scanner userInput = new Scanner(System.in);
	static int count[] = new int[10007];

	public static void main(String[] args) {
		int cases, line;

		cases = userInput.nextInt();

		while (cases > 0) {
			for (int i = 0; i < 10007; i++)
				count[i] = 0;

			TreeSet<Integer> lengths = new TreeSet<Integer>();
			ArrayList<Integer> list = new ArrayList<Integer>();
			int a = userInput.nextInt();
			count[a]++;
			int b = userInput.nextInt();
			count[b]++;
			int c = userInput.nextInt();
			count[c]++;
			int d = userInput.nextInt();
			count[d]++;

			lengths.add(a);
			lengths.add(b);
			lengths.add(c);
			lengths.add(d);

			Iterator<Integer> itr = lengths.iterator();
			while (itr.hasNext()) {
				list.add(itr.next());
			}

			if (list.size() == 2) {
				if (count[list.get(0)] == 2 && count[list.get(1)] == 2)
					System.out.println("YES");
				else
					System.out.println("NO");
			} else if (list.size() == 1)
				System.out.println("YES");

			else
				System.out.println("NO");

			cases -= 1;
		}

	}
}
