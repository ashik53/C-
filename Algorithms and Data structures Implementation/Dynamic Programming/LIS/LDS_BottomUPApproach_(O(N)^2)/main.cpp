#include <bits/stdc++.h>
using namespace std;

int sz ; // number of items in the sequence
int Sequence[32]; //the sequence of integers;
int L[32]; /// L[] is to get the LIS value of each index of Sequence array;
int SolutionAra[32]; ///SolutionAra is to store sequence of a 'LIS';

void takeInput(){

    scanf("%d",&sz); //how many numbers in the sequence

    //take the sequence
    for(int i=0;i<sz;i++){
        scanf("%d",&Sequence[i]);
    }
}

// which runs the LIS algorithm and returns the result
int LDS(){

    int i,j; //auxiliary variables for iteration

    ///initialize L[] with 1
    for( i = 0; i < sz; i++) {
        L[i] = 1;
    }

    ///start from the left most item and iterate right

    for( i = 0; i < sz; i++){
        /// for the ith item item find all items that are in right
        for( j = i+1; j < sz; j++){
            if( Sequence[j] < Sequence[i] ) {
                 // the item is greater than the ith item
                // so, L[j] = L[i] + 1, since jth item can be added after ith
                // item. if L[j] is already greater than or equal to L[i] +
                // then ignore it
                if( L[j] <  L[i] + 1 ){
                    L[j] = L[i] + 1;
                }
            }
        }

    }

    ///now find the item whose L[] value is maximum
    int maxLength = 0;
    for( int i = 0; i < sz; i++){
        if( maxLength < L[i]){
            maxLength = L[i];
        }
    }

    ///return the result
    return maxLength;
}
void soutionPrinting(){

    ///find the maximum length and it's index
    int maxLen = 0, index = -1;
    for(int i = 0; i < sz; i++ ){
        if(maxLen < L[i]){
            maxLen = L[i];
            index = i;
        }
    }

    ///insert result into 'SolutionAra'
    int j = maxLen - 1; SolutionAra[j] = Sequence[index]; /*যেহেতু  SolutionAra 0 তম ইনডেক্স থেকে শুরু হবে তাই আমরা  maxLen এর মান

            ১ কমিয়ে নিচ্ছি, এবং SolutionAra[] এর তম j তম ইনডেক্সে আমরা  Sequence[maxLen] value টা insert করছি  */

    for(int i = index-1; i >= 0; i--){
        if(L[i] == j && Sequence[index] > Sequence[i]){
            SolutionAra[--j] = Sequence[i];
            index = i;
        }
    }

    //print the Solution

    cout << "Result : ";
    for(int i = 0; i < maxLen; i++){
        cout << SolutionAra[i] << " ";
    }
    cout << endl;

} //solution printing
int main()
{
    takeInput();
    int result = LDS(); ///LDS calculating
    printf("The LDS Length is %d\n",result);
    //soutionPrinting(); /// solution printing
    return 0;
}
