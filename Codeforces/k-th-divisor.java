import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Codeforces762A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		long k = sc.nextLong();
		ArrayList<Long> list = new ArrayList<Long>();
        for(long i = 1;i*i<=num;i++) {
        	if(num%i==0) {
        		list.add(i);
        		if(i!=(num/i))list.add(num/i);
        	}
        }
        
        Collections.sort(list);
        boolean gett =false;
        for(int i=0;i<list.size();i++) {
        	if(i+1==k) {
        		System.out.println(list.get(i));
        		gett = true;
        	}
        }
        if(gett==false) System.out.println("-1");
        
        
	}
}