
#include <bits/stdc++.h>
using namespace std;

int ara[107];
int sz;

int binary_search_func(int element);

int main(void){

    int element;

    cin >> sz;

    for(int i = 0; i < sz; i++){
        cin >> ara[i];
    }

    sort(ara, ara+sz);

    while(cin >> element){
        if(binary_search_func(element) == -1){
            cout << element << " can not be founded\n";
        } else {
            cout << "found at " << binary_search_func(element)+1<< " position\n";
        }
    }

} // main func

int binary_search_func(int element){

    int low = 0, high = sz-1;

    while(low <= high){

       int mid = (low + high) /2;

       if(ara[mid] == element) return mid;
       else if(ara[mid] < element){
            low = mid + 1;
       } else {
            high = mid - 1;
       }

    }//while

    return -1;


}//


