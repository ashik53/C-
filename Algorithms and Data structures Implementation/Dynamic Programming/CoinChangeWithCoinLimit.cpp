#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ll unsigned long long
using namespace std;
ll coinChangeWithLimit(int amount,int index,int remain);
ll dpTable[51][1007][22];
int coinList[51];
int coinLimit[51];

int main()
{
   int numberOfCoins ,amount;

   while(cin >>numberOfCoins>>amount)
   {
      for(int i=0;i<51;i++)
      {
        for(int j =0;j<1007;j++)
        {
           for(int k=0;k<22;k++)
           {
               dpTable[i][j][k] = -1;
           }
        }
      }

      for(int i=0;i<numberOfCoins;i++)
      {
          cin >>coinList[i];

      }

      for(int i=0;i<numberOfCoins;i++)
      {
          cin >>coinLimit[i];

      }

        ll ans = (coinChangeWithLimit(amount, numberOfCoins-1,coinLimit[numberOfCoins-1]))%100000007;

        cout<<ans<<endl;

   } //input loop
}

ll coinChangeWithLimit(int amount,int index,int remain)
{
    if(index<0) return 0;
    if(dpTable[index][amount][remain]!=-1) return dpTable[index][amount][remain];

    if(amount==0) return 1;



    ll ret1 = 0;
    ll ret2  = 0;
        //take
    if(amount-coinList[index]>=0 && remain-1>=0)
    {
      ret1 = (coinChangeWithLimit(amount-coinList[index],index,remain-1))%100000007; //take
    }

    ret2 =  (coinChangeWithLimit(amount,index-1,coinLimit[index-1]))%100000007; //not take

    return dpTable[index][amount][remain] = ((ret1%100000007)+(ret2%100000007))%100000007;



}
