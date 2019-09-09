#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
int recursion(int n,int r);
int dpTable[101][101];

int main()
{
   int a ,b ;
   while(cin >> a>> b){
      for(int i=0;i<101;i++){
        for(int j =0;j<101;j++){
            dpTable[i][j] = -1;
        }
      }
       cout<< recursion(a,b)<<endl;

   } //while loop
}

int recursion(int n,int r)
{
    if(dpTable[n][r]!=-1) return dpTable[n][r];
    else if(r>n){
        return 0;
    }else if(r==0){
        return 1;
    }

   return recursion(n-1, r) + recursion(n-1, r-1);
}
