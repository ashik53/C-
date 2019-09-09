

/// interviewbit, count and say,solved

#include <bits/stdc++.h>
using namespace std;


string ara[100];

string intToString(int num){

    string str = "";

    if(!num) return "0";

    while(num){
        str += ((num % 10) + '0');
        //if(!num) break;
        num /= 10;
    }

    reverse(str.begin(), str.end());

    return str;
} //str

string func(string &str){

    int cnt = 1;
    char ch = 'a';
    int len = str.size();

    string newStr = "";

    for(int i = 0; i < len; i++){

        if(ch!= str[i]){
            if(i!= 0){
               //cout << ch  << ": " << cnt << endl;
               string subStr = intToString(cnt);
               newStr += (subStr);
               newStr += ch;
            }
            cnt = 1;
            ch = str[i];
        }else{
            cnt++;
        }

        if(i == len-1){
            //cout << ch  << ": " << cnt << endl;
            string subStr = intToString(cnt);
            newStr += (subStr);
            newStr += ch;
        }
    } //for

    return newStr;

} //func

string solution(int A){

    int num = A;

    string str  = "1";

    for(int i = 2; i <= num; i++){
        str = func(str);
    } //for

    return str;

} //solution
int main(void){



    int serial;

    while(cin >> serial){
        cout << solution(serial) << endl;
    } // while

} // main func


