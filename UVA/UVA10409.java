package UVA;

import java.util.Scanner;

public class UVA10409 {
    
	public static void main(String[] args) {
		      
		 int up,up1,bottom1,bottom,left,left1,right,right1,front,front1,back,back1;
	     Scanner userInput = new Scanner(System.in); 
		      while(true) {
		    	  up1=up = 1;
			      bottom1=bottom=6;
			      left= left1 = 3;
			      right1= right = 4;
			      front= front1 = 2;
			      back = back1 = 5;
		    	  int line = userInput.nextInt();
		    	  if(line==0) break;
		    	  String command = userInput.nextLine();
		    	  for(int i=0;i<line;i++) {
		    		    command  = userInput.nextLine();
		    		    if(command.equals("north")) {
		    		    	up = back1;
		    		    	bottom = front1;
		    		    	front = up1;
		    		    	back = bottom1;
		    		    	
		    		    	
		    		    }else if(command.equals("south")) {
		    		    	up = front1;
		    		    	bottom = back1;
		    		    	front = bottom1;
		    		    	back = up1;
		    		    	
		    		    	
		    		    }else if(command.equals("east")) {
		    		    	up = left1;
		    		    	bottom = right1;
		    		    	left = bottom1;
		    		    	right = up1;
		    		    	
		    		    	
		    		    }else if(command.equals("west")) {
		    		    	up = right1;
		    		    	bottom = left1;
		    		    	left = up1;
		    		    	right = bottom1;
		    		    	
		    		    	
		    		    }
		    		  //  System.out.println(up);
		    		   //copy
		    		  up1=up ;
		  		      bottom1=bottom;
		  		      left1= left;
		  		      right1= right;
		  		      front1= front ;
		  		      back1 = back;
		    		   //
		    		    
		    		    
		    		    
		    	  }//commands
		    	  
		    	 System.out.println(up); 
		    	  
		      }//cases
 
	}

}
