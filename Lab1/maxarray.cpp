// Author:            Michael Beebower
// Assignment Number: Lab 1
// File Name:         maxarray.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              2/7/2019
// Instructor:        Michael Miller

/*-------------------------------------------------------------------------
   Program to illustrate the use of a recursive template function to find
   and display the element with the maximum value of an array with elements
   of any type for which << is defined.

   Output:  An array of doubles, an array of ints, and an array of strings
   using display().
   The maximum value element of each of those arrays using maxArray().
 -------------------------------------------------------------------------*/

#include <algorithm>    // max function
#include <iostream>     // cout
#include <string>       // strings

// Function prototypes
template <class ElementType>
void display(const ElementType array[], int numElements);
template <class ElementType>
ElementType maxArray(const ElementType array[], int first, int last);

int main()
{
    std::cout << "This is an array of doubles:\n";
    double x[] = {1.1, 6.3, 2.2, 3.3, 4.4, 5.5};
    display(x, 6);
    std::cout << "The max value is: " << maxArray(x, 5, 0) << "\n\n";

    std::cout << "This is an array of integers:\n";
    int num[] = {1, 2, 3, 4};
    display (num, 4);
    std::cout << "The max value is: " << maxArray(num, 0, 3) << "\n\n";

    std::cout << "This is an array of strings:\n";
    std::string s[] = {"aa", "d", "bb", "cc"};
    display(s, 4);
    std::cout << "The max value is: " << maxArray(s, 0, 3) << "\n\n";

    return 0;
}

/*-------------------------------------------------------------------------
  Display elements of any type (for which the output operator is defined)
  stored in an array.

  Pre-condition:  ElementType is a type parameter.
  Post-condition: First numElements of array have been output to cout.
 ------------------------------------------------------------------------*/
template <class ElementType>
void display(const ElementType array[], int numElements)
{
    for (int i = 0; i < numElements; i++)
        std::cout << array[i] << "  ";
    std::cout << std::endl;
}

/*-------------------------------------------------------------------------
  Take an (unordered) array of any type. Find the element stored in the
  array (between indexes of first and last) with the maximum value by using
  recursion and the max STL function. Return the element with the maximum
  value.

  Pre-condition:  ElementType is a type parameter.
  Post-condition: The element with the maximum value between indexes first
  and last in the array are returned.
 ------------------------------------------------------------------------*/
template <class ElementType>
ElementType maxArray(const ElementType array[], int first, int last)
{
    // Initialize local variable returnArray so that we can implement only 1 return call.
    ElementType returnArray;

    if (first == last) {                // array size = 1, end of recursion
        returnArray = array[first];     // max of 1 entry is itself
    }
    // Regular order of first and last
    else if (last > first) {            // array size > 1, need to split in half
        int mid = first + (last - first) / 2;
        returnArray = std::max(maxArray(array, first, mid), maxArray(array, mid + 1, last));
    }
    // Irregular order of first and last.
    // Since we are interested in returning the maximum value and we are not interested in returning an index like in
    // binary_search.cpp, then we cannot return -1 if (first > last).
    // Thus, it would be more logical to proceed with the indexes given and search in a "backwards" manner by swapping
    // the first and last variables.
    else { // if (first > last)         // array size > 1, need to split in half
        int mid = last + (first - last) / 2;
        returnArray = std::max(maxArray(array, last, mid), maxArray(array, mid + 1, first));
    }

    return returnArray;
}   // end maxArray
