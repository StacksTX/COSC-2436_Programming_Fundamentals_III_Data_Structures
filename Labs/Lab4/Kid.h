//
// Created by beebs on 4/2/19.
//

#ifndef KID_H
#define KID_H

#include <list>         // std::list
#include <string>       // std::string

template<class ItemType>
class Kid
{
private:
    std::string kidName;
    std::list<std::string> gifts;
public:
    void setName(const std::string&);
    void addGift(const std::string&);
    std::string getName();
    std::string giftsToString(const std::string& split = ",");
};

#include "Kid.cpp"

#endif // KID_H
