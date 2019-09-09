package Lightoj;

import java.util.Scanner;

 class Lightoj1000 {
	public static void main(String[] args) {
            Scanner userInput = new Scanner(System.in);
            
            
            
          int   cases = userInput.nextInt();
            
            for(int i=1;i<=cases;i++){
            	int a = userInput.nextInt();
            	int b = userInput.nextInt();
              
              //  System.out.println("Case "+(i+1)+": "+(a+b));
                System.out.printf("Case %d: %d\n",i,a+b);
               }
            
            
	}
}
