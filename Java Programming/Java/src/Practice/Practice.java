package Practice;

import java.util.*;

import Comparator.Student;



public class Practice {
   static int[] ara = new int[5];
   static Scanner userInput = new Scanner(System.in);
	public static void main(String[] args) throws InterruptedException {
		long a = 0L;
		a+= 111111111111L;
		System.out.println(a);
	}

	static class ElementComparator<T extends Comparable<T>> implements Comparator<T> {

		public int compare(T o1, T o2) {
			return o2.compareTo(o1);
		}
	};

}
