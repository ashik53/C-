package Codeforces;

import java.util.Scanner;

public class Codeforces681B {
	static Scanner userInput = new Scanner(System.in);

	public static void main(String[] args) {
		Long xAra[] = new Long[10000];
		Long yAra[] = new Long[10000];
		int x = 1234567, y = 123456, z = 1234;
		int n, m;
		Long givenValue;
		for (n = 0; n <= 812; n++) {

			Long value = Long.valueOf(x * n);
			xAra[(int) n] = Long.valueOf(value);
		}

		for (m = 0; m <= 8102; m++) {
			Long value = Long.valueOf(y * m);
			yAra[m] = value;
		}

		boolean ans = false;
		givenValue = userInput.nextLong();

		for (int i = 0; i < n; i++) {

			Long a = xAra[i];
			for (int j = 0; j < m; j++) {
				if (ans == true)
					break;

				Long b = yAra[j];

				if (a + b > givenValue)
					continue;
				if ((givenValue - (a + b)) % z == 0)
					ans = true;
				else if (givenValue % x == 0 || givenValue % y == 0 || givenValue % z == 0)
					ans = true;
				else if ((givenValue - a) % y == 0 || (givenValue - a) % z == 0 || (givenValue - b) % z == 0)
					ans = true;

			}
			if (ans == true)
				break;

		}
		if (ans == true)
			System.out.println("YES");
		else
			System.out.println("NO");

	}// main

}
