#include "element.h"
#include <iostream>


Element::Element(int _id) : id(_id)
{

}

Element::~Element()
{

}

void Element::setIntAttribute(const std::string& key, int x)
{
    if(intAttributes.find(key) != intAttributes.end())
        intAttributes[key] = x;
    else
        intAttributes[key] = x;
}

void Element::setFloatAttribute(const std::string& key, float x)
{
    if(floatAttributes.find(key) != floatAttributes.end())
        floatAttributes[key] = x;
    else
        floatAttributes[key] = x;
}

void Element::setStringAttribute(const std::string& key, const std::string& s)
{
    if(stringAttributes.find(key) != stringAttributes.end())
        stringAttributes[key] = s;
    else
        stringAttributes[key] = s;
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

int Element::getIntAttribute(const std::string &key) const
{
    if(intAttributes.find(key) != intAttributes.end())
    {
        return intAttributes.at(key);
    }
    else
    {
        std::cerr << "Warning : getIntAttribute(" << key <<") impossible" << std::endl;
        return false;
    }
}

float Element::getFloatAttribute(const std::string &key) const
{
    if(floatAttributes.find(key) != floatAttributes.end())
    {
        return floatAttributes.at(key);
    }
    else
    {
        std::cerr << "Warning : getFloatAttribute(" << key <<") impossible" << std::endl;
        return -1;
    }
}

bool Element::getStringAttribute(const std::string &key, std::string& out) const
{
    if(stringAttributes.find(key) != stringAttributes.end())
    {
        out = stringAttributes.at(key);
        return true;
    }
    else
    {
        std::cerr << "Warning : getStringAttribute(" << key <<") impossible" << std::endl;
        return false;
    }
}
