// Author:            Michael Beebower
// Assignment Number: Lab 2
// File Name:         charchain.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              2/21/2019
// Instructor:        Michael Miller

/*----------------------------------------------------------------------------------------------------------------------
   Ch. 4, Programming Problem 8, pg. 157

   Specify and implement an ADT character string by using a linked chain of characters. Include typical operations such
   as finding its length, appending one string to another, finding the index of the leftmost occurrence of a character
   in a string, and testing whether one string is a substring of another.

 ---------------------------------------------------------------------------------------------------------------------*/

#include <iostream> // cout
#include <string>   // strings
#include "LinkedChar.h"
#include "Node.h"
#include "LinkedChar.cpp"

int main()
{
    bool quit = false;
    int option;
    LinkedChar<char>* linkedList = nullptr;
    std::string newString;

    std::cout << "This program specifies and implements an ADT character string by using a linked chain of characters."
        << std::endl;

    while (!quit)
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Enter new string and store as linked list of characters" << std::endl;
        std::cout << "2. Get current length (number of characters stored) from the LinkedChar" << std::endl;
        std::cout << "3. Find index of character in this LinkedChar " << std::endl;
        std::cout << "4. Append another LinkedChar to this LinkedChar" << std::endl;
        std::cout << "5. Test if another LinkedChar is submatch of this LinkedChar" << std::endl;
        std::cout << "6. Quit" << std::endl << std::endl;
        std::cout << "Enter menu option number:";
        std::cin >> option;
        std::cin.ignore();
        switch(option)
        {
            case 1: {
                std::cout << "Enter a string: ";
                std::getline(std::cin, newString);
                linkedList = new LinkedChar<char>(newString);
                std::cout << "The string has been stored as a linked list of characters." << std::endl;
                break;
            }
            case 2: {
                std::cout << "The current length of the linked list is: " << linkedList->length() << std::endl;
                break;
            }
            case 3: {
                char c;
                std::cout << "Enter a character to search for: ";
                std::cin >> c;
                std::cin.ignore();
                std::cout << "The index of " << c << " is " <<  linkedList->index(c) << std::endl;
                break;
            }
            case 4: {
                std::cout << "Enter a string to append: ";
                std::getline(std::cin, newString);
                std::cout << newString << " is added to " << linkedList->display() << " to give:" << std::endl;
                linkedList->append(LinkedChar<char>(newString));
                std::cout << linkedList->display();
                break;
            }
            case 5: {
                std::cout << "Enter a string to search for: ";
                std::getline(std::cin, newString);
                if (linkedList->submatch(LinkedChar<char>(newString)))
                    std::cout << "Yes, " << newString << " is found in " << linkedList->display() << "." << std::endl;
                else
                    std::cout << "No, " << newString << " is not found in " << linkedList->display() << "." << std::endl;
                break;
            }
            case 6: {
                quit = true;
                break;
            }
            default: {
                std::cout << "Default" << std::endl;
                break;
            }
        }

    }


    return 0;
}
