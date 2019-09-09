#include <bits/stdc++.h>
using namespace std;
vector<string>per;
vector<double>elements;
string stringSize(string &str);
int whichIsBiger(string &str1,string &str2){

    if(str1.size()<str2.size()) return 2;
    else if(str1.size()>str2.size()) return 1;

    for(int i=0;i<str1.size();i++){
        int a = str1[i]-'0';
        int b = str2[i] -'0';
        if(a<b) return 2;
        else if(b<a) return 1;

    }
   return 0;
}
int main(void){
  string str2,str1;

//while(1){
     cin>> str1;
     cin>> str2;

     str1 = stringSize(str1);
     str2 = stringSize(str2);

     int ans = whichIsBiger(str1,str2);

     if(ans<1) cout<<"=";
     else if(ans==1) cout<< ">";
     else cout<<"<";
     cout<< endl;
  //}
}

string stringSize(string &str){

   bool get = false;
     int indexToDelete  = -1;
     for(int i=0;i<str.size();i+=1){

        if(get==false && str[i]!='0'){
            indexToDelete = i;
            break;
        }
     }

     if(indexToDelete>=0) str.erase(0,indexToDelete);
     else if(indexToDelete<0) return "0";
     return str;
}
