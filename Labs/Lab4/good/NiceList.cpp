//
// Created by beebs on 4/2/19.
//

#include "NiceList.h"
#include <string>           // std::string
#include <list>             // std::list

//template<class ItemType>
//NiceList<ItemType>::NiceList()
//= default; // end default constructor

//NiceList::NiceList() = default;

//template<class ItemType>
void NiceList::setName(std::string name)
{
    kidName = name;
}

//template<class ItemType>
void NiceList::addGift(std::string gift)
{
    gifts.push_back(gift);
}

//template<class ItemType>
std::string NiceList::getName()
{
    return kidName;
}

//template<class ItemType>
std::string NiceList::giftsToString(std::string split)
{
    std::string result;

    for (auto & gift : gifts)
    {
        if (!result.empty())
            result += split;
        result += std::string(gift);
    }

    return result;
}