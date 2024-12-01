#include "Node.cpp"
#include <iostream>
#include <cstddef>

using namespace std;

class LinkedList
{
    public:
        ~LinkedList();
        Node *head = NULL;
        Node *tail = NULL;
        
        void addNode(int value){
            Node *newNode = new Node(value);

            if (head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            (*tail).nextNode = newNode;
            tail = newNode;
        }

        void printList(){
            Node *current = head;
            int i = 0;
            while (current != NULL)
            {
                printf("%d. element: %d\n", i++, (*current).value);
                current = (*current).nextNode;
            }
            
        }
};

LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;        // Save the current node pointer
        current = (*current).nextNode; // Move to the next node
        delete temp;                 // Delete the saved node
    }
};
