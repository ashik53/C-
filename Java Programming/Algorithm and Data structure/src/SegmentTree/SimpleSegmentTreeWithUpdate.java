package SegmentTree;

public class SimpleSegmentTreeWithUpdate {
	static int  max =100001;
	static int ara[]= new int [max];
	static int tree[]= new int[max*3];
	void buildTree(int node, int begin, int end)
	{
	    if (begin == end) {
	        tree[node] = ara[begin];
	        return;
	    }
	    int Left = node * 2;
	    int Right = node * 2 + 1;
	    int mid = (begin + end) / 2;
	    buildTree(Left, begin, mid);
	    buildTree(Right, mid + 1, end);
	    tree[node] = tree[Left] + tree[Right];
	}
	static int query(int node, int begin, int end, int i, int j)
	{
	    if (i > end || j < begin)
	        return 0; 
	    if (begin >= i && end <= j)
	        return tree[node]; 
	    int Left = node * 2; 
	    int Right = node * 2 + 1;
	    int mid = (begin + end) / 2;
	    int p1 = query(Left, begin, mid, i, j);
	    int p2 = query(Right, mid + 1, end, i, j);
	    return p1 + p2; 
	}
	static void update(int node, int begin, int end, int i, int newvalue)
	{
	    if (i > end || i < begin)
	        return; 
	    if (begin >= i && end <= i) { 
	        tree[node] = newvalue;
	        return;
	    }
	    int Left = node * 2; 
	    int Right = node * 2 + 1;
	    int mid = (begin + end) / 2;
	    update(Left, begin, mid, i, newvalue);
	    update(Right, mid + 1, end, i, newvalue);
	    tree[node] = tree[Left] + tree[Right];
	}
}//main class
