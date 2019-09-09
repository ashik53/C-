//Working program with FastReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class fourthday
{
 static class FastReader
 {
     BufferedReader br;
     StringTokenizer st;

     public FastReader()
     {
         br = new BufferedReader(new
                  InputStreamReader(System.in));
     }

     String next()
     {
         while (st == null || !st.hasMoreElements())
         {
             try
             {
                 st = new StringTokenizer(br.readLine());
             }
             catch (IOException  e)
             {
                 e.printStackTrace();
             }
         }
         return st.nextToken();
     }

     int nextInt()
     {
         return Integer.parseInt(next());
     }

     long nextLong()
     {
         return Long.parseLong(next());
     }

     double nextDouble()
     {
         return Double.parseDouble(next());
     }

     String nextLine()
     {
         String str = "";
         try
         {
             str = br.readLine();
         }
         catch (IOException e)
         {
             e.printStackTrace();
         }
         return str;
     }
 }

 static void prln(Object any) {

	 System.out.println(any);

 }

 static void pr(Object any) {

	 System.out.print(any);

 }

 public static void main(String[] args)
 {
     FastReader myScanner =new FastReader();

     int teamList[] = new int[2001];

		int n,k,max_team_count = 0,remainder;

		n = myScanner.nextInt();
		k = myScanner.nextInt();

		for(int i=0;i<n;i++) teamList[i] = myScanner.nextInt();

		for (int c = 0 ; c < ( n - 1 ); c++)
		  {
		    for (int d = 0 ; d < n - c - 1; d++)
		    {
		      if (teamList[d] > teamList[d+1]) /* For decreasing order use < */
		      {
		        int swap       = teamList[d];
		        teamList[d]   = teamList[d+1];
		        teamList[d+1] = swap;
		      }
		    }
		  }// bubble sort

		for(int i=1;i<=n;i++)
		{
			int index = i-1;

			if(i%3==0)
			{
				remainder = 5-teamList[index];

				if(remainder>=k) max_team_count++;
			}
		}

		prln(""+max_team_count);
 }



	 }//main class end here
