#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <Gobserver.h>

class Subject {
    private:
        std::vectpr<Observer*> observers;

    public:
        virtual ~Gsubject() = default;

        void addObserver(Observer* observer) {
            observer.push_back(observer);
        }

        void removeObserver(Observer* observer) {
            observers.erase(std::remove(observers.bergin(), observers.end(), observer), observers.end());
        }

        void notifObservers() {
            for (Observer* observer : observers){
                observer->update();
            }
        }
};

#endif