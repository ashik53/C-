#include <bits/stdc++.h>
using namespace std;
void Solution(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector <int> Result;

    int sz1 = A.size();

    for(int i = 0; i < sz1; i++){
        int element = A[i];

        ///cout << B. size() << endl;

        if(!B.empty()){
            int be = 0, en = B.size() - 1, mid;
            while(be <= en){
                mid = (be+en)/2;
                if(element >= B[mid]){
                    be = mid + 1;
                }else{
                    en = mid - 1;
                }
            }// while
          ///  cout << "i = " <<i <<", en = " << en <<endl;
            for(int j = 0; j <= en; j++){
                Result.push_back(B[j]);
                //cout << B[j] <<" inserted, ";
            }
            for(int j = 0; j <= en; j++){
                B.erase(B.begin());
            }
        }// if !B.empty()
        Result.push_back(element);
        /*cout << element << " inserted\n";
        cout <<"Result vector is ";

        for(int j = 0; j < Result.size(); j++) cout << Result[j] <<" ";
        cout <<"\n\n"; */
    }//A

    int sz2 = B.size();
    for(int j = 0; j < sz2; j++) Result.push_back(B[j]);

    A.clear();
    A = Result;

    cout << endl;
    for(int i  = 0; i < Result. size(); i++){
        cout << Result[i] << " ";
    }
    cout << endl;
}//func

int main(){

   int sz1, sz2;

   while(cin >> sz1 >> sz2){
        cout << "Enter vector 1 :";
        vector <int> A,B;
        int elem;
        for(int i = 0; i < sz1; i++){
            cin >> elem;
            A.push_back(elem);
        }
        cout << endl;

        cout << "Enter vector 2 :";
        for(int i = 0; i < sz2; i++){
            cin >> elem;
            B.push_back(elem);
        }

        Solution(A, B);
   }//loop


}

