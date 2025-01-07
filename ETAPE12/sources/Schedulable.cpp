#include "Schedulable.h"
#include <iostream>
using namespace std;

namespace planning
 {
    int Schedulable::currentId = 1;

    Schedulable::Schedulable() 
    {
        #ifdef DEBUG
        std::cout << ">>Schedulable: Constructeur par defaut appelé:<<" << std::endl;
        #endif
        setId(0);
    }

    Schedulable::Schedulable(int c) 
    {
        #ifdef DEBUG
        std::cout << ">>Schedulable: Constructeur d'initialisation appelé:<<" << std::endl;
        #endif
        setId(c);
    }

    Schedulable::Schedulable(const Schedulable& c) 
    {
        #ifdef DEBUG
        std::cout << ">>Schedulable: Constructeur de copie appelé:<<" << std::endl;
        #endif
        setId(c.getId());
    }

    Schedulable::~Schedulable() 
    {
        #ifdef DEBUG
        std::cout << ">>Schedulable: destructeur appelé:<<" << std::endl;
        #endif
    }

    void Schedulable::setId(int i) 
    {
        this->id = i;
    }

    void Schedulable::setCurrentId(int newId) 
    {
        currentId = newId;
    }

    int Schedulable::getId() const 
    {
        return this->id;
    }

    int Schedulable::getCurrentId()
    {
        return currentId++;
    }

    ostream& operator<<(ostream& os, const planning::Schedulable& s) 
	{
    	os << s.toString();
    	return os;
	}

    
}

