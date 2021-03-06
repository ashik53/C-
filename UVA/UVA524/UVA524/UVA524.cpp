// UVA524.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
bool prime[100], taken[100];
int ara[100];
int result[100];
void per(int size, int len, int last);
bool primeChecking(int sum);
int main()
{
	int cases = 1;
	string line;

	for (int i = 2; i <= 100; i++) {
		ara[i - 2] = i;
	}

	for (int i = 1; i < 100; i++) {
		if (primeChecking(i) == true) prime[i] = true;
		else prime[i] = false;
	}

	int input;
	while ((scanf_s("%d", &input)) == 1) {

		if (cases != 1) printf("\n");
		int size = input;
		

		for (int i = 0; i <= 20; i++) {
			taken[i] = false;
		}
		printf("Case %d:\n", cases);
		per(size, 1, 1);
		cases++;
	}//cases
}

void per(int size, int len, int last) {
	if (len == size) {

		if (prime[1 + result[size - 2]] == false) {
			return;
		}
			printf("1 ");
			for (int j = 0; j < size - 1; j++) {
				if (j == size - 2) {

					printf("%d\n", result[j]);
				}
				else
					printf("%d ", result[j]);
			}
			
		return;
	}

	for (int i = 0; i < size - 1; i++) {
		int sum = last;
		sum += ara[i];
		if (prime[sum] == true && taken[ara[i]] == false) {


			result[len - 1] = ara[i];
			taken[ara[i]] = true;
			per(size, len + 1, ara[i]);
			taken[ara[i]] = false;


		}

	}
}//per


bool primeChecking(int sum) {
	if (sum == 1) return false;
	for (int i = 2; i*i <= sum; i++) {
		if (sum%i == 0) return false;
	}

	return true;
}
