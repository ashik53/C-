#include <bits/stdc++.h>

using namespace std;


vector<int> Solution(vector<int> &A);

int main()
{

    int sz,elem;
    //vector<int> A;
    while(cin>> sz){
        vector<int> A;
        for(int i=0;i < sz;i++){

            cin >> elem;
            A.push_back(elem);

        }
        vector<int> Result = Solution(A);

        for(int i = 0; i < Result.size(); i++){
            cout << Result[i] << " ";
        }
        cout << endl;
    }///loop


}

vector<int> Solution(vector<int> &A){

    vector<int> Result;

    int add = 1, sz = A.size();

    for(int i = sz -1; i >= 0; i--){
       int addValue = A[i] + add;
       if(addValue > 9){
          add = 1;
          Result.push_back(0);
       }else {
          add = 0;
          Result.push_back(addValue);
       }
    }// loop

    if(add) Result.push_back(1);

    reverse(Result.begin(), Result.end());

    while(Result[0] == 0){
        Result.erase(Result.begin());
    }

    return Result;

    /*for(int i = 0; i < Result.size(); i++){
        cout << Result[i] << " ";
    }
    cout << endl;

    Result.clear(); A.clear(); */
}



