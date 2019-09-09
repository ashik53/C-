#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
#define inf 1<<28
vector<int> diamond[100*2+7];
vector<int> adjList[100*2+7];
int value[100*100+7];

int recursion(int pos,int amount,int n);
int main()
{
    int n , x , element,k;

    //input taking
    for(int i=0;i<207;i++)
    {
        adjList[i].clear();
        diamond[i].clear();

    }
    k = 1;
    scanf("%d",&n);
    for(int i=1;i<n*2;i++)
    {
        if(i<n)
        {
            for(int j = 0;j<i;j++)
            {
              scanf("%d",&x);
              value[k] = x;
              diamond[i].push_back(k);
              k++;
            }//

        }//
        else
        {
            for(int j = 0;j<n*2-i;j++)
            {
              scanf("%d",&x);
              value[k] = x;
              diamond[i].push_back(k);
              k++;
            }//
        }//

    }// input loop ends

    /*
   for(int i=1;i<n*2;i++)
   {
       cout<< i <<"->>";
       for(int j=0;j<diamond[i].size();j++)
       {
           cout<< diamond[i][j] <<" " ;

       }
       cout<< endl;
   }
   */


    //processing loop
    k = 1;
    for(int i=1;i<n*2-1;i++)
    {
        if(i<n)
        {
            for(int j = 0 ;j<i;j++)
            {
              x = diamond[i][j];
              adjList[x].push_back( diamond[i+1][j]);
              adjList[x].push_back( diamond[i+1][j+1]);
              k++;
            }//

        }//
        else
        {
            for(int j = 0;j<n*2-i;j++)
            {
              x = diamond[i][j];
              if(!j) adjList[x].push_back(diamond[i+1][j]);
              if(j+1==(n*2)-i) adjList[x].push_back(diamond[i+1][j-1]);
              if(j>0 && j+1!=(n*2)-i)
              {
                 adjList[x].push_back(diamond[i+1][j-1]);
                 adjList[x].push_back(diamond[i+1][j]);
              }


            }//
        }// */

    }// processing loop ends

  /*
   for(int i=1;i<=n*n;i++)
   {
       cout<< i <<" -->> ";
       for(int j=0;j<adjList[i].size();j++)
       {
           cout<< adjList[i][j] <<" ";

       }
       cout<< endl;
   } */


   cout<< recursion(1,value[1],n)<<endl;
}

int recursion(int pos,int amount,int n)
{
    if(pos==n*n) return amount;

    int ret1 , ret2 = 0;
    int x1 = adjList[pos][0];
    int x2 = 0;

    ret1 = recursion(x1,amount+ value[x1],n);

    if(adjList[pos].size()>1)
    {
        x2  = adjList[pos][1];
        ret2 = recursion(x2,amount+value[x2],n);
    }
    return max(ret1,ret2);
}


