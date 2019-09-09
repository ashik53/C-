
/*
    This solution requires O(length *(length + length)) complexity
    but we can improve it by adding "binary search". Then complexity will be O(log(length) * length)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

map<i64, int> got;

i64 HashComputation(string &s, int sz, i64 Base, i64 Mod);
int matchFunc(string &str1, string &str2, int sz);
int solution(string &str1, string &str2);

int main(){
    string str1, str2;
    int givenLength;

    while(cin >> str1 >> str2){
        cout << solution(str1, str2) << endl;
    } // loop
} // main
int solution(string &str1, string &str2){

    int en = min(str1.size(), str2.size());

    int be = 1;

    while(be <= en){
        int mid = (be + en) / 2;
       // cout << be  << " " << en << " " << mid << endl;
        if(matchFunc(str1, str2, mid) == 1){
            be = mid + 1;
           // cout << "got " << " be  = " << be << endl;
        } else {
            en = mid - 1;
            //cout << "not got " << " be  = " << en << endl;
        }
    } // while loop

    return en;

}
i64 HashComputation(string &s, int sz, i64 base, i64 Mod){
    i64 hashValue = 0, power = 1;
    for(int i = sz - 1; i >= 0; i--){
        hashValue = (hashValue + ((s[i] * power) % Mod)) % Mod;
        power = ((power * base) % Mod);
    }
    return hashValue;

} //hashFunc
int matchFunc(string &str1, string &str2, int sz){

    got.clear();
    i64 base = 347 , Mod = 1000000000+7;

    //cout << "at first\n";
    if(str1.size() < sz || str2.size() < sz) return 0;

    i64 power = 1;
    for(int i = 1; i < sz; i++){
        power = (power * base) % Mod;
    }

    string subStr1 = str1.substr(0, sz);
    string subStr2 = str2.substr(0, sz);

    i64 hashFirst = HashComputation(subStr1, sz, base, Mod);
    got[hashFirst] = 1;

    //if(hashFirst == hashLast) return 1;

    /// hash computation of str1
    for(int i = sz; i < str1.size(); i++){
        hashFirst = (hashFirst - ((power * str1[i-sz]) % Mod)) % Mod;
        hashFirst = (hashFirst + Mod) % Mod;
        hashFirst = (hashFirst * base) % Mod;
        hashFirst = (hashFirst + str1[i]) % Mod;
        ///insert inside map
        got[hashFirst] = 1;

    }// loop

    i64 hashLast  = HashComputation(subStr2, sz, base, Mod);
    if(got[hashLast]) return 1;

    /// hash computation of str2
    for(int i = sz; i < str2.size(); i++){
        hashLast = (hashLast - ((power * str2[i-sz]) % Mod)) % Mod;
        hashLast = (hashLast + Mod) % Mod;
        hashLast = (hashLast * base) % Mod;
        hashLast = (hashLast + str2[i]) % Mod;
        ///search inside map
        if(got[hashLast] == 1) return 1;
    }// loop

    return 0;

} // matchFunc

