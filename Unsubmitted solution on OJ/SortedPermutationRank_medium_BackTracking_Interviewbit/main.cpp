#include<bits/stdc++.h>
using namespace std;

char ara[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m'};
int cnt[13];
vector <char> ans;
int len, seq;
void permute(int l){

    if(l == len){
        cout << ++seq << ":  ";
        for(int i = 0; i < len; i++){
            cout << ans[i];
        }
        cout << "\n";
        return;

    } //if

    for(int j = 0; j < len; j++){
        if(cnt[j] == 1) continue;
        cnt[j]++;
        ans.push_back(ara[j]);
        permute(l+1);
        cnt[j]--;
        ans.pop_back();
    }

} //func

int main(void){

    while(cin >> len){
        seq = 0;
        for(int i = 0; i < len; i++) cnt[i] = 0;
        ans.clear();
        permute(0);
    } //loop
} //main

