package Lightoj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
 
 
 public class LightOJ1076GetTheContainersGreedyBinarySearch {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    };
 
    static FastReader userInput = new FastReader();
    static int vessel[] = new int[1007];
    static int numberOfVessels,containerLimit;
    public static void main(String[] args) {
    	int cases = userInput.nextInt();
          for(int line = 1;line<=cases;line++) {
              numberOfVessels = userInput.nextInt();
              containerLimit =  userInput.nextInt();
              int sum =0;
              int big =  -1;
              for(int i=0;i<numberOfVessels;i++) {
                  vessel[i] = userInput.nextInt();
                  sum+= vessel[i];
                  if(big<vessel[i]) {
                      big = vessel[i];
                  }
              }
          //     System.out.println(big+" "+sum);
             int answer =  binarySearch(big, sum);
             
             System.out.println("Case "+line+": "+answer);
          }//all cases
    }
   
    static boolean check(int searchValue) {
        int sum =0;
       
        int j = 0;
       
        for(int i=0;i<numberOfVessels;i++) {
            sum+= vessel[i];
            if(sum>searchValue) {
                j++;
                sum = vessel[i];
                if(j==containerLimit) return false;
            }
        }
        return true;
    }
    static int binarySearch(int begin,int end) {
    	//int count =0;
    	int mid=0;
        while(begin<end ) {
        	
        	mid= (begin+end)/2;
           /*if(count==20) {
        	   System.out.println(begin);
        	   break;
           } */
            
           
            if(check(mid)==true) {
                end = mid;
            }
            else {
                begin = mid+1;
            }
            //count+=1;
        }
       
        return begin;
    }
 
}