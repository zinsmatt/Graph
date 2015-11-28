#ifndef ELEMENT_H
#define ELEMENT_H
#include <map>


/* \class Base type which can gets attributes
 *
 *
 * */
class Element
{
   // static int idCounter;      //!< counter incremented for each element created
    unsigned int id;                    //!< each element has its own id
    std::map<std::string,std::string> stringAttributes;     //!< a map of string attributes identified by a keyword
    std::map<std::string,int> intAttributes;            //!< a map of integer attributes identified by a keyword
    std::map<std::string,float> floatAttributes;       //!< a map of float  attributes identified by a keyword
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
    bool addIntAttribute(const std::string& key, int x);

    /* \brief add a float attribute
     * \param attribute's keyword and value
     * \return true if added, false if not added or already exists
     * */
    bool addFloatAttribute(const std::string& key, float x);

    /* \brief add a string attribute
     * \param attribute's keyword and value
     * \return true if added, false if already exists
     * */
    bool addStringAttribute(const std::string& key, const std::string& s);

    /* \brief remove a integer attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeIntAttribute(const std::string& s);

    /* \brief remove float integer attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeFloatAttribute(const std::string& s);

    /* \brief remove a string attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeStringAttribute(const std::string& s);

    /* \brief check if the int attribute key exists
     * \param a string representing a key
     * \return true if it exists, false else
     * */
    bool hasIntAttribute(const std::string& key);

    /* \brief check if the float attribute key exists
     * \param a string representing a key
     * \return true if it exists, false else
     * */
    bool hasFloatAttribute(const std::string& key);

    /* \brief check if the string attribute key exists
     * \param a string representing a key
     * \return true if it exists, false else
     * */
    bool hasStringAttribute(const std::string& key);



    /* \brief Getter for the id
     * */
    unsigned int getId() const { return id; }

    const std::map<std::string,std::string>& getStringAttributes() const {return stringAttributes;}
    const std::map<std::string,int>& getIntAttributes() const {return intAttributes;}
    const std::map<std::string,float>& getFloatAttributes() const {return floatAttributes;}

    const std::string& getStringAttribute(const std::string& key) const {return stringAttributes.at(key);}
    const int getIntAttribute(const std::string& key) const {return intAttributes.at(key);}
    const float getFloatAttribute(const std::string& key) const {return floatAttributes.at(key);}

    void setStringAttribute(const std::string& key, const std::string& s) { stringAttributes.at(key) = s; }
    void setIntAttribute(const std::string& key, int x) { intAttributes.at(key) = x; }
    void setFloatAttribute(const std::string& key, float x) { floatAttributes.at(key) = x; }

    void setStringAttributes(const std::map<std::string,std::string>& m){stringAttributes = m;}
    void setIntAttributes(const std::map<std::string,int>& m){intAttributes = m;}
    void setFloatAttributes(const std::map<std::string,float>& m){floatAttributes = m;}

    void setId(int id_){id = id_;}

};


#endif // ELEMENT_H
