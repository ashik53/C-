#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
int recursion(int n,int r);
int coinChange(int index,int taka);
int dpTable[501][501];
int coinList[8] = {1,2,4,6,8,20,35,50};
int main()
{
   int numberOfCoins ,amount;

   while(cin >>amount)
   {
      for(int i=0;i<501;i++)
      {
        for(int j =0;j<501;j++)
        {
            dpTable[i][j] = -1;
        }
      }
       cout<< coinChange(7,amount)<<endl;

   } //while loop
}

int coinChange(int index,int taka)
{
    if(index<0 || taka<0) return 0;

    if(dpTable[index][taka]!=-1) return dpTable[index][taka];
    if(!taka) return 1;

    return dpTable[index][taka] = coinChange(index,taka - coinList[index]) + coinChange(index-1,taka);

}
