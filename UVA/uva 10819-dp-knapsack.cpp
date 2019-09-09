


//UVA-10819 dp, knapSack

/*How to compile
g++ -o main main.cpp, then main
*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int >

int sizeOfArray;;
int price[107],value[107];
int vis[1007][10007];
int dpAra[1007][10007];
int True;

int func(int index,int sum,bool take,int pocketMoney);
int main() {


    int pocketMoney;

    while(scanf("%d%d",&pocketMoney,&sizeOfArray)==2) {

       for(int i=0;i<sizeOfArray;i++){
          scanf("%d%d",&price[i],&value[i]);
       }


       True++;

       int result = func(0,0,false,pocketMoney);

       printf("%d\n",result);

    }//input loop


} //main function

int func(int index,int sum,bool take,int pocketMoney){



  if(index==sizeOfArray) return 0;

  if(vis[index][sum]==True) return dpAra[index][sum];

  vis[index][sum] = True;

  int profit1,profit2;


  if(!take){
     if(sum+price[index]>2000 && sum+price[index]<=pocketMoney+200){
        profit1 = value[index]+func(index+1,sum+price[index],true,pocketMoney+200);
     }
     else if(sum+price[index]<=pocketMoney) profit1 = value[index]+func(index+1,sum+price[index],take,pocketMoney);
     else profit1 = 0;
  }//if greater than 2000

  else if(take){
     if(sum+price[index]<=pocketMoney) profit1 = value[index]+func(index+1,sum+price[index],take,pocketMoney);
     else profit1 = 0;
  }//take == true


  profit2 = func(index+1,sum,take,pocketMoney);

  return dpAra[index][sum] = max(profit1,profit2);

}

