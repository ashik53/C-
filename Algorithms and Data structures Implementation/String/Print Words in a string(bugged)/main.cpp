
#include <bits/stdc++.h>
using namespace std;

int ascii_value(char ch);

bool isChar(char ch){

    if(ascii_value(ch) >= ascii_value('a') && ascii_value(ch) <= ascii_value('z') ) return true;
    else if(ascii_value(ch) >= ascii_value('A') && ascii_value(ch) <= ascii_value('Z')) return true;

    return false;

}//


int print_words(string &str){

    int sz = str.size();
    string sub = "";

    for(int i = 0; i < sz; i++){

        if(isChar(str[i]) == true){

           sub.push_back(str[i]);

           if(i == sz-1){
              cout << sub << endl;

           }
        }else if (isChar(str[i]) == false && sub.size() > 0){
            cout << sub << endl;
            sub = "";
        }else {
            sub = "";
        }

    }//for

    sub= "";


}//
int ascii_value(char ch){

    return (int)ch;

}
int main(void){

    string str;

    while(true){

        getline(cin, str);

        cout << print_words(str) << endl;

    }//while

} // main func





