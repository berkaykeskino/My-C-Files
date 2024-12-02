#include <iostream>
#include <string>
#include "HashTable.cpp"
#include <string.h>

using namespace std;

int main()
{

    HashTable<string> *myHashTable = new HashTable<string>();

    for (int i = 0; i < 50; i++)
    {
        (*myHashTable).addEntry(to_string(i));
    }
    (*myHashTable).printHashTable();

    return 0;
}