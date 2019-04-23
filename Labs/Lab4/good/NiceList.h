//
// Created by beebs on 4/2/19.
//

#ifndef NICELIST_H
#define NICELIST_H

#include <list>         // std::list
#include <string>       // std::string

//template<class ItemType>
class NiceList
{
private:
    std::string kidName;
    std::list<std::string> gifts;
public:
    //NiceList();
    void setName(std::string);
    void addGift(std::string);
    std::string getName();
    std::string giftsToString(std::string split = ",");
    //~NiceList();
};

#include "NiceList.cpp"

#endif //NICELIST_H
