int size_of_linked_list(){

    node *currentNode = root;

    int sz = 0;

    while(currentNode!= NULL){
        sz++;
        currentNode = currentNode->next;
    }//while

    return sz;

}