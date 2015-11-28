#include "element.h"


//int Element::idCounter = 0;

/*
void Element::InitIdCounter(int value)
{
    idCounter = value;
}
*/
Element::Element()
{
}
Element::Element(int _id) : id(_id)
{

}

Element::~Element()
{

}

bool Element::addIntAttribute(const std::string& key, int x)
{
    if(intAttributes.find(key) != intAttributes.end())
        return false;
    intAttributes[key] = x;
    return true;
}

bool Element::addFloatAttribute(const std::string& key, float x)
{
    if(floatAttributes.find(key) != floatAttributes.end())
        return false;
    floatAttributes[key] = x;
    return true;
}

bool Element::addStringAttribute(const std::string& key, const std::string& s)
{
    if(stringAttributes.find(key) != stringAttributes.end())
        return false;
    stringAttributes[key] = s;
    return true;
}

bool Element::removeIntAttribute(const std::string &s)
{
    if(intAttributes.find(s) != intAttributes.end())
    {
        intAttributes.erase(s);
        return true;
    }
    return false;
}

bool Element::removeFloatAttribute(const std::string &s)
{
    if(floatAttributes.find(s) != floatAttributes.end())
    {
        floatAttributes.erase(s);
        return true;
    }
    return false;
}

bool Element::removeStringAttribute(const std::string &s)
{
    if(stringAttributes.find(s) != stringAttributes.end())
    {
        stringAttributes.erase(s);
        return true;
    }
    return false;
}

bool Element::hasIntAttribute(const std::string &key)
{
    return intAttributes.find(key) != intAttributes.end();
}

bool Element::hasFloatAttribute(const std::string &key)
{
    return floatAttributes.find(key) != floatAttributes.end();
}

bool Element::hasStringAttribute(const std::string &key)
{
    return stringAttributes.find(key) != stringAttributes.end();
}


