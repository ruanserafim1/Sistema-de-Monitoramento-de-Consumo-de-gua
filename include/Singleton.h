#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class Singleton {
private:
    static T* instance;
    
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
    
public:
    // Deleted copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static T& getInstance() {
        if (instance == nullptr) {
            instance = new T();
        }
        return *instance;
    }
    
    static void destroyInstance() {
        delete instance;
        instance = nullptr;
    }
};

template<typename T>
T* Singleton<T>::instance = nullptr;

#endif
