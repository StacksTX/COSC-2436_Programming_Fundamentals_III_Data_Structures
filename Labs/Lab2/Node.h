//
// Created by mbeebower on 2/21/2019.
//

#ifndef NODE_H
#define NODE_H

template <class ItemType>
class Node
{
private:
    ItemType item;          // A data item
    Node<ItemType>* next;   // Pointer to next node
public:
    Node();
    explicit Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
}; // end Node

//#include "Node.cpp"
#endif // NODE_H
