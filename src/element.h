#ifndef ELEMENT_H
#define ELEMENT_H
#include <QString>
#include <map>


/* \class Base type which can gets attributes
 *
 *
 * */
class Element
{
    static int idCounter;      //!< counter incremented for each element created
    int id;                    //!< each element has its own id
    std::map<QString,QString> stringAttributes;     //!< a map of string attributes identified by a keyword
    std::map<QString,int> intAttributes;            //!< a map of integer attributes identified by a keyword
    std::map<QString, float> floatAttributes;       //!< a map of float  attributes identified by a keyword
public:
    Element();
    ~Element();

    static void InitIdCounter(int value);

    bool addIntAttribute(const QString& key, int x);
    bool addFloatAttribute(const QString& key, float x);
    bool addStringAttribute(const QString& key, const QString& s);

    bool removeIntAttribute(const QString& s);
    bool removeFloatAttribute(const QString& s);
    bool removeStringAttribute(const QString& s);

};


#endif // ELEMENT_H
