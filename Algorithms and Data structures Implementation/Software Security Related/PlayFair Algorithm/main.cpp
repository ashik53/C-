#include <bits/stdc++.h>

using namespace std;

class Position{

public:
    int row, col;
    Position(int x, int y):row(x),col(y){};

};
int isAvailable[207];
int iIndex, jIndex;
char keyMatrix[27][27];
vector<Position*> fullyEncryptedVector, fullyDecryptedVector;


void keyMapping(string &str);
void encryption(string &plainText);
void decryption();
int asciiValue(char ch){

   return (int)ch;

}

int charForm(int n){

   return (char)n;

}

string removeSpace(string &str){

    string s = "";

    for(int i = 0; i < str.size(); i++){
        if(str[i] != ' '){
            s.push_back(str[i]);
        }
    }

    return s;

}

string add_X(string &str){

  string s = "";

  for(int i = 0; i < str.size(); i++){
        if(i == str.size()-1){
            s.push_back(str[i]);
        } else if(str[i] != str[i+1]){
            s.push_back(str[i]);
        } else if(str[i] == str[i+1]){
            s.push_back(str[i]);
            s.push_back('x');
        }
  }

  if(s.size()%2 != 0) s.push_back('x');

  return s;

}

Position* positionFinder(char ch){

    for(int i = 1; i <= 5 ; i++){
        for(int j = 1; j <= 5; j++){
            if(keyMatrix[i][j] == ch){
                Position* p = new Position(i, j);
                return p;
            }
        }
    }



}
int main(){
    string  plainText, keyStr, inputStr,str;

    //input taking
    printf("Enter plain text: ");
    getline(cin,inputStr);
    //getchar();
    printf("Enter key: ");
    getline(cin,keyStr);

    /// space removing from key and plain text;
    plainText = removeSpace(inputStr);
    plainText = add_X(plainText);
    keyStr = removeSpace(keyStr);
    //cout << keyStr<< endl;
    ///map key
    iIndex = 1, jIndex = 1;
    keyMapping(keyStr);
    str = "abcdefghijklmnopqrstuvwxyz";
    keyMapping(str);

    cout << "key matrix " << endl;
    for(int i = 1; i <= 5; i++ ){
        for(int j = 1; j <= 5; j++){
            cout<< keyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "modified plain text: \n";
    for(int i = 0; i < plainText.size(); i+=2){
        cout << plainText[i] << plainText[i+1] << endl;
    }

    encryption(plainText);
    cout << "encrypted plain text \n";
    for(int i = 0; i < fullyEncryptedVector.size(); i+=2){

        int x1 = fullyEncryptedVector[i]->row;
        int y1 = fullyEncryptedVector[i]->col;

        int x2 = fullyEncryptedVector[i+1]->row;
        int y2 = fullyEncryptedVector[i+1]->col;


        cout << keyMatrix[x1][y1] << keyMatrix[x2][y2] << endl;
    }

    cout << "decrypted plain text \n";
    decryption();
    for(int i = 0; i < fullyDecryptedVector.size(); i+=2){

        int x1 = fullyDecryptedVector[i]->row;
        int y1 = fullyDecryptedVector[i]->col;

        int x2 = fullyDecryptedVector[i+1]->row;
        int y2 = fullyDecryptedVector[i+1]->col;


        cout << keyMatrix[x1][y1] << keyMatrix[x2][y2] << endl;
    }


/*software engineering
software security */

}
void decryption(){

    fullyDecryptedVector.clear();

    for(int i = 0; i < fullyEncryptedVector.size(); i+=2){
        int x1 = fullyEncryptedVector[i]->row;
        int y1 = fullyEncryptedVector[i]->col;

        int x2 = fullyEncryptedVector[i+1]->row;
        int y2 = fullyEncryptedVector[i+1]->col;

        Position* pos1 = positionFinder(keyMatrix[x1][y1]);
        Position* pos2 = positionFinder(keyMatrix[x2][y2]);

        if(pos1->row == pos2->row){
            if(pos1->col == 1) pos1->col = 5;
            else pos1->col -= 1;

            if(pos2->col == 1) pos2->col = 5;
            else pos2->col -= 1;

        }
        else if(pos1->col == pos2->col){
            if(pos1->row == 1) pos1->row = 5;
            else pos1->row -= 1;

            if(pos2->row == 1) pos2->row = 5;
            else pos2->row -= 1;
        }
        else {
            int x = pos1->col;
            pos1->col = pos2->col;
            pos2->col = x;
        }

        fullyDecryptedVector.push_back(pos1);
        fullyDecryptedVector.push_back(pos2);


    }//loop


}

void encryption(string &plainText){

    fullyEncryptedVector.clear();

    for(int i = 0; i < plainText.size()-1; i+=2){
        char ch1 = plainText[i];
        char ch2 = plainText[i+1];

        Position* pos1 = positionFinder(ch1);
        Position* pos2 = positionFinder(ch2);

        if(pos1->row == pos2->row){
            if(pos1->col == 5) pos1->col = 1;
            else pos1->col += 1;

            if(pos2->col == 5) pos2->col = 1;
            else pos2->col += 1;

        }
        else if(pos1->col == pos2->col){
            if(pos1->row == 5) pos1->row = 1;
            else pos1->row += 1;

            if(pos2->row == 5) pos2->row = 1;
            else pos2->row += 1;
        }
        else {
            int x = pos1->col;
            pos1->col = pos2->col;
            pos2->col = x;
        }

        fullyEncryptedVector.push_back(pos1);
        fullyEncryptedVector.push_back(pos2);


    }//loop


}
void keyMapping(string &str){

  // cout<< iIndex <<" "<< jIndex << endl;

    for(int i = 0; i < str.size(); i++){

        int value = asciiValue(str[i]);
        if(isAvailable[value]==1) continue;

        if(charForm(value) == 'i' || charForm(value) == 'j'){
            isAvailable[asciiValue('i')] = 1;
            isAvailable[asciiValue('j')] = 1;
        }

        isAvailable[value] = 1;

        keyMatrix[iIndex][jIndex] = charForm(value);

        //increment iIndex, jIndex
        jIndex++;
        if(jIndex > 5){
            jIndex = 1;
            iIndex += 1;
        }
    }//loop

}
