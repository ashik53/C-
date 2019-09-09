#include <bits/stdc++.h>

using namespace std;
class Index{
public:
    int x,y;
    Index(int a,int b): x(a),y(b){};

};

Index* result[16];
int rowAra[8];
int sizeOfBoard,minDistance = 100000;



void backTrack(int currentRow){


    if(currentRow==sizeOfBoard) {

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                 if(i==result[i]->x)
            }
        }



        return;
    }

    for(int i=0;i<sizeOfBoard;i++){//column traverse

        bool signal = true ;

        //check validity of a position
        for(int j=0;j<currentRow;j++){
            if(result[j]->y==i || result[j]->y - result[j]->x == i-currentRow ||
              result[j]->y+result[j]->x== i+currentRow){
                    signal = false;
                    break;
            }
        }
        //end of check validity
        if(signal){
            //cout<< currentRow <<","<< i <<endl;
            result[currentRow] = new Index(currentRow,i);
            backTrack(currentRow+1);
        }

    }//column traverse

}//function backtracking


int main()
{


    backTrack(0);


}

