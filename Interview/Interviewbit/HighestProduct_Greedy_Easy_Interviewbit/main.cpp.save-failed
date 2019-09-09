#include <bits/stdc++.h>

using namespace std;

int Solution(vector<int> &A){

    int first, second, third;
    unsigned int sz = A.size();

    first = A[0];
    for(unsigned int j=1; j< sz; j++){
        if(A[j] > first){
            first = A[j];
        }
    }

    int i = 0;
    while( i < sz){
        if(first != A[i]){
            second = A[i];
            break;
        }
        i++;
    }
    for(unsigned int j=0; j < sz; j++){
        if(A[j] > second && A[j]!= first){
            second = A[j];
        }
    }

    i = 0;
    while( i < sz){
        if(first!= A[i] && second!= A[i]){
            third = A[i];
            break;
        }
        i++;
    }
    for(unsigned int j=  0; j < sz; j++){
        if(A[j] > third && A[j]!= first && A[j]!= second){
            third = A[j];
        }
    }

    return first*second*third;

}// func
int main()
{
    int sz;

    while(cin >> sz){
        vector<int> A;

        for(int i = 0; i < sz; i++){
            int elem;
            cin >> elem;
            A.push_back(elem);
        }
        cout << Solution(A) << endl;

    }
}

