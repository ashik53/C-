




//UVA-624 dp,easy knapSack

/*How to compile
g++ -o main main.cpp, then main
*/


#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int >

int ara[30],limit,sizeOfArray,True;
PII solutionAra[27][100000];
int dpAra[27][1000000];
int vis[27][1000000];
int recursion(int i,int sum);
int main() {

//input taking and initializing


   while(scanf("%d%d",&limit,&sizeOfArray)==2){

    for(int i=0;i<27;i++){
        for(int j =0;j<100000;j++){
            solutionAra[i][j] = PII(0,0);
        }
    }
    for(int i=0;i<sizeOfArray;i++)
    {
        scanf("%d",&ara[i]);
    }

    True++;
    int result = recursion(0,0);

    int id ,sum ;
    id = 0;
    sum = 0;

    //solution printing
    for(;id<=sizeOfArray; ){
        //if(solutionAra[id][sum].first==0 && solutionAra[id][sum].second==0) break;

        //print index of array which is inside solution
        if(solutionAra[id][sum].second>sum) printf("%d ",ara[id]);
       // cout<< id <<"," << sum <<endl;
        sum = solutionAra[id][sum].second;
        id  = id+1;

    }//solution printing



   //cout<<solutionAra[3][15].first <<" "<<solutionAra[3][15].second<<endl;

    printf("sum:%d\n",result);

   }//while input loop

} //main function

int recursion(int i,int sum){

  if(vis[i][sum]==True) return dpAra[i][sum];

  if(i==sizeOfArray) return 0;

  int sum1,sum2;

  vis[i][sum] = True;

  if(sum+ara[i]<=limit){
     sum1 = ara[i] + recursion(i+1,sum+ara[i]);
  }//sum1 calling
  else sum1 = 0;

  sum2 = recursion(i+1,sum);

  if((sum1>sum2 || sum1==sum2)&& sum1!=0){
     solutionAra[i][sum] = PII(i+1,ara[i]+sum);
    // cout << i <<","<< sum <<" er next "<<" "<< i+1<<","<<ara[i]+sum<<endl;
  }
  else {
        solutionAra[i][sum] = PII(i+1,sum);
     //cout << i <<","<< sum <<" er next "<<" "<< i+1<<","<<sum<<endl;

  }

   //cout<< "("<<i<<","<<sum<<")" <<" = "<< max(sum1,sum2)<<endl;
  return dpAra[i][sum] = max(sum1,sum2);

}//recursion