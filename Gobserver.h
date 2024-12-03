#ifndef GOBSERVER_H
#define GOBSERVER_H

class Observer {
    public:
        virtual ~Observer()= default;
        virtual void update() = 0; //Cette méthode est appelée quand il y a un changement

};

#endif
