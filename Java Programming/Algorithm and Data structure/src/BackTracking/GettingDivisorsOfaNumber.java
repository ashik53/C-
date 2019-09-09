package BackTracking;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class GettingDivisorsOfaNumber {

	static int ara[] = { 2, 3,5,7,11 };
	static int d = 0;
   static HashSet<Integer> divisors = new HashSet<Integer>();
	public static void main(String[] args) {
		   int count[] = new int[100];
		   int frequency[] = new int[100];
		   count[2]  =0;
		   count[3] = 0;
		   count[5] = 0 ;
		   count[7] = 0;
		   count[11] = 0;
		   count[19] = 0;
		   frequency[2] = 2;
		   frequency[3] = 2;
		   frequency[5] = 1;
		   frequency[7] = 2;
		   frequency[11] = ;
		   frequency[19] = 3;
		   
		   
          permutation(1,count,frequency);
		//System.out.println("\n d is = "+d);
          System.out.println("\n size is = "+divisors.size());
	}

	static void permutation(int sum,int count[],int frequency[]) {
       divisors.add(sum);
       
		for(int i=0;i<ara.length;i++) {
		
			  if(count[ara[i]]== frequency[ara[i]]) {
				  continue;
			  }
			  
			  sum*= ara[i];
			  count[ara[i]]++;
			  
			  permutation(sum, count, frequency);
			  count[ara[i]]--;
			  sum/=ara[i];
			  
		  }
	}

}
