package Practice;

import java.util.Arrays;
import java.util.List;

public class WildCardDemo {
	public static void main(String[] args) {
        List<Integer> list1 = Arrays.asList(4,5,6,7);
        
        //sum(Arrays.asList(1.2,1.3));
        System.out.println("sum is : "+sum(Arrays.asList(1.2,3.4)));
        //List<Number> list2 = Arrays.asList(4.6,6.7,7.8);
	}
	
	//public static void printOnly(List<? >list) {
	//	System.out.println(list);
	//}
	
	private static double sum(List<? extends Number > list) {
		double s = 0;
		
		for(Number n:list) {
			s+= n.doubleValue();
		}
		
		return s;
	}
}
