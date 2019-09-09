


//UVA-1213 dp,

/*How to compile
g++ -o main main.cpp, then main
*/


#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int >
int limit,cnt,indexLimit;
void primeGenerating();
bool primeAra[1150];
vector<int> primeVector;
int vis[207][2240][20];
int dpAra[207][2240][20];
int True;
int func(int index,int sum,int mark);
int main() {

    primeGenerating();

    while(scanf("%d%d",&limit,&cnt)==2) {

      if(limit==0 && cnt==0) break;
      primeVector.clear();

      for(int i=2;i<=limit;i++){
        if(primeAra[i]==true){
            primeVector.push_back(i);
        }
      }

      indexLimit = primeVector.size();

      True++;

      int result = func(0,0,0);

      printf("%d\n",result);


    }//input loop


} //main function

int func(int index,int sum,int mark){

  //cout<< index <<" "<< sum << " " << mark<< endl;

  if(sum==limit && mark==cnt) return 1;
  if(vis[index][sum][mark]==True) return dpAra[index][sum][mark];
  if(index==indexLimit) return 0;
  if(sum>limit || mark==cnt) return 0;

  int ret1, ret2;

  ret1 = func(index+1,sum+primeVector[index],mark+1);
  ret2 = func(index+1,sum,mark);

  vis[index][sum][mark] = True;

  return dpAra[index][sum][mark] = ret1+ret2;

}

void primeGenerating(){

   for(int i=0;i<=1150;i++) primeAra[i] = false;
   primeAra[0] = false;
   primeAra[1] = false;

  // int c = 0;
   for(int i=2;i<=1130;i++){
      int num = i;
      bool prime = true;
      for(int j=2;j*j<=num;j++){
           if(num%j==0){
               prime = false;
               break;
           }
      }//prime check

      if(prime== true) {
        primeAra[num] = true;
        //c++;
      }


   }//for loop
  // cout<< c<<endl;

}



