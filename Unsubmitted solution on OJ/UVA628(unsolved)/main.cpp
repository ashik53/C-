#include<bits/stdc++.h>
using namespace std;
char digits[] = {'0','1','2','3','4','5','6','7','8','9'};
char limitOfDigit[10];
string allCombinations[10000007];
string ruleList[1007],wordList[107];
string rule, word;
int cnt,wordSize,ruleSize,sizeOfaRule;
//prototype for functions
void backTracking(int sz,int len, int cntLimit,vector<char>temp);
int countCharacter(string &str, char ch);
int power(int base,int limit);
string stringMaking(vector<char>temp);
int main(){

    //ios::sync_with_stdio(false);
    //cin.tie(0);

    string str;
    int line = 0;
    while(cin>> wordSize){

        if(line!=0) printf("--\n");

        for(int i=0;i<wordSize;i++){
            cin>> wordList[i];
        }



        //rules input
        cin >> ruleSize;
        for(int i=0;i<ruleSize;i++){
            cin>> str;
            ruleList[i] = str;;
        }

        /*for(int i=0;i<wordSize;i++){
            cout << wordList[i] <<"\n";
        } */
        //for(int i=0;i<ruleSize;i++){
        //    cout<< ruleList[i]<<"\n";
        //}
        if(line==0) printf("--\n");
        for(int i=0;i<ruleSize;i++){
             int countOfZero = countCharacter(ruleList[i],'0');
             for(int j=0;j<10;j++) limitOfDigit[j] = countOfZero;
             rule = ruleList[i];
             sizeOfaRule = rule.size();
             vector<char> temp;
             cnt = 0;
             //cout<<countOfZero <<" "<< rule <<" "<< sizeOfaRule<<" \n";
             backTracking(countOfZero,0,power(10,countOfZero-1),temp);
        }
       line++;

    }   //all cases


}
void backTracking(int sz,int len, int cntLimit,vector<char>temp){

   if(len==sz){

      string str = stringMaking(temp);
      allCombinations[cnt] = str;
      cnt++;
      if(cnt==cntLimit){

        for(int j=0;j<wordSize;j++){
            word = wordList[j];
            //all possible combinations
            for(int k=0;k<cntLimit;k++){
                string combination = allCombinations[k];
                int t = 0;

                //traverse a rule
                for(int l=0;l<sizeOfaRule;l++){
                    if(rule[l]=='#') cout<< word;
                    else {cout<< combination[t];t++;}
                }
                printf("\n");
                //traverse a rule
            }//all possible combinations



        }//traverse all words

        cnt = 0;
      }//if cnt==cntLimit



       return;
   }

   for(int i=0;i<10;i++){

      if(limitOfDigit[i]==0) continue;

      temp.push_back(digits[i]);
      limitOfDigit[i]--;

      backTracking(sz,len+1,cntLimit,temp);
      temp.pop_back();
      limitOfDigit[i]++;


   }

}

int power(int base,int limit){

  int retValue = 1;

  for(int i=0;i<limit;i++){
    retValue*=base;
  }

  return retValue;
}
string stringMaking(vector<char>temp){

  string str = "";

  for(int i=0;i<temp.size();i++) str.push_back(temp[i]);

  return str;

}


int countCharacter(string &str, char ch){

   int cnt = 0;
   int strLen  = str.size();
   for(int i=0;i<strLen;i++){
      if(str[i]==ch) cnt++;

   }

   return cnt;


}
