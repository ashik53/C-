


//UVA-562, simple recursion

/*How to compile
g++ -o main main.cpp, then main
*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int >

long sizeOfArray,totalQuery,d,m;
long ara[207];
int dpAra[27][17];

void recursion(long index,long sum,long cnt);

int main() {

   int line = 0;

   while(scanf("%ld%ld",&sizeOfArray,&totalQuery)==2){

      line++;

      if(sizeOfArray==0 && totalQuery==0) break;

      for(int i=0;i<sizeOfArray;i++){
         scanf("%ld",&ara[i]);
      }

      memset(dpAra,0,sizeof(dpAra[0][0])*27*17);

      recursion(0,0,0);

      for(int i=1;i<=5;i++){
         for(int j=1;j<=4;j++){
            cout<< "d = "<<i <<",m = "<<j <<"->"<< dpAra[i][j]<<endl;
         }
      }

      printf("SET %d:\n",line);

      for(int i=0;i<totalQuery;i++){
          scanf("%ld%ld",&d,&m);

          printf("QUERY %d: %ld\n",i+1,dpAra[d][m]);

      }//every query check loop



   }//input loop

} //main function

void recursion(long index,long sum,long cnt){

  for(int i=1;i<=20;i++){
     if(sum%i==0){
        dpAra[i][cnt]++;
        cout<< "index = "<<index<<","<<"sum = "<<sum <<""
     }
  }//loop of finding divisors

  if(index==sizeOfArray) return ;

  recursion(index+1,sum+ara[index],cnt+1);
  recursion(index+1,sum,cnt);

}




