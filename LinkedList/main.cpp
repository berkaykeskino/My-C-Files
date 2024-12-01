#include "LinkedList.cpp"

int main(){

    LinkedList *linkedList = new LinkedList();

    for (int i = 20; i > 10; i--)
    {
        (*linkedList).addNode(i);
    }
    (*linkedList).printList();
    
    delete linkedList;

    return 0;
}