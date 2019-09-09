import java.util.Scanner;

public class Problem32B {
     public static void main(String[] args) {
    	 Scanner userInput = new Scanner(System.in);
    	 
    	 String input;
    	 input = userInput.nextLine();
    	 
    	 for(int i=0;i<input.length();) {
    		  if(input.charAt(i) =='-' && input.charAt(i+1)=='-') {
    			  System.out.print("2");
    			  i+=2;
    		  }
    		  else if(input.charAt(i) =='-' && input.charAt(i+1)=='.') {
    			  System.out.print("1");
    			  i+=2;
    		  }
    		
    		  else {
    			  System.out.print("0");
    			  i+=1;
    		  }
    	 }
     }
}