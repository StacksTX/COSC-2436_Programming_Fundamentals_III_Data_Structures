// Author:            Michael Beebower
// Assignment Number: Lab 6
// File Name:         sortedtree.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              5/9/2019
// Instructor:        Michael Miller

/*----------------------------------------------------------------------------------------------------------------------

 Ch. 16, Programming Problems 2, pg. 513

 Name the program sortedtree.cpp. Make sure the following requirements are met.

    * Program must compile and run.
    * Driver program should:
        * insert 21 random numbers (1-100) on the tree
        * remove the last number inserted
        * and display the tree
    * To display just use in order traversal
    * No user input for driver program.
    * Hint: Inherit from binarytree (binarytree.zip) as a starting point.
    * Use the BST ADT BinarySearchTree.h
    * Hint: remove override keywords from .cpp file when copying the prototypes from the .h file.
    * Second hint: use this->rootPtr to access rootPtr in BinaryNodeTree from BinarySearchTree.

 Remember to upload all files before submitting.

    * sortedtree.cpp

 ---------------------------------------------------------------------------------------------------------------------*/

#include <iostream>             // std::cout
#include <memory>               // std::make_shared
#include <random>               // std::default_random_engine, std::uniform_int_distribution
#include "BinarySearchTree.h"

// function prototype
void displayTree(int& number);

int main ()
{
    const int TREE_SIZE = 21;
    const int MAX_VALUE = 100;
    int random_integer = 0;

    auto bst = std::make_shared<BinarySearchTree<int>>();   // initialize a BST variable

    // setup random integer generator, refer to http://www.cplusplus.com/reference/random/
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dist(1, MAX_VALUE);

    std::cout << std::endl <<
              "Displaying the random integers as they are generated and inserted into the binary search tree:" <<
              std::endl << std::endl;

    // add entries
    for (int i = 0; i < TREE_SIZE; i++)
    {
        // display the line # (which iteration, 1-21)
        std::cout << (i+1);
        if (i < 9) std::cout << " ";

        // assign random (1-100) value to random_integer
        random_integer = dist(gen);

        // insert 21 random numbers (1-100) on the tree
        bst->add(random_integer);

        std::cout << " |insert " << random_integer;
        if (random_integer < 10)
            std::cout << "  ";
        else if (random_integer != 100)
            std::cout << " ";
        std::cout << "| ";

        bst->inorderTraverse(displayTree);  // display tree
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // remove the last inserted integer (not always the last number on the tree).
    std::cout << "Removing the last inserted integer, which is: " << random_integer << std::endl;
    bst->remove(random_integer);

    bst->inorderTraverse(displayTree);

    return 0;
}

void displayTree(int& number)
{
    std::cout << number << " ";
}