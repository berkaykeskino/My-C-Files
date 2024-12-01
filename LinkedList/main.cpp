#include "LinkedList.cpp"
#include <string>
#include <iostream>
using namespace std;

int main(){

    LinkedList<string> *linkedListStr = new LinkedList<string>();

    for (int i = 20; i > 10; i--)
    {
        (*linkedListStr).addNode(to_string(i));
    }
    (*linkedListStr).printList();
    
    delete linkedListStr;

    cout << "-----\n";

    LinkedList<int> *linkedListInt = new LinkedList<int>();

    for (int i = 20; i > 10; i--)
    {
        (*linkedListInt).addNode(i);
    }
    (*linkedListInt).printList();

    delete linkedListInt;

    return 0;
}