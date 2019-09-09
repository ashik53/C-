#include <bits/stdc++.h>
using namespace std;

int solution(int num){

    vector<char> str;

       while(num){
          int mod = num % 10;
          num /= 10;
          str.push_back(mod + '0');
       }

     int sz = str.size();

     for(int i = 0, j = sz - 1; i < sz; i++, j--){
        if(str[i] != str[j]){
             return 0;
        }
     }

     return 1;
}
int main(){

    int num;

    while(cin >> num){
        if(solution(num)) cout << "palin";
        else cout << "not palin";
        cout << "\n";
    }
}

