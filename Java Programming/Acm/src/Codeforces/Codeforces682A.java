package Codeforces;

import java.util.Scanner;

public class Codeforces682A {
       public static void main(String[] args) {
    	   Scanner userInput = new Scanner(System.in);
    	   Long n = userInput.nextLong();
    	   Long m = userInput.nextLong();
    	   
    	   Long ans =(long) 0;
    	   Long i,j,k;
    	   for( i=(long) 1;i<=n;i++) {
    		        for(j=(long) 1;j<=m;j++) {
    		        	if( (i+j)%5==0) break;
    		        }
    		   
    		
    		if(j<=m) {
    		        	  for(k=m;k>=1;k--) {
    		        		  if((k+i)%5==0) {
    		        			  break;
    		        		  }
    		        	  }
    		        	  ans +=  ((k-j)/5)+1 ;
    		        }
    	   }
    	   
    	   System.out.println(ans);
    	   
    	   
	}
}
