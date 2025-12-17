#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <memory>
#include <string>
#include <functional>

// Interface Observer
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& eventType, const void* eventData) = 0;
};

// Subject (Observable)
class EventDispatcher {
private:
    std::vector<IObserver*> observers;
    
public:
    void attach(IObserver* observer) {
        observers.push_back(observer);
    }
    
    void detach(IObserver* observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    
    void notify(const std::string& eventType, const void* eventData) {
        for (auto observer : observers) {
            observer->update(eventType, eventData);
        }
    }
    

};


struct ConsumoEvent {
    std::string hidrometroId;
    double consumo;
    std::string timestamp;
};

#endif
