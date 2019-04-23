// Author:            Michael Beebower
// Assignment Number: Lab 5
// File Name:         sortedlist.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              4/22/2019
// Instructor:        Michael Miller

/*----------------------------------------------------------------------------------------------------------------------
    Ch. 12, Programming Problem 1, pg. 392

    Name the program "sortedlist.cpp". Make sure the following requirements are met.

        * Program must compile and run.
        * Must use the Sorted List ADT, "SortedListInterface.h"
        * For "LinkSortedList", pg. 376 has the code for "insertSorted". You must complete the implementation.
        * Therefore, the "SortedList" is not based on a "LinkedList" but uses its own implementation of a List.
        * Driver program should insert 21 random numbers (1-100) on the sorted list.
        * Display the numbers as they are inserted.
        * To generate a number from 1-100 use the STL random library (not the rand function).
        * Then remove the last number inserted (not always the last number on the list).
        * Last of all display the sorted list of 20 numbers.
        * No user input for driver program.

    pg. 392
    1. Complete the implementation of the class "LinkedSortedList", and write a driver program to fully test it.

    pg. 376
    * insertSorted
    * template<class ItemType>
        void LinkedSortedList

 ---------------------------------------------------------------------------------------------------------------------*/

#include <iostream>     // std::cout
#include <memory>       // std::unique_ptr, std::make_unique
#include <random>       // std::default_random_engine, std::uniform_int_distribution
#include <functional>   // std::bind
#include "SortedListInterface.h"
#include "LinkedSortedList.h"

int main() {
    const int LIST_SIZE = 21;
    const int MAX_VALUE = 100;
    int random_integer = 0;

    // declare and allocate a sorted list, where LinkedSortedList is an implementation of the operations specified by
    // the interface SortedListInterface
    // std::unique_ptr<SortedListInterface<int>> intListPtr = std::make_unique<LinkedSortedList<int>>();
    std::shared_ptr<SortedListInterface<int>> intListPtr = std::make_shared<LinkedSortedList<int>>();

    // setup random integer generator, refer to http://www.cplusplus.com/reference/random/
    // hmm... random_device vs. default_random_engine, does not require seed
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, MAX_VALUE);
    auto dice = std::bind(distribution, generator);

    // add entries, realizing that the ADT will organize them / put them in order
    for (int i = 0; i < LIST_SIZE; i++) {
        // assign random (1-100) value to random_integer
        random_integer = dice();

        // insert 21 random numbers (1-100) on the sorted list.
        intListPtr->insertSorted(random_integer);

        // display the numbers as they are inserted.
        std::cout << random_integer;
    }

    return 0;
}
