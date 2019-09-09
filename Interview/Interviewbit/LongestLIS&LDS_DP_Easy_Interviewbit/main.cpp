///unsolved

#include <bits/stdc++.h>

using namespace std;


int ara[1007];
int dpAraPos[1007][1007][2][2], dpAraNeg[1007][1007][2][2], visPos[1007][1007][2][2], visNeg[1007][1007][2][2];
int sz, True;

int biggest(int a, int b){

    if(a > b) return a;
    return b;

} //biggest
int recursion(int index, int num, int inc, int dec){

    if(index == sz) return 0;

    if(num < 0){
        if(visNeg[index][num*-1][inc][dec] == True){
            return dpAraNeg[index][num*-1][inc][dec];
        }
        visNeg[index][num*-1][inc][dec] = True;
    }else {
        if(visPos[index][num][inc][dec] == True){
            return dpAraPos[index][num][inc][dec];
        }
        visPos[index][num][inc][dec] = True;
    }

    int ans1 = 0;
    int ans2 = 0;

    if(inc == 1 && num < ara[index] ){
        ans1 =  1 +  recursion(index+1, ara[index], 1, 0);
    } else if(inc == 1 && num > ara[index]){
        ans1 =  1 +  recursion(index+1, ara[index], 0, 1);
    }
    else if(dec == 1 && num > ara[index]){
        ans1 = 1 + recursion(index+1, ara[index], 0, 1);
    }

    ans2 = 0 + recursion(index+1, num, inc, dec);

    int finalAns = biggest(ans1, ans2);

    if(num < 0){
        return dpAraNeg[index][num*-1][inc][dec] = finalAns;
    }

    return dpAraPos[index][num][inc][dec] = finalAns;

} //recursion

int solution(const vector<int> &A){

    unsigned int len = A.size();
    sz =  len;
    True++;
    for(int i = 0; i < len; i++){
        ara[i] = A[i];
    }

    return recursion(0,-999, 1, 0);
} //solution
int main(){

    int elem;
    vector<int> A;

    while(cin >> sz){
        for(int i  = 0; i < sz; i++){
            cin >> elem;
            A.push_back(elem);
        }


        cout << solution(A) << endl;

    } //while

} //main




