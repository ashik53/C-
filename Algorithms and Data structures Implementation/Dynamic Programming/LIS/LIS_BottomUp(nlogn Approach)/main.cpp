#include <bits/stdc++.h>

using namespace std;

int sz ; // number of items in the sequence
int Sequence[32]; //the sequence of integers;
int L[32]; /// L[] is to get the LIS value of each index of Sequence array;
int SolutionAra[32]; ///SolutionAra is to store sequence of a 'LIS';
int I[32]; /// এই আরেতে Sequence[] এর সংখ্যা গুলো অ্যাসেন্ডিং অর্ডারে থাকবে

int differenceCalculating(int a, int b){

    if(b>a) return b-a;

    return a-b;
}
int binarySearch(int be, int en, int searchValue){


    while(true){

        if(differenceCalculating(be, en) <= 1){
            return en;
        }

        int mid = (be+en)/2;

        if(I[mid] >= searchValue) en = mid;
        else be = mid;

    }


}
int LIS_calculation(int sz){

    int maxLen = 0;
    for(int i = 1; i <= sz; i++){
        int index = binarySearch(0, sz, Sequence[i]); /// find the index of an element of Sequence[] one by one
        I[index] = Sequence[i];
        L[i] = index;
        //cout<< i << ", "<<Sequence[i]<<", "<<index << endl;
        maxLen = max(maxLen,index);
    }

    return maxLen;

}

int main()
{
    int inf = 200000000;

	//অ্যারে এলিমেনট গুলো ইনপুট নিলাম 
	
    cin >> sz;
    for(int i = 1; i <= sz; i++){
        cin >> Sequence[i];
    }

    ///fill the I[] array with -inf and inf
    fill_n(I,sz+1,inf);
    I[0] = inf*(-1);

    ///call the LIS calculating function
    int LIS = LIS_calculation(sz);
    cout << "LIS is " << LIS << endl;

}
