#include <bits/stdc++.h>

using namespace std;

int numbersAra[107], frequencyAra[107];
int sizeOfAra, limit, ans, i ;
int True, info[100007];
bool vis[101][100001][2];

void recursion(int index, int amount,int status, int estimation);
bool amountCheck(int amount){

    if(amount >= 1 && amount <= limit) return true;

    return false;

}
int main(){

    int cases;

    scanf("%d",&cases);
    for(int line = 0; line < cases; line++){
        scanf("%d%d", &sizeOfAra, &limit);
        for(int i = 0; i < sizeOfAra; i++){
            scanf("%d", &numbersAra[i]);
        }
        for(int i = 0; i < sizeOfAra; i++){
            scanf("%d", &frequencyAra[i]);
        }
        //
        True++;
        info[0] = True;
        ans = 0;
        memset(vis, false, sizeof(vis[0][0][0]) * 101 * 100001 * 2);
        recursion(0,0,0,0);
        printf("Case %d: %d\n",line+1,ans);
    }//cases
}
void recursion(int index, int amount,int status, int estimation){

    cout << index <<" " << amount << " " << status << endl;

    if(index == sizeOfAra) return;

    if(vis[index][amount][status] == true){
       cout << "call ageo aschilo :: " <<  index << " " << amount << " " << status << endl;
        return ;
    }
    vis[index][amount][status] = true;

    if(info[amount]!= True && amountCheck(amount) == true){
        ans++;
        info[amount] = True;
    }

    /// recursion calling structure

    if(!status) estimation = amount + (numbersAra[index] * frequencyAra[index]);


    if(amountCheck(amount+numbersAra[index]) == true && amount+numbersAra[index] <= estimation){
        recursion(index, amount+numbersAra[index], 1, estimation);
    }
    recursion(index+1, amount, 0, 0); // not take the coin

}
