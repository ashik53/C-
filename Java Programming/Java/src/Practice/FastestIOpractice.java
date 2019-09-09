package Practice;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FastestIOpractice {
	public static void main(String[] args) throws IOException {
		Reader userInput = new Reader ();
		out = new PrintWriter(new BufferedOutputStream(System.out),true);
	      int a = userInput.nextInt();
	      double b = userInput.nextInt();
	      String s  = userInput.nextLine();
	      Long l = userInput.nextLong();
	      
	      out.println(a+" "+b+" "+s+" "+l);
	     
	      out.close();
	
	}

	static PrintWriter out;
	   
    static class Reader {
        BufferedReader br;
        StringTokenizer st;
 
        public Reader() {
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
    }
}
