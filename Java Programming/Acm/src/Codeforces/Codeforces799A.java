package Codeforces;

import java.util.Scanner;

public class Codeforces799A {

	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);
		double n,t,k,d;
		n = userInput.nextDouble();
		t = userInput.nextDouble();
		k = userInput.nextDouble();
		d = userInput.nextDouble();
		
		double estimatedTime = (t*n)/k;
		System.out.println(estimatedTime);
		String ans = "NO";
		
		if(estimatedTime-d>0) {
			double addValue = ( (estimatedTime-d-1)*k) /t;
			if(n+addValue>n) ans = "YES";
			
		}
		System.out.println(ans);
        
	}//main

}
