
///solved

#include <bits/stdc++.h>

using namespace std;

bool solution(string &str){

    int len = str.size();
    int sz = 0;
    vector<int> v;

    for(int i = 0; i < len ; i++){
        if( sz == 0 && (str[i] == '}' || str[i] == ']' || str[i] == ')')) return 0;
        else if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            v.push_back(str[i]);
            sz++;
        } //if
        else if(str[i] == ')'){
            if(v[sz-1] != '('){
                return false;
            }else {
                v.pop_back();
                sz--;
            }
        }
        else if(str[i] == '}'){
            if(v[sz-1] != '{'){
                return false;
            }else {
                v.pop_back();
                sz--;
            }
        }
        else if(str[i] == ']'){
            if(v[sz-1] != '['){
                return false;
            }else {
                v.pop_back();
                sz--;
            }
        }
    } //for

    if(sz) return false;
    return true;
} // func


int main()
{
    string str;

    while(getline(cin, str)){
        bool ans = solution(str);
        if(ans) cout << "true\n";
        else cout << "false\n";
    }//while



}
