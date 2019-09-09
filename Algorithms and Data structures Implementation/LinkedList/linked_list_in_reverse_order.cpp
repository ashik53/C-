#include <bits/stdc++.h>
using namespace std;

struct node {

    int roll;
    node *prev;
    node *next;

};

struct node *root, *tail;
void print();
void append(int roll){

    if(root == NULL){
       // cout << roll <<" appended\n";
        root = new node();
        root->roll = roll;
        root->next = NULL;
        root->prev = NULL;
        tail = root;
    }//if
    else {

        node *newNode = new node();
        newNode->roll = roll;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

       // cout << roll <<" appended\n";

    }


}//

void print_reverse_mood(){

    node *currentNode = tail;

    while(currentNode != NULL){

        cout << currentNode->roll << " ";
        currentNode = currentNode->prev;
    } //

    cout << endl;

}//


int main(void){

    append(1);append(2);append(3);append(4);append(5);
    print();


    print_reverse_mood();


} // main func

void print(){

    node *currentNode = root;
   // cout << "entered\n";

    //cout << root->roll << endl;


    while(currentNode!= NULL){

        cout << currentNode->roll << " ";

        currentNode = currentNode->next;

            //cout << currentNode->roll;
    }//WHILE
    cout <<endl;



}//




