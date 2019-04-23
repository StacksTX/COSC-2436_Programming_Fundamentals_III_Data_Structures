// Author:            Michael Beebower
// Assignment Number: Lab 4
// File Name:         giftlist.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              4/4/2019
// Instructor:        Michael Miller

/*----------------------------------------------------------------------------------------------------------------------
    Ch. 8, Programming Problem 2, pg. 264

    Name the program giftlist.cpp. Make sure the following requirements are met.

        * Program must compile and run.
        * All inputs are strings.
        * Only do the nice list, not the naughty list.
        * User will enter names until empty string denoting no more names.
        * Each name will be followed by one or more gifts.
        * After names entered display contents of the name list and each gift list.
        * A single string list is not an adequate data structure.

    Santa Claus allegedly keeps lists of those who are naughty and those who are nice.
    On the naughty list are the names of those who will get coal in their stockings.
    On the nice list are those who will receive gifts.
    Each object in this list contains a name (a string) and a list of that person's gifts (an instance of an ADT list).
    Design an ADT for the objects in the nice list.
    Specify each ADT operation by stating its purpose, describing its parameters, and writing preconditions,
        postconditions, and a pseudocode version of its header.
    Then write a template interface for the ADT that includes javadoc-style comments.

 ---------------------------------------------------------------------------------------------------------------------*/

#include <iostream>     // std::cout, std::cin
#include <string>       // std::string
#include <list>         // std::list - This STL list Container is a template version of a doubly linked list.
#include "Kid.h"


int main() {
    std::string kidName, giftName;
    std::list<Kid<std::string>> theNiceList;

    std::cout << "name for nice list: ";
    getline(std::cin, kidName);

    // outer loop
    while (!kidName.empty())
    {
        Kid<std::string> aGiftList;
        aGiftList.setName(kidName);

        std::cout << "add gifts for " << kidName << std::endl;

        // inner loop
        do {
            std::cout << "gift: ";
            getline(std::cin, giftName);
            aGiftList.addGift(giftName);
        } while(!giftName.empty());

        theNiceList.push_back(aGiftList);     // push_back inserts elements at end in list

        std::cout << "name for nice list: ";
        getline(std::cin, kidName);
    }

    // after user input is complete, show data back to user
    std::cout << "The list contains" << std::endl;
    for (auto giftList: theNiceList)
        std::cout << giftList.getName() << "  " << giftList.giftsToString(" ") << std::endl;

    return 0;
}