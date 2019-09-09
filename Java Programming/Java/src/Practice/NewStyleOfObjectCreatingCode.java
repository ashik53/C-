package Practice;

public class NewStyleOfObjectCreatingCode {
	String name, roll;
	NewStyleOfObjectCreatingCode(String name,String roll){
    	 
    	 this.name = name;
    	 this.roll = roll;
    	 
     }
     
     public void print() {
    	 System.out.print("name: "+this.name+"\n"+"roll: "+this.roll);
     }
     public static void main(String[] args) {
		(new NewStyleOfObjectCreatingCode("Ashik","123")).print();
	}
}
