#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
char  inputString[100];
string word[7];
ll dpAra[607][307][307],vis[607][307][307];
int taka,coinLimitHigh,coinLimitLow,True,cnt;
//ll recursion(int index,int amount,int totalCoin);
int wordCounting(string &str);
int power(int base,int limit);
int stringToInt(string &str);
ll recursion(int index,int amount,int totalCoin);

int main()
{
        /*inputString[0]= '1';
        inputString[1]= '0';
        inputString[2]= '0'; */



  True++;
  ll raw = recursion(300,300,300);

   while(scanf("%[^\n]%*c",inputString)==1) {
        string str = "";
        for(int i=0;i<strlen(inputString);i++){
            str.push_back(inputString[i]);
        }

        int sz = wordCounting(str);
        /*cout<<endl;
        for(int i=0;i<sz;i++){
            cout<< word[i] <<" ";
        }
        cout<< endl; */

        if(sz==1){
            coinLimitLow = 0, coinLimitHigh = stringToInt(word[0]);
        }else if(sz==2){
            coinLimitLow = 0, coinLimitHigh = stringToInt(word[1]);
        }else{
            coinLimitLow = stringToInt(word[1]), coinLimitHigh = stringToInt(word[2]);
        }

        taka = stringToInt(word[0]);



        ll ans;

        if(coinLimitLow>taka) ans = 0;
        else {
            if(coinLimitHigh>taka) coinLimitHigh = taka;
            if(sz<3){
                ans = recursion(taka,taka,coinLimitHigh);
            }else {
                ans = recursion(taka,taka,coinLimitHigh)- recursion(taka,taka,coinLimitLow-1);
            }
        }

       // cout<< sz<<" "<< taka <<" "<<coinLimitLow<<" "<<coinLimitHigh<<endl;

        printf("%lld\n",ans);

        //cout<< cnt <<endl;+
    }//all input

}


ll recursion(int index,int amount,int totalCoin){

    if(totalCoin<0|| amount<0) return 0;
    if(!amount) return 1;

    if(vis[index][amount][totalCoin]==True) return dpAra[index][amount][totalCoin];


    vis[index][amount][totalCoin]=True;

    ll way1=0,way2=0 ;

    if(index-1>=1) way2 = recursion(index-1,amount,totalCoin);

    /*if(amount-index>=0 && totalCoin-1>=0) */way1 = recursion(index,amount-index,totalCoin-1);

    return  dpAra[index][amount][totalCoin] = way1+ way2;

}

int power(int base,int limit){

    int result = 1;

    for(int i=1;i<=limit;i++){
        result*=base;
    }

   return result;

}



int stringToInt(string &str){

    int result= 0;

    for(int i=str.size()-1,j=0;i>=0;i--,j++){
        result = result + (power(10,j)*(str[i]-'0')) ;
    }

    return result;

}
int wordCounting(string &str){

    string subStr = "";
    int cnt =0;
    for(int i=0;i<str.size();i++){
        if(str[i]==' '|| i==str.size()-1){
            if(i==str.size()-1) subStr.push_back(str[i]);
            word[cnt] = subStr;
            //cout<< subStr <<" ";
            cnt++;
            subStr = "";
        }else{
            subStr.push_back(str[i]);

        }
    }

    return cnt;

}


