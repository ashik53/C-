package HackerRank;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class JavaGenerics {
	
	
    public static void main(String[] args) {
		List<Integer> intList = Arrays.asList(1,2,3);
		List<String> strList = Arrays.asList("Hello","World");
		
		printArray(intList);
		printArray(strList);
	}
    
    static <T> void printArray (List<T>list) {
    	for(int i=0;i<list.size();i++) {
    		System.out.println(list.get(i));
    	}
    }
}
