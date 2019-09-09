#include <bits/stdc++.h>

using namespace std;
class Index{
public:
    int x,y;
    Index(int a,int b): x(a),y(b){};

};

Index* result[16];
vector<Index*>allSolutions[107];


int sizeOfBoard,ans,inputRow,inputCol;

void solutionPrinting(){

  int id = 0;

  for(int t=0;t<ans;t++){ //traverse all solutions
    bool found = false;
    for(int j=0;j<sizeOfBoard;j++){
      //  cout<<"("<<allSolutions[t][j]->x+1 <<","<<  allSolutions[t][j]->y+1<<")"<<",";
        if(allSolutions[t][j]->x==inputCol-1 && allSolutions[t][j]->y==inputRow-1){
            id++;
            found = true;
            break;
        }
    }

    if(found){
       if(id<10) printf(" ");
       printf("%d      ",id);
       for(int j=0;j<sizeOfBoard;j++){
             printf("%d",(allSolutions[t][j]->y+1));
             if(j!=7) printf(" ");
       }
       printf("\n");


    }//if found
  }//traverse all solutions

  //cout<< id << endl;
}

//printf(" #      1 2 3 4 5 6 7 8\n\n");
void backTrack(int currentRow){

    if(currentRow==sizeOfBoard) {
        for(int k=0;k<sizeOfBoard;k++){
           allSolutions[ans].push_back(result[k]);
        }
        ans++;
       // cout<< endl;
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

            result[currentRow] = new Index(currentRow,i);
            backTrack(currentRow+1);
        }

    }//column traverse

}//function backtracking


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    scanf("%d",&cases);
    ans = 0;
    sizeOfBoard = 8;
    backTrack(0);
    //cout<< ans << endl;
    for(int i=1;i<=cases;i++){ //all cases
       scanf("%d%d",&inputRow,&inputCol);

       //run process
       printf("SOLN       COLUMN\n");
       printf(" #      1 2 3 4 5 6 7 8\n\n");
       solutionPrinting();

       if(i!=cases) printf("\n");
    }//all cases










}

