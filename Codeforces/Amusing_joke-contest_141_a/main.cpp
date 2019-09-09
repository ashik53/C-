
#include <bits/stdc++.h>
using namespace std;
map<char,int> hostGuest;
map<char,int> shuffle;
int main(void){
  string str1,str2,str3;
     cin >> str1;
     cin>> str2;
     cin>> str3;

     for(int i=0;i<str1.size();i++){
        hostGuest[str1[i]] +=1;
     }
     for(int i=0;i<str2.size();i++){
        hostGuest[str2[i]] +=1;
     }

     for(int i=0;i<str3.size();i++){
        shuffle[str3[i]] +=1;
     }
     int i = 65;
     int limit = 90;
     for(;i<=limit;i++){
            char ch = i;
        if(hostGuest[ch]!=shuffle[ch]) {

            printf("NO");
            return 0;
        }
        //cout<<ch <<" : " <<hostGuest[ch]<<" , "<<shuffle[ch]<<endl;
     }
     printf("YES");
     return 0;
}
