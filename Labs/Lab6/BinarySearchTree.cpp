// Created by Michael Beebower on 5/9/2019.

#include "BinarySearchTree.h"

// protected methods

// placeNode - based on placeNode on pg. 492
// Recursively places a given new node at its proper position in a binary search tree.
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                std::shared_ptr<BinaryNode<ItemType>> newNode)
{
    if (subTreePtr == nullptr)
        return newNode;
    else if (subTreePtr->getItem() > newNode->getItem())
    {
        auto tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        auto tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

// removeValue - based on removeValue on pg. 498
// Removes a given target from the binary search tree to which subTreePtr points.
// Returns a pointer to the node at this tree location after the value is removed.
// Sets [bool& success] to true if the removal is successful, or false otherwise.
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                  const ItemType target, bool& success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
    }
    else if (subTreePtr->getItem() == target)
    {
        // Item is in the root of some subtree
        subTreePtr = removeNode(subTreePtr);    // Remove the item
        success = true;
    }
    else if (subTreePtr->getItem() > target)
    {
        // Search the left subtree
        auto tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        // Search the right subtree
        auto tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

// removeNode - based on removeNode on pg. 498-499
// Removes the data item in the node, N, to which nodePtr points.
// Returns a pointer to the node at this tree location after the removal.
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
        BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
    if (nodePtr->isLeaf())      // if N is a leaf
    {
        // Remove leaf from the tree
        // Delete the node to which nodePtr points (done for us if nodePtr is a smart pointer)
        nodePtr = nullptr;
        return nodePtr;
    }
    // else if (N has only one child C)
    else if ((nodePtr->getLeftChildPtr() == nullptr) || (nodePtr->getRightChildPtr() == nullptr))
    {
        std::shared_ptr<BinaryNode<ItemType>> nodeToConnectPtr;     // initialize nodeToConnectPtr

        // C replaces N as the child of N's parent
        if (nodePtr->getLeftChildPtr() != nullptr)                  // C is a left child
            nodeToConnectPtr= nodePtr->getLeftChildPtr();
        else                                                        // C is a right child
            nodeToConnectPtr= nodePtr->getRightChildPtr();

        // Delete the node to which nodePtr points (done for us if nodePtr is a smart pointer)
        return nodeToConnectPtr;
    }
    else    // nodePtr has two children
    {
        // Find the inorder successor of the entry in N: it is in the left subtree rooted at N's right child.
        auto newNodeValue = nodePtr->getItem();
        auto tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue);     // Put replacement value in node N
        return nodePtr;
    }
}

// removeLeftmostNode - based on removeLeftmostNode on pg. 499
// Removes the leftmost node in the left subtree of the node pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
        BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                         ItemType& inorderSuccessor)
{
    if (subTreePtr->getLeftChildPtr() == nullptr)
    // if (subTreePtr == nullptr)
    {
        // This is the node you want; it has no left child, but it might have a right subtree
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    }
    else
    {
        auto tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
}

// findNode (search) - based on findNode on pg. 501-502
// Locates the node in the binary search tree to which (subTreePtr or treePtr) points and that contains the value target.
// Returns either a pointer to the located node or nullptr if such a node is not found.
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                               const ItemType& target) const
{
    if (treePtr == nullptr)
        return nullptr;         // Not found
    else if (treePtr->getItem() == target)
        return treePtr;         // Found
    else if (treePtr->getItem() > target)
        // Search left subtree
        return findNode(treePtr->getLeftChildPtr(), target);
    else
        // Search right subtree
        return findNode(treePtr->getRightChildPtr(), target);
}

// public methods

// setRootData
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) const throw(PrecondViolatedExcep)
{
    if (this->rootPtr == nullptr)   // verify BST is empty first
    {
        auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
        this->rootPtr = placeNode(this->rootPtr, newNodePtr);
    }
    else    // if not empty, throw exception
        throw PrecondViolatedExcep("The binary search tree is not empty.");
}   // end setRootData

// add - based on add method at top of pg. 492
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
    this->rootPtr = placeNode(this->rootPtr, newNodePtr);

    return true;
}   // end add

// remove - based on remove method on pg. 498
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry)
{
    bool isSuccessful = false;
    this->rootPtr = removeValue(this->rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}   // end remove

// getEntry
// The operation getEntry must return the data item with the desired value if it exists, otherwise it must throw an
// exception NotFoundException.
// The method, therefore, calls findNode and checks its return value.
// If the desired target is found, getEntry returns it.
// If findNode returns nullptr, getEntry throws an exception.
// Look into BST traversal?
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
    auto nodePtr = findNode(this->rootPtr, anEntry);
    if (nodePtr == nullptr)
        throw NotFoundException("The entry was not found.");
    else
        return nodePtr->getItem();
}   // end getEntry

// contains
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
    auto nodePtr = findNode(this->rootPtr, anEntry);
    return (nodePtr != nullptr);
}   // end contains

