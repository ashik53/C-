#include <bits/stdc++.h>
using namespace std;
#define mx 1000
int value[mx],dp[mx],dir[mx],frequency[mx+7],n; // n == size of an array, frequency অ্যারেতে কয়টা LIS আছে  সেইটা কাউনট করবে

int longest(int u){

    if(dp[u]!=-1) return dp[u];
    int maxi = 0;

    for(int v = u+1; v<=n;v++){ //1st condition, v>u (serial maintain)
        if(value[v] > value[u]){// 2nd condition,  value[v] > value[u]

            if(longest(v) > maxi) { //I will take the highest value
                maxi = longest(v);
                dir[u] = v; // mark the parent directory
            }
        }
    }

    dp[u] = 1+maxi; //১ যোগ হবে কারণ u নম্বর নোডটাও পাথের মধ্যে আছে

    return dp[u];
}

// solution printing
void solution(int start){

    while(dir[start]!=-1){
        printf("index %d value %d\n",start,value[start]);
        start = dir[start];
        if(dir[start] == -1) printf("index %d value %d\n",start,value[start]);

    }
}

int main()
{
    int sz,startIndex; // যে ইনডেক্স হতে longest পাথ পাব সেই ইনডেক্স আমরা startIndex এ  সেভ করে রাখব
    value[0] = -10000;
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    memset(frequency,0,sizeof(frequency));

    cin >> sz;
    n = sz;
    for(int i=1;i<=sz;i++){
        cin >> value[i];
    }

    int LIS = -10;
    for(int i=1;i<=sz;i++){

        if(LIS<=longest(i)){
            LIS = max(LIS,longest(i));
            frequency[LIS]++;
        }
    }

    cout <<"max length of sequence = "<< LIS <<", frequency of LIS "<< frequency[LIS]<<endl;




}
