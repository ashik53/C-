#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define llu unsigned long long

int numbersAra[1000007], parentAra[1000007], primeAra[10000007];

int findParent(int r){

    if(parentAra[r] == r) return r;
    return parentAra[r] = findParent(parentAra[r]);

}

void unionElements(int a,int b){

    int u = findParent(a);
    int v = findParent(b);
   // cout << u << " " << v <<  " af" << endl;
    if(u != v){
        parentAra[u] = v ;
    }
}

void makeSet(int n){
    parentAra[n] = n;
}

void sieve(){

    primeAra[0] = 1;
    primeAra[1] = 1;

    for(int i = 2 ; i*i <= 1000007 ; i++){
        if(primeAra[i]) continue;
        for(int j = i*2 ; j <= 1000007; j+=i){
            primeAra[j] = 1;
        }
    }


}

void factorization(int num){

     int n = num;
   //  cout << n <<" factors -> ";
     while(primeAra[n]!= 0 && n!=1){
        for(int i = 2 ; i*i <= n; i++){
            if(primeAra[i]) continue;
            if(n%i == 0){
                n = n/i;
                //cout << i <<" ";
                unionElements(i, num);
                break;
            }
        }//for
     }//while

    if(!primeAra[n]) {/*cout<< n<<" "<< endl;*/unionElements(num, n);}



}


llu bigMod(llu N,llu P){

	if(P==0) return 1;
	if(P%2==0) {
		llu ret=bigMod(N,P/2);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(bigMod(N,P-1)%M))%M;

}

int main(){

       int cases, sz;



       sieve();

      // cout << parentAra[2] <<" " << parentAra[6] <<endl;

     // for(int i =0;i<20;i++) {if(primeAra[i]==0) cout << i <<endl;}

       cin >> cases;
       for(int line = 0; line < cases ; line++){
           cin >> sz;



          // int maxElement = -100;

           for(int i = 0; i < sz; i++){

                cin >> numbersAra[i];


               // if(maxElement < numbersAra[i]) maxElement = numbersAra[i];
                makeSet(numbersAra[i]);

                //elems.push_back(numbersAra[i]);
           }

           //sort(elems.begin(),elems.end());


           for(int i = 0; i < sz ;i++){
              if(primeAra[numbersAra[i]] == 1 && numbersAra[i]!=1) factorization(numbersAra[i]);
           }


           int power = 0;
           set<int>parents;
           for(int i = 0; i < sz ; i++){
                if(numbersAra[i] == 1) power++;
                else {
                   // cout<< numbersAra[i] << " " << findParent(numbersAra[i]) << endl;
                    parents.insert(findParent(numbersAra[i]));
                }
           }

           power += parents.size();

           llu ans = (1000000005 +  bigMod(2,power) )%M;

           ans-= 2 ;

           cout << ans <<endl;

       }// cases



}
