#include <bits/stdc++.h>

using namespace std;

int weight[1007],capacity[1007],dpAra[1007][9007],vis[1007][9007];

int numberOfBoxes,True;
int recursion(int index,int currentWeight);
int Max(int n1,int n2);

int main(){

   while(scanf("%d",&numberOfBoxes)==1 && numberOfBoxes!=0) {

        for(int i=0;i<numberOfBoxes;i++){
            scanf("%d%d",&weight[i],&capacity[i]);
        }

        True++;
        int ans = recursion(numberOfBoxes-1,0);

        printf("%d\n",ans);

   }//input

}
int recursion(int index,int currentWeight){

   if(index==-1) return 0;

   if(vis[index][currentWeight]==True) return dpAra[index][currentWeight];

   vis[index][currentWeight] =True;

   int profit1,profit2 ;

   if(currentWeight<=capacity[index]){
     profit1 = 1+ recursion(index-1,currentWeight+weight[index]);
   }
   else profit1 = 0;

   //not take
   profit2 = recursion(index-1,currentWeight);

   //return actual result
   return dpAra[index][currentWeight] = Max(profit1,profit2);

}
int Max(int n1,int n2){

  if(n1>n2) return n1;

  return n2;

}


/*#include<stdio.h>
#define ll long long
int N;
int weight[1003], load[1003];
int weight1[1003], load1[1003];
int dp[1005][9002];
void clearAra()
{
 for (int i = 0; i < 1001; i++) for (int j = 0; j < 9001; j++) dp[i][j] = -1;
}
int Max(int a, int b){
  if(a>b) return a;

  return b;
}
int solve(int i, int w){
 if (dp[i][w] != -1) return dp[i][w];
 if (i ==-1) return 0;
 int a = 0, b = 0;
 if (w <= load[i])
 {
  a = 1 + solve(i -1, w + weight[i]);
 }
 b = solve(i - 1, w);
 return dp[i][w]=Max(a, b);
 //return  Max(a, b);
}
int main()
{
 // freopen("Text.txt", "r", stdin);
 while (scanf("%d", &N) == 1 && N != 0)
 {
  for (int i = 0; i < N; i++) scanf("%d %d", &weight1[i], &load1[i]);
  //for (int i = 0, j = N - 1; i < N; i++, j--) weight[i] = weight1[j], load[i] = load1[j];
  clearAra();
  int ans = solve(0, 0);
  printf("%d\n", ans);
 }
 return 0;
}*/
