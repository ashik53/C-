#include <iostream>
#include <cstdio>

using namespace std;
int main(void){

    unsigned long long n,m,result ;

    int T,i ;

      cin >> T ;

     for(i=0;i<T;i++){
         cin >>n >>m;
         result = (n *m)/2 ;

           cout <<"Case " << i+1 <<": " << result << "\n" ;
       }







 return 0;

}
