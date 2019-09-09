#include <bits/stdc++.h>

using namespace std;

string solution(string &A){

    string str = A;
    int len = str.size();

    vector <char> stck; //vecctor is used as stack

    for(int i = 0; i < len; i++){
        stck.push_back(str[i]);
    }//for

    len = stck.size();
    string newStr = "";

    while(len!=0){
        newStr += stck[len-1];
        len--;
        stck.pop_back();
    } //while

    return newStr;
} //solution





int main(){

    string str;

    while(getline(cin, str)){
        cout << solution(str) << endl;
    } //while
} //main
