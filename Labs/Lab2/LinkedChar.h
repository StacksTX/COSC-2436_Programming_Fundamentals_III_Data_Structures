//
// Created by mbeebower on 2/21/2019.
//

#ifndef LINKEDCHAR_H
#define LINKEDCHAR_H

//#include <iostream>
#include <string>
//#include "CharInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedChar //: public CharInterface<ItemType>
{
private:
    Node<ItemType>* headPtr;    // Pointer to first node
    int itemCount;              // Current count of linked list items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the list.
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    LinkedChar();                       // Default constructor
    explicit LinkedChar(const std::string& s);   // Constructor
    virtual ~LinkedChar();              // Destructor should be virtual
    int length() const;                 // aka "getCurrentSize" from LinkedBag.h
    int index(char ch) const;           // -1 if no match
    void append(const LinkedChar& lc);
    bool submatch(const LinkedChar& lc) const;  // might be similar to "contains" from LinkedBag.h
    void clear();                       // needed for destructor
    std::string display();
    //bool isEmpty() const;
    //bool remove(const ItemType& anEntry);
    //bool contains(const ItemType& anEntry) const;
    //int getFrequencyOf(const ItemType& anEntry) const;
};


//#include "LinkedChar.cpp"   // similar to LinkedBag.cpp
#endif //LINKEDCHAR_H
