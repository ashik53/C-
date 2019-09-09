#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>characterList;
map<char,vector<char> > prefix;
char result[31];
bool taken[31];
bool check(int pos,char ch);
void backTracking(string &input,int sz,int len);

int main()
{
    string input1,input ,constraint;
    int len,cases = 0;
    while(getline(cin,input1)){



       for(int i=0;i<31;i++) taken[i] = false;
        prefix.clear();

        getline(cin,constraint);
        len = constraint.size();
        input.clear();
        for(int i=0;i<input1.size();i++){
            int ch = (int)input1[i];
            if(ch>=97 && ch<=122){
                input.push_back(input1[i]);
            }
        }

        for(int i=0;i<len;i+=4){
            char ch1 = constraint[i];
            char ch2 = constraint[i+2];
            prefix[ch2].push_back(ch1);
        }//push into vector
        //cout<<prefix['f'].size()<<endl;
        //cout<<input<<endl;
        sort(input.begin(),input.end());
        if(cases>0) printf("\n");
        backTracking(input,input.size(),0);
        //*/
        //cout<<input1<<"\n"<<constraint<<endl;

        cases++;
    }//cases




}//main func

void backTracking(string &input,int sz,int len){
  if(len==sz){
     for(int j=0;j<len;j++){
        printf("%c",result[j]);
     }
     printf("\n");
     return;
  }//if

   for(int i=0;i<sz;i++){
      char ch = input[i];
      if( taken[i]==false && check(len,ch)==true ){
        //cout<<"call with, i = "<<i <<" ,ch = "<<ch<<endl;
         result[len] = ch;
         taken[i]= true;
         backTracking(input,sz,len+1);
         taken[i] = false;
      }
   }//for loop



}//func
bool check(int pos,char ch){

//  cout<< ch <<" "<<pos<<endl;
  int cnt =0;
  int len = prefix[ch].size();
  for(int i=0;i<pos;i++){
    char ch1 = result[i];
    for(int j=0;j<len;j++){
        if(ch1 == prefix[ch][j]){
            cnt++;
            break;
        }
    }//for
   }//for
   //cout<<"len = "<< len << ", count: "<< cnt<<endl;
   if(len==cnt) return true;
   return false;

}

