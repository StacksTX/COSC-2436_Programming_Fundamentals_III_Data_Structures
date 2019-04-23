//
// Created by beebs on 4/2/19.
//

#include "Kid.h"
#include <string>           // std::string
#include <list>             // std::list

template<class ItemType>
void Kid<ItemType>::setName(const std::string& name)
{
    kidName = name;
}

template<class ItemType>
void Kid<ItemType>::addGift(const std::string& gift)
{
    gifts.push_back(gift);
}

template<class ItemType>
std::string Kid<ItemType>::getName()
{
    return kidName;
}

template<class ItemType>
std::string Kid<ItemType>::giftsToString(const std::string& split)
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