package Lightoj;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Lightoj1039BFS {
	static Scanner userInput = new Scanner(System.in);
	static int[] distance = new int[300];
	static HashMap<String, Integer> keyValue = new HashMap<String, Integer>();
	static ArrayList<String>[] forbiddenList = (ArrayList<String>[]) new ArrayList[300];
	static Queue<Node> mq = new LinkedList<>();
	static int forbiddenSize;

	public static void main(String[] args) {
		String xyz = "aaa";
		int value = 0;
		keyValue.put(xyz, value);
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j < 26; j++) {
				char ch = xyz.charAt(i);
				ch = (char) (((int) ch) + 1);
				xyz = replaceCharAt(xyz, i, ch);
				value++;
				keyValue.put(xyz, value);
				System.out.println(xyz+" : "+keyValue.get(xyz));
			}
		}

		while (true) {

			for (int i = 0; i < 300; i++) {
	
				forbiddenList[i] = new ArrayList<String>();
				distance[i] = 0;
			

			}
			String start = userInput.nextLine();
			String finish = userInput.nextLine();

			forbiddenSize = userInput.nextInt();
			xyz = userInput.nextLine();
			for (int i = 0; i < forbiddenSize; i++) {
				xyz = userInput.nextLine();
				stringMaking(xyz, i);
			}

			int ans = bfs(start, finish);
           System.out.println(ans);
		} // cases

	}// main method
	
	static class Node {
		int vertexInt;
		String vertexString;
		 Node(int vertexInt, String vertexString) {
			
			this.vertexInt = vertexInt;
			this.vertexString = vertexString;
		}
		
	};

	public static int bfs(String start, String finish) {
		System.out.println(keyValue.get(start));
		int st = keyValue.get(start);
		
		int end = keyValue.get(finish);

		mq.clear();
        
		mq.add(new Node(st,start));
		while(mq.size()!=0) {
			Node front = mq.peek();
			mq.poll();
			if(front.vertexInt==end) return distance[end];
			List<String> list = queueMaking(front.vertexString);
			for(int i=0;i<list.size();i++) {
				String xyz = list.get(i);
				int value = keyValue.get(xyz);
				distance[value] = distance[front.vertexInt]+1;
				mq.add(new Node(value,xyz));
			}
			
			
		}//queue
		
		return -1;

	}//bfs func 

	public static List<String> queueMaking(String abc) {
      // System.out.println("Parent node:\n "+abc+"\nChild: ");
		ArrayList<String> list = new ArrayList<>();
		List<String> list2 = new ArrayList<>();
		for (int j = 0; j < 3; j++) {
			char c = abc.charAt(j);
			if (c == 'a') {
				String xyz = replaceCharAt(abc, j, 'z');
				list.add(xyz);
				xyz = "";
				xyz = replaceCharAt(abc, j, 'b');
				list.add(xyz);
			} else if (c == 'z') {
				String xyz = replaceCharAt(abc, j, 'a');
				list.add(xyz);
				xyz = "";
				xyz = replaceCharAt(abc, j, 'y');

				list.add(xyz);
			} else {
				int b = ((int) c) + 1;
				char d = (char) b;
				String xyz = replaceCharAt(abc, j, d);
				list.add(xyz);
				xyz = "";
				b = ((int) c) - 1;
				d = (char) b;
				xyz = replaceCharAt(abc, j, d);
				list.add(xyz);

			}
		} // loop

		for (int i = 0; i < list.size(); i++) {
			String xyz = list.get(i);
			if(checkStringIsValid(xyz)==true) {
				list2.add(xyz);
				//System.out.println(xyz);
			}
		}
          
		return(list2);
		
	}/// func

	public static boolean checkStringIsValid(String str) {

		for (int i = 0; i < forbiddenSize; i++) {
			if (forbiddenList[i].get(0).indexOf(str.charAt(0)) >= 0 && forbiddenList[i].get(1).indexOf(str.charAt(1)) >= 0
				&& forbiddenList[i].get(2).indexOf(str.charAt(2)) >= 0	) { 
				return false;
			}
		
		}

		return true;
	}

	public static void stringMaking(String str, int index) {
		String s = "";
		for (int i = 0; i <= str.length(); i++) {
			if (i == str.length() || str.charAt(i) == ' ') {
				forbiddenList[index].add(s);
				
				//System.out.println(s);
				s = "";
			} else {
				s += str.charAt(i);
			}

		}

	}

	public static String replaceCharAt(String s, int pos, char c) {
		return s.substring(0, pos) + c + s.substring(pos + 1);
	}

}
