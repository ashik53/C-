package Lightoj;

import java.util.Scanner;

class Main {
      
   static int vis[] = new int[107],True=0,ans = 0,line;
   static char land[] = new char[107];
   static Scanner userInput = new Scanner(System.in);
   public static void main(String[] args) {
      
          line = userInput.nextInt();
          for(int li = 1;li<=line;li++) {
              True+=1;
              ans= 0 ;
              int sz = userInput.nextInt();
              String str = userInput.nextLine();
              str = userInput.nextLine();
              
              
            
              //result processing
              
              for(int i=0;i<sz;++i) {
                  if(str.charAt(i)=='.') {
                     ans+=1;
                     i+=2;
                  }
              }//result processing
              
              System.out.print("Case "+li+": "+ans+"\n");
          }
   }
  
}

	

