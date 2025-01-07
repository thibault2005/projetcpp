#include "Professor.h"
#include <iostream>
#include <string>
#include "Schedulable.h"
using namespace std;

namespace planning 
{

    
    Professor::Professor() : Schedulable() 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur par défaut appelé<<" << endl;
        #endif

        setLastName("-----");
        setFirstName("----");
    }

    Professor::Professor(int i, const string &ln, const string &fn) : Schedulable(i) 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur d'initialisation appelé<<" << endl;
        #endif

        setLastName(ln);
        setFirstName(fn);
    }
     


    Professor::Professor(const Professor &c) : Schedulable(c) 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur de copie appelé<<" << endl;
        #endif

        setLastName(c.getLastName());
        setFirstName(c.getFirstName());
    }

    void Professor::setLastName(const string &ln)
    {
        lastName = ln;
    }

    void Professor::setFirstName(const string &fn)
    {
        firstName = fn;
    }

    string Professor::getLastName() const 
    {
        return lastName;
    }

    string Professor::getFirstName() const 
    {
        return firstName;
    }


    string Professor::toString()const 
    {
        return lastName + " " + firstName;
    }

    string Professor::tuple()const 
    {
        return to_string(id) + ";" + lastName + ";" + firstName;
    }

    Professor& Professor::operator=(const Professor& teacher) 
    {
	    if (this != &teacher) 
	    {
		    Schedulable::operator=(teacher); 
		    this->lastName = teacher.lastName;
		    this->firstName = teacher.firstName;
	    }

    	return *this;
	}

    bool Professor::operator<(const Professor& other) const 
    {
        if (this->lastName != other.lastName) 
        {
            return this->lastName < other.lastName; 
        }
    return this->firstName < other.firstName;
    }



}
