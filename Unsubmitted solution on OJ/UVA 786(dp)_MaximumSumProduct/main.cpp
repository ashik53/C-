#include<bits/stdc++.h>

using namespace std;
#define ll long long
int sz,numbersAra[1000];

int stringMaking(char* str);
int power(int base,int limit);
int convertToInt(string &str);
int recursion(int index,int sum,int cnt);
string IntToString (int a);
int main()
{
  char str[1000];
  int num = 20;



  while(scanf("%[^\n]%*c",str)==1){

    sz = stringMaking(str);

    long long  ans = -999999;

    for(int i=0;i<sz;i++){
        string sumStr = "1";
        for(int j= i;j<sz;j++){
            int num = numbersAra[j];
            string numStr =IntToString (num);
            string  result
           // cout<<sum <<" ";
            //if(sum>ans) ans = sum;
        }
        if(sum>ans) ans = sum;
       // cout<< endl;
    }

    printf("%lld\n",ans);

  }//input*/
}

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
string ami_ekhon_gun_korci(string &str1,string &str2){
  string array[1000],gun,vj;
  ll a,b,i,j,k=0,c,sum;
  for(i= str2.size()-1;i>=0;i--){
       a  = str2[i] - '0',c =0;
       gun.clear();
       for(j= str1.size()-1;j>=0;j--){
          b = str1[j] -'0';
          sum = (a*b)+ c;
          if(sum>9) c = sum/10;
          else c =0;
         if(j!=0) gun.push_back((sum%10)+'0');
         else {
            stringstream str111;
            str111<< sum;
            vj = str111.str();
            reverse(vj.begin(),vj.end());
            gun = gun+ vj;
         }

       }
      reverse(gun.begin(),gun.end());
      array[k++] = gun;

  }
  for(i=0;i<k;i++){
        for(j=0;j<i;j++) array[i].push_back('0');
      }
 ll len = array[k-1].size();
  for(i=0;i<k;i++){
   ll dif = len - array[i].size();
    reverse(array[i].begin(),array[i].end());
    for(j=0;j<dif;j++) array[i].push_back('0');
    reverse(array[i].begin(),array[i].end());

  }
  c =0;
  string result;
  for(i= len-1;i>=0;i--){
    sum = 0+ c;
    for(j=0;j<k;j++) sum = sum + (array[j][i]-'0');
    if(sum>9) c = sum/10;
    else c =0;
    if(i!=0) result.push_back((sum%10)+'0');
    else {
       stringstream str20;
       str20 <<sum;
       vj.clear();
       vj = str20.str();
       reverse(vj.begin(),vj.end());
       result = result + vj;
    }
  }
 reverse(result.begin(),result.end());
 return result;
}
int stringMaking(char* str){

    string sub_str;
    int index = 0;

    for(int i=0;i<strlen(str);i++){

        if(str[i]==' ' || i==strlen(str)-1){
            if(i==strlen(str)-1) sub_str.push_back(str[i]);
            //cout<< sub_str<<endl;
            int num = convertToInt(sub_str);
            //cout<< num<<endl;
            if(num!=-999999) numbersAra[index++] = num;
            sub_str.clear();
        }

        else {
             sub_str.push_back(str[i]);
        }


    }

    return index;
}

int convertToInt(string &str){

   //cout<<str <<" ";
   reverse(str.begin(),str.end());
   int num = 0,cnt = 0;

   int multiply = 1;

   if(str[str.size()-1]=='-') multiply =-1;

   for(int i=0;i<str.size();i++){

        if(str[i]!='-') num = num + ((str[i]-'0')*power(10,cnt));
        cnt++;
   }

   //cout<< (num*multiply)<<endl;

   return num*multiply;
}

int power(int base,int limit){

  int num = 1;
  for(int i=0;i<limit;i++){
    num*=base;
  }

    return num;
}
