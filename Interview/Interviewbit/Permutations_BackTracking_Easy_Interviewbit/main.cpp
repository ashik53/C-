#include <bits/stdc++.h>

using namespace std;
bool taken[100];

int fact(int limit){

    int num = 1;

    for(int i = 1; i <= limit; i++){
       num * = i;
    } //for

    return num;

} //for

vector<vector<int> > backtracking(vector<int> &elements, vector<vector<int> > &ans, vector<int> &sorted, int len, int sz){

    if(len == sz && fact(sz) == ans.size()){
        ans.push_back(sorted);
        return ans;
    }else if(len == sz){
        ans.push_back(sorted);
    }


    for(int i = 0; i < sz; i++){

        if(taken[i]) continue;
        taken[i] = true;
        sorted.push_back(elements[i]);



    } //for

} //void

void solution(vector<int> &A){

    vector<int> elements, sorted;
    elements = A;

    vector<vector<int> > ans;
    memset(taken, false, 100);
    ans = solution(elements, ans, sorted, 0, A.size());
    return ans;
} //solution


int main(){


} //main
