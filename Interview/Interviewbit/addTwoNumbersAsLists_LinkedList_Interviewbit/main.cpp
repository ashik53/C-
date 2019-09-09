#include <bits/stdc++.h>

using namespace std;


typedef struct ListNode{

    int value;
    ListNode *next;
    ListNode(int x) : value(x),next(NULL) {}

};

ListNode *root1, *root2, *root3 = NULL;
void append(int val){

    if(root == NULL){
        root = new ListNode(val);
    } else {

        ListNode *currentNode = root;

        while(currentNode->next!= NULL){
            currentNode = currentNode->next;
        }

        ListNode *newNode = new ListNode(val);
        currentNode->next = newNode;

    } //else
}

void printAll(){

  ListNode *currentNode = root;
  while(currentNode!= NULL){
    cout << currentNode->value << " ";
    currentNode = currentNode->next;
  }


} //print all



int main(){
    for(int i =0; i <= 10; i++){
        append(i);
    }


}
