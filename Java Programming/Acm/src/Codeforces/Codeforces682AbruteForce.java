package Codeforces;

import java.util.Scanner;

public class Codeforces682AbruteForce {
      
	
	public static void main(String[] args) {
		
		while(true) {
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();
			int m = sc.nextInt();
			int ans = 0;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=m;j++) {
					if((i+j)%5==0) ans+=1;
				}
			}
			
			System.out.println(ans);
		}///cases
		
		
	}
	
	
}
