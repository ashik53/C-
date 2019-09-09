/*cases
3 3 3 5
ans = NO */
//UVA 10664, simple recursion

#include<bits/stdc++.h>
using namespace std;
int ara[107], sizeOfArray,sum;
//function prototypes
int conversion(string& str);
bool recursion(int index,int weight);
int main(){

   int cases;
   string s;

   //
   scanf("%d",&cases);
   getchar();
   for(int line =0;line<cases;line++){
       getline(cin,s);
       sum = 0;
       sizeOfArray = conversion(s);

       if(recursion(0,0)==true) printf("YES\n");
       else printf("NO\n");


   }//cases




}
bool recursion(int index,int weight){

  if(sum-weight==weight) return true;
  if(index==sizeOfArray) return false;

  bool res1 = recursion(index+1,weight+ara[index]);
  bool res2 = recursion(index+1,weight);

  if(res1==true || res2== true) return true;
  return false;
}

int conversion(string& str){

  int index = 0;
  int len = str.size();
  string subString = "";

  for(int i=0;i<len;i++){
    if(str[i]==' ' || i==len-1){
        if(i==len-1) subString.push_back(str[i]);
        int num;
        istringstream ss(subString);
        ss >> num;
        ara[index++] = num;
        sum+=num;
        subString.clear();
    }
    else{
        subString.push_back(str[i]);
    }
  }

  return index;
}


