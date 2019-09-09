#include <bits/stdc++.h>

using namespace std;
int rowSize,colSize;
vector<string>result;
string param = "IEHOVA#";
char grid[10][10];
bool isValid(int row,int col){

   if(row>=0 && row<rowSize && col>=0 && col<colSize) return true;


   return false;

}
void recursion(int row, int col,int index);
int main(){
  int cases;

  scanf("%d",&cases);

  for(int i=1;i<=cases;i++){ //all cases
     scanf("%d%d",&rowSize,&colSize);
     getchar();

     for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            scanf("%c",&grid[i][j]);
        }
        getchar();
     }

     result.clear();
     for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){

            if(grid[i][j]=='@'){
                recursion(i,j,0);
            }
        }

     }

  }//all cases

}//main function
void recursion(int row, int col,int index){

  //cout<< row<<"," << col<< "->" << index<<endl;

  if(grid[row][col]=='#'){
    for(int i=0;i<result.size();i++){
        cout<< result[i];
        if(i==result.size()-1) printf("\n");
        else printf(" ");
    }
    result.clear();
    return;
  }//base case

  int newRow, newCol;

  newRow = row-1, newCol = col;

  if(isValid(newRow,newCol)==true && grid[newRow][newCol]== param[index]){
        result.push_back("forth");
        recursion(newRow,newCol,index+1);
  }

  newRow = row, newCol = col+1;

  if(isValid(newRow,newCol)==true && grid[newRow][newCol]== param[index]){
        result.push_back("right");
        recursion(newRow,newCol,index+1);
  }

  newRow = row, newCol = col-1;

  if(isValid(newRow,newCol)==true && grid[newRow][newCol]== param[index]){
        result.push_back("left");
        recursion(newRow,newCol,index+1);
  }

}
