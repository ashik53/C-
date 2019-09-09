#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int main(void){

    char str[100];

   long i,line ,operation,j,total,taka,r;
   cin >> line;
    for(i=0;i<line;i++){
        cin >>  operation ;
        getchar();
        total = 0,r=0;
        for(j=0;j<operation;j++){
          scanf("%s",str);
          if(!strcmp("donate",str)){
              cin >> taka;
              total = total + taka;
            }
          else {
              r++;
              if(r==1) printf("Case %ld:\n",i+1);
              cout << total << "\n";

           }
        }

    }

 return 0;
}
