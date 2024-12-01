#include "Node.cpp"
#include <iostream>
#include <cstddef>
using namespace std;

template <typename E>
class LinkedList
{
    public:
        ~LinkedList();
        Node<E> *head = NULL;
        Node<E> *tail = NULL;
        
        void addNode(E value){
            Node<E> *newNode = new Node<E>(value);

            if (head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            (*tail).nextNode = newNode;
            tail = newNode;
        }

        void printList(){
            Node<E> *current = head;
            int i = 0;
            while (current != NULL)
            {
                cout << i++ << ". element: " << (*current).value << "\n";
                current = (*current).nextNode;
            }
            
        }
};

template <typename E>
LinkedList<E>::~LinkedList()
{
    Node<E> *current = head;
    while (current != nullptr)
    {
        Node<E> *temp = current;        // Save the current node pointer
        current = (*current).nextNode; // Move to the next node
        delete temp;                 // Delete the saved node
    }
};
