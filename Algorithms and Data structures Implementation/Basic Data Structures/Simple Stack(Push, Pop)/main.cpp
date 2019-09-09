/// interviewbit, LIS, unsolved

#include <bits/stdc++.h>
using namespace std;

int sz, lastIndex;
int ara[107];

void pop();
void push(int item);
void print();
int main(void){

    int item;

    cin >> sz;

    lastIndex = 0;

    while(lastIndex != sz){
        cin >> item;
        push(item);
    }

    while(lastIndex != -1){
        pop();
    }

}

void pop(){

    lastIndex -= 1;
    ara[lastIndex] = -99;

    print();
}//
void push(int item){

    ara[lastIndex] = item;

    print();

    lastIndex++;

}//push
void print(){

    for(int i = lastIndex ; i >= 0; i--){

        cout << ara[i] << " ";
    }
    cout << endl;

}



