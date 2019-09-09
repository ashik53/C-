#include <bits/stdc++.h>

using namespace std;

int keyMatrix[3][3], inverseMatrix[3][3];
int index[207], encryptedArray[207], decryptedArray[207];
int determinent;
string plainText;

void encryption();
void decryption();
int t1Calculation();
void determinentAndInverseCalculation();
void indexing();
int asciiValue(char ch);
char charValue(int n);
int addByMultipleOf26(int value);
int main(){

    indexing();
    cout << "Enter plain text \n";
    getline(cin, plainText);

    cout << "Enter key \n";
    for(int i = 1; i < 3; i++){
        for(int j = 1; j < 3; j++){
            cin >> keyMatrix[i][j];
        }
    }

    determinentAndInverseCalculation();
    encryption();
    decryption();

}
void encryption(){
    int pt[207]   ;
    for(int i = 0; i < plainText.size(); i++){
        pt[i+1] = index[asciiValue(plainText[i])];
    }



    //main encryption task
    for(int i = 1; i < plainText.size()+1; i+=2){
        encryptedArray[i] = ((keyMatrix[1][1] * pt[i]) + (keyMatrix[1][2] * pt[i+1]))%26;
        encryptedArray[i+1] = ((keyMatrix[2][1] * pt[i]) + (keyMatrix[2][2] * pt[i+1]))%26;

    }


    cout << "encrypted text : ";
    for(int i = 1; i < plainText.size()+1; i++){
        cout << charValue(encryptedArray[i]+asciiValue('a'));
        if(i%2 == 0) cout << " ";
    }

    cout << endl;

}
void decryption(){

    int t1 = t1Calculation();
    //cout << t1 << endl;
    for(int i = 1; i < 3; i++){
        for(int j = 1; j < 3; j++){
            inverseMatrix[i][j]*=t1;
            inverseMatrix[i][j]%=26;
        }
    }

    //decryption matrix*matrix

    for(int i = 1; i < plainText.size()+1; i+=2){
        decryptedArray[i] = ((inverseMatrix[1][1] * encryptedArray[i]) + (inverseMatrix[1][2] * encryptedArray[i+1]))%26;
        decryptedArray[i+1] = ((inverseMatrix[2][1] * encryptedArray[i]) + (inverseMatrix[2][2] * encryptedArray[i+1]))%26;
    }
    cout << "decrypted text ";
    for(int i = 1; i < plainText.size()+1; i++){
        cout << charValue(decryptedArray[i] + (int)'a');

        if(i%2 == 0) cout << " ";
    }

    cout << endl;


}
int t1Calculation(){

    int d, r1 = 26, r2 = determinent, r, t1 = 0, t2 = 1, t;

    while(true){
        if(r1 == 1 && r2 == 0) break;
        d = r1/r2, r = r1%r2;
        t = t1 - (t2*d);
        r1 = r2, r2 = r, t1 = t2, t2 = t;
    }

    return t1;
}

void determinentAndInverseCalculation(){

    determinent = (keyMatrix[1][1] * keyMatrix[2][2]) - (keyMatrix[1][2] * keyMatrix[2][1]);

    //inverse
    inverseMatrix[1][1] = keyMatrix[2][2];
    inverseMatrix[2][2] = keyMatrix[1][1];
    inverseMatrix[1][2] = addByMultipleOf26(keyMatrix[1][2]*(-1));
    inverseMatrix[2][1] = addByMultipleOf26(keyMatrix[2][1]*(-1));


}

int addByMultipleOf26(int value){

    for(int i = 1; ; i++){
        int mulValue = i * 26;
        if((value*-1) <= mulValue){
            value+=mulValue;
            break;
        }
    }

    return value;

}

void indexing(){

    int start = (int)'a';

    for(int i = 0; i < 26; i++){
        index[start] = i;
        start++;
    }


}

int asciiValue(char ch){

    return (int)ch;

}

char charValue(int n){

    return  (char)n;

}
