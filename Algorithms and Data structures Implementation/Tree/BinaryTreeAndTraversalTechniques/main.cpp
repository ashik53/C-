#include <bits/stdc++.h>
using namespace std;

typedef struct Node{

    int data;
    Node *left,*right;

};

void add_left_child(Node *parent,Node *child){

    parent->left = child;
}

void add_right_child(Node *parent,Node *child){

    parent->right= child;
}

Node *createNode(int item){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode==NULL){
        printf("Error! Could not create a new node!\n");
        exit(1);
    }

    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}
Node *create_tree(){
    //creating all the nodes 2,7,9,1,6,8,5,10,3,4
    Node *two = createNode(2);
    Node *seven = createNode(7);
    Node *nine = createNode(9);
    Node *one = createNode(1);
    Node *six = createNode(6);
    Node *eight = createNode(8);
    Node *five = createNode(5);
    Node *ten = createNode(10);
    Node *three = createNode(3);
    Node *four = createNode(4);

    //adding all lefts children to the left of their root
    add_left_child(two,seven);
    add_left_child(seven,one);
    add_left_child(six,five);
    add_left_child(eight,three);


    //adding all right children to the right of their root
    add_right_child(two,nine);
    add_right_child(seven,six);
    add_right_child(nine,eight);
    add_right_child(six,ten);
    add_right_child(eight,four);



    return two;
}
void preOrderTraversal(Node *root){

    printf("%d ",root->data);

    //firstly, root node will go the the most left depth of the tree until the NULL left
    if(root->left!=NULL){
        preOrderTraversal(root->left);
    }

    //firstly, root node will traverse right nodes
    if(root->right!=NULL){
        preOrderTraversal(root->right);
    }


}

void postOrderTraversal(Node *root){

    //firstly, root node will go the the most left depth of the tree until the NULL left
    if(root->left!=NULL){
        postOrderTraversal(root->left);
    }

    //firstly, root node will traverse right nodes
    if(root->right!=NULL){
        postOrderTraversal(root->right);
    }

    //at last the data inside root will be printed
    printf("%d ",root->data);

}

void inOrderTraversal(Node *root){

    //firstly, root node will go the the most left depth of the tree until the NULL left
    if(root->left!=NULL){
        inOrderTraversal(root->left);
    }

    //at the middle ,data inside "root" will be printed
    printf("%d ",root->data);

    //firstly, root node will traverse right nodes
    if(root->right!=NULL){
        inOrderTraversal(root->right);
    }



}
int main()
{
    //create the tree by calling the create_tree() function
    Node *root = create_tree();

    printf("%d\n",root->data);

    //pre-order traversal of a binary tree(root,left,right)
    cout<<"pre-order traversal of a binary tree\n";
    preOrderTraversal(root);
    cout<< endl;

    //post-order traversal of a binary tree
    cout<< "post-order traversal of a binary tree\n";
    postOrderTraversal(root);
    cout<<endl;

    //in order traversal
    cout<< "in-order traversal of a binary tree\n";
    inOrderTraversal(root);
    cout<<endl;

    return 0;

}
