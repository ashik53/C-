#include <bits/stdc++.h>
using namespace std;

void solution(string &A);
int main(){
    string str;

    while(getline(cin, str)){
        solution(str);
    }//input
}

void solution(string &A){


    vector<string> result;
    string s = "";

    string str = A;
    int len = A.size(), x = 0;
    for(int i = 0; i < len; i++){
        //cout << str[i] ;
        if(i == len-1 || str[i] == ' '){
            if(i == len-1 && str[i]!= ' ' ) {x++; s.push_back(str[i]);}
            if(x > 0){
                result.push_back(s);
                s.clear();
                x = 0;
            }
            s.clear();
            x = 0;
        } else {
            s.push_back(str[i]);
            x++;
        }
    }//loop

    reverse(result.begin(), result.end());
    str.clear();
    //cout << result[0] << << endl;

    for(int i = 0; i < result.size(); i++){

        str += result[i];
        //cout << result[i];

        if(i != result.size() - 1) {/*cout << " ";*/str += ' ';}

    }// last insertion loop

    cout << str << endl;
    //cout << endl;

} // func
