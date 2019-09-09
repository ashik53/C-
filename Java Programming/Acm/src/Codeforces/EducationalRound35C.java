package Codeforces;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class EducationalRound35C {
    static int a,b,c;   
    static Scanner userInput = new Scanner(System.in);
    static 	TreeSet list = new TreeSet();
	public static void main(String[] args) {
		
		//while(true) {
			a = userInput.nextInt();
			b = userInput.nextInt();
			c = userInput.nextInt();
			boolean v =true;
			int count = 0;
			for(int i=1;i<=100;i++) {
				for(int j=1;j<=100;j++) {
					for(int k=1;k<=100;k++) {
						
						for(int z=0;z<=100;z++) {
							list.add(i+(a*z));
						}
						
						for(int z=0;z<=100;z++) {
							list.add(j+(b*z));
						}
						
						for(int z=0;z<=100;z++) {
							list.add(k+(c*z));
						}
						
						v = true;
						for(int z=1;z<=100;z++) {
							if(list.contains(z)==false) {
								v= false;
								list.clear();
							}
						}
						if(v==true) {
							System.out.println(i+" "+j+" "+k);
							System.out.println("YES");
							count++;
							
							//if(v==true) break;
							//System.out.println(list);
						}
					if(count==5) break;	
					list.clear();	
					}//k
					
					//if(v==true) break;
					if(count==5) break;	
				}//j
				//if(v==true) break;
				if(count==5) break;	
			}//i
			
			if(v==false) System.out.println("NO");
			
		//}//while 
		
		
		
		
		
		
	}
	
	
	
}
