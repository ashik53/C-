#include <bits/stdc++.h>

using namespace std;

string convertToLowerCases(string &str){

    string s = "";
    int len = str.size();
    int dif = (int)'a' - (int)'A';
    for(int i = 0; i < len; i++)
    {
         char ch = str[i];
         //cout << ch << endl
         if((int)ch >= (int)'A' && (int)ch <= (int)'Z'){
            int value = (int)ch + dif;
            s += (char)value;
         } else if(((int)ch >= (int)'a' && (int)ch <= (int)'z') || ((int)ch >= (int)'0' && (int)ch <= (int)'9')){
            s += ch;
         }
    }

    //cout << s << endl;
    return s;
} // func

int isPalindrome(string &str){
    int len = str.size();
    for(int  i = 0, j = len - 1; i < len && j >= 0; i++, j--){
        if(str[i] != str[j]) return 0;
    }

    return 1;
}

int solution(string &str){

       str = convertToLowerCases(str);
       //cout << str << endl;

       if(isPalindrome(str) == 1) return 1;

       return 0;
} //solution
int main(){
    string str;
    while(getline(cin, str)){
        int ans = solution(str);
        cout << ans << endl;
    }

}
