#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <algorithm>

template<class T>
class Manager
{
private:
    std::vector<T*> container;


public:
    Manager();
    void add(T* t);
    void remove(T* t);
    static T* instanciate();
};

template<class T>
Manager<T>::Manager()
{

}

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
