#include <cstddef>

template <typename E>
class Node
{
public:
    E value;
    Node<E> *nextNode = NULL;
    Node(E value)
    {
        (*this).value = value;
    }
};
