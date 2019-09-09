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


int absoluteValue(int a,int b){

    if(a>b) return a-b;

    return b-a;

}
void backTrack(int currentRow){

    if(currentRow==sizeOfBoard) {
        printf("\n");
        //print the current result
        int distance = 0;
        for(int i=0;i<sizeOfBoard;i++){

            for(int j=0;j<sizeOfBoard;j++){

                //if row ,column is matched with result
                if(result[i]->x==i && result[i]->y==j) {
                    cout<< "("<<i+1 <<","<<j+1<<")"<<"\t"<<"("<<(rowAra[i]+1)<<")" <<endl;
                    distance  = distance + absoluteValue(i,rowAra[i]);
                    cout<< "distance is "<<absoluteValue(i,rowAra[i])<<endl;
                    cout<< endl;
                   // cout<< "1";
                }//if row ,column is matched with result
                //else cout<< "0";

               // if(j!=sizeOfBoard-1) cout<<" ";
            }
            cout<< endl;

        }//board traversal



        minDistance = min(minDistance,distance);
        cout<< "max distance is "<<distance <<endl;
        exit(1);
        return ;
    }//if row size is eight

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

        //if signal false , then go to the previous step and tries to find out a solution

    }//column traverse
}//function backtracking


int main()
{


       sizeOfBoard = 8;

       rowAra[0]= 0;
       rowAra[1]= 0;
       rowAra[2]= 0;
       rowAra[3]= 0;
       rowAra[4]= 0;
       rowAra[5]= 0;
       rowAra[6]= 0;
       rowAra[7]= 0;





       backTrack(0);

}

