#include <bits/stdc++.h>
using namespace std;
typedef struct node{
   int roll;
   node *next,*prev; //take next and previous nodes;
};
node *root = NULL;
node *tail = NULL;
void append(int roll){

    if(root==NULL) //If the list is empty
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
        tail = root;
        root->prev= NULL;
    }

    else {
        node *newNode = new node();
        newNode->roll = roll;
        newNode->next = NULL;
        tail->next = newNode; //add the "new node" after "tail node"
        newNode->prev = tail; // holds previous node
        tail = tail->next; //move tail pointer forward
    }


}

void print(){
    node *current_node = root;

    printf("All elements: ");

    while(current_node!=NULL) //loop until you reach null
    {
        printf("%d ",current_node->roll);
        current_node = current_node->next;
    }
    cout<< endl;

}

void deleteNode(){

    node *lastNode = tail->prev;

    lastNode->next = NULL;

    delete(tail);

}
int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    print();
    deleteNode();
    print();
    printf("\nAfter deleting \n");
    print();
}
