#include <iostream>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
class SegmentNode{
public:
    int highestValue;
    int highestNumber;
    SegmentNode(int x,int y): highestNumber(x),highestValue(y){};

};
class Frequency {
public:
    int st;
    int fn;
    Frequency(){
    }

};
#define pii pair<int,int>
map<int,int> frequencyMap;
int lengthOfInputArray,querySize;

SegmentNode* segmentTree[100007*3];
int ara[100007];
int frequencyQuery(int node,int be,int en,int i,int j,int value);
void buildMap();
void buildTree(int node,int be,int en);
pii query(int node,int be,int en,int i,int j);
int AnotherFrequencyQuery(int node, int be, int en, int i, int j,int q1,int q2,int value);
int main()
{

   while(scanf("%d",&lengthOfInputArray)){

   if(lengthOfInputArray==0) break;
   scanf("%d",&querySize);

   for(int i=0;i<lengthOfInputArray;i++){
      scanf("%d",&ara[i]);
   }
  // for(int i=0;i<lengthOfInputArray;i++) cout<<ara[i]<<endl;
   frequencyMap.clear();
   buildMap();
   /*int a;
   while(cin >> a){

      cout<<frequencyMap[a]->st <<" "<<frequencyMap[a]->fn<<endl;
     //cout<<"hello\n";
   } */

   buildTree(1,0,lengthOfInputArray-1);

  for(int i=0;i<querySize;i++) {
   int a, b;

   //while(cin >>a>>b){
        scanf("%d%d",&a,&b);
        pii result = query(1,0,lengthOfInputArray-1,a-1,b-1);
        printf("%d\n",result.second);
        //cout<<result.second<<endl;
   }
   //}


   /*index[1]  = new P(3,6);
   index[-1] = new P(1,2);
   index[3] = new P(7,7);
   index[10] = new P(8,10);
   int i,j,value;
   while(cin>> i>> j>> value){
       //int ans = frequencyQuery(1,1,10,i,j,value);
      cout<<frequencyQuery(1,1,10,i,j,value)<<endl;
   }

   ara[1] = new P(3,6);
   cout<<ara[1]->a<<endl;
   cout<<ara[1]->b << endl; */
   }//cases
}



void buildTree(int node,int be,int en){

  if(be==en){
      segmentTree[node] = new SegmentNode(ara[be],1);
      //cout<<node<<" ,"<<segmentTree[node]->highestNumber<<" , "<<segmentTree[node]->highestValue<<endl;
      return;
  }

  int left = node*2;
  int right = (node*2)+1;
  int mid =(be+en)/2;

  buildTree(left,be,mid);
  buildTree(right,mid+1,en);

  int r1 = segmentTree[left]->highestValue+ frequencyQuery(1,0,lengthOfInputArray-1,mid+1,en,segmentTree[left]->highestNumber);
  int r2 = segmentTree[right]->highestValue+ frequencyQuery(1,0,lengthOfInputArray-1,be,mid,segmentTree[right]->highestNumber);
  if(r1>r2) segmentTree[node] = new SegmentNode(segmentTree[left]->highestNumber,r1);
  else segmentTree[node] = new SegmentNode(segmentTree[right]->highestNumber,r2);
}
int AnotherFrequencyQuery(int node, int be, int en, int i, int j,int q1,int q2,int value)
{
    if (i > en || j < be)
        return 0;
   // if(q1>en || q2<be) return 0;
    if ((be >= i && en <= j)){
          if((be>= frequencyMap[value]->st && en<=frequencyMap[value]->fn) && (be>=q1 && en<=q2)) return en-be+1;
          else if(frequencyMap[value]->st >en || frequencyMap[value]->fn <be) return 0;
          else if(q1>en || q2<be) return 0;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (be + en) / 2;

    int p1 = AnotherFrequencyQuery(Left, be, mid, i, j,q1,q2,value);
    int p2 = AnotherFrequencyQuery(Right, mid + 1, en, i, j,q1,q2,value);
  /*cout<< b<<","<<mid<<" result aslo = "<<p1<<"\t";
    cout<< mid+1<<","<<e<<" result aslo = "<<p2<<endl;
    cout<<b<<","<<e<<" theke aslo "<<p1+p2<<endl;
    cout<<endl; */
    return p1 + p2;
}
pii query(int node,int be,int en,int i,int j){

  if(i>en || j<be) return make_pair(0,0);
  if(be>=i && en<=j) return make_pair(segmentTree[node]->highestNumber,segmentTree[node]->highestValue);

  int left = node*2;
  int right = node*2 +1;
  int mid = (be+en)/2;


  pii sibling1 = query(left,be,mid,i,j);
  pii sibling2 = query(right,mid+1,en,i,j);


  int r1,r2;
  if(sibling1.first==0 && sibling1.second==0) r1= 0;
  else r1 = sibling1.second + AnotherFrequencyQuery(1,0,lengthOfInputArray-1,mid+1,en,i,j,sibling1.first);


  if(sibling2.first==0 && sibling2.second==0) r2= 0;
  else r2 = sibling2.second + AnotherFrequencyQuery(1,0,lengthOfInputArray-1,be,mid,i,j,sibling2.first); ;

  //cout<< node<< "-> " << r1 << ", "<<r2<<endl;
  int mx = max(r1,r2);
  int mxValue;
  if(mx==r2){
     mxValue = sibling2.first;
  }
  else mxValue = sibling1.first;

  return make_pair(mxValue,mx);
}
/*int query(int node,int be,int en,int i,int j){

  if(i>en || j<be) return 0;
  if(be>=i && en<=j) return segmentTree[node]->highestValue;

  int left = node*2;
  int right = node*2 +1;
  int mid = (be+en)/2;

  int r1 = query(left,be,mid,i,j)+AnotherFrequencyQuery(1,0,lengthOfInputArray-1,mid+1,en,i,j,segmentTree[left]->highestNumber);
  int r2 = query(right,mid+1,en,i,j)+AnotherFrequencyQuery(1,0,lengthOfInputArray-1,be,mid,i,j,segmentTree[right]->highestNumber); ;

  cout<< node<< "-> " << r1 << ", "<<r2<<endl;

  return max(r1,r2);
}*/
void buildMap(){

  int number = 100008;
  frequencyMap[number] = new Frequency();
  for(int i=0;i<lengthOfInputArray;i++){

     if(ara[i]!=number){
         frequencyMap[number]->fn = i-1;
         number = ara[i];
         frequencyMap[number] = new Frequency();
         frequencyMap[number]->st = i;
     }
    if(i==lengthOfInputArray-1){
        frequencyMap[number]->fn = i;
    }
    //cout<<i <<endl;
  }//for loop


}//func

int frequencyQuery(int node, int b, int e, int i, int j,int value)
{
    if (i > e || j < b)
        return 0;
    if ((b >= i && e <= j)){
          if(b>= frequencyMap[value]->st && e<=frequencyMap[value]->fn) return e-b+1;
          else if(frequencyMap[value]->st >e || frequencyMap[value]->fn <b) return 0;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = frequencyQuery(Left, b, mid, i, j,value);
    int p2 = frequencyQuery(Right, mid + 1, e, i, j,value);
  /*  cout<< b<<","<<mid<<" result aslo = "<<p1<<"\t";
    cout<< mid+1<<","<<e<<" result aslo = "<<p2<<endl;
    cout<<b<<","<<e<<" theke aslo "<<p1+p2<<endl;
    cout<<endl; */
    return p1 + p2;
}
