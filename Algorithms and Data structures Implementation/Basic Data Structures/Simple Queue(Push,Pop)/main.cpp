/// interviewbit, LIS, unsolved

#include <bits/stdc++.h>
using namespace std;

int sz, lastIndex, frontIndex;
int ara[107];

bool pop();
bool push(int item);
void print();
int main(void){

    int item;

    cin >> sz;

    lastIndex = 0;
    frontIndex = 0;

    while(true){
        cin >> item;
        if(!push(item)) break;
    }

    while(true){
        if(!pop()) break;
    }

}

bool pop(){

    if(lastIndex == frontIndex) {
        cout << "can not deleted\n";
        return false;
    }

    ara[frontIndex] = -99;
    frontIndex++;


    print();

    return true;
}//
bool push(int item){

    if(lastIndex == sz){
        cout << "Queue is full\n";
        return false;
    }

    ara[lastIndex] = item;

    lastIndex++;

    print();



    return true;

}//push
void print(){


    for(int i = 0; i < lastIndex; i++){

        cout << ara[i] << " ";
    }
    cout << endl;

}



