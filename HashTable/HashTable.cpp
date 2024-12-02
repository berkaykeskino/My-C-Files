#include "HashEntry.cpp"
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

template <typename E>
class HashTable
{
public:
    ~HashTable<E>();

    int size = 7;
    int numberOfElements = 0;
    vector<HashEntry<E> *> hashTable;
    vector<int> currentPositions;

    HashTable<E>()
    {
        hashTable.resize(size, NULL);
        currentPositions.resize(size / 2, -1);
    };

    int newSize(int size)
    {
        return size * 2; // asal dönmeli
    }

    int hashFunction(E value, int depth)
    {
        hash<E> hashObject;
        int hashValue = hashObject(value);
        if (hashValue < 0)
        {
            hashValue = -hashValue;
        }
        return (hashValue + depth) % size;
    }

    int removeEntry(E value)
    {
        HashEntry<E> *searchPointer;
        int found = -1;
        for (int i = 0; i < size / 2; i++)
        {
            if (currentPositions[i] == -1)
            {
                continue;
            }
            searchPointer = hashTable[currentPositions[i]];
            if (value == (*searchPointer).value)
            {
                found = currentPositions[i];
                currentPositions[found] = -1;
                break;
            }
        }
        if (found == -1)
        {
            return -1; // not found
        }
        numberOfElements--;
        delete hashTable[found];
        hashTable[found] = NULL;
        return 0; // deleted
    }

    void addEntry(E value)
    {
        HashEntry<E> *newEntry = new HashEntry<E>(value);
        if (size / 2 <= numberOfElements)
        {

            // store existing nodes in presentValues
            vector<HashEntry<E> *> presentValues;
            presentValues.resize(numberOfElements, NULL);
            for (int i = 0; i < size / 2; i++)
            {
                presentValues[i] = hashTable[currentPositions[i]];
            }

            // store existing nodes in new resized hashTable
            for (int i = 0; i < size; i++)
            {
                hashTable[i] = NULL;
                currentPositions[i / 2] = -1;
            }
            size = newSize(size);

            hashTable.resize(size, nullptr);
            currentPositions.resize(size / 2, -1);

            for (int i = 0; i < numberOfElements; i++)
            {
                int depth = 0;
                int entryPosition = hashFunction((*presentValues[i]).value, depth);
                while (hashTable[entryPosition] != NULL)
                {
                    depth++;
                    entryPosition = hashFunction((*presentValues[i]).value, depth);
                }
                hashTable[entryPosition] = presentValues[i];
                currentPositions[i] = entryPosition;
            }
        }
        int depth = 0;
        int newEntryPosition = hashFunction((*newEntry).value, depth);
        while (hashTable[newEntryPosition] != NULL)
        {
            depth++;
            newEntryPosition = hashFunction((*newEntry).value, depth);
        }
        hashTable[newEntryPosition] = newEntry;

        ++numberOfElements;
        for (int i = 0; i < size / 2; i++)
        {
            if (currentPositions[(numberOfElements + i) % (size / 2)] == -1)
            {
                currentPositions[(numberOfElements + i) % (size / 2)] = newEntryPosition;
                break;
            }
        }
    }

    void printHashTable()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ". element: ";
            if (hashTable[i] == NULL)
            {
                cout << "NULL";
            }
            else
            {
                cout << (*hashTable[i]).value;
            }
            cout << "\n";
        }
    }
};

template <typename E>
HashTable<E>::~HashTable()
{
    for (int i = 0; i < size; i++)
    {
        if (hashTable[i] != nullptr)
        {
            delete hashTable[i];
        }
    }
}