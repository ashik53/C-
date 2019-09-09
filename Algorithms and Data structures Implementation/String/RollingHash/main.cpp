#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 HashComputing(string &s, int sz, i64 Base, i64 Mod){

    i64 hashValue = 0, power = 1;
    for(int i = sz - 1; i >= 0; i--){
        hashValue = (hashValue + ((s[i] * power) % Mod)) % Mod;
        power = ((power * Base) % Mod);
    }
    return hashValue;
}

int match(string &text, string &pattern, i64 Base, i64 Mod){

    int sizeOfText    = text.size();
    int sizeOfPattern = pattern.size();

    if(sizeOfPattern > sizeOfText) return 0;
    if(sizeOfPattern == 0) return 0;
    if(sizeOfText == 0) return 0;

   // i64 Base = 347, Mod = 1000000000+7;

    /// calculate Base^(sizeOfPattern-1)
    i64 power = 1;
    for(int i = 1; i <= sizeOfPattern - 1; i++){
        power = (power * Base)%Mod;
    }

    ///find hash value of first m characters of text
    ///find hash value of pattern
    i64 hashValueOfText    = HashComputing(text, sizeOfPattern, Base, Mod);
    i64 hashValueOfPattern = HashComputing(pattern, sizeOfPattern, Base, Mod);

    ///check first 'sizeOfPattern' substring of text
    int ans = 0;
    if(hashValueOfPattern == hashValueOfText) ans++;

    ///now the main hash value computation pattern sized substring of text from index 'sizeOfPattern'
    for(int i = sizeOfPattern; i < sizeOfText; i++){
        ///Run rolling Hash
        hashValueOfText = (hashValueOfText - ((power * text[i-sizeOfPattern]) % Mod)) % Mod; /// exclude first char of substring
        hashValueOfText = (hashValueOfText + Mod) % Mod; /// consider negative value
        hashValueOfText = (hashValueOfText * Base) % Mod; /// multiply with base
        hashValueOfText = (hashValueOfText + text[i]) % Mod; /// add the first character

        if(hashValueOfText == hashValueOfPattern) ans++;
    } //loop

    return ans;
} //function

int bruteForceSolution(string &text, string &pattern){

    int sizeOfText    = text.size();
    int sizeOfPattern = pattern.size();

    if(sizeOfPattern > sizeOfText) return 0;
    if(sizeOfPattern == 0) return 0;
    if(sizeOfText == 0) return 0;

    int ans = 0;

    for(int i = 0; i < sizeOfText; i++){
        bool get = true;
        for(int j  = 0; j < sizeOfPattern && i+j < sizeOfText; j++){
            if(text[i+j] != pattern[j]) { // if pattern does not match with text's substring
                get = false;
                break;
            }
        }
        if(get) ans++;
    }

    return ans;

}// function

int main(){

    string text, pattern;

    while(cin >> text >> pattern){

        i64 Base = 347, Mod = 1000000000+7;

        i64 ans1 = match(text, pattern, Base, Mod);

        Base = 97, Mod = 102345689;

        i64 ans2 = match(text, pattern, Base, Mod);

        if(ans1 == ans2) cout << ans1 << endl;
        else cout << bruteForceSolution(text, pattern);

    }
}//main
