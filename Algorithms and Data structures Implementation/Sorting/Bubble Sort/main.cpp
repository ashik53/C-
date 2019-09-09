#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int ara[107];

void bubble_sort(int sz);


int main(void){

    int sz;

    cin >> sz;
    for(int i = 0; i < sz ; i++){
       cin >> ara[i];
    }//for

    bubble_sort(sz);

    for(int i = 0; i < sz; i++){
        cout << ara[i] << " ";
    }

    cout << endl;

} //
 void bubble_sort(int sz){

    for(int i = 0; i < sz; i++){
        for(int j =  0; j < sz - i - 1; j++){
            if(ara[j] > ara[j+1]){
                int temp = ara[j];
                ara[j] = ara[j+1];
                ara[j+1] = temp;
            }
        }
    }


 }//

