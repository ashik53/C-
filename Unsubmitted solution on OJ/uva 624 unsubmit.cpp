


//UVA-624 dp,easy knapSack

/*How to compile
g++ -o main main.cpp, then main
*/


#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int >

int ara[30],limit,sizeOfArray;
PII solutionAra[27][100000];

int recursion(int i,int sum);
int main() {

//input taking and initializing


   while(scanf("%d%d",&limit,&sizeOfArray)==2){


    for(int i=0;i<sizeOfArray;i++)
    {
        scanf("%d",&ara[i]);


    }


    int result = recursion(0,0);
    /*int s = 0;
    int i = 0;
    for(int k=0;k<10;k++){
        cout<< i <<","<< s<<"      " <<  solutionAra[i][s].first <<"," <<solutionAra[i][s].second <<endl;
        i =  solutionAra[i][s].first;
        s = solutionAra[i][s].second ;

    }*/


    printf("sum:%d\n",result);

   }//while input loop

} //main function

int recursion(int i,int sum){

  if(i==sizeOfArray) return 0;

  int sum1,sum2;

  if(sum+ara[i]<=limit){
     sum1 = ara[i] + recursion(i+1,sum+ara[i]);
  }//sum1 calling
  else sum1 = 0;

  sum2 = recursion(i+1,sum);

  if(sum1>sum2){
     solutionAra[i][sum] = PII(i+1,sum1);
     cout << i <<","<< sum <<" er next "<<" "<< i+1<<","<<sum1<<endl;
  }
  else {
        solutionAra[i][sum] = PII(i+1,sum2);
        cout << i <<","<< sum <<" er next "<<" "<< i+1<<","<<sum2<<endl;

  }

  return max(sum1,sum2);

}//recursion

