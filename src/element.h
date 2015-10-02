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


    /* \brief Getter for the id
     * */
    int getId() const { return id; }

    const std::map<QString,QString>& getStringAttributes() const {return stringAttributes;}
    const std::map<QString,int>& getIntAttributes() const {return intAttributes;}
    const std::map<QString,float>& getFloatAttributes() const {return floatAttributes;}

    const QString& getStringAttribute(const QString& key) const {return stringAttributes.at(key);}
    const int getIntAttribute(const QString& key) const {return intAttributes.at(key);}
    const float getFloatAttribute(const QString& key) const {return floatAttributes.at(key);}

    void setStringAttributes(const std::map<QString,QString>& m){stringAttributes = m;}
    void setIntAttributes(const std::map<QString,int>& m){intAttributes = m;}
    void setFloatAttributes(const std::map<QString,float>& m){floatAttributes = m;}

    void setId(int id_){id = id_;}

};


#endif // ELEMENT_H
