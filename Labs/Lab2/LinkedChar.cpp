//
// Created by mbeebower on 2/21/2019.
//

#include "LinkedChar.h"
#include "Node.h"
#include <string>

template<class ItemType>
LinkedChar<ItemType>::LinkedChar() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedChar<ItemType>::LinkedChar(const std::string& s)
{
    itemCount = static_cast<int>(s.length());
    headPtr = nullptr;  // Linked list starts as empty

    // iterate through the string and add to linked list
    for (int i=itemCount-1;i>=0;i--)
    {
        if (headPtr == nullptr)     // empty list
        {
            headPtr = new Node<ItemType>(); // initialize the headptr by creating the new node
            headPtr->setItem(s[i]);         // store the character s[i] in the node (1st character)
        }
        else    // not empty list
        {
            auto * newNodePtr = new Node<ItemType>(s[i]); // pointer to create a new node with next character
            newNodePtr->setNext(headPtr);   // point new node to head
            headPtr = newNodePtr;           // make head point to the actual first node
        }
    }
}  // end constructor

template<class ItemType>
LinkedChar<ItemType>::~LinkedChar()
{
    clear();
}  // end destructor

/*
template<class ItemType>
bool LinkedChar<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty
*/

template<class ItemType>
int LinkedChar<ItemType>::length() const
{
    return itemCount;
}  // end length

template<class ItemType>
void LinkedChar<ItemType>::append(const LinkedChar& lc)
{
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is null if chain is empty)
    auto * nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(lc);
    nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

    headPtr = nextNodePtr;          // New node is now first node
    itemCount++;
}  // end append

template<class ItemType>
int LinkedChar<ItemType>::index(char ch) const
{
    int index = -1;  // initialize index
    // search for node
    Node<ItemType>* curr = headPtr;

    while(curr != nullptr && curr->getItem() != ch)
    {
        index++;
        curr = curr->getNext();
    }
    if (curr == nullptr)
        index = -1;
    return index;
}   // end index

template<class ItemType>
bool LinkedChar<ItemType>::submatch(const LinkedChar& lc) const
{
    return (getPointerTo(lc) != nullptr);   // similar to "contains" from LinkedBag.cpp?
}   // end submatch

template<class ItemType>
void LinkedChar<ItemType>::clear()
{
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr

    itemCount = 0;
}   // end clear

template<class ItemType>
Node<ItemType>* LinkedChar<ItemType>::getPointerTo(const ItemType& anEntry) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;

    while (!found && (curPtr != nullptr))
    {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
} // end getPointerTo

template<class ItemType>
std::string LinkedChar<ItemType>::display()
{
    Node<ItemType>* curr = headPtr;
    std::string s;

    while(curr != nullptr) {
        s += curr->getItem();
        curr = curr->getNext();
    }
    return s;
}   // end display