#include <bits/stdc++.h>

using namespace std;
int sz,numberOfQueries,numbersAra[1007];

int binarySearch(int be, int en, int searchValue);
int differenceCalculating(int a, int b){

    if(b>a) return b-a;

    return a-b;
}
int main()
{

   int searchValue,sz,numberOfQueries;

   while(true){
       cin >> sz;
       for(int i = 0; i < sz; i++){
            scanf("%d",&numbersAra[i]);
       }

       cin >> numberOfQueries;
       for(int i = 0; i < numberOfQueries; i++){
            scanf("%d",&searchValue);

            int result = binarySearch(0,sz-1,searchValue);
            if(result>=0){
                printf("element found , position %d\n", (result+1));
            } else {
                printf("not found\n");
            }
       }

   }//while loop

}


int binarySearch(int be, int en, int searchValue){

    if(searchValue<numbersAra[0]) return -1;
    if(searchValue>numbersAra[en]) return en;

    while(true){
        if(differenceCalculating(be,en) <= 1){
            if(numbersAra[en] == searchValue) return en;
            return be;
        }

        int mid = (be+en)/2;

        if(numbersAra[mid] >= searchValue) en = mid;
        else be = mid;

    }


}
  

