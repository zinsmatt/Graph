#include "element.h"
#include <iostream>


Element::Element(ElementId _id) : id(_id)
{

}

Element::~Element()
{

}

Element& Element::operator=(const Element& elt)
{
    this->stringAttributes = elt.stringAttributes;
    this->intAttributes = elt.intAttributes;
    this->floatAttributes = elt.floatAttributes;
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

void Element::mergeAttributes(const Element* elt2)
{
    if(!elt2)
        return;
    for(auto intIt : elt2->intAttributes)
    {
        if(this->hasIntAttribute(intIt.first))
        {
            if(this->getIntAttribute(intIt.first) != intIt.second)
                this->setIntAttribute(intIt.first+"_2",intIt.second);
        }
        else
            this->setIntAttribute(intIt.first,intIt.second);
    }

    for(auto floatIt : elt2->floatAttributes)
    {
        if(this->hasFloatAttribute(floatIt.first))
        {
            if(this->getFloatAttribute(floatIt.first) != floatIt.second)
                this->setFloatAttribute(floatIt.first+"_2",floatIt.second);
        }
        else
            this->setFloatAttribute(floatIt.first,floatIt.second);
    }

    for(auto stringIt : elt2->stringAttributes)
    {
        if(this->hasStringAttribute(stringIt.first))
        {
            std::string temp;
            this->getStringAttribute(stringIt.first,temp);
            if( temp != stringIt.second)
                this->setStringAttribute(stringIt.first+"_2",stringIt.second);
        }
        else
            this->setStringAttribute(stringIt.first,stringIt.second);
    }
}
