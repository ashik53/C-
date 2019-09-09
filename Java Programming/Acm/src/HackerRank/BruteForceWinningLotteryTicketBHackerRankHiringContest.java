package HackerRank;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

public class BruteForceWinningLotteryTicketBHackerRankHiringContest {

	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);
		int line = userInput.nextInt();
		String str2 = userInput.nextLine();
		ArrayList<String> list = new ArrayList<>();
		for(int i=0;i<line;i++) {
			list.add(userInput.next());
			
		}
		//System.out.println(list.size());
		int res = 0;
		for(int i=0;i<line;i++) {
			
			for(int j=i+1;j<line;j++) {
				
				TreeSet<Character> a = new TreeSet<Character>();
				//System.out.print(list.get(i)+" ");
				String str = list.get(i);
				for(int k=0;k<str.length();k++) {
					a.add(str.charAt(k));
				}
			
				//System.out.print(a.size()+" ");
				String str1 = list.get(j);
				//System.out.print(list.get(j)+" ");
				for(int k=0;k<str1.length();k++) {
					a.add(str1.charAt(k));
				}
				//System.out.print(a.size()+" ");
				if(a.size()==10) res++;
			//	System.out.print("\n");
			}//second
			//System.out.println();
		}
       System.out.println(res);
	}

}
