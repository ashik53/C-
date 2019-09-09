#include <bits/stdc++.h>
using namespace std;

int getSquareRoot(int num){

    /*if(num < 0) value = num * (-1);
    else value = num; */

    long long  be = 0, en = (long long)num;

    while(be <= en){

        //cout << be << ", " << en << ", "<< (be+en)/2 <<endl;
        long long mid = (en + be) / 2;
        if(mid * mid == num){
            return mid;
        } else if((mid * mid) > num){
            en = mid - 1;
        } else {
            be = mid + 1;
        }
    }// binary search

    return (int)en;

}//get square root

int main(){
   int n;

   for(int i = 0; i <= 1000000; i++){
        int r1 = getSquareRoot(i);
        int r2 = floor(sqrt(i));

        if(r1 != r2){cout << "mismatch for "<< i  <<", r1 = " << r1 <<  " r2 is = " << r2 << endl; break;}
   }

   //cout << getSquareRoot(92682) << endl;

}
