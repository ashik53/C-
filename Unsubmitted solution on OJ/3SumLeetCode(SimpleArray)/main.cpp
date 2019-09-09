#include <bits/stdc++.h>

using namespace std;

map<int,int>elementInfo[100];
map<int,int>validity;
int main()
{
    int sz,element;
    scanf("%d",&sz);
    cout<< sz<<endl;

    elementInfo[-1][0] = 1;
    elementInfo[-1][1] = 10;

    cout<< elementInfo[-1][0]<<" "<< elementInfo[-1][1]<<endl;

    vector<int>numbersAra;
    for(int i=0;i<sz;i++){
        elementInfo[i].clear();
    }
    for(int i=0;i<sz;i++){
        scanf("%d",&element);
        elementInfo[element][0] = 1;
        elementInfo[element][1]++;
        numbersAra.push_back(element);
    }

    sort(numbersAra.begin(),numbersAra.end());

    for(int i=0;i<sz;i++){
        cout<< numbersAra[i]<<" ";
    }
    cout<< endl;

    for(int i=0;i<sz;i++){
        validity.clear();
        int a = numbersAra[i];
        validity[a]++;
        for(int j= i+1;j<sz;j++){
            int b = numbersAra[j];
            validity[b]++;

            //all calculation
            int remain = 0-(a+b);

            cout<< a <<" "<<b <<" "<<remain <<endl;

            if(elementInfo[remain][0]==1 && elementInfo[remain][1]>validity[remain]){
                cout<< "("<<a <<" "<<b << " "<< remain<<")"<<endl;
            }

        }
    }

}
