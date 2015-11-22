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
   // static int idCounter;      //!< counter incremented for each element created
    unsigned int id;                    //!< each element has its own id
    std::map<QString,QString> stringAttributes;     //!< a map of string attributes identified by a keyword
    std::map<QString,int> intAttributes;            //!< a map of integer attributes identified by a keyword
    std::map<QString,float> floatAttributes;       //!< a map of float  attributes identified by a keyword
public:

    Element();
    Element(int id);

    virtual ~Element();

    /* \brief initialise idCounter
     * \param init value
     * */
    static void InitIdCounter(int value);

    /* \brief add an integer attribute
     * \param attribute's keyword and value
     * \return true if added, false if not added or already exists
     * */
    bool addIntAttribute(const QString& key, int x);

    /* \brief add a float attribute
     * \param attribute's keyword and value
     * \return true if added, false if not added or already exists
     * */
    bool addFloatAttribute(const QString& key, float x);

    /* \brief add a string attribute
     * \param attribute's keyword and value
     * \return true if added, false if already exists
     * */
    bool addStringAttribute(const QString& key, const QString& s);

    /* \brief remove a integer attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeIntAttribute(const QString& s);

    /* \brief remove float integer attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeFloatAttribute(const QString& s);

    /* \brief remove a string attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeStringAttribute(const QString& s);

    /* \brief check if the int attribute key exists
     * \param a string representing a key
     * \return true if it exists, false else
     * */
    bool hasIntAttribute(const QString& key);

    /* \brief check if the float attribute key exists
     * \param a string representing a key
     * \return true if it exists, false else
     * */
    bool hasFloatAttribute(const QString& key);

    /* \brief check if the string attribute key exists
     * \param a string representing a key
     * \return true if it exists, false else
     * */
    bool hasStringAttribute(const QString& key);



    /* \brief Getter for the id
     * */
    unsigned int getId() const { return id; }

    const std::map<QString,QString>& getStringAttributes() const {return stringAttributes;}
    const std::map<QString,int>& getIntAttributes() const {return intAttributes;}
    const std::map<QString,float>& getFloatAttributes() const {return floatAttributes;}

    const QString& getStringAttribute(const QString& key) const {return stringAttributes.at(key);}
    const int getIntAttribute(const QString& key) const {return intAttributes.at(key);}
    const float getFloatAttribute(const QString& key) const {return floatAttributes.at(key);}

    void setStringAttribute(const QString& key, const QString& s) { stringAttributes.at(key) = s; }
    void setIntAttribute(const QString& key, int x) { intAttributes.at(key) = x; }
    void setFloatAttribute(const QString& key, float x) { floatAttributes.at(key) = x; }

    void setStringAttributes(const std::map<QString,QString>& m){stringAttributes = m;}
    void setIntAttributes(const std::map<QString,int>& m){intAttributes = m;}
    void setFloatAttributes(const std::map<QString,float>& m){floatAttributes = m;}

    void setId(int id_){id = id_;}

};


#endif // ELEMENT_H
