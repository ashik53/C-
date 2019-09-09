#include <bits/stdc++.h>
using namespace std;

#define llu unsigned long long
int coinList[]= {1, 5, 10, 25, 50};
llu dp[10][30007];
llu coinChange(int index,int taka);
int main()
{
   int taka;

   //initializing array
   for(int i=0;i<10;i++)
   {
       for(int j=0;j<30007;j++)
       {
           dp[i][j] = -1;
       }
   }


   for(int i=1 ;i<=30000;i++)
   {
       dp[4][i] = coinChange(4,i);
   }
   dp[4][0] = 1;
   while((scanf("%d",&taka))==1)
   {
       if(dp[4][taka]>1)
       {
          printf("there are %llu ways to produce %d cents change.\n",dp[4][taka],taka);
           continue;
       }
       printf("There is only 1 way to produce %d cents change.\n",taka);
   }

}//main function

//dynamic programming function
llu coinChange(int index, int taka)
{

    if(index<0) return 0;
    if(taka<0) return 0;
    if(taka ==0) return 1;

    if(dp[index][taka]!=-1) return dp[index][taka]; // if the result already computes, return the result

    llu ret1,ret2 ;
    ret1 = 0; ret2 = 0;

    ret1 = coinChange(index,taka-coinList[index]); // take the current coin
    ret2 = coinChange(index-1,taka); // instead of taking the current coin, move to the backward coin

    return dp[index][taka] =  ret1+ ret2; // return the result

}

