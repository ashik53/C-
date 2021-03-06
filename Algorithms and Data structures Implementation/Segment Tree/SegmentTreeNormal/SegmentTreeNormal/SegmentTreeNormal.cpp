// SegmentTreeNormal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define mx 100001
int ara[mx];
int segmentTree[mx * 3];
void buildTree(int node, int be, int en)
{
	if (be == en) {
		segmentTree[node] = ara[be];
		return;
	}
	int Left = node * 2;
	int Right = node * 2 + 1;
	int mid = (be + en) / 2;
	buildTree(Left, be, mid);
	buildTree(Right, mid + 1, en);
	segmentTree[node] = segmentTree[Left] + segmentTree[Right];
}
int query(int node, int be, int en, int i, int j)
{
	if (i > en || j < be) {
		return 0;
	}
	if (be >= i && en <= j)
		return segmentTree[node]; //রিলেভেন্ট সেগমেন্ট
	int Left = node * 2; //আরো ভাঙতে হবে
	int Right = node * 2 + 1;
	int mid = (be + en) / 2;
	int p1 = query(Left, be, mid, i, j);
	int p2 = query(Right, mid + 1, en, i, j);
	return p1 + p2; //বাম এবং ডান পাশের যোগফল
}
void update(int node, int be, int en, int i, int newvalue)
{
	if (i > en || i < be)
		return; //বাইরে চলে গিয়েছে
	if (be >= i && en <= i) { //রিলেভেন্ট সেগমেন্ট
		segmentTree[node] = newvalue;
		return;
	}
	int Left = node * 2; //আরো ভাঙতে হবে
	int Right = node * 2 + 1;
	int mid = (be + en) / 2;
	update(Left, be, mid, i, newvalue);
	update(Right, mid + 1, en, i, newvalue);
	segmentTree[node] = segmentTree[Left] + segmentTree[Right];
}
int main()
{
	int sz, operationSize,low,high,index,newValue;
	
	scanf_s("%d%d", &sz,&operationSize);

	for (int i = 0; i < sz; i++) {
		scanf_s("%d", &ara[i]);
	}
	getchar();
	buildTree(1, 0, sz - 1);
	char choice;
	for (int i = 0; i < operationSize; i++) {
		scanf_s("%c", &choice);
		//cout << choice << endl;
		if (choice == 'q') {
			scanf_s("%d%d", &low, &high);
			int ans = query(1, 0, sz - 1, low - 1, high - 1);
			printf("%d\n", ans);
		}
		else {
			scanf_s("%d%d", &index,&newValue);
			update(1, 0, sz - 1, index - 1, newValue);
		}
		getchar();
	}//loop



}

