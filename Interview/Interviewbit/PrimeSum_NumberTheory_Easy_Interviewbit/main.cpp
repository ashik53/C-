#include <bits/stdc++.h>

using namespace std;

#define mx  2*1000000
int primeDetectionAra[mx+7];

vector <int> onlyPrime;

void sieve(){

    primeDetectionAra[0] = 1;
    primeDetectionAra[1] = 1;

    for(int i = 2; i * i <= mx;){ //for
        if(i == 2 && primeDetectionAra[i] == 0){
            onlyPrime.push_back(i);
            for(int j = i+i; j <= mx; j+=i){
                primeDetectionAra[j] = 1;
            } //for
            i++;
        }// if i == 2
        else if(primeDetectionAra[i] == 0){
            onlyPrime.push_back(i);
            for(int j = i+i+i; j <= mx; j = j+i+i){
                primeDetectionAra[j] = 1;
            } //for
            i+=2;
        }// if i > 2
        else i+=2;
    }// sieve loop



} //sieve

bool checkPrime(int n){

    if(n == 0 || n == 1) return 0;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;

    for(int i = 3; i*i <= n; i+=2){
        if(n%i == 0) return 0;
    } //for

    return 1;

} //check prime
vector<int> solution(int A){


    vector<int> ans;

    int num = A;

    /*for(int i = 0; onlyPrime[i] <= num; i++){
        if(primeDetectionAra[num - onlyPrime[i]] == 0){

            ans.push_back(onlyPrime[i]);
            ans.push_back(num - onlyPrime[i]);
            break;
        }
    }

    cout << ans[0] << ","<< ans[1] << endl;
    */

    for(int i = 2; i <= num; ){

        if(checkPrime(i) == 1 && checkPrime(num-i) == 1){
            ans.push_back(i);
            ans.push_back(num-i);
            break;
        }
        if(i == 2){
           i++;
        }else{
            i+=2;
        }
    } //for

     return ans;

} //solution
int main(){

    int num;

   /// onlyPrime.clear();
   /// sieve();

   /* while(cin >> num){
        solution(num);
    }//while */
    vector<int> ans;
    int big = -999;
    cout << "yes\n";
    for(unsigned int i = 4; i <= 2147483646; i+=2){
        ans = solution(i);
        if(ans[0] > big) big = ans[0];
        //cout << i <<":"<< ans[0] <<"," << ans[1]<< endl;
    } //for

    cout << big << endl;

} //main
