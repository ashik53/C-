package Lightoj;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Practice {

	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);
		while (true) {

			
			char ara[] = new char[3];
			String abc = userInput.nextLine();

			for (int j = 0; j < 3; j++) {
				char c = abc.charAt(j);
				if (c == 'a') {
					String xyz = replaceCharAt(abc, j, 'z');
					System.out.println(xyz);
					xyz = "";
					xyz = replaceCharAt(abc, j, 'b');
					System.out.println(xyz);
				} else if (c == 'z') {
					String xyz = replaceCharAt(abc, j, 'a');
					System.out.println(xyz);
					xyz = "";
					xyz = replaceCharAt(abc, j, 'y');
					System.out.println(xyz);
				} else {
					int b = ((int) c) + 1;
					char d = (char) b;
					String xyz = replaceCharAt(abc, j, d);
					System.out.println(xyz);
					xyz = "";
					b = ((int) c) - 1;
					d = (char) b;
					xyz = replaceCharAt(abc, j, d);
					System.out.println(xyz);
				}

			} // for

		} // loop
		
		/*String abc = "xyz";
		
		if(abc.indexOf('a')>=0) {
			System.out.println("present");
		}else {
			System.out.println("absent");
		}*/
		
		
		/*HashMap<String,Integer> map = new HashMap<String,Integer>();
		map.put("abc",100);
		System.out.println(map.get("abc"));
		map.clear();
		
		System.out.println(map.get("abc"));
		map.clear();
		
		ArrayList<Integer>[] aList = (ArrayList<Integer>[]) new ArrayList[1007]; */
		
		//String abc = userInput.nextLine();
		//System.out.println(abc);
		
		//int a,b,c;
		//a = 1; b = 1 ; c = 3;
		//if(a==1 && b == 2 && c==3) System.out.println("ok");
		//else System.out.println("no");
	}//main method

	public static String replaceCharAt(String s, int pos, char c) {
		return s.substring(0, pos) + c + s.substring(pos + 1);
	}
	
	
}
