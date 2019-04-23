//
// Created by beebs on 4/22/19.
//

/** ADT sorted list: Linked-based implementation.
 @file LinkedSortedList.h */

#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_
#include <memory>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
    std::shared_ptr<Node<ItemType>> headPtr;    // Pointer to 1st node in chain
    int itemCount;                              // Current count of list items

    // Locates the node that is before the node that should or does
    // contain the given entry.
    // @param anEntry   The entry to find.
    // @return  Either a pointer to the node before the node that contains
    //  or should contain the given entry, or nullptr if no prior node exists.
    auto getNodeBefore(const ItemType& anEntry) const;

    // Locates the node at a given position within the chain.
    auto getNodeAt(int position) const;

    // Returns a pointer to a copy of the chain to which origChainPtr points.
    auto copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr);

public:
    // constructors
    LinkedSortedList();
    LinkedSortedList(const LinkedSortedList<ItemType>& aList);

    // destructor
    virtual ~LinkedSortedList();

    // The following 3 new public methods for the sorted list are not found in ListInterface.
    bool insertSorted(const ItemType& newEntry);
    bool removeSorted(const ItemType& anEntry);
    int getPosition(const ItemType& anEntry) const;

    // The following methods are the same as given in ListInterface.
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const noexcept(false);
}; // end LinkedSortedList
// #include "LinkedSortedList.cpp"
#endif // LINKED_SORTED_LIST_
