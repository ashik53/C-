#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

unsigned int coinAra[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned int limit = 300;
int sz = 11, True;
ULL dpAra[17][30007];
int vis[17][30007];

ULL recursion(int index, int amount){

    if(index == sz) return 0;
    if(amount > limit) return 0;
    if(amount == limit) return 1;
    if(vis[index][amount] == True) return dpAra[index][amount];

    vis[index][amount] = True;
    ULL ret1 = recursion(index, amount+coinAra[index]);
    ULL ret2 = recursion(index+1, amount);

    return dpAra[index][amount] = ret1 + ret2;

}
int main(){
    double input;
    while(cin >> input){
        int b = input;
        printf("%d\n",b);

        b += (1e-9);

        printf("%d\n",b);
    }
}


