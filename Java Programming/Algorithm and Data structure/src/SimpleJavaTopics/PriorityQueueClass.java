package SimpleJavaTopics;

import java.util.HashMap;
import java.util.PriorityQueue;

public class PriorityQueueClass {
    public static void main(String[] args) {
		PriorityQueue<Book> pQueue = new PriorityQueue<Book>();
		
		pQueue.add( new Book("C++",100) );
		pQueue.add( new Book("Java",89) );
		pQueue.add( new Book("Python",120) );
		pQueue.add( new Book("A",110) );
       
		
		//System.out.println("Queue top: "+pQueue.peek());
		
	   while(pQueue.size()!=0) {
		   System.out.println(pQueue.peek().name+" "+pQueue.peek().id);
		   pQueue.poll();
	   }
    	HashMap<String,Integer> hs = new HashMap<String,Integer>();
    	//hs.put("ashik",123);
    	System.out.println(hs.get("ashik"));
	}//main
    static class Book implements Comparable<Book>{
       
    	int id;
    	String name;
    	Book(String  name,int id){
    		this.id = id;
    		this.name = name;
    	}
    	
    	
    	
	
		public int compareTo(Book b) {
			 if(id>b.id) return 1;
			 else if(id<b.id) return -1;
			 return 0;
		}
    	
    };
} 
