package Practice;

import java.util.*;

public class MapExercise implements Pair {
	int n1,n2;
    public static void main(String[] args) {
		
		MapExercise mp = new MapExercise();
		
		Pair p = new MapExercise();
		p.setValue(101, 102);
		
		p.printValue();
	}

	@Override
	public void setValue(int n1, int n2) {
		
		this.n1 = n1;
		this.n2 = n2;
	}

	@Override
	public void printValue() {
		System.out.println(n1+" "+n2);
	}
}
