#ifndef ELEMENT_H
#define ELEMENT_H
#include "types.h"
#include <map>


/* \class Base type which can gets attributes
 *
 *
 * */
class Element
{
   // static int idCounter;      //!< counter incremented for each element created
    ElementId id;                    //!< each element has its own id
    std::map<std::string,std::string> stringAttributes;     //!< a map of string attributes identified by a keyword
    std::map<std::string,int> intAttributes;            //!< a map of integer attributes identified by a keyword
    std::map<std::string,float> floatAttributes;       //!< a map of float  attributes identified by a keyword

public:

    /* \brief Constructor
     * \param element id (given by ElementManager)
     * */
    Element(ElementId _id);

    Element& operator=(const Element& elt);

    /* \brief Destructor
     * */
    virtual ~Element();

    /* \brief Initialise idCounter
     * \param init value
     * */
    static void InitIdCounter(int value);

    /* \brief Set or add an integer attribute
     * \param attribute's keyword and value
     * */
    void setIntAttribute(const std::string& key, int x);

    /* \brief Set or add a float attribute
     * \param attribute's keyword and value
     * */
    void setFloatAttribute(const std::string& key, float x);

    /* \brief Set or add a string attribute
     * \param attribute's keyword and value
     * */
    void setStringAttribute(const std::string& key, const std::string& s);

    /* \brief remove a integer attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeIntAttribute(const std::string& s);

    /* \brief Remove float integer attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeFloatAttribute(const std::string& s);

    /* \brief Remove a string attribute
     * \param name of the attribute
     * \return true if the attribute was removed, else false
     * */
    bool removeStringAttribute(const std::string& s);

    /* \brief Check if the int attribute key exists
     * \param name of the attribute
     * \return true if it exists, false else
     * */
    bool hasIntAttribute(const std::string& key);

    /* \brief Check if the float attribute key exists
     * \param name of the attribute
     * \return true if it exists, false else
     * */
    bool hasFloatAttribute(const std::string& key);

    /* \brief Check if the string attribute key exists
     * \param name of the attribute
     * \return true if it exists, false else
     * */
    bool hasStringAttribute(const std::string& key);

    /* \brief Get an integer attribute
     * \param name of the attribute
     * \return integer
     * */
    int getIntAttribute(const std::string& key) const;

    /* \brief Get a float attribute
     * \param name of the attribute
     * \return float value
     * */
    float getFloatAttribute(const std::string& key) const;

    /* \brief Get a string attribute
     * \param name of the attribute and a reference as out parameter
     * \return boolean true if ok, false if key unknown
     * */
    bool getStringAttribute(const std::string& key, std::string& out) const;

    /* \brief Merge all attributes
     * \param the other element
     * */
    void mergeAttributes(const Element* elt2);

    /* \brief Getter for the id
     * */
    ElementId getId() const { return id; }
};


#endif // ELEMENT_H
