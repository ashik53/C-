package MST;

public class DisJointSetUnionDSD {
	
	static int parent[] = new int[100];
         public static void main(String[] args) {
			
		}
         
      static void makeSet(int n) {
    	  parent[n] = n;
      }
      
      static void union(int a,int b) {
    	  int u = find(a);
    	  int v = find(b);
    	  
    	  if(u==v) System.out.println("They are already inside same set");
    	  else parent[u] = v;
    	  
      }
      
      static int find(int r) {
    	  if(parent[r]==r) return r;
    	  
    	  parent[r] = find(parent[r]);
    	  return parent[r];
    	  
    	  
      }
}
