#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <algorithm>

template<class T>
class Manager
{
private:

    std::vector<T*> elements;
    std::vector<T*> container;
    static Manager<T> *instance;

    Manager(){}
    Manager(const Manager<T>&);
    Manager& operator=(const Manager<T>&);


    static Manager<T>* getInstance() {
        if(!instance)
            instance = new Manager<T>;
        return instance;
    }
    static void killInstance() {
        if(instance)
            delete instance;
    }

public:

    T* create() {
        T* obj = new T;
                return new T; }
    void release(T* obj) {
        if(obj)
            delete obj;
    }

    void add(T* t);
    void remove(T* t);
    static T* instanciate();
};

template<class T>
Manager<T>* Manager<T>::instance = nullptr;


template<class T>
T* Manager<T>::instanciate()
{
    return new T();
}

template<typename T>
void Manager<T>::add(T* t)
{
    container.push_back(t);
}

template<typename T>
void Manager<T>::remove(T* t)
{
    T* tmp = t;
    container.erase(std::find(container.begin(), container.end(), t));
}

#endif // MANAGER_H
