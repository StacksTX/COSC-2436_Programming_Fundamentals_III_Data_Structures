//
// Created by beebs on 4/22/19.
//

/** Implementation file for the class LinkedSortedList.
 @file LinkedSortedList.cpp */

#include "LinkedSortedList.h"   // Header file

// constructors
template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0)
{
}   // end default constructor

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
    headPtr = copyChain(aList.headPtr);
    itemCount = aList.itemCount;
}   // end copy constructor

// destructor
template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    clear();
}   // end destructor

// *** Private Methods ***
// -----------------------

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr)
{
    std::shared_ptr<Node<ItemType>> copiedChainPtr;     // Initial value is nullptr
    if (origChainPtr != nullptr)
    {
        // Build new chain from given one
        // Create new node with the current item
        copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
        // Make the node point to the rest of the chain
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    }   // end if

    return copiedChainPtr;
}   // end copyChain private method

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
    auto curPtr = headPtr;
    std::shared_ptr<Node<ItemType>> prevPtr;

    while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
    {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    }   // end while

    return prevPtr;
}   // end getNodeBefore private method

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const {

    //return nullptr;
}   // end getNodeAt private method

// *** Public Methods ***
// ----------------------

// Task: Inserts an entry into this sorted list in its proper order so that the list remains sorted.
// Input: newEntry is the new entry.
// Output: True if insertion is successful, or false if not.
template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
    auto newNodePtr(std::make_shared<Node<ItemType>>(newEntry));
    auto prevPtr = getNodeBefore(newEntry);

    if (isEmpty() || (prevPtr == nullptr))  // Add at beginning
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else                                    // Add after node before
    {
        auto aftPtr = prevPtr->getNext();
        newNodePtr->setNext(aftPtr);
        prevPtr->setNext(newNodePtr);
    }   // end if

    itemCount++;
    return true;
}   // end insertSorted public method

// Task: Removes the first or only occurrence of anEntry from this sorted list.
// Input: anEntry is the entry to remove.
// Output: Returns true if anEntry was located and removed, or false if not.
//          In the latter case, the list remain unchanged.
template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry) {
    //return false;
}   // end removeSorted public method

// Task: Gets the position of the first or only occurrence of anEntry in this sorted list.
// Input: anEntry is the entry to be located.
// Output: Returns the position of anEntry if it occurs in the sorted list.
//          Otherwise, returns the position where anEntry would occur in the list, but as a negative integer.
template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const {
    //return 0;
}   // end getPosition public method

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}   // end isEmpty public method

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const {
    return itemCount;
}   // end getLength public method

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        if (position == 1)
        {
            // Remove the first node in the chain
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            auto prevPtr = getNodeAt(position - 1);

            // Point to node to delete
            auto curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }  // end if

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}   // end remove public method

template<class ItemType>
void LinkedSortedList<ItemType>::clear() {
    headPtr.reset();
    // headPtr = nullptr; // is OK also
    itemCount = 0;
}   // end clear public method

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const {
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        auto nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message  = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}   // end getEntry public method



