//UVA 990 DP - knapSack
/*How to compile
g++ -o main main.cpp, then main
*/

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
class Info {
public:
    int depth;
    int amount;
    Info(int d, int a):depth(d),amount(a){};

};

Info* arrayOfInfo[37];
int timeLimit,constant,numberOfTreasures;
int process(int index, int seconds);
pii dpAra[37][2007];
int main(void)
{
  int a,b,line;

  line = 0;

  while(scanf("%d%d",&timeLimit,&constant)==2)
  {

       scanf("%d",&numberOfTreasures);
       for(int i=0;i<numberOfTreasures;i++)
       {
           scanf("%d%d",&a,&b);
           arrayOfInfo[i]= new Info(a,b);

       }

      // cout<< "start\n";

       int result = process(0,0);

       int sec = 0;
       int cnt = 0;
       for(int  i = 0;i<numberOfTreasures;i++)
       {
         if(sec!=dpAra[i][sec].second)
         {
           cnt++;
         }

        sec =  dpAra[i][sec].second;

       }
       if(line>0) puts("");
      // cout<< "start2\n";
       printf("%d\n",result);
       printf("%d\n",cnt);
       sec = 0;
       for(int  i = 0;i<numberOfTreasures;i++)
       {
         if(sec!=dpAra[i][sec].second)
         {
            printf("%d %d\n",arrayOfInfo[i]->depth,arrayOfInfo[i]->amount);
         }

        sec =  dpAra[i][sec].second;

       }

     //  cout<< "start3\n";

       line++;


  }//infinity loop


}

int process(int index, int seconds)
{

    if(index==numberOfTreasures) return 0;

    int profit1,profit2;
    int currentTime = arrayOfInfo[index]->depth*constant;
    currentTime+= (currentTime*2);


    if(seconds+currentTime<=timeLimit)
    {
        profit1 = arrayOfInfo[index]->amount + process(index+1,seconds+ currentTime);

    }
    else profit1 = 0;

    profit2 = process(index+1,seconds);


    if(profit1>profit2)
    {
        dpAra[index][seconds]= make_pair(index+1,seconds+ currentTime);

    }
    else dpAra[index][seconds]= make_pair(index+1,seconds);

    return max(profit1,profit2);



}




