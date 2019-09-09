#include <bits/stdc++.h>

using namespace std;

int power(int base, int limit){

    int num = 1;
    for(int i = 1; i <= limit; i++){
        num *= base;
    }

    return num;
} // power

int stringToInt(string &str, int lenLimit){

    int num = 0;

    if(lenLimit > 1 && str[0] == '0'){
        return -9999;
    } //if

    int x = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        num += (power(10, x++) * (str[i] - '0'));
    }//for

    return num;

} //stringToInt

int solution(vector <int> &A, int B, int C){

    int numLimit = C;
    int lenLimit = B;
    int sizeOfAra = A.size();
    vector <int> elements;



} //solution

void recursion(vector<int> v, string str, int index, int vSize, int len){


    string str1 = str ;
    char c = (v[index] + '0');
    str1 = str1 + c;
    recursion(v, str1, index+1, vSize, len+1);
    recursion(v, str, index+1, vSize, len);

} //recursion
int main()
{
    vector <int > A;
    int B, C, sz, elem;

    while(cin >> sz){
        A.clear();
        for(int i = 0; i < sz; i++){
            cin >> elem;
            A.push_back(elem);
        } //for

        recursion(A, "",0, A.size(), 0);
    //    cin >> B >> C;

    } //loop

    /*string str = "177711";
    str = str + 'c';
    cout << str << endl;
    cout << stringToInt(str, 4) << endl ; */



}



