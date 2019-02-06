// Author:            Michael Beebower
// Assignment Number: Lab 1
// File Name:         maxarray.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              2/5/2019
// Instructor:        Michael Miller

// Refer to:
// template_main.cpp in Examples
// how to build template functions
// don't create classes
// use max function to compare arrays of size 1

/*-------------------------------------------------------------------------
   Program to illustrate the use of a function template to display
   an array with elements of any type for which << is defined.

   Output:  An array of ints and an array of doubles using display()
 -------------------------------------------------------------------------*/

#include <algorithm> // used for max function
#include <iostream>
#include <string>

template <class ElementType>
void display(const ElementType array[], int numElements);
template <class ElementType>
ElementType maxArray(const ElementType array[], int first, int last);

int main()
{
    double x[] = {1.1, 6.3, 2.2, 3.3, 4.4, 5.5};
    display(x, 6);
    //maxArray(x, 0, 4);
    std::cout << "maxArray: " << maxArray(x, 5, 0) << std::endl;

    //int num[] = {1, 2, 3, 4};
    //display (num, 4);
    //maxArray(num, 0, 3);

    //std::string s[] = {"aa", "bb", "cc"};
    //display(s, 3);
    //maxArray(s, 0, 2);

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


// Assume unordered array, such as <1,6,8,3>
template <class ElementType>
ElementType maxArray(const ElementType array[], int first, int last)
{
    if (first > last) // not logical comparison, give exit flag of -1?
        return -1;
    else if (first == last) // array size = 1, end of recursion
        return array[first];    // max of 1 entry is itself
    // else if (last > first)  // array size > 1, need to split in half

    int mid = first + (last - first) / 2;
    return std::max(maxArray(array,first,mid), maxArray(array,mid+1,last));
}
