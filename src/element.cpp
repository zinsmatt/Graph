#include "element.h"



int Element::idCounter = 0;

/* \brief initialise idCounter
 * \param init value
 * */
void Element::InitIdCounter(int value)
{
    idCounter = value;
}




Element::Element()
{
    id = idCounter++;
}

Element::~Element()
{

}




/* \brief add an integer attribute
 * \param attribute's keyword and value
 * \return true if added, false if not added or already exists
 * */
bool Element::addIntAttribute(const QString& key, int x)
{
    if(intAttributes.find(key) != intAttributes.end())
        return false;
    intAttributes[key] = x;
    return true;
}

/* \brief add a float attribute
 * \param attribute's keyword and value
 * \return true if added, false if not added or already exists
 * */
bool Element::addFloatAttribute(const QString& key, float x)
{
    if(floatAttributes.find(key) != floatAttributes.end())
        return false;
    floatAttributes[key] = x;
    return true;
}

/* \brief add a string attribute
 * \param attribute's keyword and value
 * \return true if added, false if already exists
 * */
bool Element::addStringAttribute(const QString& key, const QString& s)
{
    if(stringAttributes.find(key) != stringAttributes.end())
        return false;
    stringAttributes[key] = s;
    return true;
}



/* \brief remove a integer attribute
 * \param name of the attribute
 * \return true if the attribute was removed, else false
 * */
bool Element::removeIntAttribute(const QString &s)
{
    if(intAttributes.find(s) != intAttributes.end())
    {
        intAttributes.erase(s);
        return true;
    }
    return false;
}

/* \brief remove float integer attribute
 * \param name of the attribute
 * \return true if the attribute was removed, else false
 * */
bool Element::removeFloatAttribute(const QString &s)
{
    if(floatAttributes.find(s) != floatAttributes.end())
    {
        floatAttributes.erase(s);
        return true;
    }
    return false;
}


/* \brief remove a string attribute
 * \param name of the attribute
 * \return true if the attribute was removed, else false
 * */
bool Element::removeStringAttribute(const QString &s)
{
    if(stringAttributes.find(s) != stringAttributes.end())
    {
        stringAttributes.erase(s);
        return true;
    }
    return false;
}
